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
//ͳ�ƹ���
void statistics::on_pushButton_3_clicked()
{
    int num=0;
    //�������ݿ�ķ�����õ���ס������������
    query_2.exec("select * from room where room_state=2");
    while(query_2.next())
    {
        if(query_2.value(3)==2)
            ++num;
    }
    //q��ʾ��ס��
    double q=(double)num/34;
    //��ʾ��ס������������ס��
    ui->roomnum->setText(QString::number(num));
    ui->roomp->setText(QString::number(q,'f',4));
    double total=0;
    //�������ݿ�ķ�����õ����з���������룬���Ƶ�������
    query_2.exec("select * from historyspends");
    while(query_2.next())
        total = total + query_2.value(7).toDouble();
    ui->allcharge->setText(QString::number(total));
}

void statistics::on_ok_button_clicked()
{
    this->close();
}
//������Ų�ѯ
void statistics::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString num;
    QString kind,name,year,month,day;
    int price,state;
    //��ȡҪ��ѯ�ķ����
    num=ui->comboBox->currentText();
    //��ѯ���ݿ⣬�õ��÷�������ͣ����ۣ�״̬��Ϣ
    query_2.exec("select * from room where room_num = '"+num+"'");
    while(query_2.next())
    {
        kind=query_2.value(1).toString();
        price=query_2.value(2).toInt();
        state=query_2.value(3).toInt();
    }
    //����Ӧ��Ϣ��ʾ����Ӧ�ı�ǩ��
    ui->room_information->setText(num);
    ui->room_information->insertPlainText(tr("����ţ�"));//��ǰ�����
    ui->room_information->append(tr("�������ͣ�"));//����һ�����
    ui->room_information->moveCursor(QTextCursor::End);//������ƶ����ı����
    if(kind==tr("A"))
    {
        ui->room_information->insertPlainText(tr("���˼�"));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("      ���ۣ�"));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(QString::number(price));
    }
    else if(kind==tr("B"))
    {
        ui->room_information->insertPlainText(tr("˫�˼�"));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("      ���ۣ�"));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(QString::number(price));
    }
    else if(kind==tr("C"))
    {
        ui->room_information->insertPlainText(tr("������"));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("      ���ۣ�"));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(QString::number(price));
    }
    else
    {
        ui->room_information->insertPlainText(tr("�����׷�"));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("      ���ۣ�"));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(QString::number(price));
    }
    //���ݷ���״̬����ʾ��Ӧ����Ϣ
    //0��ʾ������ס
    if(state==0)
        ui->room_information->append(tr("����״̬��������ס"));
    //1��ʾ���䱻Ԥ��
    else if(state==1)
    {
        ui->room_information->append(tr("����״̬:��Ԥ��"));
        query_2.exec("select * from customer where room_num = '"+num+"'");
        while(query_2.next())
        {
            name=query_2.value(0).toString();
            year=query_2.value(8).toString();
            month=query_2.value(9).toString();
            day=query_2.value(10).toString();
        }
        ui->room_information->append(tr("�ͻ���Ϣ��"));
        ui->room_information->append(tr("       ������"));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(name);
        ui->room_information->append(tr("       ��סʱ�䣺"));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(year);
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("  ��  "));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(month);
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("  ��  "));
        ui->room_information->insertPlainText(day);
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("  ��  "));
    }
    //2��ʾ������ס��
    else
    {
        ui->room_information->append(tr("����״̬:��ס��"));
        query_2.exec("select * from customer where room_num = '"+num+"'");
        while(query_2.next())
        {
            name=query_2.value(0).toString();
            year=query_2.value(8).toString();
            month=query_2.value(9).toString();
            day=query_2.value(10).toString();
        }
        ui->room_information->append(tr("�ͻ���Ϣ��"));
        ui->room_information->append(tr("       ������"));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(name);
        ui->room_information->append(tr("       ��סʱ�䣺"));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(year);
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("  ��  "));
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(month);
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("  ��  "));
        ui->room_information->insertPlainText(day);
        ui->room_information->moveCursor(QTextCursor::End);
        ui->room_information->insertPlainText(tr("  ��  "));

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
//��������ѯ
void statistics::on_pushButton_4_clicked()
{
    //���Ҫ��ѯ���û�����
    QString name=ui->namelineEdit->text();
    QString num;
    QString year,month,day;
    //�������ݿ�Ŀͻ���Ϣ�����Ҹ��û���Ϣ
    query_2.exec("select * from customer where name = '"+name+"'");
    while(query_2.next())
    {
        num=query_2.value(7).toString();
        year=query_2.value(8).toString();
        month=query_2.value(9).toString();
        day=query_2.value(10).toString();
    }
    //�ҵ����û�����Ϣ������ʾ����Ӧ�ı�ǩ��
    if(num!=NULL)
    {
        ui->roomLabel->setText(num);
        ui->year->setText(year);
        ui->month->setText(month);
        ui->day->setText(day);
    }
    //���Ƶ�û�и��û�������ʾ�û���������
    else
    {
        QMessageBox::warning(NULL,tr("����"),tr("�Ƶ��޸��û���ס������������"));
        ui->namelineEdit->clear();
    }
}
