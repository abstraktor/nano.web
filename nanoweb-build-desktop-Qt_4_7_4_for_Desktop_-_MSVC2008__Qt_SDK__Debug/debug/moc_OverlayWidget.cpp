/****************************************************************************
** Meta object code from reading C++ file 'OverlayWidget.h'
**
** Created: Wed Jan 11 21:15:34 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/widgets/OverlayWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OverlayWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__OverlayWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   20,   19,   19, 0x05,
      53,   20,   19,   19, 0x05,
      81,   20,   19,   19, 0x05,
     106,   20,   19,   19, 0x05,
     144,  133,   19,   19, 0x05,
     185,  180,   19,   19, 0x25,

       0        // eod
};

static const char qt_meta_stringdata_ipn__OverlayWidget[] = {
    "ipn::OverlayWidget\0\0event\0"
    "mousePressed(QMouseEvent*)\0"
    "mouseReleased(QMouseEvent*)\0"
    "mouseMoved(QMouseEvent*)\0"
    "mouseHovered(QMouseEvent*)\0type,param\0"
    "gestureTriggered(GestureType,qreal)\0"
    "type\0gestureTriggered(GestureType)\0"
};

const QMetaObject ipn::OverlayWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ipn__OverlayWidget,
      qt_meta_data_ipn__OverlayWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::OverlayWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::OverlayWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::OverlayWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__OverlayWidget))
        return static_cast<void*>(const_cast< OverlayWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ipn::OverlayWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mousePressed((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: mouseReleased((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: mouseMoved((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: mouseHovered((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: gestureTriggered((*reinterpret_cast< GestureType(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 5: gestureTriggered((*reinterpret_cast< GestureType(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ipn::OverlayWidget::mousePressed(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ipn::OverlayWidget::mouseReleased(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ipn::OverlayWidget::mouseMoved(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ipn::OverlayWidget::mouseHovered(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ipn::OverlayWidget::gestureTriggered(GestureType _t1, qreal _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
