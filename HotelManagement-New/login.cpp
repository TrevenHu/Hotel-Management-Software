#include "login.h"
#include "ui_login.h"
#include "mydatabase.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QTextCodec>//支持中文
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());//可以使用中文
    //打开数据库
    mydatabase  db;
    if(db.opendb("data.db"))
    {
        //创建数据库表
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
    // 判断用户名和密码是否正确，如果错误则弹出警告对话框
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
       QMessageBox::warning(this, tr("警告"),
                             tr("用户名或密码错误!"),
                             QMessageBox::Yes);
       // 清空内容并定位光标
       ui->usrLineEdit->clear();
       ui->pwdLineEdit->clear();
       ui->usrLineEdit->setFocus();
    }
}

void Login::on_logout_clicked()
{
    this->close();
}
