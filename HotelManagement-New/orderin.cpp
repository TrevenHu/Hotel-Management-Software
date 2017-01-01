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
//ȡ�������֤
void orderin::on_pushButton_2_clicked()
{
    room_management *p= new room_management;
    p->show();
    this->close();
}
//Ԥ���û�����ס�����֤
void orderin::on_ok_clicked()
{
    //��ô˿̵�ʱ�ӣ����û������֤�ɹ�����Ϊ����סʱ��
    int y,m,da;
    query_7.exec("select * from time");
    while(query_7.next())
    {
        y=query_7.value(0).toInt();
        m=query_7.value(1).toInt();
        da=query_7.value(2).toInt();
    }
    //�����������֤��
    idNum=ui->idEdit->text();
    rn=QString::number(r_num/10);
    query_7.exec("select * from customer where room_num='"+rn+"'");
    while(query_7.next())
    {
        //��������֤����Ԥ���Ǽ�ʱ�����֤��һ�£���ȷ���û���ס��ˢ�·���״̬��ˢ�¸��û��ĵǼǱ�
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
        //�����֤������ʾ�û���������
        else
        {
            QMessageBox::warning(NULL,tr("����"),tr("���֤����Ч�����������룡"));
            ui->idEdit->clear();
        }
    }
}
