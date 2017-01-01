/********************************************************************************
** Form generated from reading UI file 'order_out.ui'
**
** Created: Sat Jun 6 16:01:50 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDER_OUT_H
#define UI_ORDER_OUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_order_out
{
public:
    QLabel *label;
    QPushButton *yes;
    QPushButton *no;

    void setupUi(QDialog *order_out)
    {
        if (order_out->objectName().isEmpty())
            order_out->setObjectName(QString::fromUtf8("order_out"));
        order_out->resize(355, 188);
        label = new QLabel(order_out);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 50, 191, 31));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        yes = new QPushButton(order_out);
        yes->setObjectName(QString::fromUtf8("yes"));
        yes->setGeometry(QRect(150, 130, 75, 23));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        yes->setFont(font1);
        no = new QPushButton(order_out);
        no->setObjectName(QString::fromUtf8("no"));
        no->setGeometry(QRect(240, 130, 75, 23));
        no->setFont(font1);

        retranslateUi(order_out);

        QMetaObject::connectSlotsByName(order_out);
    } // setupUi

    void retranslateUi(QDialog *order_out)
    {
        order_out->setWindowTitle(QApplication::translate("order_out", "\351\242\204\345\256\232\351\200\200\346\210\277", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("order_out", "\350\257\267\345\206\215\346\254\241\347\241\256\350\256\244\346\230\257\345\220\246\351\200\200\346\210\277", 0, QApplication::UnicodeUTF8));
        yes->setText(QApplication::translate("order_out", "\346\230\257", 0, QApplication::UnicodeUTF8));
        no->setText(QApplication::translate("order_out", "\345\220\246", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class order_out: public Ui_order_out {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDER_OUT_H
