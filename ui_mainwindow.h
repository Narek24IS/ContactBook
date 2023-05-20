/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *editButton;
    QPushButton *sortButton;
    QTableView *contactTableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(423, 332);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(875, 500));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resoruces/images/title_ico.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setMinimumSize(QSize(0, 32));

        horizontalLayout->addWidget(addButton);

        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName("removeButton");
        removeButton->setMinimumSize(QSize(0, 32));

        horizontalLayout->addWidget(removeButton);

        editButton = new QPushButton(centralwidget);
        editButton->setObjectName("editButton");
        editButton->setMinimumSize(QSize(0, 32));

        horizontalLayout->addWidget(editButton);

        sortButton = new QPushButton(centralwidget);
        sortButton->setObjectName("sortButton");
        sortButton->setMinimumSize(QSize(0, 32));

        horizontalLayout->addWidget(sortButton);


        verticalLayout->addLayout(horizontalLayout);

        contactTableView = new QTableView(centralwidget);
        contactTableView->setObjectName("contactTableView");
        QFont font;
        font.setPointSize(13);
        contactTableView->setFont(font);
        contactTableView->setStyleSheet(QString::fromUtf8(""));
        contactTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        contactTableView->setAlternatingRowColors(false);
        contactTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        contactTableView->setSortingEnabled(true);
        contactTableView->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        contactTableView->horizontalHeader()->setStretchLastSection(true);
        contactTableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(contactTableView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 423, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275\320\275\321\213\320\271 \321\201\320\277\321\200\320\260\320\262\320\276\321\207\320\275\320\270\320\272", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        editButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        sortButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
