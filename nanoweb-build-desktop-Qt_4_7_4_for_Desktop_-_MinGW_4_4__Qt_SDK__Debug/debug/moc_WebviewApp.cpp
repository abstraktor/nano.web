/****************************************************************************
** Meta object code from reading C++ file 'WebviewApp.h'
**
** Created: Thu 5. Jan 12:57:58 2012
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
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   37,   16,   16, 0x0a,
      75,   37,   16,   16, 0x0a,
     105,   16,   16,   16, 0x0a,
     115,   16,   16,   16, 0x0a,
     126,   16,   16,   16, 0x0a,
     138,   16,   16,   16, 0x0a,
     148,   16,   16,   16, 0x0a,
     161,   16,   16,   16, 0x0a,
     179,  173,   16,   16, 0x0a,
     192,   16,   16,   16, 0x0a,
     210,   16,   16,   16, 0x0a,
     229,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ipn__WebviewApp[] = {
    "ipn::WebviewApp\0\0quitButtonClicked()\0"
    "delta\0changePinchRotationAngle(qreal)\0"
    "changePinchScaleFactor(qreal)\0pinchIn()\0"
    "pinchOut()\0swipeLeft()\0swipeUp()\0"
    "swipeRight()\0swipeDown()\0angle\0"
    "swipe(qreal)\0backButtonClick()\0"
    "rightButtonClick()\0leftButtonClick()\0"
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
        case 1: changePinchRotationAngle((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 2: changePinchScaleFactor((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 3: pinchIn(); break;
        case 4: pinchOut(); break;
        case 5: swipeLeft(); break;
        case 6: swipeUp(); break;
        case 7: swipeRight(); break;
        case 8: swipeDown(); break;
        case 9: swipe((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 10: backButtonClick(); break;
        case 11: rightButtonClick(); break;
        case 12: leftButtonClick(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ipn::WebviewApp::quitButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
