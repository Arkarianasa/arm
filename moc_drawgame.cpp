/****************************************************************************
** Meta object code from reading C++ file 'drawgame.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "drawgame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drawgame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DrawGame_t {
    QByteArrayData data[19];
    char stringdata[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_DrawGame_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_DrawGame_t qt_meta_stringdata_DrawGame = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 14),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 1),
QT_MOC_LITERAL(4, 27, 14),
QT_MOC_LITERAL(5, 42, 12),
QT_MOC_LITERAL(6, 55, 7),
QT_MOC_LITERAL(7, 63, 4),
QT_MOC_LITERAL(8, 68, 4),
QT_MOC_LITERAL(9, 73, 4),
QT_MOC_LITERAL(10, 78, 10),
QT_MOC_LITERAL(11, 89, 11),
QT_MOC_LITERAL(12, 101, 1),
QT_MOC_LITERAL(13, 103, 8),
QT_MOC_LITERAL(14, 112, 4),
QT_MOC_LITERAL(15, 117, 2),
QT_MOC_LITERAL(16, 120, 10),
QT_MOC_LITERAL(17, 131, 11),
QT_MOC_LITERAL(18, 143, 15)
    },
    "DrawGame\0drawGame_error\0\0e\0drawGame_start\0"
    "drawGame_end\0Shuffle\0Play\0Next\0Home\0"
    "ChangeGame\0setPosition\0p\0AutoPlay\0"
    "Dice\0cc\0loadPoints\0defaultPath\0"
    "calculatePoints\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawGame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06,
       4,    0,   82,    2, 0x06,
       5,    0,   83,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    0,   84,    2, 0x0a,
       7,    0,   85,    2, 0x0a,
       8,    0,   86,    2, 0x0a,
       9,    0,   87,    2, 0x0a,
      10,    0,   88,    2, 0x0a,
      11,    1,   89,    2, 0x0a,
      13,    0,   92,    2, 0x0a,
      14,    1,   93,    2, 0x0a,
      16,    1,   96,    2, 0x0a,
      18,    1,   99,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,

       0        // eod
};

void DrawGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DrawGame *_t = static_cast<DrawGame *>(_o);
        switch (_id) {
        case 0: _t->drawGame_error((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->drawGame_start(); break;
        case 2: _t->drawGame_end(); break;
        case 3: _t->Shuffle(); break;
        case 4: _t->Play(); break;
        case 5: _t->Next(); break;
        case 6: _t->Home(); break;
        case 7: _t->ChangeGame(); break;
        case 8: _t->setPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->AutoPlay(); break;
        case 10: _t->Dice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->loadPoints((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->calculatePoints((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DrawGame::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DrawGame::drawGame_error)) {
                *result = 0;
            }
        }
        {
            typedef void (DrawGame::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DrawGame::drawGame_start)) {
                *result = 1;
            }
        }
        {
            typedef void (DrawGame::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DrawGame::drawGame_end)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject DrawGame::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DrawGame.data,
      qt_meta_data_DrawGame,  qt_static_metacall, 0, 0}
};


const QMetaObject *DrawGame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawGame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DrawGame.stringdata))
        return static_cast<void*>(const_cast< DrawGame*>(this));
    return QThread::qt_metacast(_clname);
}

int DrawGame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void DrawGame::drawGame_error(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DrawGame::drawGame_start()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void DrawGame::drawGame_end()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
