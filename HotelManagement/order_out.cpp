#include "order_out.h"
#include "ui_order_out.h"
#include "mydatabase.h"
#include "room_management.h"
order_out::order_out(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::order_out)
{
    ui->setupUi(this);
}

order_out::~order_out()
{
    delete ui;
}
//确定退房
void order_out::on_yes_clicked()
{
    QString rn=QString::number(r_num/10);//得到房间号
    //更新房间状态，删除数据库中该用户的记录
    query.exec("update room set room_state=0 where room_num='"+rn+"'");
    query.exec("delete from customer where room_num='"+rn+"'");
    this->close();

}
//取消退房
void order_out::on_no_clicked()
{
    room_management *p= new room_management;
    p->show();
    this->close();
}
