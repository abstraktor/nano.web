/****************************************************************************
** Meta object code from reading C++ file 'BorderEditApp.h'
**
** Created: Tue 10. Jan 21:13:22 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/apps/BorderEditApp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BorderEditApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__BorderEditApp[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      32,   19,   19,   19, 0x0a,
      44,   19,   19,   19, 0x0a,
      57,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ipn__BorderEditApp[] = {
    "ipn::BorderEditApp\0\0timerTick()\0"
    "swipeLeft()\0swipeRight()\0backButtonClick()\0"
};

const QMetaObject ipn::BorderEditApp::staticMetaObject = {
    { &App::staticMetaObject, qt_meta_stringdata_ipn__BorderEditApp,
      qt_meta_data_ipn__BorderEditApp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::BorderEditApp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::BorderEditApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::BorderEditApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__BorderEditApp))
        return static_cast<void*>(const_cast< BorderEditApp*>(this));
    return App::qt_metacast(_clname);
}

int ipn::BorderEditApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = App::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: timerTick(); break;
        case 1: swipeLeft(); break;
        case 2: swipeRight(); break;
        case 3: backButtonClick(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
