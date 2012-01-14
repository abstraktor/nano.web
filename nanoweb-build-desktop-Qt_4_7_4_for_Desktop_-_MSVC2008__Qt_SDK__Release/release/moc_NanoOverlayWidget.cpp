/****************************************************************************
** Meta object code from reading C++ file 'NanoOverlayWidget.h'
**
** Created: Fri Jan 13 18:52:32 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/nanoweb/NanoOverlayWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NanoOverlayWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__NanoOverlayWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_ipn__NanoOverlayWidget[] = {
    "ipn::NanoOverlayWidget\0"
};

const QMetaObject ipn::NanoOverlayWidget::staticMetaObject = {
    { &OverlayWidget::staticMetaObject, qt_meta_stringdata_ipn__NanoOverlayWidget,
      qt_meta_data_ipn__NanoOverlayWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::NanoOverlayWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::NanoOverlayWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::NanoOverlayWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__NanoOverlayWidget))
        return static_cast<void*>(const_cast< NanoOverlayWidget*>(this));
    return OverlayWidget::qt_metacast(_clname);
}

int ipn::NanoOverlayWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = OverlayWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
