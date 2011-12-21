/****************************************************************************
** Meta object code from reading C++ file 'WebviewApp.h'
**
** Created: Wed Dec 21 20:42:08 2011
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../nanoweb/src/apps/WebviewApp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WebviewApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__WebviewApp[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
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

       0        // eod
};

static const char qt_meta_stringdata_ipn__WebviewApp[] = {
    "ipn::WebviewApp\0\0quitButtonClicked()\0"
    "delta\0changePinchRotationAngle(qreal)\0"
    "changePinchScaleFactor(qreal)\0pinchIn()\0"
    "pinchOut()\0swipeLeft()\0swipeUp()\0"
    "swipeRight()\0swipeDown()\0angle\0"
    "swipe(qreal)\0"
};

void ipn::WebviewApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WebviewApp *_t = static_cast<WebviewApp *>(_o);
        switch (_id) {
        case 0: _t->quitButtonClicked(); break;
        case 1: _t->changePinchRotationAngle((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 2: _t->changePinchScaleFactor((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 3: _t->pinchIn(); break;
        case 4: _t->pinchOut(); break;
        case 5: _t->swipeLeft(); break;
        case 6: _t->swipeUp(); break;
        case 7: _t->swipeRight(); break;
        case 8: _t->swipeDown(); break;
        case 9: _t->swipe((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ipn::WebviewApp::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ipn::WebviewApp::staticMetaObject = {
    { &App::staticMetaObject, qt_meta_stringdata_ipn__WebviewApp,
      qt_meta_data_ipn__WebviewApp, &staticMetaObjectExtraData }
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ipn::WebviewApp::quitButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
