/****************************************************************************
** Meta object code from reading C++ file 'TitleBarWidget.h'
**
** Created: Mon Jan 2 11:37:48 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/widgets/TitleBarWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TitleBarWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__TitleBarWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,
      41,   20,   20,   20, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ipn__TitleBarWidget[] = {
    "ipn::TitleBarWidget\0\0leftButtonClicked()\0"
    "rightButtonClicked()\0"
};

const QMetaObject ipn::TitleBarWidget::staticMetaObject = {
    { &ClickableWidget::staticMetaObject, qt_meta_stringdata_ipn__TitleBarWidget,
      qt_meta_data_ipn__TitleBarWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::TitleBarWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::TitleBarWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::TitleBarWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__TitleBarWidget))
        return static_cast<void*>(const_cast< TitleBarWidget*>(this));
    return ClickableWidget::qt_metacast(_clname);
}

int ipn::TitleBarWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ClickableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: leftButtonClicked(); break;
        case 1: rightButtonClicked(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ipn::TitleBarWidget::leftButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ipn::TitleBarWidget::rightButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
