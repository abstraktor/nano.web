/****************************************************************************
** Meta object code from reading C++ file 'ElementTappedApp.h'
**
** Created: Fri 6. Jan 22:06:23 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/apps/ElementTappedApp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ElementTappedApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__ElementTappedApp[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   22,   22,   22, 0x0a,
      53,   22,   22,   22, 0x0a,
      64,   22,   22,   22, 0x0a,
      76,   22,   22,   22, 0x0a,
      86,   22,   22,   22, 0x0a,
      99,   22,   22,   22, 0x0a,
     117,  111,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ipn__ElementTappedApp[] = {
    "ipn::ElementTappedApp\0\0quitButtonClicked()\0"
    "pinchIn()\0pinchOut()\0swipeLeft()\0"
    "swipeUp()\0swipeRight()\0swipeDown()\0"
    "angle\0swipe(qreal)\0"
};

const QMetaObject ipn::ElementTappedApp::staticMetaObject = {
    { &App::staticMetaObject, qt_meta_stringdata_ipn__ElementTappedApp,
      qt_meta_data_ipn__ElementTappedApp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::ElementTappedApp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::ElementTappedApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::ElementTappedApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__ElementTappedApp))
        return static_cast<void*>(const_cast< ElementTappedApp*>(this));
    return App::qt_metacast(_clname);
}

int ipn::ElementTappedApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = App::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: quitButtonClicked(); break;
        case 1: pinchIn(); break;
        case 2: pinchOut(); break;
        case 3: swipeLeft(); break;
        case 4: swipeUp(); break;
        case 5: swipeRight(); break;
        case 6: swipeDown(); break;
        case 7: swipe((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ipn::ElementTappedApp::quitButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
