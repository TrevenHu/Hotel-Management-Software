#include "fangjianyizhuren.h"
#include "ui_fangjianyizhuren.h"

fangjianyizhuren::fangjianyizhuren(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fangjianyizhuren)
{
    ui->setupUi(this);
}

fangjianyizhuren::~fangjianyizhuren()
{
    delete ui;
}
