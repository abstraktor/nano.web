/****************************************************************************
** Meta object code from reading C++ file 'ClickableWidget.h'
**
** Created: Wed Dec 21 20:00:47 2011
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../nanoweb/src/widgets/ClickableWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClickableWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__ClickableWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,
      32,   21,   21,   21, 0x05,
      42,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,   21,   21,   21, 0x0a,
      61,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ipn__ClickableWidget[] = {
    "ipn::ClickableWidget\0\0clicked()\0"
    "pressed()\0released()\0press()\0release()\0"
};

void ipn::ClickableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ClickableWidget *_t = static_cast<ClickableWidget *>(_o);
        switch (_id) {
        case 0: _t->clicked(); break;
        case 1: _t->pressed(); break;
        case 2: _t->released(); break;
        case 3: _t->press(); break;
        case 4: _t->release(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ipn::ClickableWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ipn::ClickableWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ipn__ClickableWidget,
      qt_meta_data_ipn__ClickableWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::ClickableWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::ClickableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::ClickableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__ClickableWidget))
        return static_cast<void*>(const_cast< ClickableWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ipn::ClickableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void ipn::ClickableWidget::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ipn::ClickableWidget::pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ipn::ClickableWidget::released()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
