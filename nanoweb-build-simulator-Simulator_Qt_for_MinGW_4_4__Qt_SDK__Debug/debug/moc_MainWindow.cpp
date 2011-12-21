/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Wed 21. Dec 16:56:03 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      37,   31,   16,   16, 0x08,
      68,   31,   16,   16, 0x08,
     101,   31,   16,   16, 0x08,
     131,   31,   16,   16, 0x08,
     162,   31,   16,   16, 0x08,
     205,  194,   16,   16, 0x08,
     238,   16,   16,   16, 0x08,
     256,   16,   16,   16, 0x08,
     281,   16,   16,   16, 0x08,
     310,   16,   16,   16, 0x08,
     333,   16,   16,   16, 0x08,
     357,   16,   16,   16, 0x08,
     376,   16,   16,   16, 0x08,
     395,   16,   16,   16, 0x08,
     414,   16,   16,   16, 0x08,
     431,   16,   16,   16, 0x08,
     448,   16,   16,   16, 0x08,
     470,   16,   16,   16, 0x08,
     491,   16,   16,   16, 0x08,
     516,   16,   16,   16, 0x08,
     538,   16,   16,   16, 0x08,
     562,  558,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ipn__MainWindow[] = {
    "ipn::MainWindow\0\0moveOverlay()\0event\0"
    "handleMousePress(QMouseEvent*)\0"
    "handleMouseRelease(QMouseEvent*)\0"
    "handleMouseMove(QMouseEvent*)\0"
    "handleMouseHover(QMouseEvent*)\0"
    "forwardMouseEvent(QMouseEvent*)\0"
    "type,param\0handleGesture(GestureType,qreal)\0"
    "switchToInfoApp()\0switchToDisplayMenuApp()\0"
    "switchToInteractiveMenuApp()\0"
    "switchToInputMenuApp()\0switchToChoiceMenuApp()\0"
    "switchToClockApp()\0switchToPaintApp()\0"
    "switchToMusicApp()\0switchToGUIApp()\0"
    "switchToMapApp()\0switchToPeepholeApp()\0"
    "switchToGestureApp()\0switchToMarkingMenuApp()\0"
    "switchToMultiTapApp()\0switchToPickerApp()\0"
    "app\0switchToApp(App*)\0"
};

const QMetaObject ipn::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ipn__MainWindow,
      qt_meta_data_ipn__MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ipn::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: moveOverlay(); break;
        case 1: handleMousePress((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: handleMouseRelease((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: handleMouseMove((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: handleMouseHover((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: forwardMouseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: handleGesture((*reinterpret_cast< GestureType(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 7: switchToInfoApp(); break;
        case 8: switchToDisplayMenuApp(); break;
        case 9: switchToInteractiveMenuApp(); break;
        case 10: switchToInputMenuApp(); break;
        case 11: switchToChoiceMenuApp(); break;
        case 12: switchToClockApp(); break;
        case 13: switchToPaintApp(); break;
        case 14: switchToMusicApp(); break;
        case 15: switchToGUIApp(); break;
        case 16: switchToMapApp(); break;
        case 17: switchToPeepholeApp(); break;
        case 18: switchToGestureApp(); break;
        case 19: switchToMarkingMenuApp(); break;
        case 20: switchToMultiTapApp(); break;
        case 21: switchToPickerApp(); break;
        case 22: switchToApp((*reinterpret_cast< App*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
