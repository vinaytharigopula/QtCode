/****************************************************************************
** Meta object code from reading C++ file 'S57DrawSymbols.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DrawLogic/DrawSymbols/S57DrawSymbols.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'S57DrawSymbols.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_S57DrawSymbols_t {
    QByteArrayData data[10];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_S57DrawSymbols_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_S57DrawSymbols_t qt_meta_stringdata_S57DrawSymbols = {
    {
QT_MOC_LITERAL(0, 0, 14), // "S57DrawSymbols"
QT_MOC_LITERAL(1, 15, 13), // "setSymbolData"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 25), // "QMap<QString,QStringList>"
QT_MOC_LITERAL(4, 56, 4), // "Data"
QT_MOC_LITERAL(5, 61, 5), // "paint"
QT_MOC_LITERAL(6, 67, 12), // "QPaintEvent*"
QT_MOC_LITERAL(7, 80, 5), // "event"
QT_MOC_LITERAL(8, 86, 9), // "QPainter*"
QT_MOC_LITERAL(9, 96, 7) // "painter"

    },
    "S57DrawSymbols\0setSymbolData\0\0"
    "QMap<QString,QStringList>\0Data\0paint\0"
    "QPaintEvent*\0event\0QPainter*\0painter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_S57DrawSymbols[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       5,    2,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,

       0        // eod
};

void S57DrawSymbols::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<S57DrawSymbols *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setSymbolData((*reinterpret_cast< QMap<QString,QStringList>(*)>(_a[1]))); break;
        case 1: _t->paint((*reinterpret_cast< QPaintEvent*(*)>(_a[1])),(*reinterpret_cast< QPainter*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject S57DrawSymbols::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_S57DrawSymbols.data,
    qt_meta_data_S57DrawSymbols,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *S57DrawSymbols::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *S57DrawSymbols::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_S57DrawSymbols.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int S57DrawSymbols::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
