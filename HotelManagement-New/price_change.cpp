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

//修改房价
void price_change::on_pushButton_clicked()
{
    //获得房间类型和房间新单价
    room_kind=ui->comboBox->currentText();
    r_price=ui->pricelineEdit->text();
    //将滚动条的中文转换为相应的房间类型代表字符，用于下面更新房间的单价
    QString rk;
    if(room_kind==tr("单人间"))
        rk='A';
    else if(room_kind==tr("双人间"))
        rk='B';
    else if(room_kind==tr("豪华间"))
        rk='C';
    else
        rk='D';
    query_3.exec("update room set room_price='"+r_price+"' where room_kind='"+rk+"' ");
    this->close();
}
//取消修改房价
void price_change::on_pushButton_2_clicked()
{
    this->close();
}
