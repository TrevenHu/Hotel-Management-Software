#include "user_information.h"
#include "ui_user_information.h"
#include "mainwindow.h"
#include "room_management.h"
#include "user_information.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QTime>
user_information::user_information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_information)
{
    ui->setupUi(this);

}

user_information::~user_information()
{
    delete ui;
}

//�û���Ϣ��¼ȷ��
void user_information::on_pushButton_clicked()
{
    //����ı����е��û���Ϣ
    name=ui->namelineEdit->text();
    sex=ui->comboBox->currentText();
    cId=ui->idlineEdit->text();
    age=ui->agelineEdit->text();
    phone=ui->phonelineEdit->text();
    city=ui->citylineEdit->text();
    address=ui->lineEdit->text();
    //��ô�ʱ��ʱ��
    query_4.exec("select * from time");
    while(query_4.next())
    {
        year=query_4.value(0).toString();
        month=query_4.value(1).toString();
        day=query_4.value(2).toString();
    }
    //��÷����
    rn=QString::number(r_num/10);
    //�жϷǿղ���id���ظ�
    query_4.exec("select * from customer");
    while(query_4.next())
    {
        if(query_4.value(2).toString()==cId)//query_4.value(2)��id��ֵ
        {

            if( QMessageBox::warning(this,tr("�˿���Ϣ����"),tr("��˶Ժ���������"),tr("��"),tr("��")))
            {
                this->close();
            }
            break;
        }
    }
    //���û���Ϣ���뵽���ݿ��еĿͻ���Ϣ����
    query_4.exec("insert into customer values('"+name+"','"+sex+"','"+cId+"','"+age+"','"+phone+"','"+city+"','"+address+"','"+rn+"','"+year+"','"+month+"','"+day+"',0,0,0)");
    //���ķ���״̬
    if(r_num%10==2)
        query_4.exec("update room set room_state=2 where room_num= '"+rn+"'");
    else
        query_4.exec("update room set room_state=1 where room_num= '"+rn+"'");

    this->close();
}

//ȡ���û���¼
void user_information::on_pushButton_2_clicked()
{
    this->close();
}
