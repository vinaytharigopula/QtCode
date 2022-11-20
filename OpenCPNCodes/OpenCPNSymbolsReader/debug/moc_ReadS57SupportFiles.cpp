/****************************************************************************
** Meta object code from reading C++ file 'ReadS57SupportFiles.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ReadSupportFiles/S57Support/ReadS57SupportFiles.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ReadS57SupportFiles.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ReadS57SupportFiles_t {
    QByteArrayData data[19];
    char stringdata0[323];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReadS57SupportFiles_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReadS57SupportFiles_t qt_meta_stringdata_ReadS57SupportFiles = {
    {
QT_MOC_LITERAL(0, 0, 19), // "ReadS57SupportFiles"
QT_MOC_LITERAL(1, 20, 18), // "readS57SymbolsFile"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 13), // "getS57Symbols"
QT_MOC_LITERAL(4, 54, 25), // "QMap<QString,QStringList>"
QT_MOC_LITERAL(5, 80, 21), // "getS57InstructionData"
QT_MOC_LITERAL(6, 102, 27), // "QMap<QString,SymbolAllData>"
QT_MOC_LITERAL(7, 130, 15), // "processLineData"
QT_MOC_LITERAL(8, 146, 4), // "Data"
QT_MOC_LITERAL(9, 151, 14), // "initialiseData"
QT_MOC_LITERAL(10, 166, 3), // "Sym"
QT_MOC_LITERAL(11, 170, 3), // "lst"
QT_MOC_LITERAL(12, 174, 23), // "processSymbolVectorData"
QT_MOC_LITERAL(13, 198, 8), // "DataList"
QT_MOC_LITERAL(14, 207, 10), // "multiplePd"
QT_MOC_LITERAL(15, 218, 20), // "saveDataInSymbolData"
QT_MOC_LITERAL(16, 239, 31), // "processSymbolIdentificationData"
QT_MOC_LITERAL(17, 271, 27), // "processSymbolExpositionData"
QT_MOC_LITERAL(18, 299, 23) // "processSymbolColRefData"

    },
    "ReadS57SupportFiles\0readS57SymbolsFile\0"
    "\0getS57Symbols\0QMap<QString,QStringList>\0"
    "getS57InstructionData\0QMap<QString,SymbolAllData>\0"
    "processLineData\0Data\0initialiseData\0"
    "Sym\0lst\0processSymbolVectorData\0"
    "DataList\0multiplePd\0saveDataInSymbolData\0"
    "processSymbolIdentificationData\0"
    "processSymbolExpositionData\0"
    "processSymbolColRefData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReadS57SupportFiles[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       5,    0,   66,    2, 0x0a /* Public */,
       7,    1,   67,    2, 0x08 /* Private */,
       9,    2,   70,    2, 0x08 /* Private */,
      12,    2,   75,    2, 0x08 /* Private */,
      15,    0,   80,    2, 0x08 /* Private */,
      16,    1,   81,    2, 0x08 /* Private */,
      17,    1,   84,    2, 0x08 /* Private */,
      18,    1,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    0x80000000 | 4,
    0x80000000 | 6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,   10,   11,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Bool,   13,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void ReadS57SupportFiles::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ReadS57SupportFiles *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readS57SymbolsFile(); break;
        case 1: { QMap<QString,QStringList> _r = _t->getS57Symbols();
            if (_a[0]) *reinterpret_cast< QMap<QString,QStringList>*>(_a[0]) = std::move(_r); }  break;
        case 2: { QMap<QString,SymbolAllData> _r = _t->getS57InstructionData();
            if (_a[0]) *reinterpret_cast< QMap<QString,SymbolAllData>*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->processLineData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->initialiseData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 5: _t->processSymbolVectorData((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->saveDataInSymbolData(); break;
        case 7: _t->processSymbolIdentificationData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->processSymbolExpositionData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->processSymbolColRefData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ReadS57SupportFiles::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ReadS57SupportFiles.data,
    qt_meta_data_ReadS57SupportFiles,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ReadS57SupportFiles::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReadS57SupportFiles::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ReadS57SupportFiles.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ReadS57SupportFiles::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
