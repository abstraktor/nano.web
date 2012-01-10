/****************************************************************************
** Meta object code from reading C++ file 'ChooseToolBoxmodelApp.h'
**
** Created: Tue 10. Jan 00:39:29 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/apps/ChooseToolBoxmodelApp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChooseToolBoxmodelApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__ChooseToolBoxmodelApp[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   27,   27,   27, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ipn__ChooseToolBoxmodelApp[] = {
    "ipn::ChooseToolBoxmodelApp\0\0tapped()\0"
    "backButtonClick()\0"
};

const QMetaObject ipn::ChooseToolBoxmodelApp::staticMetaObject = {
    { &App::staticMetaObject, qt_meta_stringdata_ipn__ChooseToolBoxmodelApp,
      qt_meta_data_ipn__ChooseToolBoxmodelApp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::ChooseToolBoxmodelApp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::ChooseToolBoxmodelApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::ChooseToolBoxmodelApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__ChooseToolBoxmodelApp))
        return static_cast<void*>(const_cast< ChooseToolBoxmodelApp*>(this));
    return App::qt_metacast(_clname);
}

int ipn::ChooseToolBoxmodelApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = App::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: tapped(); break;
        case 1: backButtonClick(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ipn::ChooseToolBoxmodelApp::tapped()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
