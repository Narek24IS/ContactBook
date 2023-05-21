#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStandardItemModel>
#include <QTableView>
#include "editdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setGlobalStyle();
    void setIcons();
    void resizeToContent();

    void initTable();
    void initNewEditDialog(QList<QStandardItem *> data);
    void initNewAddDialog();

    void dbConnect();
    void refreshTable();

    void closeEvent(QCloseEvent *event);
    void saveDataToFile();
private slots:
    void on_editButton_clicked();

    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_sortButton_clicked();

    void setDataFromEditDialog(const QList<QStandardItem *> &data);
    void setDataFromAddDialog(const QList<QStandardItem *> &data);

private:
    Ui::MainWindow *ui;
    EditDialog *edit;
    QStandardItemModel *model;
    QString styleStr;
    unsigned curId;
    unsigned id = 0;
};
#endif // MAINWINDOW_H
