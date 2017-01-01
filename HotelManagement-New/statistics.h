#ifndef STATISTICS_H
#define STATISTICS_H
#include "mydatabase.h"
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QWidget>

namespace Ui {
class statistics;
}

class statistics : public QWidget
{
    Q_OBJECT
    
public:
    explicit statistics(QWidget *parent = 0);
    ~statistics();


    


private slots:
    void on_pushButton_3_clicked();

    void on_ok_button_clicked();



    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::statistics *ui;
    QSqlQuery query_2;
    QSqlTableModel *model;
};

#endif // STATISTICS_H
