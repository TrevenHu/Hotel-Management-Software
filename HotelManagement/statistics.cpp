#include "statistics.h"
#include "ui_statistics.h"
#include "mainwindow.h"
#include "mydatabase.h"
#include <QMessageBox>
#include <QTime>
#include <QTextCursor>
statistics::statistics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::statistics)
{
    ui->setupUi(this);
}

statistics::~statistics()
{
    delete ui;
}
//统计功能
void statistics::on_pushButton_3_clicked()
{
    int num=0;
    //遍历数据库的房间表，得到入住房间数量总数
    query_2.exec("select * from room where room_state=2");
    while(query_2.next())
    {
        if(query_2.value(3)==2)
            ++num;
    }
    //q表示入住率
    double q=(double)num/34;
    //显示入住房间数量和入住率
    ui->roomnum->setText(QString::number(num));
    ui->roomp->setText(QString::number(q,'f',4));
    double total=0;
    //遍历数据库的房间表，得到所有房间的总收入，即酒店总收入
    query_2.exec("select * from historyspends");
    while(query_2.next())
        total = total + query_2.value(7).toDouble();
    ui->allcharge->setText(QString::number(total));
}

void statistics::on_ok_button_clicked()
{
    this->close();
}
//按房间号查询
void statistics::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString num;
    QString kind,name,year,month,day;
    int price,state;
    //获取要查询的房间号
    num=ui->comboBox->currentText();
    //查询数据库，得到该房间的类型，单价，状态信息
    query_2.exec("select * from room where room_num = '"+num+"'");
    while(query_2.next())
    {
        kind=query_2.value(1).toString();
        price=query_2.value(2).toInt();
        state=query_2.value(3).toInt();
    }
    //将相应信息显示在相应的标签中
    ui->room_information->setText(num);
    ui->room_information->insertPlainText(tr("房间号："));//在前面插入
    ui->room_information->append(tr("房间类型："));//在另一行添加
    ui->room_information->moveCursor(QTextCursor::End);//将光标移动到文本最后
    if(kind==tr("A"))
    {
        ui->room_information->insertPlainText(tr("单人间"));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("      房价："));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(QString::number(price));
    }
    else if(kind==tr("B"))
    {
        ui->room_information->insertPlainText(tr("双人间"));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("      房价："));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(QString::number(price));
    }
    else if(kind==tr("C"))
    {
        ui->room_information->insertPlainText(tr("豪华间"));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("      房价："));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(QString::number(price));
    }
    else
    {
        ui->room_information->insertPlainText(tr("豪华套房"));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("      房价："));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(QString::number(price));
    }
    //根据房间状态，显示相应的信息
    //0表示无人入住
    if(state==0)
        ui->room_information->append(tr("房间状态：无人入住"));
    //1表示房间被预订
    else if(state==1)
    {
        ui->room_information->append(tr("房间状态:被预定"));
        query_2.exec("select * from customer where room_num = '"+num+"'");
        while(query_2.next())
        {
            name=query_2.value(0).toString();
            year=query_2.value(8).toString();
            month=query_2.value(9).toString();
            day=query_2.value(10).toString();
        }
        ui->room_information->append(tr("客户信息："));
        ui->room_information->append(tr("       姓名："));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(name);
        ui->room_information->append(tr("       入住时间："));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(year);
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("  年  "));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(month);
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("  月  "));
        ui->room_information->insertPlainText(day);
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("  日  "));
    }
    //2表示房间已住人
    else
    {
        ui->room_information->append(tr("房间状态:已住人"));
        query_2.exec("select * from customer where room_num = '"+num+"'");
        while(query_2.next())
        {
            name=query_2.value(0).toString();
            year=query_2.value(8).toString();
            month=query_2.value(9).toString();
            day=query_2.value(10).toString();
        }
        ui->room_information->append(tr("客户信息："));
        ui->room_information->append(tr("       姓名："));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(name);
        ui->room_information->append(tr("       入住时间："));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(year);
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("  年  "));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(month);
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("  月  "));
        ui->room_information->insertPlainText(day);
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("  日  "));

    }

}

void statistics::on_pushButton_clicked()
{
    this->close();
}

void statistics::on_pushButton_2_clicked()
{
    this->close();
}
//按姓名查询
void statistics::on_pushButton_4_clicked()
{
    //获得要查询的用户姓名
    QString name=ui->namelineEdit->text();
    QString num;
    QString year,month,day;
    //遍历数据库的客户信息表，查找该用户信息
    query_2.exec("select * from customer where name = '"+name+"'");
    while(query_2.next())
    {
        num=query_2.value(7).toString();
        year=query_2.value(8).toString();
        month=query_2.value(9).toString();
        day=query_2.value(10).toString();
    }
    //找到该用户的信息，则显示到相应的标签中
    if(num!=NULL)
    {
        ui->roomLabel->setText(num);
        ui->year->setText(year);
        ui->month->setText(month);
        ui->day->setText(day);
    }
    //本酒店没有该用户，则提示用户重新输入
    else
    {
        QMessageBox::warning(NULL,tr("警告"),tr("酒店无该用户入住，请重新输入"));
        ui->namelineEdit->clear();
    }
}
