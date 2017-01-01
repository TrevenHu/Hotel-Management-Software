#include <QApplication>
#include "mainwindow.h"
#include "mydatabase.h"
#include "login.h"
#include <QTextCodec>//֧������
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());//����ʹ������
    //�����ݿ�
    mydatabase  db;
    if(db.opendb("data.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    MainWindow w;
    w.show();
    return a.exec();
}
