/****************************************************************************
** Meta object code from reading C++ file 'V4S57ColorCalibLib.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ReadSupportFiles/V4S57SupportFiles/V4S57ColorCalibLib.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'V4S57ColorCalibLib.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_V4S57ColorCalibLib_t {
    QByteArrayData data[11];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_V4S57ColorCalibLib_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_V4S57ColorCalibLib_t qt_meta_stringdata_V4S57ColorCalibLib = {
    {
QT_MOC_LITERAL(0, 0, 18), // "V4S57ColorCalibLib"
QT_MOC_LITERAL(1, 19, 20), // "getColorCalibDataMap"
QT_MOC_LITERAL(2, 40, 25), // "QMap<QString,QStringList>"
QT_MOC_LITERAL(3, 66, 0), // ""
QT_MOC_LITERAL(4, 67, 20), // "appendColorCalibData"
QT_MOC_LITERAL(5, 88, 9), // "ColorName"
QT_MOC_LITERAL(6, 98, 4), // "List"
QT_MOC_LITERAL(7, 103, 5), // "clear"
QT_MOC_LITERAL(8, 109, 24), // "writeDataIntoSupportFile"
QT_MOC_LITERAL(9, 134, 4), // "path"
QT_MOC_LITERAL(10, 139, 4) // "Name"

    },
    "V4S57ColorCalibLib\0getColorCalibDataMap\0"
    "QMap<QString,QStringList>\0\0"
    "appendColorCalibData\0ColorName\0List\0"
    "clear\0writeDataIntoSupportFile\0path\0"
    "Name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_V4S57ColorCalibLib[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    3, 0x0a /* Public */,
       4,    2,   35,    3, 0x0a /* Public */,
       7,    0,   40,    3, 0x0a /* Public */,
       8,    2,   41,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,

       0        // eod
};

void V4S57ColorCalibLib::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<V4S57ColorCalibLib *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QMap<QString,QStringList> _r = _t->getColorCalibDataMap();
            if (_a[0]) *reinterpret_cast< QMap<QString,QStringList>*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->appendColorCalibData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 2: _t->clear(); break;
        case 3: _t->writeDataIntoSupportFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject V4S57ColorCalibLib::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_V4S57ColorCalibLib.data,
    qt_meta_data_V4S57ColorCalibLib,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *V4S57ColorCalibLib::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *V4S57ColorCalibLib::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_V4S57ColorCalibLib.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int V4S57ColorCalibLib::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
