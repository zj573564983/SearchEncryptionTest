#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <Qtsql/QSqlDatabase>
#include <Qtsql/QSqlQuery>
#include <QtSql/QSql>
#include <QDebug>
Dialog::Dialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);
	this->setWindowTitle("登录界面");
}

Dialog::~Dialog()
{
	delete ui;
}
void Dialog::on_pushButton_clicked()
{
	QString flag = ui->comboBox->currentText();
	QString s = ui->user->text();
	QString p = ui->password->text();
	bool result = false;
	//验证用户是否在mysql数据库中
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setDatabaseName("searchencrypt");
	db.setUserName("root");
	db.setPassword("123456");
	if (db.open())
	{
		QSqlQuery query;
		QString tmp;
		if (flag == QString::fromStdString("用户")) {
			//QMessageBox::information(this, QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("user"));
			tmp = "select * from user where id=" + s + " limit 1";
		}
		else if (flag == QString::fromStdString("发送方")) {
			tmp = "select * from sender where id='" + s + "' limit 1";
			//QMessageBox::information(this, QString::fromLocal8Bit("警告"),tmp);
		}
		else if(flag == QString::fromStdString("管理")) {
			tmp = "select * from manager where id='" + s + "' limit 1";
		}

		query.exec(tmp);
		while (query.next())
		{
			QString id = query.value(0).toString();
			QString str = query.value(1).toString();
			if (str == p) result = true;
		}
		db.close();
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("Error"), QString::fromLocal8Bit("Can not link mysql!"));
	}

	if (result == true && flag == QString::fromStdString("用户")) {
		//QMessageBox::information(this,QString::fromLocal8Bit("Succeed"),QString::fromLocal8Bit("Succeed"));
		mainwindow = new MainWindow();
		mainwindow->receiveData(s);
		mainwindow->show();
	}
	else if (result == true && flag == QString::fromStdString("发送方")) {
		sender = new Sender();
		sender->show();
	}
	else if (result == true && flag == QString::fromStdString("管理")) {
		manager = new Manager();
		manager->show();
	}
	else {
		QMessageBox::information(this, QString::fromLocal8Bit("Error"), QString::fromLocal8Bit("Username or Password is incorrect"));
	}
}
