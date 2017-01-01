#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "room_management.h"
#include "statistics.h"
#include "price_change.h"
#include <QTimer>
int b;//ȫ�ֱ���
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    onTimerOut();//��ʱˢ�º���
    timer = new QTimer();
    //���ö�ʱ��ÿ��10s����һ��timeout()�ź�
    timer->setInterval(10000);
    //������ʱ��
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));


}
void MainWindow::onTimerOut()
{
    //��������ʱ�������ݿ��ʱ����л�ȡʱ�䲢��ʾ��������
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
    //���������ÿ��10m�ƽ�20���ӣ�����ʾ��������
    minute=minute+20;
    if(minute>=60)
    {
        hour += 1;
        minute=minute%60;
        if(hour>=24)
        {
            da += 1;
            //���ÿ�����ͷ��ĵ���
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
            //���¿ͻ���Ϣ���еķ��ۣ�ʹ���һ�����ͷ��ĵ���
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
            //���¿ͻ���Ϣ���е���ס������ʹ���һ
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
    //�������ݿ��ʱ���
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
//ͳ�Ʋ�ѯ������ʾ
void MainWindow::on_statistic_clicked()
{
    statistics *p =new statistics;
    p->show();
}
//�޸ķ��۽�����ʾ
void MainWindow::on_price_change_clicked()
{
    price_change *p =new price_change;
    p->show();
}
//������������ʾ
void MainWindow::on_pushButton_clicked()
{
    room_management *p =new room_management;
    p->show();
}
//�˳�����ʱ�����˿̵�ʱ�ӱ��浽���ݿ�
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
