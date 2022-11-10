/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tutorial1/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 3), // "pan"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 5), // "delta"
QT_MOC_LITERAL(4, 22, 18), // "readTextLineByLine"
QT_MOC_LITERAL(5, 41, 8), // "QString&"
QT_MOC_LITERAL(6, 50, 4), // "path"
QT_MOC_LITERAL(7, 55, 7), // "Method1"
QT_MOC_LITERAL(8, 63, 25), // "QMap<QString,QStringList>"
QT_MOC_LITERAL(9, 89, 4), // "Data"
QT_MOC_LITERAL(10, 94, 14), // "readSymbolData"
QT_MOC_LITERAL(11, 109, 8), // "DataList"
QT_MOC_LITERAL(12, 118, 12), // "readLineData"
QT_MOC_LITERAL(13, 131, 15), // "readPatternData"
QT_MOC_LITERAL(14, 147, 15), // "getSymbolStatus"
QT_MOC_LITERAL(15, 163, 1), // "S"
QT_MOC_LITERAL(16, 165, 10), // "InitColPal"
QT_MOC_LITERAL(17, 176, 10) // "InitVector"

    },
    "MainWindow\0pan\0\0delta\0readTextLineByLine\0"
    "QString&\0path\0Method1\0QMap<QString,QStringList>\0"
    "Data\0readSymbolData\0DataList\0readLineData\0"
    "readPatternData\0getSymbolStatus\0S\0"
    "InitColPal\0InitVector"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       1,    1,   59,    2, 0x08 /* Private */,
       4,    1,   62,    2, 0x08 /* Private */,
       7,    1,   65,    2, 0x08 /* Private */,
      10,    1,   68,    2, 0x08 /* Private */,
      12,    1,   71,    2, 0x08 /* Private */,
      13,    1,   74,    2, 0x08 /* Private */,
      14,    1,   77,    2, 0x08 /* Private */,
      16,    1,   80,    2, 0x08 /* Private */,
      17,    1,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QStringList,   11,
    QMetaType::Void, QMetaType::QStringList,   11,
    QMetaType::Void, QMetaType::QStringList,   11,
    QMetaType::UShort, 0x80000000 | 5,   15,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pan((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->readTextLineByLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->Method1((*reinterpret_cast< QMap<QString,QStringList>(*)>(_a[1]))); break;
        case 3: _t->readSymbolData((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->readLineData((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 5: _t->readPatternData((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 6: { ushort _r = _t->getSymbolStatus((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< ushort*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->InitColPal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->InitVector((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
