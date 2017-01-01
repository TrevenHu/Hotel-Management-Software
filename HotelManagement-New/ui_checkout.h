/********************************************************************************
** Form generated from reading UI file 'checkout.ui'
**
** Created: Thu Jun 11 20:32:46 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKOUT_H
#define UI_CHECKOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_checkout
{
public:
    QLabel *name;
    QLabel *room_p;
    QLabel *extercharge;
    QLabel *all;
    QLineEdit *exterchargeEdit;
    QLabel *nameEdit;
    QLabel *room_pEdit;
    QLabel *allEdit;
    QLabel *label_5;
    QPushButton *okButton;
    QPushButton *cancellButton;
    QPushButton *add;

    void setupUi(QDialog *checkout)
    {
        if (checkout->objectName().isEmpty())
            checkout->setObjectName(QString::fromUtf8("checkout"));
        checkout->resize(735, 526);
        name = new QLabel(checkout);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(120, 100, 90, 30));
        name->setFrameShape(QFrame::NoFrame);
        name->setFrameShadow(QFrame::Plain);
        room_p = new QLabel(checkout);
        room_p->setObjectName(QString::fromUtf8("room_p"));
        room_p->setGeometry(QRect(120, 180, 90, 30));
        extercharge = new QLabel(checkout);
        extercharge->setObjectName(QString::fromUtf8("extercharge"));
        extercharge->setGeometry(QRect(120, 260, 90, 30));
        all = new QLabel(checkout);
        all->setObjectName(QString::fromUtf8("all"));
        all->setGeometry(QRect(120, 340, 90, 30));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        all->setFont(font);
        exterchargeEdit = new QLineEdit(checkout);
        exterchargeEdit->setObjectName(QString::fromUtf8("exterchargeEdit"));
        exterchargeEdit->setGeometry(QRect(270, 260, 120, 30));
        nameEdit = new QLabel(checkout);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(270, 100, 120, 30));
        nameEdit->setFrameShape(QFrame::Panel);
        nameEdit->setFrameShadow(QFrame::Sunken);
        room_pEdit = new QLabel(checkout);
        room_pEdit->setObjectName(QString::fromUtf8("room_pEdit"));
        room_pEdit->setGeometry(QRect(270, 180, 120, 30));
        room_pEdit->setFrameShape(QFrame::Panel);
        room_pEdit->setFrameShadow(QFrame::Sunken);
        allEdit = new QLabel(checkout);
        allEdit->setObjectName(QString::fromUtf8("allEdit"));
        allEdit->setGeometry(QRect(270, 340, 120, 30));
        allEdit->setFrameShape(QFrame::Panel);
        allEdit->setFrameShadow(QFrame::Sunken);
        label_5 = new QLabel(checkout);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 0, 741, 521));
        label_5->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/1.jpg);"));
        okButton = new QPushButton(checkout);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(520, 470, 75, 23));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        okButton->setFont(font1);
        cancellButton = new QPushButton(checkout);
        cancellButton->setObjectName(QString::fromUtf8("cancellButton"));
        cancellButton->setGeometry(QRect(610, 470, 75, 23));
        cancellButton->setFont(font1);
        add = new QPushButton(checkout);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(400, 260, 61, 30));
        add->setFont(font1);
        label_5->raise();
        name->raise();
        room_p->raise();
        extercharge->raise();
        all->raise();
        exterchargeEdit->raise();
        nameEdit->raise();
        room_pEdit->raise();
        allEdit->raise();
        okButton->raise();
        cancellButton->raise();
        add->raise();

        retranslateUi(checkout);

        QMetaObject::connectSlotsByName(checkout);
    } // setupUi

    void retranslateUi(QDialog *checkout)
    {
        checkout->setWindowTitle(QApplication::translate("checkout", "\347\224\250\346\210\267\351\200\200\346\210\277", 0, QApplication::UnicodeUTF8));
        name->setText(QApplication::translate("checkout", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\345\247\223\345\220\215\357\274\232</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        room_p->setText(QApplication::translate("checkout", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\346\210\277\350\264\271\357\274\232</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        extercharge->setText(QApplication::translate("checkout", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\351\242\235\345\244\226\350\264\271\347\224\250\357\274\232</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        all->setText(QApplication::translate("checkout", "<html><head/><body><p align=\"center\">\346\200\273\350\264\271\347\224\250\357\274\232</p></body></html>", 0, QApplication::UnicodeUTF8));
        nameEdit->setText(QString());
        room_pEdit->setText(QString());
        allEdit->setText(QString());
        label_5->setText(QString());
        okButton->setText(QApplication::translate("checkout", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        cancellButton->setText(QApplication::translate("checkout", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        add->setText(QApplication::translate("checkout", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class checkout: public Ui_checkout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUT_H
