#include "room_management.h"
#include "ui_room_management.h"
#include "user_information.h"
#include "order_out.h"
#include "checkout.h"
#include "orderin.h"
#include <QMessageBox>
#include<QPalette>
//房间状态和房间号，全局变量，用于房间状态的实时刷新
int state[34];
int r_num;
//房间状态刷新
room_management::room_management(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::room_management)
{
    ui->setupUi(this);
    //遍历房间表，初始化state[]变量
    query_1.exec("select * from room");
    int i=0;
    while(query_1.next())
    {
        state[i]=query_1.value(3).toInt();
        i++;
    }
    //0代表无人入住，房间标签为绿色；1表示被预定，房间标签为黄色；2表示入住，房间标签为红色；
    for(int i=0;i<=33;i++){
         if(state[i] ==0)
            switch (i){
            case 0:
                ui->drj_1->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_11->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_21->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 1:
                ui->drj_2->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_12->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_22->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 2:
                ui->drj_3->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_13->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_23->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 3:
                ui->drj_4->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_14->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_24->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 4:
                ui->drj_5->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_15->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_25->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 5:
                ui->drj_6->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_16->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_26->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 6:
                ui->drj_7->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_17->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_27->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 7:
                ui->drj_8->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_18->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_28->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 8:
                ui->drj_9->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_19->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_29->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 9:
                ui->drj_10->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_20->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->drj_30->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 10:
                ui->srj_1->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_11->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_21->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 11:
                ui->srj_2->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_12->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_22->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 12:
                ui->srj_3->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_13->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_23->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 13:
                ui->srj_4->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_14->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_24->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 14:
                ui->srj_5->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_15->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_25->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 15:
                ui->srj_6->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_16->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_26->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 16:
                ui->srj_7->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_17->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_27->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 17:
                ui->srj_8->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_18->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_28->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 18:
                ui->srj_9->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_19->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_29->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 19:
                ui->srj_10->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_20->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->srj_30->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 20:
                ui->hhj_1->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hhj_11->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hhj_21->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 21:
                ui->hhj_2->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hhj_12->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hhj_22->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 22:
                ui->hhj_3->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hhj_13->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hhj_23->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 23:
                ui->hhj_4->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hhj_14->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hhj_24->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 24:
                ui->hhj_5->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hhj_15->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hhj_25->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 25:
                ui->hhj_6->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hhj_16->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hhj_26->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 26:
                ui->hhj_7->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hhj_17->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hhj_27->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 27:
                ui->hhj_8->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hhj_18->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hhj_28->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 28:
                ui->hht_1->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hht_11->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hht_21->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 29:
                ui->hht_2->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hht_12->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hht_22->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 30:
                ui->hht_3->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hht_13->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hht_23->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 31:
                ui->hht_4->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hht_14->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hht_24->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 32:
                ui->hht_5->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hht_15->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hht_25->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
            case 33:
                ui->hht_6->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hht_16->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                ui->hht_26->setStyleSheet("background-color: rgb( 0, 255, 0);");//绿
                break;
         }
         else if(state[i] == 2)
             switch (i){
             case 0:
                 ui->drj_1->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_11->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_21->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 1:
                 ui->drj_2->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_12->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_22->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 2:
                 ui->drj_3->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_13->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_23->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 3:
                 ui->drj_4->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_14->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_24->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 4:
                 ui->drj_5->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_15->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_25->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 5:
                 ui->drj_6->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_16->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_26->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 6:
                 ui->drj_7->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_17->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_27->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 7:
                 ui->drj_8->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_18->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_28->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 8:
                 ui->drj_9->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_19->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_29->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 9:
                 ui->drj_10->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_20->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->drj_30->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 10:
                 ui->srj_1->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_11->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_21->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 11:
                 ui->srj_2->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_12->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_22->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 12:
                 ui->srj_3->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_13->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_23->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 13:
                 ui->srj_4->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_14->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_24->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 14:
                 ui->srj_5->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_15->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_25->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 15:
                 ui->srj_6->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_16->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_26->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 16:
                 ui->srj_7->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_17->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_27->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 17:
                 ui->srj_8->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_18->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_28->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 18:
                 ui->srj_9->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_19->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_29->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 19:
                 ui->srj_10->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_20->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->srj_30->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 20:
                 ui->hhj_1->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hhj_11->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hhj_21->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 21:
                 ui->hhj_2->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hhj_12->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hhj_22->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 22:
                 ui->hhj_3->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hhj_13->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hhj_23->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 23:
                 ui->hhj_4->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hhj_14->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hhj_24->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 24:
                 ui->hhj_5->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hhj_15->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hhj_25->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 25:
                 ui->hhj_6->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hhj_16->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hhj_26->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 26:
                 ui->hhj_7->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hhj_17->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hhj_27->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 27:
                 ui->hhj_8->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hhj_18->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hhj_28->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 28:
                 ui->hht_1->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hht_11->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hht_21->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 29:
                 ui->hht_2->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hht_12->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hht_22->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 30:
                 ui->hht_3->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hht_13->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hht_23->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 31:
                 ui->hht_4->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hht_14->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hht_24->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 32:
                 ui->hht_5->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hht_15->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hht_25->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
             case 33:
                 ui->hht_6->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hht_16->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 ui->hht_26->setStyleSheet("background-color: rgb( 255, 0, 0);");//红
                 break;
         }
         else if(state[i] == 1)
             switch (i){
             case 0:
                 ui->drj_1->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_11->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_21->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 1:
                 ui->drj_2->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_12->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_22->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 2:
                 ui->drj_3->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_13->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_23->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 3:
                 ui->drj_4->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_14->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_24->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 4:
                 ui->drj_5->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_15->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_25->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 5:
                 ui->drj_6->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_16->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_26->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 6:
                 ui->drj_7->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_17->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_27->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 7:
                 ui->drj_8->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_18->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_28->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 8:
                 ui->drj_9->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_19->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_29->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 9:
                 ui->drj_10->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_20->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->drj_30->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 10:
                 ui->srj_1->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_11->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_21->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 11:
                 ui->srj_2->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_12->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_22->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 12:
                 ui->srj_3->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_13->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_23->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 13:
                 ui->srj_4->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_14->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_24->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 14:
                 ui->srj_5->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_15->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_25->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 15:
                 ui->srj_6->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_16->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_26->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 16:
                 ui->srj_7->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_17->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_27->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 17:
                 ui->srj_8->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_18->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_28->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 18:
                 ui->srj_9->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_19->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_29->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 19:
                 ui->srj_10->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_20->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->srj_30->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 20:
                 ui->hhj_1->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hhj_11->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hhj_21->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 21:
                 ui->hhj_2->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hhj_12->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hhj_22->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 22:
                 ui->hhj_3->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hhj_13->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hhj_23->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 23:
                 ui->hhj_4->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hhj_14->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hhj_24->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 24:
                 ui->hhj_5->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hhj_15->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hhj_25->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 25:
                 ui->hhj_6->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hhj_16->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hhj_26->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 26:
                 ui->hhj_7->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hhj_17->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hhj_27->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 27:
                 ui->hhj_8->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hhj_18->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hhj_28->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 28:
                 ui->hht_1->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hht_11->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hht_21->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 29:
                 ui->hht_2->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hht_12->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hht_22->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 30:
                 ui->hht_3->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hht_13->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hht_23->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 31:
                 ui->hht_4->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hht_14->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hht_24->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 32:
                 ui->hht_5->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hht_15->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hht_25->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
             case 33:
                 ui->hht_6->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hht_16->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 ui->hht_26->setStyleSheet("background-color: rgb(255, 255, 0);");//黄
                 break;
         }
     }
}

room_management::~room_management()
{
    delete ui;
}
//请求入住时，根据房间的相应状态，提示相应信息
void room_management::on_drj_1_clicked()
{
    if(state[0] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[0] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    //可以入住，则弹出用户信息登记窗口
    else
    {
        r_num=1012;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_drj_2_clicked()
{
    if(state[1] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[1] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=1022;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_drj_3_clicked()
{
    if(state[2] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[2] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=1032;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_drj_4_clicked()
{
    if(state[3] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[3] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=1042;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_drj_5_clicked()
{
    if(state[4] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[4] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=1052;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_drj_6_clicked()
{
    if(state[5] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[5] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=1062;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_drj_7_clicked()
{
    if(state[6] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[6] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=1072;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_drj_8_clicked()
{
    if(state[7] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[7] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=1082;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_drj_9_clicked()
{
    if(state[8] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[8] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=1092;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_drj_10_clicked()
{
    if(state[9] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[9] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=1102;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_1_clicked()
{
    if(state[10] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[10] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=2012;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_2_clicked()
{
    if(state[11] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[11] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=2022;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_3_clicked()
{
    if(state[12] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[12] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=2032;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_4_clicked()
{
    if(state[13] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[13] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=2042;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_5_clicked()
{
    if(state[14] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[14] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=2052;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_6_clicked()
{
    if(state[15] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[15] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=2062;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_7_clicked()
{
    if(state[16] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[16] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=2072;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_8_clicked()
{
    if(state[17] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[17] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=2082;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_9_clicked()
{
    if(state[18] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[18] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=2092;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_10_clicked()
{
    if(state[19] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[19] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=2102;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_1_clicked()
{
    if(state[20] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[20] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=3012;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_2_clicked()
{
    if(state[21] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[21] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=3022;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_3_clicked()
{
    if(state[22] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[22] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=3032;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_4_clicked()
{
    if(state[23] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[23] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=3042;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_5_clicked()
{
    if(state[24] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[24] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=3052;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_6_clicked()
{
    if(state[25] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[25] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=3062;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_7_clicked()
{
    if(state[26] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[26] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=3072;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_8_clicked()
{
    if(state[27] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[27] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=3082;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hht_1_clicked()
{
    if(state[28] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[28] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=4012;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hht_2_clicked()
{
    if(state[29] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[29] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=4022;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hht_3_clicked()
{
    if(state[30] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[30] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=4032;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hht_4_clicked()
{
    if(state[31] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[31] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=4042;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hht_5_clicked()
{
    if(state[32] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[32] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=4052;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hht_6_clicked()
{
    if(state[33] == 2 )
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人入住，请重新选择"));
    else if(state[33] == 1)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间已有人预定，请重新选择"));
    else
    {
        r_num=4062;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}
//入住用户退房或预定用户退房
void room_management::on_drj_21_clicked()
{
    if(state[0]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    //预定用户退房
    else if(state[0]==1)
    {
        r_num=1010;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    //入住用户退房
    else
    {
        r_num=1010;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_drj_22_clicked()
{
    if(state[1]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[1]==1)
    {
        r_num=1020;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=1020;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_drj_23_clicked()
{
    if(state[2]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[2]==1)
    {
        r_num=1030;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=1030;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_drj_24_clicked()
{
    if(state[3]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[3]==1)
    {
        r_num=1040;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=1040;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_drj_25_clicked()
{
    if(state[4]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[4]==1)
    {
        r_num=1050;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=1050;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_drj_26_clicked()
{
    if(state[5]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[5]==1)
    {
        r_num=1060;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=1060;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_drj_27_clicked()
{
    if(state[6]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[6]==1)
    {
        r_num=1070;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=1070;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_drj_28_clicked()
{
    if(state[7]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[7]==1)
    {
        r_num=1080;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=1080;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_drj_29_clicked()
{
    if(state[8]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[8]==1)
    {
        r_num=1090;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=1090;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_drj_30_clicked()
{
    if(state[9]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[9]==1)
    {
        r_num=1100;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=1100;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_srj_21_clicked()
{
    if(state[10]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[10]==1)
    {
        r_num=2010;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=2010;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_srj_22_clicked()
{
    if(state[11]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[11]==1)
    {
        r_num=2020;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=2020;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_srj_23_clicked()
{
    if(state[12]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[12]==1)
    {
        r_num=2030;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=2030;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_srj_24_clicked()
{
    if(state[13]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[13]==1)
    {
        r_num=2040;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=2040;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_srj_25_clicked()
{
    if(state[14]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[14]==1)
    {
        r_num=2050;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=2050;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_srj_26_clicked()
{
    if(state[15]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[15]==1)
    {
        r_num=2060;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=2060;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_srj_27_clicked()
{
    if(state[16]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[16]==1)
    {
        r_num=2070;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=2070;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_srj_28_clicked()
{
    if(state[17]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[17]==1)
    {
        r_num=2080;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=2080;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_srj_29_clicked()
{
    if(state[18]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[18]==1)
    {
        r_num=2090;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=2090;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_srj_30_clicked()
{
    if(state[19]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[19]==1)
    {
        r_num=2100;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=2100;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_21_clicked()
{
    if(state[20]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[20]==1)
    {
        r_num=3010;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=3010;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_22_clicked()
{
    if(state[21]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[21]==1)
    {
        r_num=3020;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=3020;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_23_clicked()
{
    if(state[22]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[22]==1)
    {
        r_num=3030;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=3030;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_24_clicked()
{
    if(state[23]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[23]==1)
    {
        r_num=3040;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=3040;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_25_clicked()
{
    if(state[24]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[24]==1)
    {
        r_num=3050;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=3050;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_26_clicked()
{
    if(state[25]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[25]==1)
    {
        r_num=3060;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=3060;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_27_clicked()
{
    if(state[26]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[26]==1)
    {
        r_num=3070;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=3070;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_28_clicked()
{
    if(state[27]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[27]==1)
    {
        r_num=3080;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=3080;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_hht_21_clicked()
{
    if(state[28]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[28]==1)
    {
        r_num=4010;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=4010;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_hht_22_clicked()
{
    if(state[29]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[29]==1)
    {
        r_num=4020;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=4020;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_hht_23_clicked()
{
    if(state[30]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[30]==1)
    {
        r_num=4030;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=4030;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_hht_24_clicked()
{
    if(state[31]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[31]==1)
    {
        r_num=4040;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=4040;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_hht_25_clicked()
{
    if(state[32]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[32]==1)
    {
        r_num=4050;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=4050;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}

void room_management::on_hht_26_clicked()
{
    if(state[33]==0)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间无人入住，请重新选择"));
    else if(state[33]==1)
    {
        r_num=4060;
        order_out *p= new order_out;
        p->show();
        this->close();
    }
    else
    {
        r_num=4060;
        checkout *p= new checkout;
        p->show();
        this->close();
    }
}
//已经预定客户的入住登记或预定
void room_management::on_drj_11_clicked()
{
    if(state[0]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    //已经预定客户的入住登记
    else if(state[0]==1)
    {
        r_num=1012;
        //进入信息验证框
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    //用户预订
    else
    {
        r_num=1011;
        user_information *p= new user_information;
        p->show();
        this->close();
    }

}

void room_management::on_drj_12_clicked()
{
    if(state[1]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[1]==1)
    {
        r_num=1022;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=1021;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_drj_13_clicked()
{
    if(state[2]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[2]==1)
    {
        r_num=1032;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=1031;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_drj_14_clicked()
{
    if(state[3]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[3]==1)
    {
        r_num=1042;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=1041;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_drj_15_clicked()
{
    if(state[4]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[4]==1)
    {
        r_num=1052;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=1051;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_drj_16_clicked()
{
    if(state[5]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[5]==1)
    {
        r_num=1062;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=1061;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_drj_17_clicked()
{
    if(state[6]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[6]==1)
    {
        r_num=1072;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=1071;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_drj_18_clicked()
{
    if(state[7]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[7]==1)
    {
        r_num=1082;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=1081;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_drj_19_clicked()
{
    if(state[8]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[8]==1)
    {
        r_num=1092;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=1091;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_drj_20_clicked()
{
    if(state[9]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[9]==1)
    {
        r_num=1102;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=1101;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_11_clicked()
{
    if(state[10]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[10]==1)
    {
        r_num=2012;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=2011;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_12_clicked()
{
    if(state[11]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[11]==1)
    {
        r_num=2022;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=2021;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_13_clicked()
{
    if(state[12]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[12]==1)
    {
        r_num=2032;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=2031;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_14_clicked()
{
    if(state[13]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[13]==1)
    {
        r_num=2042;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=2041;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_15_clicked()
{
    if(state[14]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[14]==1)
    {
        r_num=2052;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=2051;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_16_clicked()
{
    if(state[15]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[15]==1)
    {
        r_num=2062;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=2061;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_17_clicked()
{
    if(state[16]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[16]==1)
    {
        r_num=2072;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=2071;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_18_clicked()
{
    if(state[17]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[17]==1)
    {
        r_num=2082;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=2081;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_19_clicked()
{
    if(state[18]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[18]==1)
    {
        r_num=2092;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=2091;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_srj_20_clicked()
{
    if(state[19]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[19]==1)
    {
        r_num=2102;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=2101;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}



void room_management::on_hhj_11_clicked()
{
    if(state[20]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[20]==1)
    {
        r_num=3012;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=3011;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_12_clicked()
{
    if(state[21]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[21]==1)
    {
        r_num=3022;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=3021;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_13_clicked()
{
    if(state[22]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[22]==1)
    {
        r_num=3032;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=3031;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_14_clicked()
{
    if(state[23]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[23]==1)
    {
        r_num=3042;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=3041;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_15_clicked()
{
    if(state[24]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[24]==1)
    {
        r_num=3052;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=3051;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_16_clicked()
{
    if(state[25]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[25]==1)
    {
        r_num=3062;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=3061;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_17_clicked()
{
    if(state[26]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[26]==1)
    {
        r_num=3072;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=3071;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hhj_18_clicked()
{
    if(state[27]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[27]==1)
    {
        r_num=3082;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=3081;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hht_11_clicked()
{
    if(state[28]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[28]==1)
    {
        r_num=4012;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=4011;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hht_12_clicked()
{
    if(state[29]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[29]==1)
    {
        r_num=4022;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=4021;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hht_13_clicked()
{
    if(state[30]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[30]==1)
    {
        r_num=4032;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=4031;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hht_14_clicked()
{
    if(state[31]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[31]==1)
    {
        r_num=4042;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=4041;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hht_15_clicked()
{
    if(state[32]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[32]==1)
    {
        r_num=4052;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=4051;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}

void room_management::on_hht_16_clicked()
{
    if(state[33]==2)
        QMessageBox::warning(NULL,tr("警告"),tr("该房间有人入住，请重新选择"));
    else if(state[33]==1)
    {
        r_num=4062;
        orderin *p= new orderin;
        p->show();
        this->close();
    }
    else
    {
        r_num=4061;
        user_information *p= new user_information;
        p->show();
        this->close();
    }
}
