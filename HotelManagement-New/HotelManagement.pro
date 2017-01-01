#-------------------------------------------------
#
# Project created by QtCreator 2015-05-10T10:46:37
#
#-------------------------------------------------

QT       += core gui
QT       += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HotelManagement
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    user_information.cpp \
    checkout.cpp \
    statistics.cpp \
    price_change.cpp \
    mydatabase.cpp \
    room_management.cpp \
    orderin.cpp \
    order_out.cpp

HEADERS  += mainwindow.h \
    user_information.h \
    checkout.h \
    statistics.h \
    price_change.h \
    mydatabase.h \
    room_management.h \
    orderin.h \
    order_out.h

FORMS    += mainwindow.ui \
    user_information.ui \
    checkout.ui \
    statistics.ui \
    price_change.ui \
    room_management.ui \
    orderin.ui \
    order_out.ui

RESOURCES += \
    image.qrc
