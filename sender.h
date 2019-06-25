#ifndef SENDER_H
#define SENDER_H

#include <QDialog>
#include"QMessageBox"
#include "mainwindow.h"

namespace Ui {
class Sender;
}

class Sender : public QDialog
{
    Q_OBJECT

public:
    explicit Sender(QWidget *parent = nullptr);
    ~Sender();

private slots:
    void on_uploadButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::Sender *ui;
};

#endif // SENDER_H
