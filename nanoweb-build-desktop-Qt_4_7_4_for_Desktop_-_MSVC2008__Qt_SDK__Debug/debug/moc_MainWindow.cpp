/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Wed Jan 11 21:15:29 2012
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
      20,   14, // methods
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
     283,  280,   16,   16, 0x08,
     318,   16,   16,   16, 0x08,
     343,  280,   16,   16, 0x08,
     379,   16,   16,   16, 0x08,
     394,   16,   16,   16, 0x08,
     419,   16,   16,   16, 0x08,
     451,   16,   16,   16, 0x08,
     483,  471,   16,   16, 0x08,
     518,   16,   16,   16, 0x08,
     551,   16,   16,   16, 0x08,
     580,  576,   16,   16, 0x08,

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
    "switchToWebPage()\0switchToElementTapped()\0"
    "el\0switchToElementTapped(QWebElement)\0"
    "switchToElementFisheye()\0"
    "switchToElementFisheye(QWebElement)\0"
    "switchToInfo()\0switchToChooseTool1App()\0"
    "switchToChooseToolBoxmodelApp()\0"
    "switchToBorderApp()\0cssproperty\0"
    "switchToSpecificBorderApp(QString)\0"
    "elementTappedLeftButtonClicked()\0"
    "elementTappedInFisheye()\0app\0"
    "switchToApp(App*)\0"
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
        case 7: switchToWebPage(); break;
        case 8: switchToElementTapped(); break;
        case 9: switchToElementTapped((*reinterpret_cast< QWebElement(*)>(_a[1]))); break;
        case 10: switchToElementFisheye(); break;
        case 11: switchToElementFisheye((*reinterpret_cast< QWebElement(*)>(_a[1]))); break;
        case 12: switchToInfo(); break;
        case 13: switchToChooseTool1App(); break;
        case 14: switchToChooseToolBoxmodelApp(); break;
        case 15: switchToBorderApp(); break;
        case 16: switchToSpecificBorderApp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: elementTappedLeftButtonClicked(); break;
        case 18: elementTappedInFisheye(); break;
        case 19: switchToApp((*reinterpret_cast< App*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
