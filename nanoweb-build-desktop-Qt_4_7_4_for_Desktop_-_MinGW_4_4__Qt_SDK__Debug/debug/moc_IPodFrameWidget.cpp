/****************************************************************************
** Meta object code from reading C++ file 'IPodFrameWidget.h'
**
** Created: Sat 7. Jan 17:49:24 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/IPodFrameWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IPodFrameWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__IPodFrameWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,
      52,   35,   21,   21, 0x05,
      82,   71,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
     122,  118,   21,   21, 0x0a,
     136,   21,   21,   21, 0x0a,
     145,  118,   21,   21, 0x0a,
     164,  118,   21,   21, 0x0a,
     185,   21,   21,   21, 0x0a,
     201,  118,   21,   21, 0x0a,
     227,  118,   21,   21, 0x0a,
     257,   21,   21,   21, 0x0a,
     286,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ipn__IPodFrameWidget[] = {
    "ipn::IPodFrameWidget\0\0frameMoved()\0"
    "relativeMovement\0frameMoved(QPoint)\0"
    "type,param\0gestureTriggered(GestureType,qreal)\0"
    "app\0pushApp(App*)\0popApp()\0"
    "switchBackTo(App*)\0instantPushApp(App*)\0"
    "instantPopApp()\0instantSwitchBackTo(App*)\0"
    "instantReplaceAllAppsBy(App*)\0"
    "triggerHardwareButtonClick()\0"
    "drawAnimation()\0"
};

const QMetaObject ipn::IPodFrameWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ipn__IPodFrameWidget,
      qt_meta_data_ipn__IPodFrameWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::IPodFrameWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::IPodFrameWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::IPodFrameWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__IPodFrameWidget))
        return static_cast<void*>(const_cast< IPodFrameWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ipn::IPodFrameWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: frameMoved(); break;
        case 1: frameMoved((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 2: gestureTriggered((*reinterpret_cast< GestureType(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 3: pushApp((*reinterpret_cast< App*(*)>(_a[1]))); break;
        case 4: popApp(); break;
        case 5: switchBackTo((*reinterpret_cast< App*(*)>(_a[1]))); break;
        case 6: instantPushApp((*reinterpret_cast< App*(*)>(_a[1]))); break;
        case 7: instantPopApp(); break;
        case 8: instantSwitchBackTo((*reinterpret_cast< App*(*)>(_a[1]))); break;
        case 9: instantReplaceAllAppsBy((*reinterpret_cast< App*(*)>(_a[1]))); break;
        case 10: triggerHardwareButtonClick(); break;
        case 11: drawAnimation(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ipn::IPodFrameWidget::frameMoved()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ipn::IPodFrameWidget::frameMoved(const QPoint _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ipn::IPodFrameWidget::gestureTriggered(GestureType _t1, qreal _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
