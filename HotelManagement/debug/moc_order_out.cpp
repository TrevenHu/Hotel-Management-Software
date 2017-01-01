/****************************************************************************
** Meta object code from reading C++ file 'order_out.h'
**
** Created: Sat Jun 6 16:08:13 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../order_out.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'order_out.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_order_out[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      28,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_order_out[] = {
    "order_out\0\0on_yes_clicked()\0on_no_clicked()\0"
};

void order_out::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        order_out *_t = static_cast<order_out *>(_o);
        switch (_id) {
        case 0: _t->on_yes_clicked(); break;
        case 1: _t->on_no_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData order_out::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject order_out::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_order_out,
      qt_meta_data_order_out, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &order_out::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *order_out::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *order_out::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_order_out))
        return static_cast<void*>(const_cast< order_out*>(this));
    return QDialog::qt_metacast(_clname);
}

int order_out::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
