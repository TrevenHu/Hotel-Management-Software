#include "price_change.h"
#include "ui_price_change.h"
price_change::price_change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::price_change)
{
    ui->setupUi(this);
}

price_change::~price_change()
{
    delete ui;
}

//�޸ķ���
void price_change::on_pushButton_clicked()
{
    //��÷������ͺͷ����µ���
    room_kind=ui->comboBox->currentText();
    r_price=ui->pricelineEdit->text();
    //��������������ת��Ϊ��Ӧ�ķ������ʹ����ַ�������������·���ĵ���
    QString rk;
    if(room_kind==tr("���˼�"))
        rk='A';
    else if(room_kind==tr("˫�˼�"))
        rk='B';
    else if(room_kind==tr("������"))
        rk='C';
    else
        rk='D';
    query_3.exec("update room set room_price='"+r_price+"' where room_kind='"+rk+"' ");
    this->close();
}
//ȡ���޸ķ���
void price_change::on_pushButton_2_clicked()
{
    this->close();
}
