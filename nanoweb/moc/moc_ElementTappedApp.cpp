/****************************************************************************
** Meta object code from reading C++ file 'ElementTappedApp.h'
**
** Created: Wed Jan 11 21:01:17 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/apps/ElementTappedApp.h"
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
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x05,
      46,   43,   22,   22, 0x05,
      73,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      93,   22,   22,   22, 0x0a,
     103,   22,   22,   22, 0x0a,
     114,   22,   22,   22, 0x0a,
     126,   22,   22,   22, 0x0a,
     136,   22,   22,   22, 0x0a,
     149,   22,   22,   22, 0x0a,
     161,   43,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ipn__ElementTappedApp[] = {
    "ipn::ElementTappedApp\0\0leftButtonClicked()\0"
    "el\0elementTapped(QWebElement)\0"
    "editButtonClicked()\0pinchIn()\0pinchOut()\0"
    "swipeLeft()\0swipeUp()\0swipeRight()\0"
    "swipeDown()\0elementTappedInFisheye(QWebElement)\0"
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
        case 0: leftButtonClicked(); break;
        case 1: elementTapped((*reinterpret_cast< QWebElement(*)>(_a[1]))); break;
        case 2: editButtonClicked(); break;
        case 3: pinchIn(); break;
        case 4: pinchOut(); break;
        case 5: swipeLeft(); break;
        case 6: swipeUp(); break;
        case 7: swipeRight(); break;
        case 8: swipeDown(); break;
        case 9: elementTappedInFisheye((*reinterpret_cast< QWebElement(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ipn::ElementTappedApp::leftButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ipn::ElementTappedApp::elementTapped(QWebElement _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ipn::ElementTappedApp::editButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
