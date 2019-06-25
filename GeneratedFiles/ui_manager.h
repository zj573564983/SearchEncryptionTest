/********************************************************************************
** Form generated from reading UI file 'manager.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Manager
{
public:
    QComboBox *userBox;
    QPushButton *authButton;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QLabel *staticText1;
    QLabel *statiText2;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *Manager)
    {
        if (Manager->objectName().isEmpty())
            Manager->setObjectName(QStringLiteral("Manager"));
        Manager->resize(400, 300);
        userBox = new QComboBox(Manager);
        userBox->setObjectName(QStringLiteral("userBox"));
        userBox->setGeometry(QRect(60, 140, 231, 22));
        authButton = new QPushButton(Manager);
        authButton->setObjectName(QStringLiteral("authButton"));
        authButton->setGeometry(QRect(200, 220, 93, 28));
        checkBox = new QCheckBox(Manager);
        buttonGroup = new QButtonGroup(Manager);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(checkBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(60, 60, 91, 19));
        checkBox_2 = new QCheckBox(Manager);
        buttonGroup->addButton(checkBox_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(130, 60, 91, 19));
        checkBox_3 = new QCheckBox(Manager);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(210, 60, 91, 19));
        staticText1 = new QLabel(Manager);
        staticText1->setObjectName(QStringLiteral("staticText1"));
        staticText1->setGeometry(QRect(60, 30, 91, 16));
        statiText2 = new QLabel(Manager);
        statiText2->setObjectName(QStringLiteral("statiText2"));
        statiText2->setGeometry(QRect(60, 110, 72, 15));

        retranslateUi(Manager);

        QMetaObject::connectSlotsByName(Manager);
    } // setupUi

    void retranslateUi(QDialog *Manager)
    {
        Manager->setWindowTitle(QApplication::translate("Manager", "Dialog", nullptr));
        authButton->setText(QApplication::translate("Manager", "\346\216\210\346\235\203", nullptr));
        checkBox->setText(QApplication::translate("Manager", "apple", nullptr));
        checkBox_2->setText(QApplication::translate("Manager", "orangle", nullptr));
        checkBox_3->setText(QApplication::translate("Manager", "blue", nullptr));
        staticText1->setText(QApplication::translate("Manager", "\345\205\263\351\224\256\350\257\215\351\200\211\346\213\251\357\274\232", nullptr));
        statiText2->setText(QApplication::translate("Manager", "\347\224\250\346\210\267\351\200\211\346\213\251\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Manager: public Ui_Manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGER_H
