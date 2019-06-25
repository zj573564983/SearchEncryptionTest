#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "pbc_use.h"
#include"QMessageBox"
#include"RSA.h"
#include<sstream>


namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void receiveData(QString data);
    QString id;

private slots:
    void on_getPrivateKeyButton_clicked();

    void on_getPrivateKeyAction_triggered();

    void on_getTokenAction_triggered();

    void on_search_triggered();

    void on_getTokenButton_clicked();

    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
