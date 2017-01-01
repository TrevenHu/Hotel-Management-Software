#include "mydatabase.h"
#include <QSqlQuery>
#include <QStringList>
#include <QTextCodec>
mydatabase::mydatabase(QObject *parent) ://选择驱动程序名
    QObject(parent)
{
    db=QSqlDatabase::addDatabase("QSQLITE");
}

//建立数据库
bool mydatabase::opendb(QString dbname)
{
    db.setDatabaseName(dbname);
    if(!db.open())
    {
        qDebug("db file open error.");
        return false;
    }
    return true;
}

//创建各种信息表
void mydatabase::createtable()
{
    QStringList tables=db.tables();
    QSqlQuery query;
    //创建客户信息表(姓名，性别，身份证号，年龄，电话号码，所在城市，工作地址，房间号，入住年，月，日，入住天数，房费，总消费)
    query.exec("create table customer(name varchar,sex varchar,id varchar primary key,age int,phone varchar,city varchar,address varchar,room_num int,year int,month int,day int,times double,room_price double,allcharge double)");
    //创建房间信息表(房间号，房间类型，房价，房间状态)
    query.exec("create table room(room_num int primary key,room_kind varchar,room_price double,room_state int)");
    query.exec("insert into room values(101,'A',100,0)");
    query.exec("insert into room values(102,'A',100,0)");
    query.exec("insert into room values(103,'A',100,0)");
    query.exec("insert into room values(104,'A',100,0)");
    query.exec("insert into room values(105,'A',100,0)");
    query.exec("insert into room values(106,'A',100,0)");
    query.exec("insert into room values(107,'A',100,0)");
    query.exec("insert into room values(108,'A',100,0)");
    query.exec("insert into room values(109,'A',100,0)");
    query.exec("insert into room values(110,'A',100,0)");
    query.exec("insert into room values(201,'B',200,0)");
    query.exec("insert into room values(202,'B',200,0)");
    query.exec("insert into room values(203,'B',200,0)");
    query.exec("insert into room values(204,'B',200,0)");
    query.exec("insert into room values(205,'B',200,0)");
    query.exec("insert into room values(206,'B',200,0)");
    query.exec("insert into room values(207,'B',200,0)");
    query.exec("insert into room values(208,'B',200,0)");
    query.exec("insert into room values(209,'B',200,0)");
    query.exec("insert into room values(210,'B',200,0)");
    query.exec("insert into room values(301,'C',300,0)");
    query.exec("insert into room values(302,'C',300,0)");
    query.exec("insert into room values(303,'C',300,0)");
    query.exec("insert into room values(304,'C',300,0)");
    query.exec("insert into room values(305,'C',300,0)");
    query.exec("insert into room values(306,'C',300,0)");
    query.exec("insert into room values(307,'C',300,0)");
    query.exec("insert into room values(308,'C',300,0)");
    query.exec("insert into room values(401,'D',400,0)");
    query.exec("insert into room values(402,'D',400,0)");
    query.exec("insert into room values(403,'D',400,0)");
    query.exec("insert into room values(404,'D',400,0)");
    query.exec("insert into room values(405,'D',400,0)");
    query.exec("insert into room values(406,'D',400,0)");
    //创建历史用户信息（姓名，房间号，身份证号，年，月，日，入住天数，总消费）
    query.exec("create table historyspends(hname varchar,hroom_num int,hid varchar,year int,month int,day int,times double,allcharge double)");
    //创建时间表（年，月，日，时，分）
    if(query.exec("create table time(year int,month int,day int,hour int,minute int)"))
        query.exec("insert into time values(2015,5,17,12,0)");
}

void mydatabase::closedb()
{

    db.close();

}
