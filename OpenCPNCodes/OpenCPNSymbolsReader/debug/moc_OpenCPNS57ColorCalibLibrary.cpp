/****************************************************************************
** Meta object code from reading C++ file 'OpenCPNS57ColorCalibLibrary.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ReadSupportFiles/OpenCPN/OpenCPNS57ColorCalibLibrary.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OpenCPNS57ColorCalibLibrary.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rgbPoint_t {
    QByteArrayData data[20];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rgbPoint_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rgbPoint_t qt_meta_stringdata_rgbPoint = {
    {
QT_MOC_LITERAL(0, 0, 8), // "rgbPoint"
QT_MOC_LITERAL(1, 9, 10), // "getSymName"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9), // "getRValue"
QT_MOC_LITERAL(4, 31, 9), // "getGValue"
QT_MOC_LITERAL(5, 41, 9), // "getBValue"
QT_MOC_LITERAL(6, 51, 10), // "getClrName"
QT_MOC_LITERAL(7, 62, 10), // "setSymName"
QT_MOC_LITERAL(8, 73, 1), // "S"
QT_MOC_LITERAL(9, 75, 9), // "setRValue"
QT_MOC_LITERAL(10, 85, 1), // "r"
QT_MOC_LITERAL(11, 87, 9), // "setGValue"
QT_MOC_LITERAL(12, 97, 1), // "g"
QT_MOC_LITERAL(13, 99, 9), // "setBValue"
QT_MOC_LITERAL(14, 109, 1), // "b"
QT_MOC_LITERAL(15, 111, 10), // "setClrName"
QT_MOC_LITERAL(16, 122, 7), // "setData"
QT_MOC_LITERAL(17, 130, 7), // "SymName"
QT_MOC_LITERAL(18, 138, 7), // "ClrName"
QT_MOC_LITERAL(19, 146, 5) // "clear"

    },
    "rgbPoint\0getSymName\0\0getRValue\0getGValue\0"
    "getBValue\0getClrName\0setSymName\0S\0"
    "setRValue\0r\0setGValue\0g\0setBValue\0b\0"
    "setClrName\0setData\0SymName\0ClrName\0"
    "clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rgbPoint[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    0,   78,    2, 0x0a /* Public */,
       7,    1,   79,    2, 0x0a /* Public */,
       9,    1,   82,    2, 0x0a /* Public */,
      11,    1,   85,    2, 0x0a /* Public */,
      13,    1,   88,    2, 0x0a /* Public */,
      15,    1,   91,    2, 0x0a /* Public */,
      16,    5,   94,    2, 0x0a /* Public */,
      19,    0,  105,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QString,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QString,   17,   10,   12,   14,   18,
    QMetaType::Void,

       0        // eod
};

void rgbPoint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<rgbPoint *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->getSymName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { double _r = _t->getRValue();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 2: { double _r = _t->getGValue();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 3: { double _r = _t->getBValue();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->getClrName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->setSymName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setRValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->setGValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->setBValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->setClrName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->setData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 11: _t->clear(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject rgbPoint::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_rgbPoint.data,
    qt_meta_data_rgbPoint,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *rgbPoint::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rgbPoint::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rgbPoint.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int rgbPoint::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
struct qt_meta_stringdata_rgbStructure_t {
    QByteArrayData data[1];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rgbStructure_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rgbStructure_t qt_meta_stringdata_rgbStructure = {
    {
QT_MOC_LITERAL(0, 0, 12) // "rgbStructure"

    },
    "rgbStructure"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rgbStructure[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void rgbStructure::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject rgbStructure::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_rgbStructure.data,
    qt_meta_data_rgbStructure,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *rgbStructure::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rgbStructure::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rgbStructure.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int rgbStructure::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_OpenCPNS57ColorCalibLibrary_t {
    QByteArrayData data[11];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OpenCPNS57ColorCalibLibrary_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OpenCPNS57ColorCalibLibrary_t qt_meta_stringdata_OpenCPNS57ColorCalibLibrary = {
    {
QT_MOC_LITERAL(0, 0, 27), // "OpenCPNS57ColorCalibLibrary"
QT_MOC_LITERAL(1, 28, 20), // "getColorCalibDataMap"
QT_MOC_LITERAL(2, 49, 25), // "QMap<QString,QStringList>"
QT_MOC_LITERAL(3, 75, 0), // ""
QT_MOC_LITERAL(4, 76, 20), // "appendColorCalibData"
QT_MOC_LITERAL(5, 97, 9), // "ColorName"
QT_MOC_LITERAL(6, 107, 4), // "List"
QT_MOC_LITERAL(7, 112, 5), // "clear"
QT_MOC_LITERAL(8, 118, 24), // "writeDataIntoSupportFile"
QT_MOC_LITERAL(9, 143, 4), // "path"
QT_MOC_LITERAL(10, 148, 4) // "Name"

    },
    "OpenCPNS57ColorCalibLibrary\0"
    "getColorCalibDataMap\0QMap<QString,QStringList>\0"
    "\0appendColorCalibData\0ColorName\0List\0"
    "clear\0writeDataIntoSupportFile\0path\0"
    "Name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OpenCPNS57ColorCalibLibrary[] = {

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

void OpenCPNS57ColorCalibLibrary::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OpenCPNS57ColorCalibLibrary *>(_o);
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

QT_INIT_METAOBJECT const QMetaObject OpenCPNS57ColorCalibLibrary::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_OpenCPNS57ColorCalibLibrary.data,
    qt_meta_data_OpenCPNS57ColorCalibLibrary,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OpenCPNS57ColorCalibLibrary::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OpenCPNS57ColorCalibLibrary::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OpenCPNS57ColorCalibLibrary.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int OpenCPNS57ColorCalibLibrary::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
