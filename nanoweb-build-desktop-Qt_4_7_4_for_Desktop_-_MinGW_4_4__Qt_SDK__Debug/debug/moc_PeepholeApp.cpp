/****************************************************************************
** Meta object code from reading C++ file 'PeepholeApp.h'
**
** Created: Tue 3. Jan 16:26:10 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/apps/PeepholeApp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PeepholeApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__PeepholeApp[] = {

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
      35,   18,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ipn__PeepholeApp[] = {
    "ipn::PeepholeApp\0\0relativeMovement\0"
    "moveContents(QPoint)\0"
};

const QMetaObject ipn::PeepholeApp::staticMetaObject = {
    { &App::staticMetaObject, qt_meta_stringdata_ipn__PeepholeApp,
      qt_meta_data_ipn__PeepholeApp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::PeepholeApp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::PeepholeApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::PeepholeApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__PeepholeApp))
        return static_cast<void*>(const_cast< PeepholeApp*>(this));
    return App::qt_metacast(_clname);
}

int ipn::PeepholeApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = App::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: moveContents((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
