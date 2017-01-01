#ifndef PRICE_CHANGE_H
#define PRICE_CHANGE_H
#include "room_management.h"
#include "mydatabase.h"

#include <QDialog>

namespace Ui {
class price_change;
}

class price_change : public QDialog
{
    Q_OBJECT
    
public:
    explicit price_change(QWidget *parent = 0);
    ~price_change();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::price_change *ui;
    QSqlQuery query_3;
    QString r_price;
    QString room_kind;
};

#endif // PRICE_CHANGE_H
