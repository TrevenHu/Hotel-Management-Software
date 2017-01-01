/********************************************************************************
** Form generated from reading UI file 'orderin.ui'
**
** Created: Sun May 17 20:39:47 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERIN_H
#define UI_ORDERIN_H

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

class Ui_orderin
{
public:
    QLabel *label;
    QLineEdit *idEdit;
    QPushButton *ok;
    QPushButton *pushButton_2;

    void setupUi(QDialog *orderin)
    {
        if (orderin->objectName().isEmpty())
            orderin->setObjectName(QString::fromUtf8("orderin"));
        orderin->resize(400, 178);
        label = new QLabel(orderin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 60, 111, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        idEdit = new QLineEdit(orderin);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));
        idEdit->setGeometry(QRect(140, 60, 171, 20));
        ok = new QPushButton(orderin);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(220, 140, 75, 23));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        ok->setFont(font1);
        pushButton_2 = new QPushButton(orderin);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 140, 75, 23));
        pushButton_2->setFont(font1);

        retranslateUi(orderin);

        QMetaObject::connectSlotsByName(orderin);
    } // setupUi

    void retranslateUi(QDialog *orderin)
    {
        orderin->setWindowTitle(QApplication::translate("orderin", "\345\205\245\344\275\217\351\252\214\350\257\201", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("orderin", "\350\257\267\350\276\223\345\205\245\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        ok->setText(QApplication::translate("orderin", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("orderin", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class orderin: public Ui_orderin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERIN_H
