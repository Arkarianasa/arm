/****************************************************************************
** Meta object code from reading C++ file 'senddata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "senddata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'senddata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SendData_t {
    QByteArrayData data[32];
    char stringdata[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SendData_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SendData_t qt_meta_stringdata_SendData = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 5),
QT_MOC_LITERAL(2, 15, 0),
QT_MOC_LITERAL(3, 16, 1),
QT_MOC_LITERAL(4, 18, 9),
QT_MOC_LITERAL(5, 28, 3),
QT_MOC_LITERAL(6, 32, 9),
QT_MOC_LITERAL(7, 42, 9),
QT_MOC_LITERAL(8, 52, 9),
QT_MOC_LITERAL(9, 62, 9),
QT_MOC_LITERAL(10, 72, 9),
QT_MOC_LITERAL(11, 82, 9),
QT_MOC_LITERAL(12, 92, 7),
QT_MOC_LITERAL(13, 100, 4),
QT_MOC_LITERAL(14, 105, 4),
QT_MOC_LITERAL(15, 110, 1),
QT_MOC_LITERAL(16, 112, 4),
QT_MOC_LITERAL(17, 117, 1),
QT_MOC_LITERAL(18, 119, 4),
QT_MOC_LITERAL(19, 124, 1),
QT_MOC_LITERAL(20, 126, 8),
QT_MOC_LITERAL(21, 135, 1),
QT_MOC_LITERAL(22, 137, 7),
QT_MOC_LITERAL(23, 145, 13),
QT_MOC_LITERAL(24, 159, 5),
QT_MOC_LITERAL(25, 165, 4),
QT_MOC_LITERAL(26, 170, 4),
QT_MOC_LITERAL(27, 175, 8),
QT_MOC_LITERAL(28, 184, 8),
QT_MOC_LITERAL(29, 193, 10),
QT_MOC_LITERAL(30, 204, 7),
QT_MOC_LITERAL(31, 212, 3)
    },
    "SendData\0Error\0\0e\0SendAngle\0val\0"
    "setServo1\0setServo2\0setServo3\0setServo4\0"
    "setServo5\0setServo0\0setTime\0time\0setX\0"
    "x\0setY\0y\0setZ\0z\0setAngle\0a\0moveXYZ\0"
    "PrepareSerial\0char*\0port\0baud\0CheckRun\0"
    "GetAngle\0ReadFromFD\0lRecBuf\0aFD\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SendData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    1,  107,    2, 0x0a,
       6,    0,  110,    2, 0x0a,
       7,    0,  111,    2, 0x0a,
       8,    0,  112,    2, 0x0a,
       9,    0,  113,    2, 0x0a,
      10,    0,  114,    2, 0x0a,
      11,    0,  115,    2, 0x0a,
      12,    1,  116,    2, 0x0a,
      14,    1,  119,    2, 0x0a,
      16,    1,  122,    2, 0x0a,
      18,    1,  125,    2, 0x0a,
      20,    1,  128,    2, 0x0a,
      22,    0,  131,    2, 0x0a,
      23,    2,  132,    2, 0x08,
      27,    0,  137,    2, 0x08,
      28,    2,  138,    2, 0x08,
      29,    2,  143,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Int,
    QMetaType::Int, 0x80000000 | 24, QMetaType::Long,   25,   26,
    QMetaType::Bool,
    QMetaType::Double, QMetaType::Int, QMetaType::Double,   21,    5,
    QMetaType::Void, 0x80000000 | 24, QMetaType::Int,   30,   31,

       0        // eod
};

void SendData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SendData *_t = static_cast<SendData *>(_o);
        switch (_id) {
        case 0: _t->Error((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->SendAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setServo1(); break;
        case 3: _t->setServo2(); break;
        case 4: _t->setServo3(); break;
        case 5: _t->setServo4(); break;
        case 6: _t->setServo5(); break;
        case 7: _t->setServo0(); break;
        case 8: _t->setTime((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->setX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->setZ((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: { int _r = _t->moveXYZ();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 14: { int _r = _t->PrepareSerial((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 15: { bool _r = _t->CheckRun();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 16: { double _r = _t->GetAngle((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 17: _t->ReadFromFD((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SendData::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SendData::Error)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SendData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SendData.data,
      qt_meta_data_SendData,  qt_static_metacall, 0, 0}
};


const QMetaObject *SendData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SendData::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SendData.stringdata))
        return static_cast<void*>(const_cast< SendData*>(this));
    return QObject::qt_metacast(_clname);
}

int SendData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void SendData::Error(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
