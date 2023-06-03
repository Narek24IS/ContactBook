#include "editdialog.h"
#include <QBuffer>
#include <QFileDialog>
#include "ui_editdialog.h"

EditDialog::EditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);
    ui->contactNameEdit->setPlaceholderText("Введите имя контакта");
    ui->contactNumberEdit->setInputMask("+7(999)999-99-99");
}

EditDialog::EditDialog(QList<QString> data, QByteArray imageBytes, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditDialog)
{
    ui->setupUi(this);
    ui->contactNumberEdit->setInputMask("+7(999)999-99-99");
    ui->contactNameEdit->setPlaceholderText("Введите имя контакта");
    this->id = data[0].toInt();
    ui->contactNameEdit->setText(data[1]);
    ui->contactNumberEdit->setText(data[2]);
    ui->contactTypeBox->setCurrentText(data[3]);
    imageData = imageBytes;
    //    qDebug() << imageData;
    QImage image = QImage::fromData(imageData);
    imagePixmap = QPixmap::fromImage(image).scaled(QSize(100, 100));
    ui->imageLabel->setPixmap(imagePixmap);
    connect(ui->contactTypeBox,
            &QComboBox::currentIndexChanged,
            this,
            &EditDialog::on_contactTypeBox_currentIndexChanged);
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

QPixmap EditDialog::getImagePixmap()
{
    return imagePixmap;
}

void EditDialog::on_saveButton_clicked()
{
    QList<QString> data;
    data.append(QString::number(this->id));
    data.append(this->getContactName());
    data.append(this->getContactNumber());
    data.append(this->getContactType());
    //    qDebug() << imageData;
    emit saveData(data, imageData);
    this->close();
}

void EditDialog::on_closeButton_clicked()
{
    this->close();
}

void EditDialog::on_contactTypeBox_currentIndexChanged(int index)
{
    switch (index) {
        case 0:
            ui->contactNumberEdit->setInputMask("+7(999)999-99-99");
            ui->contactNumberEdit->clear();
            break;
        case 1:
            ui->contactNumberEdit->setInputMask("999-99-99");
            ui->contactNumberEdit->clear();
            break;
        case 2:
            ui->contactNumberEdit->setInputMask("999");
            ui->contactNumberEdit->clear();
            break;
        default:
            break;
    }
}

void EditDialog::on_getFileButton_clicked()
{
    imagePath = QFileDialog::getOpenFileName(this,
                                             tr("Выберите файл"),
                                             "",
                                             tr("Image Files (*.png *.jpg *.bmp)"));
    QImage image = QImage(imagePath);
    QBuffer buffer(&imageData);
    image = image.scaled(QSize(100, 100));
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "PNG");
    imagePixmap = QPixmap::fromImage(image).scaled(QSize(100, 100));
    ui->imageLabel->setPixmap(imagePixmap);
}
