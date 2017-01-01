#include "orderin.h"
#include "ui_orderin.h"
#include "room_management.h"
#include <QMessageBox>
orderin::orderin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::orderin)
{
    ui->setupUi(this);
}

orderin::~orderin()
{
    delete ui;
}
//取消身份验证
void orderin::on_pushButton_2_clicked()
{
    room_management *p= new room_management;
    p->show();
    this->close();
}
//预订用户的入住身份验证
void orderin::on_ok_clicked()
{
    //获得此刻的时钟，若用户身份验证成功，作为其入住时间
    int y,m,da;
    query_7.exec("select * from time");
    while(query_7.next())
    {
        y=query_7.value(0).toInt();
        m=query_7.value(1).toInt();
        da=query_7.value(2).toInt();
    }
    //获得输入的身份证号
    idNum=ui->idEdit->text();
    rn=QString::number(r_num/10);
    query_7.exec("select * from customer where room_num='"+rn+"'");
    while(query_7.next())
    {
        //如果此身份证号与预定登记时的身份证号一致，则确认用户入住，刷新房间状态，刷新该用户的登记表
        if(query_7.value(2).toString()==idNum)
        {
            query_7.exec("update room set room_state=2 where room_num='"+rn+"'");
            query_7.exec("update customer set times=0 where room_num='"+rn+"'");
            query_7.exec("update customer set room_price=0 where room_num='"+rn+"'");
            query_7.exec("update customer set allcharge=0 where room_num='"+rn+"'");
            query_7.prepare("update customer set year=? where room_num='"+rn+"'");
            query_7.addBindValue(y);
            query_7.prepare("update customer set month=? where room_num='"+rn+"'");
            query_7.addBindValue(m);
            query_7.prepare("update customer set day=? where room_num='"+rn+"'");
            query_7.addBindValue(da);
            query_7.exec();
            this->close();
        }
        //身份验证错误，提示用户重新输入
        else
        {
            QMessageBox::warning(NULL,tr("警告"),tr("身份证号无效，请重新输入！"));
            ui->idEdit->clear();
        }
    }
}
