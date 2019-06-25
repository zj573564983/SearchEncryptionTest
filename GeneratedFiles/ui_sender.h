/********************************************************************************
** Form generated from reading UI file 'sender.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDER_H
#define UI_SENDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Sender
{
public:
    QComboBox *keyWord;
    QTextEdit *keyWordText;
    QPushButton *uploadButton;
    QPushButton *cancelButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Sender)
    {
        if (Sender->objectName().isEmpty())
            Sender->setObjectName(QStringLiteral("Sender"));
        Sender->resize(400, 300);
        keyWord = new QComboBox(Sender);
        keyWord->setObjectName(QStringLiteral("keyWord"));
        keyWord->setGeometry(QRect(70, 40, 161, 22));
        keyWordText = new QTextEdit(Sender);
        keyWordText->setObjectName(QStringLiteral("keyWordText"));
        keyWordText->setGeometry(QRect(70, 80, 161, 131));
        uploadButton = new QPushButton(Sender);
        uploadButton->setObjectName(QStringLiteral("uploadButton"));
        uploadButton->setGeometry(QRect(70, 240, 93, 28));
        cancelButton = new QPushButton(Sender);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(190, 240, 93, 28));
        label = new QLabel(Sender);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 20, 91, 16));
        label_2 = new QLabel(Sender);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 80, 72, 15));

        retranslateUi(Sender);

        QMetaObject::connectSlotsByName(Sender);
    } // setupUi

    void retranslateUi(QDialog *Sender)
    {
        Sender->setWindowTitle(QApplication::translate("Sender", "Dialog", nullptr));
        uploadButton->setText(QApplication::translate("Sender", "\344\270\212\344\274\240", nullptr));
        cancelButton->setText(QApplication::translate("Sender", "\345\217\226\346\266\210", nullptr));
        label->setText(QApplication::translate("Sender", "\345\205\263\351\224\256\350\257\215\351\200\211\346\213\251\357\274\232", nullptr));
        label_2->setText(QApplication::translate("Sender", "\350\276\223\345\205\245\346\225\260\346\215\256\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sender: public Ui_Sender {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDER_H
