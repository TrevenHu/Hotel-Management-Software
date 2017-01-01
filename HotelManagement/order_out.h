#ifndef ORDER_OUT_H
#define ORDER_OUT_H
#include <QSqlQuery>
#include <QDialog>

namespace Ui {
class order_out;
}

class order_out : public QDialog
{
    Q_OBJECT
    
public:
    explicit order_out(QWidget *parent = 0);
    ~order_out();
    
private slots:
    void on_yes_clicked();

    void on_no_clicked();

private:
    Ui::order_out *ui;
    QSqlQuery query;
};

#endif // ORDER_OUT_H
