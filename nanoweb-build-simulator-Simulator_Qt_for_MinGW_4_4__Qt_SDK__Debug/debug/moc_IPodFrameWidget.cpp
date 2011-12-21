/****************************************************************************
** Meta object code from reading C++ file 'IPodFrameWidget.h'
**
** Created: Wed 21. Dec 16:56:08 2011
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
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,
      52,   35,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      75,   71,   21,   21, 0x0a,
      89,   21,   21,   21, 0x0a,
      98,   71,   21,   21, 0x0a,
     117,   71,   21,   21, 0x0a,
     138,   21,   21,   21, 0x0a,
     154,   71,   21,   21, 0x0a,
     180,   71,   21,   21, 0x0a,
     210,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ipn__IPodFrameWidget[] = {
    "ipn::IPodFrameWidget\0\0frameMoved()\0"
    "relativeMovement\0frameMoved(QPoint)\0"
    "app\0pushApp(App*)\0popApp()\0"
    "switchBackTo(App*)\0instantPushApp(App*)\0"
    "instantPopApp()\0instantSwitchBackTo(App*)\0"
    "instantReplaceAllAppsBy(App*)\0"
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
        case 2: pushApp((*reinterpret_cast< App*(*)>(_a[1]))); break;
        case 3: popApp(); break;
        case 4: switchBackTo((*reinterpret_cast< App*(*)>(_a[1]))); break;
        case 5: instantPushApp((*reinterpret_cast< App*(*)>(_a[1]))); break;
        case 6: instantPopApp(); break;
        case 7: instantSwitchBackTo((*reinterpret_cast< App*(*)>(_a[1]))); break;
        case 8: instantReplaceAllAppsBy((*reinterpret_cast< App*(*)>(_a[1]))); break;
        case 9: drawAnimation(); break;
        default: ;
        }
        _id -= 10;
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
QT_END_MOC_NAMESPACE
