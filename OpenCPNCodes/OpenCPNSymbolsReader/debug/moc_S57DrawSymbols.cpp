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
    QByteArrayData data[25];
    char stringdata0[318];
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
QT_MOC_LITERAL(5, 61, 25), // "setS57SymbolInstrnDataMap"
QT_MOC_LITERAL(6, 87, 27), // "QMap<QString,SymbolAllData>"
QT_MOC_LITERAL(7, 115, 9), // "SymInstrn"
QT_MOC_LITERAL(8, 125, 5), // "paint"
QT_MOC_LITERAL(9, 131, 12), // "QPaintEvent*"
QT_MOC_LITERAL(10, 144, 5), // "event"
QT_MOC_LITERAL(11, 150, 9), // "QPainter*"
QT_MOC_LITERAL(12, 160, 7), // "painter"
QT_MOC_LITERAL(13, 168, 6), // "Symbol"
QT_MOC_LITERAL(14, 175, 23), // "processSymbolInstrnData"
QT_MOC_LITERAL(15, 199, 13), // "SymbolAllData"
QT_MOC_LITERAL(16, 213, 13), // "SymInstrnData"
QT_MOC_LITERAL(17, 227, 10), // "onDrawLine"
QT_MOC_LITERAL(18, 238, 12), // "SymVectrData"
QT_MOC_LITERAL(19, 251, 7), // "VecData"
QT_MOC_LITERAL(20, 259, 13), // "onDrawPolygon"
QT_MOC_LITERAL(21, 273, 12), // "onDrawCircle"
QT_MOC_LITERAL(22, 286, 9), // "onDrawArc"
QT_MOC_LITERAL(23, 296, 19), // "scaleTheCoordinates"
QT_MOC_LITERAL(24, 316, 1) // "P"

    },
    "S57DrawSymbols\0setSymbolData\0\0"
    "QMap<QString,QStringList>\0Data\0"
    "setS57SymbolInstrnDataMap\0"
    "QMap<QString,SymbolAllData>\0SymInstrn\0"
    "paint\0QPaintEvent*\0event\0QPainter*\0"
    "painter\0Symbol\0processSymbolInstrnData\0"
    "SymbolAllData\0SymInstrnData\0onDrawLine\0"
    "SymVectrData\0VecData\0onDrawPolygon\0"
    "onDrawCircle\0onDrawArc\0scaleTheCoordinates\0"
    "P"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_S57DrawSymbols[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       5,    1,   62,    2, 0x0a /* Public */,
       8,    3,   65,    2, 0x0a /* Public */,
      14,    4,   72,    2, 0x08 /* Private */,
      17,    3,   81,    2, 0x08 /* Private */,
      20,    3,   88,    2, 0x08 /* Private */,
      21,    3,   95,    2, 0x08 /* Private */,
      22,    3,  102,    2, 0x08 /* Private */,
      23,    1,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 11, QMetaType::QString,   10,   12,   13,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 15, 0x80000000 | 9, 0x80000000 | 11,   13,   16,   10,   12,
    QMetaType::Void, 0x80000000 | 18, 0x80000000 | 9, 0x80000000 | 11,   19,   10,   12,
    QMetaType::Void, 0x80000000 | 18, 0x80000000 | 9, 0x80000000 | 11,   19,   10,   12,
    QMetaType::Void, 0x80000000 | 18, 0x80000000 | 9, 0x80000000 | 11,   19,   10,   12,
    QMetaType::Void, 0x80000000 | 18, 0x80000000 | 9, 0x80000000 | 11,   19,   10,   12,
    QMetaType::QPointF, QMetaType::QPointF,   24,

       0        // eod
};

void S57DrawSymbols::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<S57DrawSymbols *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setSymbolData((*reinterpret_cast< QMap<QString,QStringList>(*)>(_a[1]))); break;
        case 1: _t->setS57SymbolInstrnDataMap((*reinterpret_cast< QMap<QString,SymbolAllData>(*)>(_a[1]))); break;
        case 2: _t->paint((*reinterpret_cast< QPaintEvent*(*)>(_a[1])),(*reinterpret_cast< QPainter*(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->processSymbolInstrnData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< SymbolAllData(*)>(_a[2])),(*reinterpret_cast< QPaintEvent*(*)>(_a[3])),(*reinterpret_cast< QPainter*(*)>(_a[4]))); break;
        case 4: _t->onDrawLine((*reinterpret_cast< SymVectrData(*)>(_a[1])),(*reinterpret_cast< QPaintEvent*(*)>(_a[2])),(*reinterpret_cast< QPainter*(*)>(_a[3]))); break;
        case 5: _t->onDrawPolygon((*reinterpret_cast< SymVectrData(*)>(_a[1])),(*reinterpret_cast< QPaintEvent*(*)>(_a[2])),(*reinterpret_cast< QPainter*(*)>(_a[3]))); break;
        case 6: _t->onDrawCircle((*reinterpret_cast< SymVectrData(*)>(_a[1])),(*reinterpret_cast< QPaintEvent*(*)>(_a[2])),(*reinterpret_cast< QPainter*(*)>(_a[3]))); break;
        case 7: _t->onDrawArc((*reinterpret_cast< SymVectrData(*)>(_a[1])),(*reinterpret_cast< QPaintEvent*(*)>(_a[2])),(*reinterpret_cast< QPainter*(*)>(_a[3]))); break;
        case 8: { QPointF _r = _t->scaleTheCoordinates((*reinterpret_cast< QPointF(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPointF*>(_a[0]) = std::move(_r); }  break;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
