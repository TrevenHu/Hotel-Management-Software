#ifndef ORDERIN_H
#define ORDERIN_H

#include <QDialog>
#include <QSqlQuery>
#include <QString>

namespace Ui {
class orderin;
}

class orderin : public QDialog
{
    Q_OBJECT
    
public:
    explicit orderin(QWidget *parent = 0);
    ~orderin();
    
private slots:
    void on_pushButton_2_clicked();

    void on_ok_clicked();

private:
    Ui::orderin *ui;
    QSqlQuery query_7;
    QString rn;
    QString idNum;
};

#endif // ORDERIN_H
