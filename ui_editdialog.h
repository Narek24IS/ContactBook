/********************************************************************************
** Form generated from reading UI file 'editdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIALOG_H
#define UI_EDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *contactNameLabel;
    QLineEdit *contactNameEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *contactNumberLabel;
    QLineEdit *contactNumberEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *contactTypeLabel;
    QComboBox *contactTypeBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QPushButton *closeButton;

    void setupUi(QDialog *EditDialog)
    {
        if (EditDialog->objectName().isEmpty())
            EditDialog->setObjectName("EditDialog");
        EditDialog->resize(500, 280);
        EditDialog->setMinimumSize(QSize(500, 280));
        EditDialog->setMaximumSize(QSize(500, 280));
        EditDialog->setBaseSize(QSize(500, 280));
        EditDialog->setSizeGripEnabled(false);
        verticalLayout_4 = new QVBoxLayout(EditDialog);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName("verticalLayout");
        contactNameLabel = new QLabel(EditDialog);
        contactNameLabel->setObjectName("contactNameLabel");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(contactNameLabel->sizePolicy().hasHeightForWidth());
        contactNameLabel->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(contactNameLabel);

        contactNameEdit = new QLineEdit(EditDialog);
        contactNameEdit->setObjectName("contactNameEdit");
        contactNameEdit->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(contactNameEdit);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        contactNumberLabel = new QLabel(EditDialog);
        contactNumberLabel->setObjectName("contactNumberLabel");
        sizePolicy.setHeightForWidth(contactNumberLabel->sizePolicy().hasHeightForWidth());
        contactNumberLabel->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(contactNumberLabel);

        contactNumberEdit = new QLineEdit(EditDialog);
        contactNumberEdit->setObjectName("contactNumberEdit");
        contactNumberEdit->setMinimumSize(QSize(0, 30));

        verticalLayout_2->addWidget(contactNumberEdit);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        contactTypeLabel = new QLabel(EditDialog);
        contactTypeLabel->setObjectName("contactTypeLabel");

        verticalLayout_3->addWidget(contactTypeLabel);

        contactTypeBox = new QComboBox(EditDialog);
        contactTypeBox->addItem(QString());
        contactTypeBox->addItem(QString());
        contactTypeBox->addItem(QString());
        contactTypeBox->setObjectName("contactTypeBox");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(contactTypeBox->sizePolicy().hasHeightForWidth());
        contactTypeBox->setSizePolicy(sizePolicy1);
        contactTypeBox->setMinimumSize(QSize(150, 32));
        contactTypeBox->setBaseSize(QSize(0, 0));
        QFont font;
        font.setPointSize(11);
        contactTypeBox->setFont(font);

        verticalLayout_3->addWidget(contactTypeBox);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalSpacer = new QSpacerItem(287, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        saveButton = new QPushButton(EditDialog);
        saveButton->setObjectName("saveButton");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy2);
        saveButton->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(22);
        font1.setBold(false);
        font1.setItalic(false);
        saveButton->setFont(font1);
        saveButton->setStyleSheet(QString::fromUtf8("font: 22pt \"Segoe UI\";"));
        saveButton->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(saveButton);

        closeButton = new QPushButton(EditDialog);
        closeButton->setObjectName("closeButton");
        sizePolicy2.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy2);
        closeButton->setMinimumSize(QSize(0, 40));
        closeButton->setFont(font1);
        closeButton->setStyleSheet(QString::fromUtf8("font: 22pt \"Segoe UI\";"));
        closeButton->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(closeButton);


        verticalLayout_4->addLayout(horizontalLayout);


        retranslateUi(EditDialog);

        saveButton->setDefault(true);


        QMetaObject::connectSlotsByName(EditDialog);
    } // setupUi

    void retranslateUi(QDialog *EditDialog)
    {
        EditDialog->setWindowTitle(QCoreApplication::translate("EditDialog", "Dialog", nullptr));
        contactNameLabel->setText(QCoreApplication::translate("EditDialog", "\320\230\320\274\321\217 \320\272\320\276\320\275\321\202\320\260\320\272\321\202\320\260", nullptr));
        contactNumberLabel->setText(QCoreApplication::translate("EditDialog", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        contactTypeLabel->setText(QCoreApplication::translate("EditDialog", "\320\242\320\270\320\277", nullptr));
        contactTypeBox->setItemText(0, QCoreApplication::translate("EditDialog", "\320\234\320\276\320\261\320\270\320\273\321\214\320\275\321\213\320\271", nullptr));
        contactTypeBox->setItemText(1, QCoreApplication::translate("EditDialog", "\320\224\320\276\320\274\320\260\321\210\320\275\320\270\320\271", nullptr));
        contactTypeBox->setItemText(2, QCoreApplication::translate("EditDialog", "\320\255\320\272\321\201\321\202\321\200\320\265\320\275\320\275\321\213\320\265 \321\201\320\273\321\203\320\266\320\261\321\213", nullptr));

        saveButton->setText(QCoreApplication::translate("EditDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        closeButton->setText(QCoreApplication::translate("EditDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditDialog: public Ui_EditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIALOG_H
