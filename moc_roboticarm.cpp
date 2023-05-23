/****************************************************************************
** Meta object code from reading C++ file 'roboticarm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "roboticarm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roboticarm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RoboticArm_t {
    QByteArrayData data[22];
    char stringdata[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RoboticArm_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RoboticArm_t qt_meta_stringdata_RoboticArm = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 10),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 1),
QT_MOC_LITERAL(4, 25, 6),
QT_MOC_LITERAL(5, 32, 8),
QT_MOC_LITERAL(6, 41, 8),
QT_MOC_LITERAL(7, 50, 1),
QT_MOC_LITERAL(8, 52, 9),
QT_MOC_LITERAL(9, 62, 8),
QT_MOC_LITERAL(10, 71, 3),
QT_MOC_LITERAL(11, 75, 9),
QT_MOC_LITERAL(12, 85, 7),
QT_MOC_LITERAL(13, 93, 12),
QT_MOC_LITERAL(14, 106, 8),
QT_MOC_LITERAL(15, 115, 13),
QT_MOC_LITERAL(16, 129, 8),
QT_MOC_LITERAL(17, 138, 11),
QT_MOC_LITERAL(18, 150, 6),
QT_MOC_LITERAL(19, 157, 18),
QT_MOC_LITERAL(20, 176, 5),
QT_MOC_LITERAL(21, 182, 12)
    },
    "RoboticArm\0printError\0\0e\0setSld\0"
    "DrawMove\0handText\0i\0rotarText\0diceShow\0"
    "num\0gameStart\0gameEnd\0timerTimeout\0"
    "AutoPlay\0SetAsPosition\0drawGame\0"
    "reloadTrack\0cancel\0setButtonsDrawGame\0"
    "value\0calibrateArm\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RoboticArm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x0a,
       4,    0,   97,    2, 0x0a,
       5,    0,   98,    2, 0x0a,
       6,    1,   99,    2, 0x0a,
       8,    1,  102,    2, 0x0a,
       9,    1,  105,    2, 0x0a,
      11,    0,  108,    2, 0x0a,
      12,    0,  109,    2, 0x0a,
      13,    0,  110,    2, 0x0a,
      14,    0,  111,    2, 0x0a,
      15,    0,  112,    2, 0x0a,
      16,    0,  113,    2, 0x0a,
      17,    0,  114,    2, 0x0a,
      18,    0,  115,    2, 0x0a,
      19,    1,  116,    2, 0x0a,
      21,    0,  119,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void,

       0        // eod
};

void RoboticArm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RoboticArm *_t = static_cast<RoboticArm *>(_o);
        switch (_id) {
        case 0: _t->printError((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setSld(); break;
        case 2: _t->DrawMove(); break;
        case 3: _t->handText((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->rotarText((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->diceShow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->gameStart(); break;
        case 7: _t->gameEnd(); break;
        case 8: _t->timerTimeout(); break;
        case 9: _t->AutoPlay(); break;
        case 10: _t->SetAsPosition(); break;
        case 11: _t->drawGame(); break;
        case 12: _t->reloadTrack(); break;
        case 13: _t->cancel(); break;
        case 14: _t->setButtonsDrawGame((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->calibrateArm(); break;
        default: ;
        }
    }
}

const QMetaObject RoboticArm::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RoboticArm.data,
      qt_meta_data_RoboticArm,  qt_static_metacall, 0, 0}
};


const QMetaObject *RoboticArm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoboticArm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RoboticArm.stringdata))
        return static_cast<void*>(const_cast< RoboticArm*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int RoboticArm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
