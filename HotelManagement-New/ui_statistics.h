/********************************************************************************
** Form generated from reading UI file 'statistics.ui'
**
** Created: Thu Jun 11 21:31:02 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICS_H
#define UI_STATISTICS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_statistics
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTabWidget *statistics_2;
    QWidget *statis;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *roomnum;
    QLabel *roomp;
    QLabel *allcharge;
    QPushButton *ok_button;
    QLabel *label_9;
    QPushButton *pushButton_3;
    QWidget *search;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_7;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *label_10;
    QTextEdit *room_information;
    QWidget *tab_2;
    QLineEdit *namelineEdit;
    QLabel *label_8;
    QPushButton *pushButton_2;
    QLabel *label_11;
    QPushButton *pushButton_4;
    QTableView *infor;

    void setupUi(QWidget *statistics)
    {
        if (statistics->objectName().isEmpty())
            statistics->setObjectName(QString::fromUtf8("statistics"));
        statistics->resize(737, 523);
        gridLayoutWidget = new QWidget(statistics);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(-1, -1, 731, 521));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        statistics_2 = new QTabWidget(gridLayoutWidget);
        statistics_2->setObjectName(QString::fromUtf8("statistics_2"));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        statistics_2->setFont(font);
        statistics_2->setTabPosition(QTabWidget::North);
        statistics_2->setTabShape(QTabWidget::Rounded);
        statis = new QWidget();
        statis->setObjectName(QString::fromUtf8("statis"));
        label = new QLabel(statis);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(80, 90, 150, 30));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(statis);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 210, 150, 30));
        QFont font2;
        font2.setPointSize(16);
        label_2->setFont(font2);
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(statis);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 340, 150, 30));
        label_3->setFrameShape(QFrame::NoFrame);
        label_3->setFrameShadow(QFrame::Raised);
        roomnum = new QLabel(statis);
        roomnum->setObjectName(QString::fromUtf8("roomnum"));
        roomnum->setGeometry(QRect(310, 90, 200, 30));
        roomnum->setFrameShape(QFrame::Panel);
        roomnum->setFrameShadow(QFrame::Sunken);
        roomp = new QLabel(statis);
        roomp->setObjectName(QString::fromUtf8("roomp"));
        roomp->setGeometry(QRect(310, 210, 200, 30));
        roomp->setFrameShape(QFrame::Panel);
        roomp->setFrameShadow(QFrame::Sunken);
        allcharge = new QLabel(statis);
        allcharge->setObjectName(QString::fromUtf8("allcharge"));
        allcharge->setGeometry(QRect(310, 340, 200, 30));
        allcharge->setFrameShape(QFrame::Panel);
        allcharge->setFrameShadow(QFrame::Sunken);
        ok_button = new QPushButton(statis);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));
        ok_button->setGeometry(QRect(580, 430, 90, 30));
        QFont font3;
        font3.setPointSize(11);
        ok_button->setFont(font3);
        label_9 = new QLabel(statis);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 0, 721, 491));
        label_9->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/1.jpg);"));
        pushButton_3 = new QPushButton(statis);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(480, 430, 90, 30));
        pushButton_3->setFont(font3);
        statistics_2->addTab(statis, QString());
        label_9->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        roomnum->raise();
        roomp->raise();
        allcharge->raise();
        ok_button->raise();
        pushButton_3->raise();
        search = new QWidget();
        search->setObjectName(QString::fromUtf8("search"));
        tabWidget = new QTabWidget(search);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 731, 491));
        tabWidget->setTabPosition(QTabWidget::West);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 40, 160, 30));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(550, 430, 90, 30));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        pushButton->setFont(font4);
        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(240, 40, 160, 30));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(0, 0, 701, 491));
        label_10->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/1.jpg);"));
        room_information = new QTextEdit(tab);
        room_information->setObjectName(QString::fromUtf8("room_information"));
        room_information->setGeometry(QRect(70, 100, 501, 271));
        tabWidget->addTab(tab, QString());
        label_10->raise();
        label_7->raise();
        pushButton->raise();
        comboBox->raise();
        room_information->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        namelineEdit = new QLineEdit(tab_2);
        namelineEdit->setObjectName(QString::fromUtf8("namelineEdit"));
        namelineEdit->setGeometry(QRect(230, 40, 150, 30));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(80, 40, 141, 30));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(560, 420, 90, 30));
        pushButton_2->setFont(font4);
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(0, 0, 701, 481));
        label_11->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/1.jpg);"));
        label_11->setFrameShadow(QFrame::Plain);
        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(410, 40, 75, 23));
        pushButton_4->setFont(font3);
        infor = new QTableView(tab_2);
        infor->setObjectName(QString::fromUtf8("infor"));
        infor->setGeometry(QRect(80, 100, 521, 311));
        infor->setFrameShape(QFrame::Box);
        infor->setFrameShadow(QFrame::Plain);
        tabWidget->addTab(tab_2, QString());
        label_11->raise();
        namelineEdit->raise();
        label_8->raise();
        pushButton_2->raise();
        pushButton_4->raise();
        infor->raise();
        statistics_2->addTab(search, QString());

        gridLayout->addWidget(statistics_2, 0, 0, 1, 1);


        retranslateUi(statistics);

        statistics_2->setCurrentIndex(1);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(statistics);
    } // setupUi

    void retranslateUi(QWidget *statistics)
    {
        statistics->setWindowTitle(QApplication::translate("statistics", "\347\273\237\350\256\241\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("statistics", "<html><head/><body><p align=\"center\">\345\205\245\344\275\217\346\210\277\351\227\264\346\225\260\351\207\217\357\274\232</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("statistics", "<html><head/><body><p align=\"center\">\345\205\245\344\275\217\347\216\207\357\274\232</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("statistics", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\346\200\273\346\224\266\345\205\245\357\274\232</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        roomnum->setText(QString());
        roomp->setText(QString());
        allcharge->setText(QString());
        ok_button->setText(QApplication::translate("statistics", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QString());
        pushButton_3->setText(QApplication::translate("statistics", "\347\273\237\350\256\241", 0, QApplication::UnicodeUTF8));
        statistics_2->setTabText(statistics_2->indexOf(statis), QApplication::translate("statistics", "\347\273\237\350\256\241", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("statistics", "<html><head/><body><p>\346\214\211\345\247\223\345\220\215\346\237\245\350\257\242</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("statistics", "\350\257\267\351\200\211\346\213\251\346\237\245\346\211\276\346\210\277\351\227\264\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("statistics", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("statistics", "101", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "102", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "103", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "104", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "105", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "106", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "107", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "108", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "109", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "110", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "201", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "202", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "203", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "204", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "205", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "207", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "208", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "209", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "210", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "301", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "302", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "303", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "304", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "305", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "306", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "307", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "308", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "401", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "402", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "403", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "404", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "405", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statistics", "406", 0, QApplication::UnicodeUTF8)
        );
        label_10->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("statistics", "\346\214\211\346\210\277\351\227\264\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tab_2->setToolTip(QApplication::translate("statistics", "<html><head/><body><p>an</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_8->setText(QApplication::translate("statistics", "\350\257\267\350\276\223\345\205\245\346\237\245\350\257\242\345\247\223\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("statistics", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        label_11->setText(QString());
        pushButton_4->setText(QApplication::translate("statistics", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("statistics", "\346\214\211\345\247\223\345\220\215\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        statistics_2->setTabText(statistics_2->indexOf(search), QApplication::translate("statistics", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class statistics: public Ui_statistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICS_H
