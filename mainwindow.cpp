#include "mainwindow.h"
#include <QSqlField>
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

void MainWindow::initTable()
{
    model = new QSqlTableModel(this);
    model->setTable("contact");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Name");
    model->setHeaderData(2, Qt::Horizontal, "Number");
    model->setHeaderData(3, Qt::Horizontal, "Type");
    model->setHeaderData(4, Qt::Horizontal, "Image");
    model->select();
    for (int row = 0; row < 5; ++row) {
        QSqlRecord record = model->record(row);
        QByteArray DBimg = record.value(4).toByteArray();
        qDebug() << record.value(4).toByteArray();
        QPixmap pixmap = QPixmap::fromImage(QImage::fromData(DBimg));
        model->setData(model->index(editRow, 4), pixmap);
    }
    this->ui->contactTableView->setModel(model);
    this->ui->contactTableView->setSortingEnabled(true);
    this->ui->contactTableView->sortByColumn(sortedCol, Qt::AscendingOrder);
    this->ui->contactTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->contactTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    resizeToContent();
}

void MainWindow::initNewEditDialog(QList<QString> data, QByteArray imageData)
{
    edit = new EditDialog(data, imageData, this);
    edit->setStyleSheet(styleStr);
    connect(edit, &EditDialog::saveData, this, &MainWindow::setDataFromEditDialog);
    edit->exec();
}

void MainWindow::setDataFromEditDialog(const QList<QString> &data, QByteArray imageData)
{
    QSqlRecord record = model->record(editRow);
    record.setValue("name", data[1]);
    record.setValue("number", data[2]);
    record.setValue("type", data[3]);
    record.setValue("image", imageData);
    model->setData(model->index(editRow, 4), QPixmap::fromImage(QImage::fromData(imageData)));
    resizeToContent();
}

void MainWindow::on_editButton_clicked()
{
    editRow = this->ui->contactTableView->currentIndex().row();
    if (editRow != -1) {
        QList<QString> data;
        for (int col = 0; col < 4; ++col) {
            QModelIndex index = model->index(editRow, col);
            QString cellData = model->data(index).toString();
            data.append(cellData);
        }
        QModelIndex index = model->index(editRow, 4);
        QByteArray imageData = model->data(index).toByteArray();
        initNewEditDialog(data, imageData);
    }
    resizeToContent();
}

void MainWindow::initNewAddDialog()
{
    edit = new EditDialog(this);
    connect(edit, &EditDialog::saveData, this, &MainWindow::setDataFromAddDialog);
    edit->setStyleSheet(styleStr);
    edit->exec();
}

void MainWindow::setDataFromAddDialog(const QList<QString> &data, QByteArray imageData)
{
    QSqlRecord record;
    record.append(QSqlField("name", QMetaType()));
    record.append(QSqlField("number", QMetaType()));
    record.append(QSqlField("type", QMetaType()));
    record.append(QSqlField("image", QMetaType()));
    record.setValue("name", data[1]);
    record.setValue("number", data[2]);
    record.setValue("type", data[3]);
    record.setValue("image", imageData);
    model->insertRecord(-1, record);
    model->setData(model->index(-1, 4), QPixmap::fromImage(QImage::fromData(imageData)));
    resizeToContent();
}

void MainWindow::on_addButton_clicked()
{
    initNewAddDialog();
}

void MainWindow::on_removeButton_clicked()
{
    int row = this->ui->contactTableView->currentIndex().row();
    model->removeRow(row);
    ui->contactTableView->sortByColumn(sortedCol, Qt::AscendingOrder);
}

void MainWindow::on_sortButton_clicked()
{
    switch (sortedCol) {
        case 0:
            ui->contactTableView->sortByColumn(++sortedCol, Qt::AscendingOrder);
            break;
        case 1:
            ui->contactTableView->sortByColumn(++sortedCol, Qt::AscendingOrder);
            break;
        case 2:
            ui->contactTableView->sortByColumn(++sortedCol, Qt::AscendingOrder);
            break;
        case 3:
            sortedCol = 0;
            ui->contactTableView->sortByColumn(sortedCol, Qt::AscendingOrder);
            break;
    }
}
