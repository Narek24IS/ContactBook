#include "mainwindow.h"
#include <QSqlRecord>
#include <QTableView>
#include "editdialog.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setIcons();
    setGlobalStyle();
    dbConnect();
    refreshTable();
    initTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setGlobalStyle()
{
    QFile styleF;
    styleF.setFileName(":/resoruces/MacOS.qss");
    styleF.open(QFile::ReadOnly);
    styleStr = styleF.readAll();
    QMainWindow::setStyleSheet(styleStr);
}

void MainWindow::setIcons()
{
    this->setWindowIcon(QIcon(":/resoruces/contact_icon.png"));
    this->ui->addButton->setIcon(QIcon(":/resoruces/add.png"));
    this->ui->removeButton->setIcon(QIcon(":/resoruces/remove.png"));
    this->ui->editButton->setIcon(QIcon(":/resoruces/edit.png"));
    this->ui->sortButton->setIcon(QIcon(":/resoruces/down_arrow.png"));
}

void MainWindow::resizeToContent()
{
    this->ui->contactTableView->resizeColumnsToContents();
    this->ui->contactTableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
}

void MainWindow::dbConnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("phones");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("68ee3e138");
    db.setPort(3306);
    db.open();
}

void MainWindow::refreshTable()
{
    model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels({"Id", "Контакт", "Номер", "Тип номера"});
    QSqlQuery query("SELECT * FROM contact");
    int row = 0;
    while (query.next()) {
        qDebug() << "Ok";
        QList<QStandardItem *> items;
        for (int i = 0; i < query.record().count(); ++i) {
            items << new QStandardItem(query.value(i).toString());
        }
        model->insertRow(row++, items);
    }
}

void MainWindow::initTable()
{
    //    QString fileName = "tableData.dat";
    //    QFile file(fileName);
    //    if (file.open(QIODevice::ReadOnly)) {
    //        QTextStream stream(&file);
    //        int rows = 0;
    //        int cols = 0;
    //        if (!stream.atEnd()) {
    //            this->id = stream.readLine().toInt();
    //        }
    //        if (!stream.atEnd()) {
    //            rows = stream.readLine().toInt();
    //        }
    //        if (!stream.atEnd()) {
    //            cols = stream.readLine().toInt();
    //        }

    //        model->setRowCount(rows);
    //        model->setColumnCount(cols);
    //        for (int row = 0; row < rows; ++row) {
    //            for (int col = 0; col < cols; ++col) {
    //                if (!stream.atEnd()) {
    //                    QModelIndex index = model->index(row, col);
    //                    QString data = stream.readLine();
    //                    model->setData(index, data);
    //                }
    //            }
    //        }
    //        file.close();
    //    }
    this->ui->contactTableView->setModel(model);
    this->ui->contactTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->contactTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    resizeToContent();
}

void MainWindow::saveDataToFile()
{
    QString fileName = "tableData.dat";
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        unsigned lastId = this->id;
        int rows = model->rowCount();
        int cols = model->columnCount();
        stream << lastId << "\n" << rows << "\n" << cols << "\n";
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                QModelIndex index = model->index(row, col);
                QString data = model->data(index).toString();
                stream << data << "\n";
            }
        }
        file.close();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    saveDataToFile();
    QMainWindow::closeEvent(event);
}

void MainWindow::initNewEditDialog(QList<QStandardItem *> data)
{
    edit = new EditDialog(data, this);
    edit->setStyleSheet(styleStr);
    connect(edit, &EditDialog::saveData, this, &MainWindow::setDataFromEditDialog);
    edit->exec();
}

void MainWindow::setDataFromEditDialog(const QList<QStandardItem *> &data)
{
    for (int col = 1; col < model->columnCount(); ++col) {
        QModelIndex index = model->index(curId - 1, col);
        QVariant cellData = data[col]->text();
        model->setData(index, cellData);
    }
    model->setItem(curId - 1, 0, new QStandardItem(QString::number(curId)));
    resizeToContent();
}

void MainWindow::on_editButton_clicked()
{
    int row = this->ui->contactTableView->currentIndex().row();
    if (row != -1) {
        QList<QStandardItem *> data;
        for (int col = 0; col < model->columnCount(); ++col) {
            QModelIndex index = model->index(row, col);
            QString cellData = model->data(index).toString();
            data.append(new QStandardItem(cellData));
        }
        curId = data[0]->text().toUInt();
        initNewEditDialog(data);
    }
}

void MainWindow::initNewAddDialog()
{
    edit = new EditDialog(this);
    connect(edit, &EditDialog::saveData, this, &MainWindow::setDataFromAddDialog);
    edit->setStyleSheet(styleStr);
    edit->exec();
}

void MainWindow::setDataFromAddDialog(const QList<QStandardItem *> &data)
{
    model->appendRow(data);
    model->setItem(model->rowCount() - 1, 0, new QStandardItem(QString::number(id)));
    resizeToContent();
}

void MainWindow::on_addButton_clicked()
{
    id++;
    initNewAddDialog();
}

void MainWindow::on_removeButton_clicked()
{
    int row = this->ui->contactTableView->currentIndex().row();
    model->removeRow(row);
}

void MainWindow::on_sortButton_clicked()
{
    this->ui->contactTableView->setSortingEnabled(true);
    if (ui->contactTableView->horizontalHeader()->isSortIndicatorClearable()) {
        ui->contactTableView->horizontalHeader()->setSortIndicatorClearable(false);
        ui->contactTableView->horizontalHeader()->setSortIndicator(1, Qt::AscendingOrder);
    } else {
        ui->contactTableView->horizontalHeader()->setSortIndicatorClearable(true);
        ui->contactTableView->horizontalHeader()->setSortIndicator(0, Qt::AscendingOrder);
    }
    this->ui->contactTableView->setSortingEnabled(false);
}
