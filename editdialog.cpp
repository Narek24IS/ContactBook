#include "editdialog.h"
#include "ui_editdialog.h"

EditDialog::EditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);
    ui->saveButton->setIcon(QIcon(":/resoruces/check.png"));
    ui->closeButton->setIcon(QIcon(":/resoruces/check.png"));
}

EditDialog::EditDialog(QList<QStandardItem *> data, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditDialog)
{
    ui->setupUi(this);
    ui->contactNameEdit->setText(data[1]->text());
    ui->contactNumberEdit->setText(data[2]->text());
    ui->contactTypeBox->setCurrentText(data[3]->text());

    ui->saveButton->setIcon(QIcon(":/resoruces/check.png"));
    ui->closeButton->setIcon(QIcon(":/resoruces/check.png"));
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
    QList<QStandardItem *> data;
    data.append(new QStandardItem());
    data.append(new QStandardItem(this->getContactName()));
    data.append(new QStandardItem(this->getContactNumber()));
    data.append(new QStandardItem(this->getContactType()));

    emit saveData(data);
    this->close();
}

void EditDialog::on_closeButton_clicked()
{
    this->close();
}
