/****************************************************************************
** Meta object code from reading C++ file 'App.h'
**
** Created: Wed Jan 11 21:01:08 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/apps/App.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'App.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__App[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      21,       // signalCount

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
     230,    9,    9,    9, 0x05,
     257,    9,    9,    9, 0x05,
     284,    9,    9,    9, 0x05,
     312,    9,    9,    9, 0x05,
     339,    9,    9,    9, 0x05,
     366,    9,    9,    9, 0x05,
     394,    9,    9,    9, 0x05,
     423,    9,    9,    9, 0x05,
     452,    9,    9,    9, 0x05,
     482,    9,    9,    9, 0x05,
     508,    9,    9,    9, 0x05,
     534,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     561,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ipn__App[] = {
    "ipn::App\0\0delta\0pinchRotationAngleChanged(qreal)\0"
    "pinchScaleFactorChanged(qreal)\0"
    "pinchInTriggered()\0pinchOutTriggered()\0"
    "angle\0swipeTriggered(qreal)\0"
    "swipeLeftTriggered()\0swipeUpTriggered()\0"
    "swipeRightTriggered()\0swipeDownTriggered()\0"
    "backButtonClickTriggered()\0"
    "leftButtonClickTriggered()\0"
    "rightButtonClickTriggered()\0"
    "backButtonPressTriggered()\0"
    "leftButtonPressTriggered()\0"
    "rightButtonPressTriggered()\0"
    "backButtonReleaseTriggered()\0"
    "leftButtonReleaseTriggered()\0"
    "rightButtonReleaseTriggered()\0"
    "backButtonHoldTriggered()\0"
    "leftButtonHoldTriggered()\0"
    "rightButtonHoldTriggered()\0"
    "triggerButtonHold()\0"
};

const QMetaObject ipn::App::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ipn__App,
      qt_meta_data_ipn__App, 0 }
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
        switch (_id) {
        case 0: pinchRotationAngleChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 1: pinchScaleFactorChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 2: pinchInTriggered(); break;
        case 3: pinchOutTriggered(); break;
        case 4: swipeTriggered((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 5: swipeLeftTriggered(); break;
        case 6: swipeUpTriggered(); break;
        case 7: swipeRightTriggered(); break;
        case 8: swipeDownTriggered(); break;
        case 9: backButtonClickTriggered(); break;
        case 10: leftButtonClickTriggered(); break;
        case 11: rightButtonClickTriggered(); break;
        case 12: backButtonPressTriggered(); break;
        case 13: leftButtonPressTriggered(); break;
        case 14: rightButtonPressTriggered(); break;
        case 15: backButtonReleaseTriggered(); break;
        case 16: leftButtonReleaseTriggered(); break;
        case 17: rightButtonReleaseTriggered(); break;
        case 18: backButtonHoldTriggered(); break;
        case 19: leftButtonHoldTriggered(); break;
        case 20: rightButtonHoldTriggered(); break;
        case 21: triggerButtonHold(); break;
        default: ;
        }
        _id -= 22;
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

// SIGNAL 9
void ipn::App::backButtonClickTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}

// SIGNAL 10
void ipn::App::leftButtonClickTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}

// SIGNAL 11
void ipn::App::rightButtonClickTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void ipn::App::backButtonPressTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 12, 0);
}

// SIGNAL 13
void ipn::App::leftButtonPressTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 13, 0);
}

// SIGNAL 14
void ipn::App::rightButtonPressTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 14, 0);
}

// SIGNAL 15
void ipn::App::backButtonReleaseTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 15, 0);
}

// SIGNAL 16
void ipn::App::leftButtonReleaseTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 16, 0);
}

// SIGNAL 17
void ipn::App::rightButtonReleaseTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 17, 0);
}

// SIGNAL 18
void ipn::App::backButtonHoldTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 18, 0);
}

// SIGNAL 19
void ipn::App::leftButtonHoldTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 19, 0);
}

// SIGNAL 20
void ipn::App::rightButtonHoldTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 20, 0);
}
QT_END_MOC_NAMESPACE
