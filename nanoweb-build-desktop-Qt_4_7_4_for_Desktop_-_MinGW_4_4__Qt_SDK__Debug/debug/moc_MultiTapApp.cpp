/****************************************************************************
** Meta object code from reading C++ file 'MultiTapApp.h'
**
** Created: Fri 6. Jan 15:21:09 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/apps/MultiTapApp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MultiTapApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__MultiTapApp[] = {

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
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,   17,   17,   17, 0x09,
      50,   17,   17,   17, 0x09,
      58,   17,   17,   17, 0x09,
      77,   17,   17,   17, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_ipn__MultiTapApp[] = {
    "ipn::MultiTapApp\0\0accepted()\0"
    "multiTapKeyPressed()\0blink()\0"
    "catchCurrentChar()\0refreshText()\0"
};

const QMetaObject ipn::MultiTapApp::staticMetaObject = {
    { &App::staticMetaObject, qt_meta_stringdata_ipn__MultiTapApp,
      qt_meta_data_ipn__MultiTapApp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::MultiTapApp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::MultiTapApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::MultiTapApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__MultiTapApp))
        return static_cast<void*>(const_cast< MultiTapApp*>(this));
    return App::qt_metacast(_clname);
}

int ipn::MultiTapApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = App::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: accepted(); break;
        case 1: multiTapKeyPressed(); break;
        case 2: blink(); break;
        case 3: catchCurrentChar(); break;
        case 4: refreshText(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ipn::MultiTapApp::accepted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
