/****************************************************************************
** Meta object code from reading C++ file 'OpenCPNS57LookUpTableLibrary.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OpenCPNSymbolsReader/ReadSupportFiles/OpenCPN/OpenCPNS57LookUpTableLibrary.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OpenCPNS57LookUpTableLibrary.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LookupTable_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LookupTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LookupTable_t qt_meta_stringdata_LookupTable = {
    {
QT_MOC_LITERAL(0, 0, 11) // "LookupTable"

    },
    "LookupTable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LookupTable[] = {

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

void LookupTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject LookupTable::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_LookupTable.data,
    qt_meta_data_LookupTable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LookupTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LookupTable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LookupTable.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LookupTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_OpenCPNS57LookUpTableLibrary_t {
    QByteArrayData data[21];
    char stringdata0[333];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OpenCPNS57LookUpTableLibrary_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OpenCPNS57LookUpTableLibrary_t qt_meta_stringdata_OpenCPNS57LookUpTableLibrary = {
    {
QT_MOC_LITERAL(0, 0, 28), // "OpenCPNS57LookUpTableLibrary"
QT_MOC_LITERAL(1, 29, 20), // "appendLookUpTbleData"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 4), // "Type"
QT_MOC_LITERAL(4, 56, 4), // "List"
QT_MOC_LITERAL(5, 61, 5), // "clear"
QT_MOC_LITERAL(6, 67, 21), // "getPlainBoundariesVec"
QT_MOC_LITERAL(7, 89, 20), // "QVector<LookupTable>"
QT_MOC_LITERAL(8, 110, 23), // "getSymbolisedBoundryVec"
QT_MOC_LITERAL(9, 134, 11), // "getLinesVec"
QT_MOC_LITERAL(10, 146, 16), // "getSimplifiedVec"
QT_MOC_LITERAL(11, 163, 16), // "getPaperChartVec"
QT_MOC_LITERAL(12, 180, 24), // "writePlainBoundariesData"
QT_MOC_LITERAL(13, 205, 4), // "path"
QT_MOC_LITERAL(14, 210, 4), // "Name"
QT_MOC_LITERAL(15, 215, 27), // "writesymbolisedBoundaryData"
QT_MOC_LITERAL(16, 243, 14), // "writelinesData"
QT_MOC_LITERAL(17, 258, 19), // "writeSimplifiedData"
QT_MOC_LITERAL(18, 278, 19), // "writepaperChartData"
QT_MOC_LITERAL(19, 298, 26), // "writeLukTblIntoSupportFile"
QT_MOC_LITERAL(20, 325, 7) // "DataVec"

    },
    "OpenCPNS57LookUpTableLibrary\0"
    "appendLookUpTbleData\0\0Type\0List\0clear\0"
    "getPlainBoundariesVec\0QVector<LookupTable>\0"
    "getSymbolisedBoundryVec\0getLinesVec\0"
    "getSimplifiedVec\0getPaperChartVec\0"
    "writePlainBoundariesData\0path\0Name\0"
    "writesymbolisedBoundaryData\0writelinesData\0"
    "writeSimplifiedData\0writepaperChartData\0"
    "writeLukTblIntoSupportFile\0DataVec"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OpenCPNS57LookUpTableLibrary[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x0a /* Public */,
       5,    0,   84,    2, 0x0a /* Public */,
       6,    0,   85,    2, 0x0a /* Public */,
       8,    0,   86,    2, 0x0a /* Public */,
       9,    0,   87,    2, 0x0a /* Public */,
      10,    0,   88,    2, 0x0a /* Public */,
      11,    0,   89,    2, 0x0a /* Public */,
      12,    2,   90,    2, 0x0a /* Public */,
      15,    2,   95,    2, 0x0a /* Public */,
      16,    2,  100,    2, 0x0a /* Public */,
      17,    2,  105,    2, 0x0a /* Public */,
      18,    2,  110,    2, 0x0a /* Public */,
      19,    3,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    3,    4,
    QMetaType::Void,
    0x80000000 | 7,
    0x80000000 | 7,
    0x80000000 | 7,
    0x80000000 | 7,
    0x80000000 | 7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 7,   13,   14,   20,

       0        // eod
};

void OpenCPNS57LookUpTableLibrary::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OpenCPNS57LookUpTableLibrary *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->appendLookUpTbleData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 1: _t->clear(); break;
        case 2: { QVector<LookupTable> _r = _t->getPlainBoundariesVec();
            if (_a[0]) *reinterpret_cast< QVector<LookupTable>*>(_a[0]) = std::move(_r); }  break;
        case 3: { QVector<LookupTable> _r = _t->getSymbolisedBoundryVec();
            if (_a[0]) *reinterpret_cast< QVector<LookupTable>*>(_a[0]) = std::move(_r); }  break;
        case 4: { QVector<LookupTable> _r = _t->getLinesVec();
            if (_a[0]) *reinterpret_cast< QVector<LookupTable>*>(_a[0]) = std::move(_r); }  break;
        case 5: { QVector<LookupTable> _r = _t->getSimplifiedVec();
            if (_a[0]) *reinterpret_cast< QVector<LookupTable>*>(_a[0]) = std::move(_r); }  break;
        case 6: { QVector<LookupTable> _r = _t->getPaperChartVec();
            if (_a[0]) *reinterpret_cast< QVector<LookupTable>*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->writePlainBoundariesData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->writesymbolisedBoundaryData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->writelinesData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->writeSimplifiedData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->writepaperChartData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: _t->writeLukTblIntoSupportFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QVector<LookupTable>(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OpenCPNS57LookUpTableLibrary::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_OpenCPNS57LookUpTableLibrary.data,
    qt_meta_data_OpenCPNS57LookUpTableLibrary,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OpenCPNS57LookUpTableLibrary::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OpenCPNS57LookUpTableLibrary::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OpenCPNS57LookUpTableLibrary.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int OpenCPNS57LookUpTableLibrary::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
