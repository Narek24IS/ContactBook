#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QByteArray>
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
    EditDialog(QList<QString> data, QByteArray imageBytes, QWidget *parent = nullptr);
    ~EditDialog();

    QString getContactName();
    QString getContactNumber();
    QString getContactType();
    QPixmap getImagePixmap();

signals:
    void saveData(const QList<QString> &data, QByteArray imageData);

private slots:
    void on_saveButton_clicked();

    void on_closeButton_clicked();

    void on_contactTypeBox_currentIndexChanged(int index);

    void on_getFileButton_clicked();

private:
    Ui::EditDialog *ui;
    QString imagePath;
    QPixmap imagePixmap;
    QByteArray imageData;
    int id = 0;
};

#endif // EDITDIALOG_H
