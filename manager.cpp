#include "manager.h"
#include "ui_manager.h"
#include <Qtsql/QSqlDatabase>
#include <Qtsql/QSqlQuery>
#include <QtSql/QSql>

Manager::Manager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Manager)
{
    ui->setupUi(this);
	this->setWindowTitle("Manager");
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setDatabaseName("searchencrypt");
	db.setUserName("root");
	db.setPassword("123456");
	if (db.open())
	{
		QSqlQuery query;
		QString tmp;
		tmp = QString::fromStdString("select * from keyword");
		query.exec(tmp);
		QButtonGroup *buttonGroup = new QButtonGroup(this);
		buttonGroup->addButton(ui->checkBox, 1);
		buttonGroup->addButton(ui->checkBox_2, 2);
		buttonGroup->addButton(ui->checkBox_3, 3);
		buttonGroup->setExclusive(false);

		tmp = QString::fromStdString("select id from user");
		query.exec(tmp);
		while (query.next()) {
			ui->userBox->addItem(query.value(0).toString());
		}
		db.close();
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("Error"), QString::fromLocal8Bit("Can not link mysql!"));
	}
}

Manager::~Manager()
{
    delete ui;
}

void Manager::on_authButton_clicked()
{
	if (ui->checkBox->isChecked() == false && ui->checkBox_2->isChecked() == false && ui->checkBox_3->isChecked() == false) {
		QMessageBox::information(this, QString::fromLocal8Bit("Error"), QString::fromLocal8Bit("没有选择关键字"));
	}
	else {
		QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
		db.setHostName("localhost");
		db.setDatabaseName("searchencrypt");
		db.setUserName("root");
		db.setPassword("123456");
		bool result = false;
		if (ui->checkBox->isChecked() == true) {
			QString id = "1";
			QString user = ui->userBox->currentText();
			if (db.open())
			{
				QSqlQuery query;
				QString tmp;
				tmp = QString::fromStdString("insert into user_keyword values("+ user.toStdString() +"," + id.toStdString() +")");
				result=query.exec(tmp);
				if (result == false) {
					QMessageBox::information(this, QString::fromLocal8Bit("Error"), QString::fromLocal8Bit("Insert failed!"));
				}
				db.close();
			}
			else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("Error"), QString::fromLocal8Bit("Can not link mysql!"));
			}
		}
		if (ui->checkBox_2->isChecked() == true) {
			QString id = "2";
			QString user = ui->userBox->currentText();
			if (db.open())
			{
				QSqlQuery query;
				QString tmp;
				tmp = QString::fromStdString("insert into user_keyword values(" + user.toStdString() + "," + id.toStdString() + ")");
				result = query.exec(tmp);
				if (result == false) {
					QMessageBox::information(this, QString::fromLocal8Bit("Error"), QString::fromLocal8Bit("Insert failed!"));
				}
				db.close();
			}
			else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("Error"), QString::fromLocal8Bit("Can not link mysql!"));
			}
		}
		if (ui->checkBox_3->isChecked() == true) {
			QString id = "3";
			QString user = ui->userBox->currentText();
			if (db.open())
			{
				QSqlQuery query;
				QString tmp;
				tmp = QString::fromStdString("insert into user_keyword values(" + user.toStdString() + "," + id.toStdString() + ")");
				result = query.exec(tmp);
				if (result == false) {
					QMessageBox::information(this, QString::fromLocal8Bit("Error"), QString::fromLocal8Bit("Insert failed!"));
				}
			}
			else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("Error"), QString::fromLocal8Bit("Can not link mysql!"));
			}
		}
		if (result == true) {
			QMessageBox::information(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("授权成功"));
		}
		db.close();
	}
}
