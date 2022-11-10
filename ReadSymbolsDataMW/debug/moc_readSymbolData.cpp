/****************************************************************************
** Meta object code from reading C++ file 'readSymbolData.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ReadSymbols/readSymbolData.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'readSymbolData.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_readSymbolData_t {
    QByteArrayData data[16];
    char stringdata0[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_readSymbolData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_readSymbolData_t qt_meta_stringdata_readSymbolData = {
    {
QT_MOC_LITERAL(0, 0, 14), // "readSymbolData"
QT_MOC_LITERAL(1, 15, 19), // "readSymbolsTextFile"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 11), // "loadSymbols"
QT_MOC_LITERAL(4, 48, 4), // "Data"
QT_MOC_LITERAL(5, 53, 18), // "processSymbolsData"
QT_MOC_LITERAL(6, 72, 15), // "readSymbol_SYMB"
QT_MOC_LITERAL(7, 88, 15), // "read_SYM_Symbol"
QT_MOC_LITERAL(8, 104, 8), // "DataList"
QT_MOC_LITERAL(9, 113, 15), // "getSymbolStatus"
QT_MOC_LITERAL(10, 129, 1), // "S"
QT_MOC_LITERAL(11, 131, 15), // "readSymbol_SYMD"
QT_MOC_LITERAL(12, 147, 15), // "readSymbol_SXPO"
QT_MOC_LITERAL(13, 163, 15), // "readSymbol_SCRF"
QT_MOC_LITERAL(14, 179, 15), // "readSymbol_SVCT"
QT_MOC_LITERAL(15, 195, 11) // "InitVectors"

    },
    "readSymbolData\0readSymbolsTextFile\0\0"
    "loadSymbols\0Data\0processSymbolsData\0"
    "readSymbol_SYMB\0read_SYM_Symbol\0"
    "DataList\0getSymbolStatus\0S\0readSymbol_SYMD\0"
    "readSymbol_SXPO\0readSymbol_SCRF\0"
    "readSymbol_SVCT\0InitVectors"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_readSymbolData[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    1,   70,    2, 0x08 /* Private */,
       5,    0,   73,    2, 0x08 /* Private */,
       6,    1,   74,    2, 0x08 /* Private */,
       7,    2,   77,    2, 0x08 /* Private */,
       9,    1,   82,    2, 0x08 /* Private */,
      11,    1,   85,    2, 0x08 /* Private */,
      12,    1,   88,    2, 0x08 /* Private */,
      13,    1,   91,    2, 0x08 /* Private */,
      14,    1,   94,    2, 0x08 /* Private */,
      15,    1,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    4,    8,
    QMetaType::UShort, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void readSymbolData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<readSymbolData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readSymbolsTextFile(); break;
        case 1: _t->loadSymbols((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->processSymbolsData(); break;
        case 3: _t->readSymbol_SYMB((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->read_SYM_Symbol((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 5: { ushort _r = _t->getSymbolStatus((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< ushort*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->readSymbol_SYMD((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->readSymbol_SXPO((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->readSymbol_SCRF((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->readSymbol_SVCT((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->InitVectors((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject readSymbolData::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_readSymbolData.data,
    qt_meta_data_readSymbolData,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *readSymbolData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *readSymbolData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_readSymbolData.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int readSymbolData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
