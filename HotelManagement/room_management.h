#ifndef ROOM_MANAGEMENT_H
#define ROOM_MANAGEMENT_H
#include <QSqlQuery>
#include <QDialog>

extern int r_num;
extern int state[34];

namespace Ui {
class room_management;
}

class room_management : public QDialog
{
    Q_OBJECT
    
public:
    explicit room_management(QWidget *parent = 0);
    ~room_management();
    


private slots:
    void on_drj_1_clicked();

    void on_drj_2_clicked();

    void on_drj_3_clicked();

    void on_drj_4_clicked();

    void on_drj_5_clicked();

    void on_drj_6_clicked();

    void on_drj_7_clicked();

    void on_drj_8_clicked();

    void on_drj_9_clicked();

    void on_drj_10_clicked();

    void on_srj_1_clicked();

    void on_srj_2_clicked();

    void on_srj_3_clicked();

    void on_srj_4_clicked();

    void on_srj_5_clicked();

    void on_srj_6_clicked();

    void on_srj_7_clicked();

    void on_srj_8_clicked();

    void on_srj_9_clicked();

    void on_srj_10_clicked();

    void on_hhj_1_clicked();

    void on_hhj_2_clicked();

    void on_hhj_3_clicked();

    void on_hhj_4_clicked();

    void on_hhj_5_clicked();

    void on_hhj_6_clicked();

    void on_hhj_7_clicked();

    void on_hhj_8_clicked();

    void on_hht_1_clicked();

    void on_hht_2_clicked();

    void on_hht_3_clicked();

    void on_hht_4_clicked();

    void on_hht_5_clicked();

    void on_hht_6_clicked();

    void on_drj_21_clicked();

    void on_drj_22_clicked();

    void on_drj_23_clicked();

    void on_drj_24_clicked();

    void on_drj_25_clicked();

    void on_drj_26_clicked();

    void on_drj_27_clicked();

    void on_drj_28_clicked();

    void on_drj_29_clicked();

    void on_drj_30_clicked();

    void on_srj_21_clicked();

    void on_srj_22_clicked();

    void on_srj_23_clicked();

    void on_srj_24_clicked();

    void on_srj_25_clicked();

    void on_srj_26_clicked();

    void on_srj_27_clicked();

    void on_srj_28_clicked();

    void on_srj_29_clicked();

    void on_srj_30_clicked();

    void on_hhj_21_clicked();

    void on_hhj_22_clicked();

    void on_hhj_23_clicked();

    void on_hhj_24_clicked();

    void on_hhj_25_clicked();

    void on_hhj_26_clicked();

    void on_hhj_27_clicked();

    void on_hhj_28_clicked();

    void on_hht_21_clicked();

    void on_hht_22_clicked();

    void on_hht_23_clicked();

    void on_hht_24_clicked();

    void on_hht_25_clicked();

    void on_hht_26_clicked();

    void on_drj_11_clicked();

    void on_drj_12_clicked();

    void on_drj_13_clicked();

    void on_drj_14_clicked();

    void on_drj_15_clicked();

    void on_drj_16_clicked();

    void on_drj_17_clicked();

    void on_drj_18_clicked();

    void on_drj_19_clicked();

    void on_drj_20_clicked();

    void on_srj_11_clicked();

    void on_srj_12_clicked();

    void on_srj_13_clicked();

    void on_srj_14_clicked();

    void on_srj_15_clicked();

    void on_srj_16_clicked();

    void on_srj_17_clicked();

    void on_srj_18_clicked();

    void on_srj_19_clicked();

    void on_srj_20_clicked();

    void on_hhj_11_clicked();

    void on_hhj_12_clicked();

    void on_hhj_13_clicked();

    void on_hhj_14_clicked();

    void on_hhj_15_clicked();

    void on_hhj_16_clicked();

    void on_hhj_17_clicked();

    void on_hhj_18_clicked();

    void on_hht_11_clicked();

    void on_hht_12_clicked();

    void on_hht_13_clicked();

    void on_hht_14_clicked();

    void on_hht_15_clicked();

    void on_hht_16_clicked();

private:
    Ui::room_management *ui;
    QSqlQuery query_1;

};

#endif // ROOM_MANAGEMENT_H
