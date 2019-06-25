#ifndef MANAGER_H
#define MANAGER_H

#include <QDialog>
#include"QMessageBox"

namespace Ui {
class Manager;
}

class Manager : public QDialog
{
    Q_OBJECT

public:
    explicit Manager(QWidget *parent = nullptr);
    ~Manager();

private slots:
    void on_authButton_clicked();

private:
    Ui::Manager *ui;
};

#endif // MANAGER_H
