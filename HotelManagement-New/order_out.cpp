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
//ȷ���˷�
void order_out::on_yes_clicked()
{
    QString rn=QString::number(r_num/10);//�õ������
    //���·���״̬��ɾ�����ݿ��и��û��ļ�¼
    query.exec("update room set room_state=0 where room_num='"+rn+"'");
    query.exec("delete from customer where room_num='"+rn+"'");
    this->close();

}
//ȡ���˷�
void order_out::on_no_clicked()
{
    room_management *p= new room_management;
    p->show();
    this->close();
}
