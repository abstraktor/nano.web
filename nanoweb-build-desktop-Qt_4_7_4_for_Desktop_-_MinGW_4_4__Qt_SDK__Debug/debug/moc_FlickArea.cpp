/****************************************************************************
** Meta object code from reading C++ file 'FlickArea.h'
**
** Created: Sat 7. Jan 17:40:28 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/widgets/FlickArea.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FlickArea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__FlickArea[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   24,   15,   15, 0x0a,
      94,   88,   15,   15, 0x2a,
     126,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ipn__FlickArea[] = {
    "ipn::FlickArea\0\0moved()\0"
    "event,simulateMouseRelease\0"
    "forwardMouseEvent(QMouseEvent*,bool)\0"
    "event\0forwardMouseEvent(QMouseEvent*)\0"
    "proceedAnimation()\0"
};

const QMetaObject ipn::FlickArea::staticMetaObject = {
    { &ClickableWidget::staticMetaObject, qt_meta_stringdata_ipn__FlickArea,
      qt_meta_data_ipn__FlickArea, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::FlickArea::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::FlickArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::FlickArea::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__FlickArea))
        return static_cast<void*>(const_cast< FlickArea*>(this));
    return ClickableWidget::qt_metacast(_clname);
}

int ipn::FlickArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ClickableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: moved(); break;
        case 1: forwardMouseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: forwardMouseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: proceedAnimation(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ipn::FlickArea::moved()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
