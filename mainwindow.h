#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
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
    void initNewEditDialog(QList<QString> data);
    void initNewAddDialog();

    void dbConnect();

private slots:
    void on_editButton_clicked();

    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_sortButton_clicked();

    void setDataFromEditDialog(const QList<QString> &data);
    void setDataFromAddDialog(const QList<QString> &data);

private:
    Ui::MainWindow *ui;
    EditDialog *edit;
    QSqlTableModel *model;
    QString styleStr;
    unsigned id = 0;
    int editRow;
    int sortedCol = 0;
};
#endif // MAINWINDOW_H
