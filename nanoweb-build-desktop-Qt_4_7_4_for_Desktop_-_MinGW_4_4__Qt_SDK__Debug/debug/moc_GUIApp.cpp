/****************************************************************************
** Meta object code from reading C++ file 'GUIApp.h'
**
** Created: Fri 6. Jan 15:21:04 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/apps/GUIApp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUIApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__GUIApp[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_ipn__GUIApp[] = {
    "ipn::GUIApp\0\0updatePageIndicator()\0"
};

const QMetaObject ipn::GUIApp::staticMetaObject = {
    { &App::staticMetaObject, qt_meta_stringdata_ipn__GUIApp,
      qt_meta_data_ipn__GUIApp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::GUIApp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::GUIApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::GUIApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__GUIApp))
        return static_cast<void*>(const_cast< GUIApp*>(this));
    return App::qt_metacast(_clname);
}

int ipn::GUIApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = App::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updatePageIndicator(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
