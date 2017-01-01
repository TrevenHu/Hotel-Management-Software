#include "login.h"
#include "ui_login.h"
#include "mydatabase.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QTextCodec>//֧������
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());//����ʹ������
    //�����ݿ�
    mydatabase  db;
    if(db.opendb("data.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    ui->pwdLineEdit->setEchoMode(QLineEdit::Password);
}

Login::~Login()
{
    delete ui;
}

void Login::on_login_clicked()
{
    // �ж��û����������Ƿ���ȷ����������򵯳�����Ի���
    QSqlQuery query;
    query.exec("select * from login");
    int flag=0;
    while(query.next())
    {
        if(ui->usrLineEdit->text().trimmed() == query.value(0).toString()
               && ui->pwdLineEdit->text() == query.value(1).toString())
        {
            flag=1;
            accept();
        }
    }
    if(flag==0)
    {
       QMessageBox::warning(this, tr("����"),
                             tr("�û������������!"),
                             QMessageBox::Yes);
       // ������ݲ���λ���
       ui->usrLineEdit->clear();
       ui->pwdLineEdit->clear();
       ui->usrLineEdit->setFocus();
    }
}

void Login::on_logout_clicked()
{
    this->close();
}
