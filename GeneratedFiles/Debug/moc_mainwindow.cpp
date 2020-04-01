/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_wndMain_t {
    QByteArrayData data[16];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_wndMain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_wndMain_t qt_meta_stringdata_wndMain = {
    {
QT_MOC_LITERAL(0, 0, 7), // "wndMain"
QT_MOC_LITERAL(1, 8, 8), // "generate"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 13), // "addProduction"
QT_MOC_LITERAL(4, 32, 16), // "removeProduction"
QT_MOC_LITERAL(5, 49, 9), // "exportObj"
QT_MOC_LITERAL(6, 59, 11), // "clearCamera"
QT_MOC_LITERAL(7, 71, 4), // "open"
QT_MOC_LITERAL(8, 76, 4), // "save"
QT_MOC_LITERAL(9, 81, 4), // "exit"
QT_MOC_LITERAL(10, 86, 4), // "help"
QT_MOC_LITERAL(11, 91, 19), // "assignBranchTexture"
QT_MOC_LITERAL(12, 111, 17), // "assignLeafTexture"
QT_MOC_LITERAL(13, 129, 8), // "isShadow"
QT_MOC_LITERAL(14, 138, 11), // "isAnimation"
QT_MOC_LITERAL(15, 150, 11) // "isWireframe"

    },
    "wndMain\0generate\0\0addProduction\0"
    "removeProduction\0exportObj\0clearCamera\0"
    "open\0save\0exit\0help\0assignBranchTexture\0"
    "assignLeafTexture\0isShadow\0isAnimation\0"
    "isWireframe"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wndMain[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x0a /* Public */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    1,   95,    2, 0x0a /* Public */,
      14,    1,   98,    2, 0x0a /* Public */,
      15,    1,  101,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void wndMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        wndMain *_t = static_cast<wndMain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->generate(); break;
        case 1: _t->addProduction(); break;
        case 2: _t->removeProduction(); break;
        case 3: _t->exportObj(); break;
        case 4: _t->clearCamera(); break;
        case 5: _t->open(); break;
        case 6: _t->save(); break;
        case 7: _t->exit(); break;
        case 8: _t->help(); break;
        case 9: _t->assignBranchTexture(); break;
        case 10: _t->assignLeafTexture(); break;
        case 11: _t->isShadow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->isAnimation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->isWireframe((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject wndMain::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_wndMain.data,
      qt_meta_data_wndMain,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *wndMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wndMain::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_wndMain.stringdata0))
        return static_cast<void*>(const_cast< wndMain*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int wndMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
