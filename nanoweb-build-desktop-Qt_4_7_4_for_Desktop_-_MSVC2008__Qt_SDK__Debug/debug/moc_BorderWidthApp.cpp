/****************************************************************************
** Meta object code from reading C++ file 'BorderWidthApp.h'
**
** Created: Wed Jan 11 21:15:40 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/apps/BorderWidthApp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BorderWidthApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__BorderWidthApp[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   20,   20,   20, 0x0a,
      47,   20,   20,   20, 0x0a,
      59,   20,   20,   20, 0x0a,
      72,   20,   20,   20, 0x0a,
      96,   90,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ipn__BorderWidthApp[] = {
    "ipn::BorderWidthApp\0\0valueChosen()\0"
    "timerTick()\0swipeLeft()\0swipeRight()\0"
    "backButtonClick()\0value\0entryClicked(QString)\0"
};

const QMetaObject ipn::BorderWidthApp::staticMetaObject = {
    { &App::staticMetaObject, qt_meta_stringdata_ipn__BorderWidthApp,
      qt_meta_data_ipn__BorderWidthApp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::BorderWidthApp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::BorderWidthApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::BorderWidthApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__BorderWidthApp))
        return static_cast<void*>(const_cast< BorderWidthApp*>(this));
    return App::qt_metacast(_clname);
}

int ipn::BorderWidthApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = App::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueChosen(); break;
        case 1: timerTick(); break;
        case 2: swipeLeft(); break;
        case 3: swipeRight(); break;
        case 4: backButtonClick(); break;
        case 5: entryClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ipn::BorderWidthApp::valueChosen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
