/****************************************************************************
** Meta object code from reading C++ file 'App.h'
**
** Created: Fri Jan 13 18:52:20 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/apps/App.h"
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
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      24,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      32,   26,    9,    9, 0x05,
      65,   26,    9,    9, 0x05,
      96,    9,    9,    9, 0x05,
     115,    9,    9,    9, 0x05,
     141,  135,    9,    9, 0x05,
     163,    9,    9,    9, 0x05,
     184,    9,    9,    9, 0x05,
     203,    9,    9,    9, 0x05,
     225,    9,    9,    9, 0x05,
     246,    9,    9,    9, 0x05,
     273,    9,    9,    9, 0x05,
     300,    9,    9,    9, 0x05,
     328,    9,    9,    9, 0x05,
     355,    9,    9,    9, 0x05,
     382,    9,    9,    9, 0x05,
     410,    9,    9,    9, 0x05,
     439,    9,    9,    9, 0x05,
     468,    9,    9,    9, 0x05,
     498,    9,    9,    9, 0x05,
     524,    9,    9,    9, 0x05,
     550,    9,    9,    9, 0x05,
     577,    9,    9,    9, 0x05,
     594,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     612,    9,    9,    9, 0x08,
     621,    9,    9,    9, 0x08,
     641,    9,    9,    9, 0x08,
     659,    9,    9,    9, 0x08,
     678,    9,    9,    9, 0x08,
     696,    9,    9,    9, 0x08,
     713,    9,    9,    9, 0x08,
     731,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ipn__App[] = {
    "ipn::App\0\0performPopApp()\0delta\0"
    "pinchRotationAngleChanged(qreal)\0"
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
    "rightButtonHoldTriggered()\0switchToMockUp()\0"
    "switchToWebPage()\0popApp()\0"
    "triggerButtonHold()\0backButtonClick()\0"
    "rightButtonClick()\0leftButtonClick()\0"
    "backButtonHold()\0rightButtonHold()\0"
    "leftButtonHold()\0"
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
        case 0: performPopApp(); break;
        case 1: pinchRotationAngleChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 2: pinchScaleFactorChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 3: pinchInTriggered(); break;
        case 4: pinchOutTriggered(); break;
        case 5: swipeTriggered((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 6: swipeLeftTriggered(); break;
        case 7: swipeUpTriggered(); break;
        case 8: swipeRightTriggered(); break;
        case 9: swipeDownTriggered(); break;
        case 10: backButtonClickTriggered(); break;
        case 11: leftButtonClickTriggered(); break;
        case 12: rightButtonClickTriggered(); break;
        case 13: backButtonPressTriggered(); break;
        case 14: leftButtonPressTriggered(); break;
        case 15: rightButtonPressTriggered(); break;
        case 16: backButtonReleaseTriggered(); break;
        case 17: leftButtonReleaseTriggered(); break;
        case 18: rightButtonReleaseTriggered(); break;
        case 19: backButtonHoldTriggered(); break;
        case 20: leftButtonHoldTriggered(); break;
        case 21: rightButtonHoldTriggered(); break;
        case 22: switchToMockUp(); break;
        case 23: switchToWebPage(); break;
        case 24: popApp(); break;
        case 25: triggerButtonHold(); break;
        case 26: backButtonClick(); break;
        case 27: rightButtonClick(); break;
        case 28: leftButtonClick(); break;
        case 29: backButtonHold(); break;
        case 30: rightButtonHold(); break;
        case 31: leftButtonHold(); break;
        default: ;
        }
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void ipn::App::performPopApp()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ipn::App::pinchRotationAngleChanged(qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ipn::App::pinchScaleFactorChanged(qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ipn::App::pinchInTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void ipn::App::pinchOutTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void ipn::App::swipeTriggered(qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ipn::App::swipeLeftTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void ipn::App::swipeUpTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void ipn::App::swipeRightTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void ipn::App::swipeDownTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}

// SIGNAL 10
void ipn::App::backButtonClickTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}

// SIGNAL 11
void ipn::App::leftButtonClickTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void ipn::App::rightButtonClickTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 12, 0);
}

// SIGNAL 13
void ipn::App::backButtonPressTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 13, 0);
}

// SIGNAL 14
void ipn::App::leftButtonPressTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 14, 0);
}

// SIGNAL 15
void ipn::App::rightButtonPressTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 15, 0);
}

// SIGNAL 16
void ipn::App::backButtonReleaseTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 16, 0);
}

// SIGNAL 17
void ipn::App::leftButtonReleaseTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 17, 0);
}

// SIGNAL 18
void ipn::App::rightButtonReleaseTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 18, 0);
}

// SIGNAL 19
void ipn::App::backButtonHoldTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 19, 0);
}

// SIGNAL 20
void ipn::App::leftButtonHoldTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 20, 0);
}

// SIGNAL 21
void ipn::App::rightButtonHoldTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 21, 0);
}

// SIGNAL 22
void ipn::App::switchToMockUp()
{
    QMetaObject::activate(this, &staticMetaObject, 22, 0);
}

// SIGNAL 23
void ipn::App::switchToWebPage()
{
    QMetaObject::activate(this, &staticMetaObject, 23, 0);
}
QT_END_MOC_NAMESPACE
