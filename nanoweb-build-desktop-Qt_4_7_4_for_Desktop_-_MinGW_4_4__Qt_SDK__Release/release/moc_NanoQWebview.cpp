/****************************************************************************
** Meta object code from reading C++ file 'NanoQWebview.h'
**
** Created: Fri 13. Jan 14:08:22 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/nanoweb/NanoQWebview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NanoQWebview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__NanoQWebview[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   19,   18,   18, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ipn__NanoQWebview[] = {
    "ipn::NanoQWebview\0\0el\0elementTapped(QWebElement)\0"
};

const QMetaObject ipn::NanoQWebview::staticMetaObject = {
    { &QWebView::staticMetaObject, qt_meta_stringdata_ipn__NanoQWebview,
      qt_meta_data_ipn__NanoQWebview, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::NanoQWebview::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::NanoQWebview::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::NanoQWebview::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__NanoQWebview))
        return static_cast<void*>(const_cast< NanoQWebview*>(this));
    return QWebView::qt_metacast(_clname);
}

int ipn::NanoQWebview::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: elementTapped((*reinterpret_cast< QWebElement(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ipn::NanoQWebview::elementTapped(QWebElement _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
