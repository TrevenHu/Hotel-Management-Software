/********************************************************************************
** Form generated from reading UI file 'price_change.ui'
**
** Created: Thu Jun 11 20:32:46 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRICE_CHANGE_H
#define UI_PRICE_CHANGE_H

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

class Ui_price_change
{
public:
    QLabel *choice;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QLineEdit *pricelineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *price_change)
    {
        if (price_change->objectName().isEmpty())
            price_change->setObjectName(QString::fromUtf8("price_change"));
        price_change->resize(700, 477);
        choice = new QLabel(price_change);
        choice->setObjectName(QString::fromUtf8("choice"));
        choice->setGeometry(QRect(110, 130, 131, 20));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        choice->setFont(font);
        choice->setFrameShape(QFrame::NoFrame);
        choice->setFrameShadow(QFrame::Plain);
        label = new QLabel(price_change);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 731, 481));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/1.jpg);"));
        comboBox = new QComboBox(price_change);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(246, 130, 101, 20));
        label_2 = new QLabel(price_change);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 210, 120, 40));
        label_2->setFont(font);
        pricelineEdit = new QLineEdit(price_change);
        pricelineEdit->setObjectName(QString::fromUtf8("pricelineEdit"));
        pricelineEdit->setGeometry(QRect(245, 220, 104, 20));
        pushButton = new QPushButton(price_change);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(440, 370, 80, 30));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton->setFont(font2);
        pushButton_2 = new QPushButton(price_change);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(550, 370, 80, 30));
        pushButton_2->setFont(font2);
        label->raise();
        choice->raise();
        comboBox->raise();
        label_2->raise();
        pricelineEdit->raise();
        pushButton->raise();
        pushButton_2->raise();

        retranslateUi(price_change);

        QMetaObject::connectSlotsByName(price_change);
    } // setupUi

    void retranslateUi(QDialog *price_change)
    {
        price_change->setWindowTitle(QApplication::translate("price_change", "\344\277\256\346\224\271\346\210\277\344\273\267", 0, QApplication::UnicodeUTF8));
        choice->setText(QApplication::translate("price_change", "\350\257\267\351\200\211\346\213\251\347\261\273\345\236\213\346\210\277\357\274\232", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("price_change", "\345\215\225\344\272\272\351\227\264", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("price_change", "\345\217\214\344\272\272\351\227\264", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("price_change", "\350\261\252\345\215\216\351\227\264", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("price_change", "\350\261\252\345\215\216\345\245\227\346\210\277", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("price_change", "\350\257\267\350\276\223\345\205\245\346\226\260\346\210\277\344\273\267\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("price_change", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("price_change", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class price_change: public Ui_price_change {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRICE_CHANGE_H
