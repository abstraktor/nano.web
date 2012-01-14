/****************************************************************************
** Meta object code from reading C++ file 'BorderEditApp.h'
**
** Created: Fri Jan 13 18:52:30 2012
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
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   20,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   19,   19,   19, 0x0a,
      61,   19,   19,   19, 0x0a,
      73,   19,   19,   19, 0x0a,
      86,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ipn__BorderEditApp[] = {
    "ipn::BorderEditApp\0\0property\0"
    "borderEdit(QString)\0timerTick()\0"
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
        case 0: borderEdit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: timerTick(); break;
        case 2: swipeLeft(); break;
        case 3: swipeRight(); break;
        case 4: backButtonClick(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ipn::BorderEditApp::borderEdit(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
