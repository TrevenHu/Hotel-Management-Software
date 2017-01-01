/****************************************************************************
** Meta object code from reading C++ file 'checkout.h'
**
** Created: Thu Jun 11 20:33:37 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../checkout.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'checkout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_checkout[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      27,    9,    9,    9, 0x08,
      49,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_checkout[] = {
    "checkout\0\0on_add_clicked()\0"
    "on_okButton_clicked()\0on_cancellButton_clicked()\0"
};

void checkout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        checkout *_t = static_cast<checkout *>(_o);
        switch (_id) {
        case 0: _t->on_add_clicked(); break;
        case 1: _t->on_okButton_clicked(); break;
        case 2: _t->on_cancellButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData checkout::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject checkout::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_checkout,
      qt_meta_data_checkout, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &checkout::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *checkout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *checkout::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_checkout))
        return static_cast<void*>(const_cast< checkout*>(this));
    return QDialog::qt_metacast(_clname);
}

int checkout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
