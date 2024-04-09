/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Practic/window.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSWindowENDCLASS = QtMocHelpers::stringData(
    "Window",
    "add",
    "",
    "addShow",
    "clear",
    "delEnable",
    "delElem",
    "hall",
    "time",
    "StoreRoom",
    "Graf"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSWindowENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[7];
    char stringdata1[4];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[6];
    char stringdata5[10];
    char stringdata6[8];
    char stringdata7[5];
    char stringdata8[5];
    char stringdata9[10];
    char stringdata10[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSWindowENDCLASS_t qt_meta_stringdata_CLASSWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Window"
        QT_MOC_LITERAL(7, 3),  // "add"
        QT_MOC_LITERAL(11, 0),  // ""
        QT_MOC_LITERAL(12, 7),  // "addShow"
        QT_MOC_LITERAL(20, 5),  // "clear"
        QT_MOC_LITERAL(26, 9),  // "delEnable"
        QT_MOC_LITERAL(36, 7),  // "delElem"
        QT_MOC_LITERAL(44, 4),  // "hall"
        QT_MOC_LITERAL(49, 4),  // "time"
        QT_MOC_LITERAL(54, 9),  // "StoreRoom"
        QT_MOC_LITERAL(64, 4)   // "Graf"
    },
    "Window",
    "add",
    "",
    "addShow",
    "clear",
    "delEnable",
    "delElem",
    "hall",
    "time",
    "StoreRoom",
    "Graf"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    0,   71,    2, 0x08,    4 /* Private */,
       6,    0,   72,    2, 0x08,    5 /* Private */,
       7,    0,   73,    2, 0x08,    6 /* Private */,
       8,    0,   74,    2, 0x08,    7 /* Private */,
       9,    0,   75,    2, 0x08,    8 /* Private */,
      10,    0,   76,    2, 0x08,    9 /* Private */,

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

       0        // eod
};

Q_CONSTINIT const QMetaObject Window::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Window, std::true_type>,
        // method 'add'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addShow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clear'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'delEnable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'delElem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'hall'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'time'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'StoreRoom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Graf'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Window *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->add(); break;
        case 1: _t->addShow(); break;
        case 2: _t->clear(); break;
        case 3: _t->delEnable(); break;
        case 4: _t->delElem(); break;
        case 5: _t->hall(); break;
        case 6: _t->time(); break;
        case 7: _t->StoreRoom(); break;
        case 8: _t->Graf(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
