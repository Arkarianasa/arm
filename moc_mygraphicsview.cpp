/****************************************************************************
** Meta object code from reading C++ file 'mygraphicsview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mygraphicsview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygraphicsview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyGraphicsView_t {
    QByteArrayData data[8];
    char stringdata[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MyGraphicsView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MyGraphicsView_t qt_meta_stringdata_MyGraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 6),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 13),
QT_MOC_LITERAL(4, 37, 1),
QT_MOC_LITERAL(5, 39, 14),
QT_MOC_LITERAL(6, 54, 25),
QT_MOC_LITERAL(7, 80, 5)
    },
    "MyGraphicsView\0newPos\0\0clicked_pitch\0"
    "n\0mouseMoveEvent\0QGraphicsSceneMouseEvent*\0"
    "event\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGraphicsView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06,
       3,    1,   30,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    1,   33,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void MyGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyGraphicsView *_t = static_cast<MyGraphicsView *>(_o);
        switch (_id) {
        case 0: _t->newPos(); break;
        case 1: { int _r = _t->clicked_pitch((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: _t->mouseMoveEvent((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyGraphicsView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGraphicsView::newPos)) {
                *result = 0;
            }
        }
        {
            typedef int (MyGraphicsView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGraphicsView::clicked_pitch)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MyGraphicsView::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_MyGraphicsView.data,
      qt_meta_data_MyGraphicsView,  qt_static_metacall, 0, 0}
};


const QMetaObject *MyGraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyGraphicsView.stringdata))
        return static_cast<void*>(const_cast< MyGraphicsView*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int MyGraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void MyGraphicsView::newPos()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
int MyGraphicsView::clicked_pitch(int _t1)
{
    int _t0 = int();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
