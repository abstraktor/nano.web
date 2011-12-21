/****************************************************************************
** Meta object code from reading C++ file 'MultiTapApp.h'
**
** Created: Wed Dec 21 20:00:42 2011
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../nanoweb/src/apps/MultiTapApp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MultiTapApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__MultiTapApp[] = {

 // content:
       6,       // revision
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

void ipn::MultiTapApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MultiTapApp *_t = static_cast<MultiTapApp *>(_o);
        switch (_id) {
        case 0: _t->accepted(); break;
        case 1: _t->multiTapKeyPressed(); break;
        case 2: _t->blink(); break;
        case 3: _t->catchCurrentChar(); break;
        case 4: _t->refreshText(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ipn::MultiTapApp::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ipn::MultiTapApp::staticMetaObject = {
    { &App::staticMetaObject, qt_meta_stringdata_ipn__MultiTapApp,
      qt_meta_data_ipn__MultiTapApp, &staticMetaObjectExtraData }
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
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
