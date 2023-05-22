#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include <QStandardItem>
#include <QString>

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(QWidget *parent = nullptr);
    EditDialog(QList<QString > data, QWidget *parent = nullptr);
    ~EditDialog();

    QString getContactName();
    QString getContactNumber();
    QString getContactType();

signals:
    void saveData(const QList<QString > &data);

private slots:
    void on_saveButton_clicked();

    void on_closeButton_clicked();

    void on_contactTypeBox_currentIndexChanged(int index);

private:
    Ui::EditDialog *ui;
    int id = 0;
};

#endif // EDITDIALOG_H
