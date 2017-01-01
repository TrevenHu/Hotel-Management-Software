#include "checkout.h"
#include "ui_checkout.h"
#include "mydatabase.h"
#include "room_management.h"
//退房相关操作
checkout::checkout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkout)
{

    ui->setupUi(this);

    rn=QString::number(r_num/10);//得到房间号
    //获得此房间的客户姓名、入住天数和总房间费用信息
    query_5.exec("select * from customer where room_num='"+rn+"'");
    while(query_5.next())
    {
        name=query_5.value(0).toString(); 
        ts=query_5.value(11).toDouble();
        r_p=query_5.value(12).toDouble();
    }
    //获得房间的单价
    double p;
    query_5.exec("select * from room where room_num='"+rn+"'");
    while(query_5.next())
        p=query_5.value(2).toDouble();
    //获得此刻的小时
    int h;
    query_5.exec("select * from time");
    while(query_5.next())
        h=query_5.value(3).toInt();
    //如果在12点以后18点以前退房，则按半天计算，即在原来入住天数的基础上加半天，相应房费也加半
    if(h>=12&&h<18)
    {
        ts=ts+0.5;
        r_p=r_p+p/2;
        query_5.prepare("update customer set times=? where room_num='"+rn+"'");
        query_5.addBindValue(ts);
        query_5.exec();
        query_5.prepare("update customer set room_price=? where room_num='"+rn+"'");
        query_5.addBindValue(r_p);
        query_5.exec();

    }
    //如果在18点以后退房，则按一天计算，入住天数加一，相应房费也加房间单价
    else if(h>=18)
    {
        ts=ts+1;
        r_p=r_p+p;
        query_5.prepare("update customer set times=? where room_num='"+rn+"'");
        query_5.addBindValue(ts);
        query_5.exec();
        query_5.prepare("update customer set room_price=? where room_num='"+rn+"'");
        query_5.addBindValue(r_p);
        query_5.exec();
    }
    //在界面上显示用户的姓名和房间消费信息
    ui->nameEdit->setText(name);
    ui->room_pEdit->setText(QString::number(r_p));
}

checkout::~checkout()
{
    delete ui;
}

//添加额外消费金额
void checkout::on_add_clicked()
{
    //获得此房间房间消费金额
    query_5.exec("select * from customer where room_num='"+rn+"'");
    while(query_5.next())
        r_p=query_5.value(12).toDouble();
    //获得添加的额外消费金额
    externcharge=ui->exterchargeEdit->text();
    //a变量存储该房间用户的总消费金额，更新数据库
    double a= externcharge.toDouble()+r_p;
    ui->allEdit->setText(QString::number(a));
    query_5.prepare("update customer set allcharge=? where room_num='"+rn+"'");
    query_5.addBindValue(a);
    query_5.exec();
}

//确认退房
void checkout::on_okButton_clicked()
{
    //从客户信息表中获取退房用户的相关信息
    query_5.exec("select * from customer where room_num='"+rn+"'");
    while(query_5.next())
    {
        name=query_5.value(0).toString();
        hid=query_5.value(2).toString();
        year=query_5.value(8).toString();
        month=query_5.value(9).toString();
        day=query_5.value(10).toString();
        ts=query_5.value(11).toDouble();
        allcharge=query_5.value(13).toDouble();
    }
    //将该用户的相关信息插入到历史客户信息表中
    query_5.prepare("insert into historyspends values(?,?,?,?,?,?,?,?)");
    query_5.addBindValue(name);
    query_5.addBindValue(rn);
    query_5.addBindValue(hid);
    query_5.addBindValue(year);
    query_5.addBindValue(month);
    query_5.addBindValue(day);
    query_5.addBindValue(ts);
    query_5.addBindValue(allcharge);
    query_5.exec();
    //更新房间状态为无人入住，并将客户信息表中此用户的信息删除
    query_5.exec("update room set room_state=0 where room_num='"+rn+"'"); 
    query_5.exec("delete from customer where room_num='"+rn+"'");
    this->close();
}

//取消退房
void checkout::on_cancellButton_clicked()
{
    //获得房间的单价
    double p;
    query_5.exec("select * from room where room_num='"+rn+"'");
    while(query_5.next())
        p=query_5.value(2).toDouble();
    //获得此刻的小时
    int h;
    query_5.exec("select * from time");
    while(query_5.next())
        h=query_5.value(3).toInt();
    //获取用户入住天数和房间消费金额
    query_5.exec("select * from customer where room_num='"+rn+"'");
    while(query_5.next())
    {
        ts=query_5.value(11).toDouble();
        r_p=query_5.value(12).toDouble();
    }
    if(ts>0)
    {
        //由于取消退房，所以相应的减掉在退房操作时加的数据
        if(h>=12&&h<18)
        {
            ts -= 0.5;
            r_p -= p/2;
            query_5.prepare("update customer set times=? where room_num='"+rn+"'");
            query_5.addBindValue(ts);
            query_5.exec();
            query_5.prepare("update customer set room_price=? where room_num='"+rn+"'");
            query_5.addBindValue(r_p);
            query_5.exec();

        }
        else if(h>=18)
        {
            ts -= 1;
            r_p -= p;

            query_5.prepare("update customer set times=? where room_num='"+rn+"'");
            query_5.addBindValue(ts);
            query_5.exec();
            query_5.prepare("update customer set room_price=? where room_num='"+rn+"'");
            query_5.addBindValue(r_p);
            query_5.exec();

        }
    }

    this->close();
}
