#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include <QStandardItem>

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(QWidget *parent = nullptr);
    EditDialog(QList<QStandardItem *> data, QWidget *parent = nullptr);
    ~EditDialog();

    QString getContactName();
    QString getContactNumber();
    QString getContactType();

signals:
    void saveData(const QList<QStandardItem *> &data);

private slots:
    void on_saveButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::EditDialog *ui;
    inline static int id = 0;
};

#endif // EDITDIALOG_H
