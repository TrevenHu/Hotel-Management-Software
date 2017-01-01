#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QString>

extern int b;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



public slots:
    void onTimerOut();


private slots:

    void on_statistic_clicked();

    void on_price_change_clicked();

    void on_pushButton_clicked();

    void on_exit_clicked();

private:
    Ui::MainWindow *ui;
    QSqlQuery query_6;
    int year,month,da,hour,minute;
    QTimer *timer;
    QString y,m,d,h,t;

};

#endif // MAINWINDOW_H
