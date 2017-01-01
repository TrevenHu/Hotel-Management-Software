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

//用户信息登录确认
void user_information::on_pushButton_clicked()
{
    //获得文本框中的用户信息
    name=ui->namelineEdit->text();
    sex=ui->comboBox->currentText();
    cId=ui->idlineEdit->text();
    age=ui->agelineEdit->text();
    phone=ui->phonelineEdit->text();
    city=ui->citylineEdit->text();
    address=ui->lineEdit->text();
    if(name==NULL || sex==NULL || cId==NULL || age==NULL || phone==NULL || city==NULL || address==NULL)
    {
        ui->namelineEdit->clear();
        ui->idlineEdit->clear();
        ui->agelineEdit->clear();
        ui->phonelineEdit->clear();
        ui->citylineEdit->clear();
        ui->lineEdit->clear();
        QMessageBox::warning(this,tr("顾客信息错误"),tr("请核对后重新输入"),tr("是"),tr("否"));
    }

    else
    {
            //获得此时的时钟
            query_4.exec("select * from time");
            while(query_4.next())
            {
                year=query_4.value(0).toString();
                month=query_4.value(1).toString();
                day=query_4.value(2).toString();
            }
            //获得房间号
            rn=QString::number(r_num/10);
            //判断非空并且id不重复
            query_4.exec("select * from customer");
            while(query_4.next())
            {
                if(query_4.value(2).toString()==cId)//query_4.value(2)是id的值
                {

                    if( QMessageBox::warning(this,tr("顾客信息错误"),tr("请核对后重新输入"),tr("是"),tr("否")))
                    {
                        this->close();
                    }
                    break;
                }
            }
            //将用户信息插入到数据库中的客户信息表中
            query_4.exec("insert into customer values('"+name+"','"+sex+"','"+cId+"','"+age+"','"+phone+"','"+city+"','"+address+"','"+rn+"','"+year+"','"+month+"','"+day+"',0,0,0)");
            //更改房间状态
            if(r_num%10==2)
                query_4.exec("update room set room_state=2 where room_num= '"+rn+"'");
            else
                query_4.exec("update room set room_state=1 where room_num= '"+rn+"'");

            this->close();
    }


}

//取消用户登录
void user_information::on_pushButton_2_clicked()
{
    this->close();
}
