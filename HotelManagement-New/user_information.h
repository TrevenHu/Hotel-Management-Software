#ifndef USER_INFORMATION_H
#define USER_INFORMATION_H

#include <QDialog>
#include <QSqlQuery>

namespace Ui {
class user_information;
}

class user_information : public QDialog
{
    Q_OBJECT
    
public:
    explicit user_information(QWidget *parent = 0);
    ~user_information();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::user_information *ui;
    QSqlQuery query_4;
    QString name;
    QString sex;
    QString cId;
    QString age;
    QString phone;
    QString city;
    QString address;
    QString room_num;
    QString year;
    QString month;
    QString day;
    QString rn;
    QString room_price;
    QString all;

    //QString chkintimeD;
    //QString chkintimeT;
    //QString currentDate;
};

#endif // USER_INFORMATION_H
