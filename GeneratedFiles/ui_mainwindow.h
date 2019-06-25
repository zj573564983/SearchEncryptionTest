/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *getPrivateKeyAction;
    QAction *getTokenAction;
    QAction *search;
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *getPrivateKeyButton;
    QTextEdit *privateKey;
    QPushButton *getTokenButton;
    QPushButton *searchButton;
    QComboBox *selectBox;
    QTextEdit *cipherEdit;
    QLabel *staticText;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 354);
        getPrivateKeyAction = new QAction(MainWindow);
        getPrivateKeyAction->setObjectName(QStringLiteral("getPrivateKeyAction"));
        getTokenAction = new QAction(MainWindow);
        getTokenAction->setObjectName(QStringLiteral("getTokenAction"));
        search = new QAction(MainWindow);
        search->setObjectName(QStringLiteral("search"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 40, 72, 15));
        getPrivateKeyButton = new QPushButton(centralWidget);
        getPrivateKeyButton->setObjectName(QStringLiteral("getPrivateKeyButton"));
        getPrivateKeyButton->setGeometry(QRect(40, 20, 93, 28));
        privateKey = new QTextEdit(centralWidget);
        privateKey->setObjectName(QStringLiteral("privateKey"));
        privateKey->setGeometry(QRect(40, 90, 291, 81));
        getTokenButton = new QPushButton(centralWidget);
        getTokenButton->setObjectName(QStringLiteral("getTokenButton"));
        getTokenButton->setGeometry(QRect(40, 20, 93, 28));
        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(240, 60, 93, 31));
        selectBox = new QComboBox(centralWidget);
        selectBox->setObjectName(QStringLiteral("selectBox"));
        selectBox->setGeometry(QRect(40, 60, 181, 31));
        cipherEdit = new QTextEdit(centralWidget);
        cipherEdit->setObjectName(QStringLiteral("cipherEdit"));
        cipherEdit->setGeometry(QRect(40, 180, 291, 87));
        staticText = new QLabel(centralWidget);
        staticText->setObjectName(QStringLiteral("staticText"));
        staticText->setGeometry(QRect(40, 30, 111, 31));
        MainWindow->setCentralWidget(centralWidget);
        searchButton->raise();
        label->raise();
        getPrivateKeyButton->raise();
        privateKey->raise();
        getTokenButton->raise();
        selectBox->raise();
        cipherEdit->raise();
        staticText->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(getPrivateKeyAction);
        menu->addAction(getTokenAction);
        menu_2->addAction(search);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        getPrivateKeyAction->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\347\247\201\351\222\245", nullptr));
        getTokenAction->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226token", nullptr));
        search->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        label->setText(QString());
        getPrivateKeyButton->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\347\247\201\351\222\245", nullptr));
        privateKey->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\247\201\351\222\245</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        getTokenButton->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226token", nullptr));
        searchButton->setText(QApplication::translate("MainWindow", "search", nullptr));
        cipherEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\212\240\345\257\206\345\220\216\347\273\223\346\236\234</p></body></html>", nullptr));
        staticText->setText(QApplication::translate("MainWindow", "\345\205\263\351\224\256\350\257\215\351\200\211\346\213\251\357\274\232", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
