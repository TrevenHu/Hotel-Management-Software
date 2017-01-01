#ifndef MYDATABASE_H
#define MYDATABASE_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QObject>

class mydatabase : public QObject
{
    Q_OBJECT
public:
    explicit mydatabase(QObject *parent = 0);
    bool opendb(QString dbname);
    void createtable();
    void closedb();


private:
    QSqlDatabase db;
    
};

#endif // MYDATABASE_H
