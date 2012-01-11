/****************************************************************************
** Meta object code from reading C++ file 'WebviewApp.h'
**
** Created: Wed 11. Jan 17:18:47 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/apps/WebviewApp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WebviewApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__WebviewApp[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      40,   37,   16,   16, 0x05,
      67,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      89,   83,   16,   16, 0x0a,
     121,   83,   16,   16, 0x0a,
     151,   16,   16,   16, 0x0a,
     161,   16,   16,   16, 0x0a,
     172,   16,   16,   16, 0x0a,
     184,   16,   16,   16, 0x0a,
     194,   16,   16,   16, 0x0a,
     207,   16,   16,   16, 0x0a,
     225,  219,   16,   16, 0x0a,
     238,   16,   16,   16, 0x0a,
     256,   16,   16,   16, 0x0a,
     275,   16,   16,   16, 0x0a,
     293,   37,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ipn__WebviewApp[] = {
    "ipn::WebviewApp\0\0quitButtonClicked()\0"
    "el\0elementTapped(QWebElement)\0"
    "zoomTriggered()\0delta\0"
    "changePinchRotationAngle(qreal)\0"
    "changePinchScaleFactor(qreal)\0pinchIn()\0"
    "pinchOut()\0swipeLeft()\0swipeUp()\0"
    "swipeRight()\0swipeDown()\0angle\0"
    "swipe(qreal)\0backButtonClick()\0"
    "rightButtonClick()\0leftButtonClick()\0"
    "elementTappedHandler(QWebElement)\0"
};

const QMetaObject ipn::WebviewApp::staticMetaObject = {
    { &App::staticMetaObject, qt_meta_stringdata_ipn__WebviewApp,
      qt_meta_data_ipn__WebviewApp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::WebviewApp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::WebviewApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::WebviewApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__WebviewApp))
        return static_cast<void*>(const_cast< WebviewApp*>(this));
    return App::qt_metacast(_clname);
}

int ipn::WebviewApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = App::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: quitButtonClicked(); break;
        case 1: elementTapped((*reinterpret_cast< QWebElement(*)>(_a[1]))); break;
        case 2: zoomTriggered(); break;
        case 3: changePinchRotationAngle((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 4: changePinchScaleFactor((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 5: pinchIn(); break;
        case 6: pinchOut(); break;
        case 7: swipeLeft(); break;
        case 8: swipeUp(); break;
        case 9: swipeRight(); break;
        case 10: swipeDown(); break;
        case 11: swipe((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 12: backButtonClick(); break;
        case 13: rightButtonClick(); break;
        case 14: leftButtonClick(); break;
        case 15: elementTappedHandler((*reinterpret_cast< QWebElement(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void ipn::WebviewApp::quitButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ipn::WebviewApp::elementTapped(QWebElement _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ipn::WebviewApp::zoomTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
