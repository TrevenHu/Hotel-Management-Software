#include <QApplication>
#include "mainwindow.h"
#include "mydatabase.h"
#include "login.h"
#include <QTextCodec>//支持中文
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());//可以使用中文
    //打开数据库
    mydatabase  db;
    if(db.opendb("data.db"))
    {
        //创建数据库表
        db.createtable();
    }

    MainWindow w;
    w.show();
    return a.exec();
}
