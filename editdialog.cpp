#include "editdialog.h"
#include "ui_editdialog.h"

EditDialog::EditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);
}

EditDialog::EditDialog(QList<QString> data, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditDialog)
{
    ui->setupUi(this);
    this->id = data[0].toInt();
    ui->contactNameEdit->setText(data[1]);
    ui->contactNumberEdit->setText(data[2]);
    ui->contactTypeBox->setCurrentText(data[3]);
}

EditDialog::~EditDialog()
{
    delete ui;
}

QString EditDialog::getContactName()
{
    return this->ui->contactNameEdit->text();
}

QString EditDialog::getContactNumber()
{
    return this->ui->contactNumberEdit->text();
}

QString EditDialog::getContactType()
{
    return this->ui->contactTypeBox->currentText();
}

void EditDialog::on_saveButton_clicked()
{
    QList<QString> data;
    data.append(QString::number(this->id));
    data.append(this->getContactName());
    data.append(this->getContactNumber());
    data.append(this->getContactType());

    emit saveData(data);
    this->close();
}

void EditDialog::on_closeButton_clicked()
{
    this->close();
}
