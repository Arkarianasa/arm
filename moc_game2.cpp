/****************************************************************************
** Meta object code from reading C++ file 'game2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "game2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Game2_t {
    QByteArrayData data[16];
    char stringdata[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Game2_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Game2_t qt_meta_stringdata_Game2 = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 10),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 1),
QT_MOC_LITERAL(4, 20, 11),
QT_MOC_LITERAL(5, 32, 9),
QT_MOC_LITERAL(6, 42, 7),
QT_MOC_LITERAL(7, 50, 4),
QT_MOC_LITERAL(8, 55, 4),
QT_MOC_LITERAL(9, 60, 4),
QT_MOC_LITERAL(10, 65, 10),
QT_MOC_LITERAL(11, 76, 11),
QT_MOC_LITERAL(12, 88, 1),
QT_MOC_LITERAL(13, 90, 8),
QT_MOC_LITERAL(14, 99, 4),
QT_MOC_LITERAL(15, 104, 2)
    },
    "Game2\0game_error\0\0e\0game2_start\0"
    "game2_end\0Shuffle\0Play\0Next\0Home\0"
    "ChangeGame\0setPosition\0p\0AutoPlay\0"
    "Dice\0cc\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Game2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06,
       4,    0,   72,    2, 0x06,
       5,    0,   73,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    0,   74,    2, 0x0a,
       7,    0,   75,    2, 0x0a,
       8,    0,   76,    2, 0x0a,
       9,    0,   77,    2, 0x0a,
      10,    0,   78,    2, 0x0a,
      11,    1,   79,    2, 0x0a,
      13,    0,   82,    2, 0x0a,
      14,    1,   83,    2, 0x0a,

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

       0        // eod
};

void Game2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Game2 *_t = static_cast<Game2 *>(_o);
        switch (_id) {
        case 0: _t->game_error((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->game2_start(); break;
        case 2: _t->game2_end(); break;
        case 3: _t->Shuffle(); break;
        case 4: _t->Play(); break;
        case 5: _t->Next(); break;
        case 6: _t->Home(); break;
        case 7: _t->ChangeGame(); break;
        case 8: _t->setPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->AutoPlay(); break;
        case 10: _t->Dice((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Game2::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game2::game_error)) {
                *result = 0;
            }
        }
        {
            typedef void (Game2::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game2::game2_start)) {
                *result = 1;
            }
        }
        {
            typedef void (Game2::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game2::game2_end)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Game2::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Game2.data,
      qt_meta_data_Game2,  qt_static_metacall, 0, 0}
};


const QMetaObject *Game2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Game2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Game2.stringdata))
        return static_cast<void*>(const_cast< Game2*>(this));
    return QThread::qt_metacast(_clname);
}

int Game2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Game2::game_error(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Game2::game2_start()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Game2::game2_end()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
