#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"QMessageBox"
#include"sender.h"
#include"manager.h"
#include"mainwindow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    MainWindow *mainwindow;
    Sender *sender;
	Manager *manager;
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
