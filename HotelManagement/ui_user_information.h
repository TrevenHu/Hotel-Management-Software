/********************************************************************************
** Form generated from reading UI file 'user_information.ui'
**
** Created: Sun May 31 20:36:40 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_INFORMATION_H
#define UI_USER_INFORMATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_user_information
{
public:
    QLineEdit *namelineEdit;
    QLineEdit *agelineEdit;
    QLineEdit *citylineEdit;
    QLineEdit *phonelineEdit;
    QLineEdit *idlineEdit;
    QLabel *name;
    QLabel *age;
    QLabel *phone;
    QLabel *id_num;
    QLabel *work_place;
    QLabel *sex;
    QLabel *live_city;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *user_information)
    {
        if (user_information->objectName().isEmpty())
            user_information->setObjectName(QString::fromUtf8("user_information"));
        user_information->resize(740, 518);
        QFont font;
        font.setPointSize(10);
        user_information->setFont(font);
        namelineEdit = new QLineEdit(user_information);
        namelineEdit->setObjectName(QString::fromUtf8("namelineEdit"));
        namelineEdit->setGeometry(QRect(190, 90, 120, 30));
        agelineEdit = new QLineEdit(user_information);
        agelineEdit->setObjectName(QString::fromUtf8("agelineEdit"));
        agelineEdit->setGeometry(QRect(190, 160, 120, 30));
        citylineEdit = new QLineEdit(user_information);
        citylineEdit->setObjectName(QString::fromUtf8("citylineEdit"));
        citylineEdit->setGeometry(QRect(520, 160, 120, 30));
        phonelineEdit = new QLineEdit(user_information);
        phonelineEdit->setObjectName(QString::fromUtf8("phonelineEdit"));
        phonelineEdit->setGeometry(QRect(190, 230, 120, 30));
        idlineEdit = new QLineEdit(user_information);
        idlineEdit->setObjectName(QString::fromUtf8("idlineEdit"));
        idlineEdit->setGeometry(QRect(520, 230, 191, 30));
        name = new QLabel(user_information);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(70, 90, 90, 30));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        name->setFont(font1);
        name->setFrameShape(QFrame::NoFrame);
        name->setFrameShadow(QFrame::Plain);
        age = new QLabel(user_information);
        age->setObjectName(QString::fromUtf8("age"));
        age->setGeometry(QRect(70, 160, 90, 30));
        age->setFrameShape(QFrame::NoFrame);
        age->setFrameShadow(QFrame::Plain);
        phone = new QLabel(user_information);
        phone->setObjectName(QString::fromUtf8("phone"));
        phone->setGeometry(QRect(60, 230, 90, 30));
        phone->setFrameShape(QFrame::NoFrame);
        phone->setFrameShadow(QFrame::Plain);
        id_num = new QLabel(user_information);
        id_num->setObjectName(QString::fromUtf8("id_num"));
        id_num->setGeometry(QRect(380, 230, 111, 30));
        id_num->setFrameShape(QFrame::NoFrame);
        id_num->setFrameShadow(QFrame::Plain);
        work_place = new QLabel(user_information);
        work_place->setObjectName(QString::fromUtf8("work_place"));
        work_place->setGeometry(QRect(50, 310, 100, 30));
        work_place->setFont(font1);
        work_place->setFrameShape(QFrame::NoFrame);
        work_place->setFrameShadow(QFrame::Plain);
        sex = new QLabel(user_information);
        sex->setObjectName(QString::fromUtf8("sex"));
        sex->setGeometry(QRect(400, 90, 90, 30));
        sex->setFrameShape(QFrame::NoFrame);
        sex->setFrameShadow(QFrame::Plain);
        live_city = new QLabel(user_information);
        live_city->setObjectName(QString::fromUtf8("live_city"));
        live_city->setGeometry(QRect(380, 160, 101, 30));
        live_city->setFrameShape(QFrame::NoFrame);
        live_city->setFrameShadow(QFrame::Plain);
        label = new QLabel(user_information);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 40, 151, 31));
        label_2 = new QLabel(user_information);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 741, 521));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/1.jpg);"));
        label_2->setFrameShape(QFrame::NoFrame);
        comboBox = new QComboBox(user_information);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(520, 90, 90, 30));
        pushButton_2 = new QPushButton(user_information);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(595, 452, 75, 23));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_2->setFont(font2);
        lineEdit = new QLineEdit(user_information);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(190, 310, 300, 30));
        pushButton = new QPushButton(user_information);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(511, 452, 75, 23));
        pushButton->setFont(font2);
        label_2->raise();
        namelineEdit->raise();
        agelineEdit->raise();
        citylineEdit->raise();
        phonelineEdit->raise();
        idlineEdit->raise();
        name->raise();
        age->raise();
        phone->raise();
        id_num->raise();
        work_place->raise();
        sex->raise();
        live_city->raise();
        label->raise();
        comboBox->raise();
        pushButton_2->raise();
        lineEdit->raise();
        pushButton->raise();

        retranslateUi(user_information);

        QMetaObject::connectSlotsByName(user_information);
    } // setupUi

    void retranslateUi(QDialog *user_information)
    {
        user_information->setWindowTitle(QApplication::translate("user_information", "\347\224\250\346\210\267\344\277\241\346\201\257\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        name->setToolTip(QApplication::translate("user_information", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        name->setWhatsThis(QApplication::translate("user_information", "<html><head/><body><p>\345\247\223\345\220\215</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        name->setText(QApplication::translate("user_information", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\345\247\223\345\220\215:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        age->setText(QApplication::translate("user_information", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">\345\271\264\351\276\204:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        phone->setText(QApplication::translate("user_information", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">\346\211\213\346\234\272\345\217\267:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        id_num->setText(QApplication::translate("user_information", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">\350\272\253\344\273\275\350\257\201\345\217\267:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        work_place->setText(QApplication::translate("user_information", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\345\267\245\344\275\234\345\215\225\344\275\215:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        sex->setText(QApplication::translate("user_information", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">\346\200\247\345\210\253:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        live_city->setText(QApplication::translate("user_information", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">\346\211\200\345\234\250\345\237\216\345\270\202:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("user_information", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600;\">\350\257\267\345\241\253\345\206\231\347\224\250\346\210\267\344\277\241\346\201\257</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("user_information", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("user_information", "\345\245\263", 0, QApplication::UnicodeUTF8)
        );
        pushButton_2->setText(QApplication::translate("user_information", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("user_information", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class user_information: public Ui_user_information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_INFORMATION_H
