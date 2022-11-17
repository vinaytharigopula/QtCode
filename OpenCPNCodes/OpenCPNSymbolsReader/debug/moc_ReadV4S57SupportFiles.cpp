/****************************************************************************
** Meta object code from reading C++ file 'ReadV4S57SupportFiles.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ReadSupportFiles/V4S57SupportFiles/ReadV4S57SupportFiles.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ReadV4S57SupportFiles.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ReadV4S57SupportFiles_t {
    QByteArrayData data[7];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReadV4S57SupportFiles_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReadV4S57SupportFiles_t qt_meta_stringdata_ReadV4S57SupportFiles = {
    {
QT_MOC_LITERAL(0, 0, 21), // "ReadV4S57SupportFiles"
QT_MOC_LITERAL(1, 22, 25), // "readVersion4_S57Data_File"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 15), // "processLineData"
QT_MOC_LITERAL(4, 65, 4), // "Data"
QT_MOC_LITERAL(5, 70, 28), // "categoriseDataBasedOnCommand"
QT_MOC_LITERAL(6, 99, 8) // "DataList"

    },
    "ReadV4S57SupportFiles\0readVersion4_S57Data_File\0"
    "\0processLineData\0Data\0"
    "categoriseDataBasedOnCommand\0DataList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReadV4S57SupportFiles[] = {

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
       3,    1,   30,    2, 0x08 /* Private */,
       5,    1,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QStringList,    6,

       0        // eod
};

void ReadV4S57SupportFiles::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ReadV4S57SupportFiles *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readVersion4_S57Data_File(); break;
        case 1: _t->processLineData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->categoriseDataBasedOnCommand((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ReadV4S57SupportFiles::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ReadV4S57SupportFiles.data,
    qt_meta_data_ReadV4S57SupportFiles,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ReadV4S57SupportFiles::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReadV4S57SupportFiles::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ReadV4S57SupportFiles.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ReadV4S57SupportFiles::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
