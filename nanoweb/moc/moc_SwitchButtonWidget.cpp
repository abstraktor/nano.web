/****************************************************************************
** Meta object code from reading C++ file 'SwitchButtonWidget.h'
**
** Created: Wed Jan 11 21:01:13 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/widgets/SwitchButtonWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SwitchButtonWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__SwitchButtonWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x0a,
      36,   24,   24,   24, 0x0a,
      48,   24,   24,   24, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ipn__SwitchButtonWidget[] = {
    "ipn::SwitchButtonWidget\0\0switchOn()\0"
    "switchOff()\0toggle()\0"
};

const QMetaObject ipn::SwitchButtonWidget::staticMetaObject = {
    { &ButtonWidget::staticMetaObject, qt_meta_stringdata_ipn__SwitchButtonWidget,
      qt_meta_data_ipn__SwitchButtonWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::SwitchButtonWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::SwitchButtonWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::SwitchButtonWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__SwitchButtonWidget))
        return static_cast<void*>(const_cast< SwitchButtonWidget*>(this));
    return ButtonWidget::qt_metacast(_clname);
}

int ipn::SwitchButtonWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ButtonWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: switchOn(); break;
        case 1: switchOff(); break;
        case 2: toggle(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
