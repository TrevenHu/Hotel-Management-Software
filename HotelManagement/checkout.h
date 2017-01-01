#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QSqlQuery>
#include <QDialog>

namespace Ui {
class checkout;
}

class checkout : public QDialog
{
    Q_OBJECT
    
public:
    explicit checkout(QWidget *parent = 0);
    ~checkout();
    
private slots:

    void on_add_clicked();

    void on_okButton_clicked();

    void on_cancellButton_clicked();

private:
    Ui::checkout *ui;
    QSqlQuery query_5;
    QString rn;
    QString name;
    double r_p;
    QString hid;
    QString year;
    QString month;
    QString day;
    double ts;
    double allcharge;
    QString externcharge;
};

#endif // CHECKOUT_H
