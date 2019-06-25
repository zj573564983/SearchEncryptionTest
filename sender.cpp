#include "sender.h"
#include "ui_sender.h"
#include <Qtsql/QSqlDatabase>
#include <Qtsql/QSqlQuery>
#include <QtSql/QSql>
#include <QDebug>

Sender::Sender(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sender)
{
    ui->setupUi(this);
	this->setWindowTitle("sender");
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("searchencrypt");
    db.setUserName("root");
    db.setPassword("123456");
    if(db.open())
    {
        QSqlQuery query;
        QString tmp="select keyword from keyword";

        query.exec(tmp);
        while(query.next())
        {
            ui->keyWord->addItem(query.value(0).toString());
        }
        db.close();
    }
    else
    {
        QMessageBox::information(this,QString::fromLocal8Bit("Error"),QString::fromLocal8Bit("Can not link mysql!"));
    }

}

Sender::~Sender()
{
    delete ui;
}

void Sender::on_uploadButton_clicked()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setDatabaseName("searchencrypt");
	db.setUserName("root");
	db.setPassword("123456");
	if (db.open())
	{
		QSqlQuery query;
		QString tmp = "select * from data limit 1";

		query.exec(tmp);
		QString g, a, u1, u2;
		while (query.next())
		{
			g = query.value(0).toString();
			a = query.value(1).toString();
			u1 = query.value(2).toString();
			u2 = query.value(3).toString();
		}
		QString keyword = ui->keyWord->currentText();
		//QMessageBox::information(this, QString::fromLocal8Bit("test"), keyword);
		C_TOTAL result=encrypt(g.toStdString(),a.toStdString(),u1.toStdString(),u2.toStdString(),keyword.toStdString());
		QSqlQuery query1;
		string pwd = ui->keyWordText->toPlainText().toStdString();
		int m = stoi(pwd);
		int d, n, t, c, r;
		int m_t = 0;
		int m_i=0;
		int m_j;
		int p = 109;
		int q = 113;
		int e = 13;
		int ciphertext[100];             //存放密文的数组
		int proclaimedtext[100];         //存放明文的数组
		n = p * q;
		t = (p - 1)*(q - 1);                              //求n的欧拉数
		d = 1;
		while (((e * d) % t) != 1)
		{
			d++;                  //由公钥e求出私钥d
		}
		while (m / 100)
		{
			m_t = m % 100;
			ciphertext[m_i] = m_t;
			proclaimedtext[m_i] = candp(m_t, e, n);
			m /= 100;
			m_i++;
		}
		ciphertext[m_i] = m;
		proclaimedtext[m_i] = candp(m, e, n);
		string res = "";
		for (int i = 0; i <= m_i; i++)
		{
			res +=  to_string(proclaimedtext[i])+" ";
		}
		

		QString tmp1 = QString::fromStdString("insert into files values('" + result.C1 + "','" + result.C2 + "','" + result.C3 + "','" + res + "')");
		bool re=query1.exec(tmp1);
		if (re == true) {
			QMessageBox::information(this, QString::fromLocal8Bit("Succeed"), QString::fromLocal8Bit("Succeed"));
		}
		else {
			QMessageBox::information(this, QString::fromLocal8Bit("Failed"), QString::fromLocal8Bit("Failed"));
		}
		db.close();
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("Error"), QString::fromLocal8Bit("Can not link mysql!"));
	}
}

void Sender::on_cancelButton_clicked()
{
	
}
