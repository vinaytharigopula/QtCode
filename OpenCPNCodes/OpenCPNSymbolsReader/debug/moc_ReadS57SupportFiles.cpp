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
    QByteArrayData data[7];
    char stringdata0[101];
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
QT_MOC_LITERAL(5, 80, 15), // "processLineData"
QT_MOC_LITERAL(6, 96, 4) // "Data"

    },
    "ReadS57SupportFiles\0readS57SymbolsFile\0"
    "\0getS57Symbols\0QMap<QString,QStringList>\0"
    "processLineData\0Data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReadS57SupportFiles[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       5,    1,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    0x80000000 | 4,
    QMetaType::Void, QMetaType::QString,    6,

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
        case 2: _t->processLineData((*reinterpret_cast< QString(*)>(_a[1]))); break;
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
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
