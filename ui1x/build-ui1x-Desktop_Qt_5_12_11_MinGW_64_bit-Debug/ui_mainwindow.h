/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtonfirst;
    QPushButton *pushButtonworker;
    QLineEdit *lineEditfirst;
    QLineEdit *lineEditworker;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(807, 596);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButtonfirst = new QPushButton(centralwidget);
        pushButtonfirst->setObjectName(QString::fromUtf8("pushButtonfirst"));
        pushButtonfirst->setGeometry(QRect(500, 200, 141, 28));
        pushButtonworker = new QPushButton(centralwidget);
        pushButtonworker->setObjectName(QString::fromUtf8("pushButtonworker"));
        pushButtonworker->setGeometry(QRect(500, 310, 141, 28));
        lineEditfirst = new QLineEdit(centralwidget);
        lineEditfirst->setObjectName(QString::fromUtf8("lineEditfirst"));
        lineEditfirst->setGeometry(QRect(340, 160, 301, 21));
        lineEditworker = new QLineEdit(centralwidget);
        lineEditworker->setObjectName(QString::fromUtf8("lineEditworker"));
        lineEditworker->setGeometry(QRect(340, 270, 301, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 160, 91, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 270, 91, 20));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(350, 400, 93, 28));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(510, 400, 93, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 807, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonfirst->setText(QApplication::translate("MainWindow", "\344\273\216\346\226\207\344\273\266\345\244\271\344\270\255\351\200\211\346\213\251", nullptr));
        pushButtonworker->setText(QApplication::translate("MainWindow", "\344\273\216\346\226\207\344\273\266\345\244\271\344\270\255\351\200\211\346\213\251", nullptr));
        label->setText(QApplication::translate("MainWindow", "\350\256\242\345\215\225\345\217\221\350\265\267\344\275\215\347\275\256", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\345\267\245\344\272\272\344\275\215\347\275\256", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "\345\214\271\351\205\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
