#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "room_management.h"
#include "statistics.h"
#include "price_change.h"
#include <QTimer>
int b;//全局变量
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    onTimerOut();//定时刷新函数
    timer = new QTimer();
    //设置定时器每隔10s发送一个timeout()信号
    timer->setInterval(10000);
    //启动定时器
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));


}
void MainWindow::onTimerOut()
{
    //开启程序时，从数据库的时间表中获取时间并显示到界面中
    if(b==0)
    {
        query_6.exec("select * from time");
        while(query_6.next())
        {
            year=query_6.value(0).toInt();
            month=query_6.value(1).toInt();
            da=query_6.value(2).toInt();
            hour=query_6.value(3).toInt();
            minute=query_6.value(4).toInt();
        }
        b=1;
        ui->yearlabel->setText(QString::number(year));
        ui->monthlabel->setText(QString::number(month));
        ui->daylabel->setText(QString::number(da));
        ui->hourlabel->setText(QString::number(hour));
        ui->minutelabel->setText(QString::number(minute));
    }
    //开启程序后，每隔10m推进20分钟，并显示到界面中
    minute=minute+20;
    if(minute>=60)
    {
        hour += 1;
        minute=minute%60;
        if(hour>=24)
        {
            da += 1;
            //获得每种类型房的单价
            double pA,pB,pC,pD;
            query_6.exec("select * from room where room_num=101");
            while(query_6.next())
                pA=query_6.value(2).toDouble();
            query_6.exec("select * from room where room_num=201");
            while(query_6.next())
                pB=query_6.value(2).toDouble();
            query_6.exec("select * from room where room_num=301");
            while(query_6.next())
                pC=query_6.value(2).toDouble();
            query_6.exec("select * from room where room_num=401");
            while(query_6.next())
                pD=query_6.value(2).toDouble();
            //更新客户信息表中的房价，使其加一个类型房的单价
            query_6.prepare("update customer set room_price=room_price+? where room_num/100=1");
            query_6.addBindValue(pA);
            query_6.exec();
            query_6.prepare("update customer set room_price=room_price+? where room_num/100=2");
            query_6.addBindValue(pB);
            query_6.exec();
            query_6.prepare("update customer set room_price=room_price+? where room_num/100=3");
            query_6.addBindValue(pC);
            query_6.exec();
            query_6.prepare("update customer set room_price=room_price+? where room_num/100=4");
            query_6.addBindValue(pD);
            query_6.exec();
            //更新客户信息表中的入住天数，使其加一
            query_6.exec("update customer set times=times+1");

            hour=hour%24;
            ui->daylabel->setText(QString::number(da));
            if(da>=30)
            {
                month += 1;
                da=da%30;
                ui->monthlabel->setText(QString::number(month));
            }
        }
        ui->hourlabel->setText(QString::number(hour));
    }
    ui->minutelabel->setText(QString::number(minute));
    //更新数据库的时间表
    y=QString::number(year);
    m=QString::number(month);
    d=QString::number(da);
    h=QString::number(hour);
    t=QString::number(minute);
    query_6.exec("update time set year='"+y+"',month='"+m+"',day='"+d+"',hour='"+h+"',minute='"+t+"'");
}

MainWindow::~MainWindow()
{
    delete ui;
}
//统计查询界面显示
void MainWindow::on_statistic_clicked()
{
    statistics *p =new statistics;
    p->show();
}
//修改房价界面显示
void MainWindow::on_price_change_clicked()
{
    price_change *p =new price_change;
    p->show();
}
//房间管理界面显示
void MainWindow::on_pushButton_clicked()
{
    room_management *p =new room_management;
    p->show();
}
//退出程序时，将此刻的时钟保存到数据库
void MainWindow::on_exit_clicked()
{
    year=ui->yearlabel->text().toInt();
    month=ui->monthlabel->text().toInt();
    da=ui->daylabel->text().toInt();
    hour=ui->hourlabel->text().toInt();
    minute=ui->minutelabel->text().toInt();
    query_6.exec("update time set year=year,month=month,day=day,hour=hour,minute=minute");
    this->close();
}
