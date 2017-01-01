/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jun 11 20:32:46 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *time;
    QPushButton *statistic;
    QPushButton *price_change;
    QPushButton *exit;
    QPushButton *pushButton;
    QLabel *yearlabel;
    QLabel *label_2;
    QLabel *monthlabel;
    QLabel *label_4;
    QLabel *daylabel;
    QLabel *label;
    QLabel *label_3;
    QLabel *hourlabel;
    QLabel *minutelabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(750, 500);
        MainWindow->setMinimumSize(QSize(750, 500));
        MainWindow->setMaximumSize(QSize(750, 500));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        time = new QLabel(centralWidget);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(0, 0, 750, 500));
        time->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/1.jpg);"));
        time->setFrameShape(QFrame::Panel);
        time->setFrameShadow(QFrame::Plain);
        statistic = new QPushButton(centralWidget);
        statistic->setObjectName(QString::fromUtf8("statistic"));
        statistic->setGeometry(QRect(210, 170, 110, 50));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        statistic->setFont(font);
        price_change = new QPushButton(centralWidget);
        price_change->setObjectName(QString::fromUtf8("price_change"));
        price_change->setGeometry(QRect(210, 250, 110, 50));
        price_change->setFont(font);
        exit = new QPushButton(centralWidget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(210, 330, 110, 50));
        exit->setFont(font);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 90, 110, 50));
        pushButton->setFont(font);
        yearlabel = new QLabel(centralWidget);
        yearlabel->setObjectName(QString::fromUtf8("yearlabel"));
        yearlabel->setGeometry(QRect(400, 190, 54, 16));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        yearlabel->setFont(font1);
        yearlabel->setFrameShape(QFrame::NoFrame);
        yearlabel->setFrameShadow(QFrame::Plain);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(450, 190, 30, 15));
        label_2->setFont(font1);
        monthlabel = new QLabel(centralWidget);
        monthlabel->setObjectName(QString::fromUtf8("monthlabel"));
        monthlabel->setGeometry(QRect(470, 190, 54, 16));
        monthlabel->setFont(font1);
        monthlabel->setFrameShape(QFrame::NoFrame);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(490, 190, 30, 15));
        label_4->setFont(font1);
        daylabel = new QLabel(centralWidget);
        daylabel->setObjectName(QString::fromUtf8("daylabel"));
        daylabel->setGeometry(QRect(510, 190, 54, 16));
        daylabel->setFont(font1);
        daylabel->setFrameShape(QFrame::NoFrame);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(540, 190, 30, 15));
        label->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(480, 240, 30, 15));
        label_3->setFont(font1);
        hourlabel = new QLabel(centralWidget);
        hourlabel->setObjectName(QString::fromUtf8("hourlabel"));
        hourlabel->setGeometry(QRect(460, 240, 40, 20));
        hourlabel->setFont(font1);
        hourlabel->setFrameShape(QFrame::NoFrame);
        minutelabel = new QLabel(centralWidget);
        minutelabel->setObjectName(QString::fromUtf8("minutelabel"));
        minutelabel->setGeometry(QRect(490, 240, 40, 20));
        minutelabel->setFont(font1);
        minutelabel->setFrameShape(QFrame::NoFrame);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\351\205\222\345\272\227\347\256\241\347\220\206\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        time->setText(QString());
        statistic->setText(QApplication::translate("MainWindow", "\347\273\237\350\256\241\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        price_change->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\346\210\277\344\273\267", 0, QApplication::UnicodeUTF8));
        exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "\346\210\277\351\227\264\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        yearlabel->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\345\271\264", 0, QApplication::UnicodeUTF8));
        monthlabel->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "\346\234\210", 0, QApplication::UnicodeUTF8));
        daylabel->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\346\227\245", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\357\274\232", 0, QApplication::UnicodeUTF8));
        hourlabel->setText(QString());
        minutelabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
