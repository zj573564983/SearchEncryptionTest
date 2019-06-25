#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Qtsql/QSqlDatabase>
#include <Qtsql/QSqlQuery>
#include <QtSql/QSql>
SK_user sk_user;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->getPrivateKeyButton->setVisible(true);
    ui->getTokenButton->setVisible(false);
    ui->searchButton->setVisible(false);
    ui->selectBox->setVisible(false);
	ui->cipherEdit->setVisible(false);
	ui->staticText->setVisible(false);
	this->setWindowTitle("用户界面");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::receiveData(QString data)
{
    id=data;    //获取传递过来的数据
}
void MainWindow::on_getPrivateKeyButton_clicked()
{
	
    //PKG判断ID是否属于RL
	char *ID;
	QByteArray ba = id.toLatin1();
	ID= ba.data();
	setup();
	VAR result;
	result = var_back();
	//将数据存到后台数据库
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setDatabaseName("searchencrypt");
	db.setUserName("root");
	db.setPassword("123456");
	if (db.open())
	{
		QSqlQuery query;
		QString tmp;
		tmp = QString::fromStdString("insert into data values('"+result.g + "','" + result.A + "','" + result.u1 + "','" + result.u2 + "')");
		query.exec(tmp);
		db.close();
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("Error"), QString::fromLocal8Bit("Can not link mysql!"));
	}
	sk_user = keyGen(ID);
	int len = element_length_in_bytes(sk_user.IK1);
	char* sk1 = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(sk1, len * sizeof(char) * 4, sk_user.IK1);
	string result1=sk1;
	len = element_length_in_bytes(sk_user.IK2);
	char* sk2 = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(sk2, len * sizeof(char) * 4, sk_user.IK2);
	string result2 = sk2;
	len = element_length_in_bytes(sk_user.VK1);
	char* vk1 = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(vk1, len * sizeof(char) * 4, sk_user.VK1);
	string result3 = vk1;
	len = element_length_in_bytes(sk_user.VK2);
	char* vk2 = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(vk2, len * sizeof(char) * 4, sk_user.VK2);
	string result4 = vk2;
    QString tmp = QString::fromStdString("(("+result1+","+result2+")"+","+"("+result3+","+result4+"))");
    ui->privateKey->setText(tmp);
    
}
void MainWindow::on_getTokenButton_clicked()
{
	char *ID;
	QByteArray ba = id.toLatin1();
	ID = ba.data();
	TOKEN token = authorize(ID);
	int len = element_length_in_bytes(token.ak);
	char* token1 = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(token1, len * sizeof(char) * 4, token.ak);
	string result1 = token1;
	len = element_length_in_bytes(token.o);
	char* token2 = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(token2, len * sizeof(char) * 4, token.o);
	string result2 = token2;
	len = element_length_in_bytes(token.CID0);
	char* token3 = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(token3, len * sizeof(char) * 4, token.CID0);
	string result3 = token3;
	len = element_length_in_bytes(token.CID1);
	char* token4 = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(token4, len * sizeof(char) * 4, token.CID1);
	string result4 = token4;
	len = element_length_in_bytes(token.EID);
	char* token5 = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(token5, len * sizeof(char) * 4, token.EID);
	string result5 = token5;
	len = element_length_in_bytes(token.EVI);
	char* token6 = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(token6, len * sizeof(char) * 4, token.EVI);
	string result6 = token6;
	QString tmp = QString::fromStdString(result1+","+result2+","+"("+result3+","+result4+","+result5+","+result6+")");
	ui->privateKey->setText(tmp);
}

void MainWindow::on_searchButton_clicked()
{
	QString keyword = ui->selectBox->currentData().toString();
	trapdoor(sk_user);
	if (test1() == true) {
		RESULT re = test2();
		if (re.result == true) {
			//获取数据
			QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
			db.setHostName("localhost");
			db.setDatabaseName("searchencrypt");
			db.setUserName("root");
			db.setPassword("123456");
			if (db.open())
			{
				QSqlQuery query;
				QString tmp;
				tmp = QString::fromStdString( "select data from files where C1='"+re.C1+"' and C2='"+re.C2+"' and C3 ='"+re.C3+"' ");
				query.exec(tmp);
				while (query.next()) {
					string re=query.value(0).toString().toStdString();
					ui->cipherEdit->setText(QString::fromStdString(re));
					int d, m, n, t, c, r;
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
					stringstream input(re);
					string tmp;
					while (input >> tmp) {
						proclaimedtext[m_i++] = stoi(tmp);
					}
					m_j = 0;
					while (m_i--)
					{
						ciphertext[m_j] = candp(proclaimedtext[m_j], d, n);
						m_j++;
					}
					m_j--;
					string res = "";
					for (int i = m_j; i >= 0; i--)
					{
						res += to_string(ciphertext[i]);
					}
					ui->privateKey->setText(QString::fromStdString(res));
				}
				db.close();
			}
			else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("Error"), QString::fromLocal8Bit("Can not link mysql!"));
			}
		}
		else {
			ui->privateKey->setText("验证失败");
		}
	}
	else {
		ui->privateKey->setText("验证失败");
	}
	
}

void MainWindow::on_getPrivateKeyAction_triggered()
{
    ui->getPrivateKeyButton->setText("获取私钥");
    ui->privateKey->setText("私钥");
    ui->getPrivateKeyButton->setVisible(true);
    ui->getTokenButton->setVisible(false);
    ui->searchButton->setVisible(false);
    ui->selectBox->setVisible(false);
	ui->cipherEdit->setVisible(false);
	ui->staticText->setVisible(false);
}

void MainWindow::on_getTokenAction_triggered()
{
    ui->getPrivateKeyButton->setText("获取token");
    ui->privateKey->setText("token");
    ui->getPrivateKeyButton->setVisible(false);
    ui->getTokenButton->setVisible(true);
    ui->searchButton->setVisible(false);
    ui->selectBox->setVisible(false);
	ui->cipherEdit->setVisible(false);
	ui->staticText->setVisible(false);
}

void MainWindow::on_search_triggered()
{
    ui->getPrivateKeyButton->setText("搜索");
    ui->privateKey->setText("结果");
    ui->getPrivateKeyButton->setVisible(false);
    ui->getTokenButton->setVisible(false);
    ui->searchButton->setVisible(true);
    ui->selectBox->setVisible(true);
	ui->cipherEdit->setVisible(true);
	ui->staticText->setVisible(true);
	//获取数据
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setDatabaseName("searchencrypt");
	db.setUserName("root");
	db.setPassword("123456");
	if (db.open())
	{
		QSqlQuery query;
		QString tmp;
		tmp = "select k.keyword from keyword k join user_keyword uk on k.id=uk.keyword_id join user u on uk.user_id=u.id where u.id="+id;
		query.exec(tmp);
		while (query.next()) {
			ui->selectBox->addItem(query.value(0).toString());
		}
		db.close();
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("Error"), QString::fromLocal8Bit("Can not link mysql!"));
	}
}


