/****************************************************************************
** Meta object code from reading C++ file 'App.h'
**
** Created: Wed Dec 21 20:00:43 2011
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../nanoweb/src/apps/App.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'App.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__App[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x05,
      49,   10,    9,    9, 0x05,
      80,    9,    9,    9, 0x05,
      99,    9,    9,    9, 0x05,
     125,  119,    9,    9, 0x05,
     147,    9,    9,    9, 0x05,
     168,    9,    9,    9, 0x05,
     187,    9,    9,    9, 0x05,
     209,    9,    9,    9, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ipn__App[] = {
    "ipn::App\0\0delta\0pinchRotationAngleChanged(qreal)\0"
    "pinchScaleFactorChanged(qreal)\0"
    "pinchInTriggered()\0pinchOutTriggered()\0"
    "angle\0swipeTriggered(qreal)\0"
    "swipeLeftTriggered()\0swipeUpTriggered()\0"
    "swipeRightTriggered()\0swipeDownTriggered()\0"
};

void ipn::App::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        App *_t = static_cast<App *>(_o);
        switch (_id) {
        case 0: _t->pinchRotationAngleChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 1: _t->pinchScaleFactorChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 2: _t->pinchInTriggered(); break;
        case 3: _t->pinchOutTriggered(); break;
        case 4: _t->swipeTriggered((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 5: _t->swipeLeftTriggered(); break;
        case 6: _t->swipeUpTriggered(); break;
        case 7: _t->swipeRightTriggered(); break;
        case 8: _t->swipeDownTriggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ipn::App::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ipn::App::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ipn__App,
      qt_meta_data_ipn__App, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::App::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::App::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::App::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__App))
        return static_cast<void*>(const_cast< App*>(this));
    return QWidget::qt_metacast(_clname);
}

int ipn::App::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ipn::App::pinchRotationAngleChanged(qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ipn::App::pinchScaleFactorChanged(qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ipn::App::pinchInTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ipn::App::pinchOutTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void ipn::App::swipeTriggered(qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ipn::App::swipeLeftTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void ipn::App::swipeUpTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void ipn::App::swipeRightTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void ipn::App::swipeDownTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE
