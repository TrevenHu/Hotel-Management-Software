#include "checkout.h"
#include "ui_checkout.h"
#include "mydatabase.h"
#include "room_management.h"
//�˷���ز���
checkout::checkout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkout)
{

    ui->setupUi(this);

    rn=QString::number(r_num/10);//�õ������
    //��ô˷���Ŀͻ���������ס�������ܷ��������Ϣ
    query_5.exec("select * from customer where room_num='"+rn+"'");
    while(query_5.next())
    {
        name=query_5.value(0).toString(); 
        ts=query_5.value(11).toDouble();
        r_p=query_5.value(12).toDouble();
    }
    //��÷���ĵ���
    double p;
    query_5.exec("select * from room where room_num='"+rn+"'");
    while(query_5.next())
        p=query_5.value(2).toDouble();
    //��ô˿̵�Сʱ
    int h;
    query_5.exec("select * from time");
    while(query_5.next())
        h=query_5.value(3).toInt();
    //�����12���Ժ�18����ǰ�˷����򰴰�����㣬����ԭ����ס�����Ļ����ϼӰ��죬��Ӧ����Ҳ�Ӱ�
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
    //�����18���Ժ��˷�����һ����㣬��ס������һ����Ӧ����Ҳ�ӷ��䵥��
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
    //�ڽ�������ʾ�û��������ͷ���������Ϣ
    ui->nameEdit->setText(name);
    ui->room_pEdit->setText(QString::number(r_p));
}

checkout::~checkout()
{
    delete ui;
}

//��Ӷ������ѽ��
void checkout::on_add_clicked()
{
    //��ô˷��䷿�����ѽ��
    query_5.exec("select * from customer where room_num='"+rn+"'");
    while(query_5.next())
        r_p=query_5.value(12).toDouble();
    //�����ӵĶ������ѽ��
    externcharge=ui->exterchargeEdit->text();
    //a�����洢�÷����û��������ѽ��������ݿ�
    double a= externcharge.toDouble()+r_p;
    ui->allEdit->setText(QString::number(a));
    query_5.prepare("update customer set allcharge=? where room_num='"+rn+"'");
    query_5.addBindValue(a);
    query_5.exec();
}

//ȷ���˷�
void checkout::on_okButton_clicked()
{
    //�ӿͻ���Ϣ���л�ȡ�˷��û��������Ϣ
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
    //�����û��������Ϣ���뵽��ʷ�ͻ���Ϣ����
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
    //���·���״̬Ϊ������ס�������ͻ���Ϣ���д��û�����Ϣɾ��
    query_5.exec("update room set room_state=0 where room_num='"+rn+"'"); 
    query_5.exec("delete from customer where room_num='"+rn+"'");
    this->close();
}

//ȡ���˷�
void checkout::on_cancellButton_clicked()
{
    //��÷���ĵ���
    double p;
    query_5.exec("select * from room where room_num='"+rn+"'");
    while(query_5.next())
        p=query_5.value(2).toDouble();
    //��ô˿̵�Сʱ
    int h;
    query_5.exec("select * from time");
    while(query_5.next())
        h=query_5.value(3).toInt();
    //��ȡ�û���ס�����ͷ������ѽ��
    query_5.exec("select * from customer where room_num='"+rn+"'");
    while(query_5.next())
    {
        ts=query_5.value(11).toDouble();
        r_p=query_5.value(12).toDouble();
    }
    if(ts>0)
    {
        //����ȡ���˷���������Ӧ�ļ������˷�����ʱ�ӵ�����
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
