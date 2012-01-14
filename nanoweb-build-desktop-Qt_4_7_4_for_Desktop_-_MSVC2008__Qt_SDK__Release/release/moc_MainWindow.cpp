/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Fri Jan 13 20:06:49 2012
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
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      26,   16,   16,   16, 0x0a,
      42,   16,   16,   16, 0x0a,
      60,   16,   16,   16, 0x0a,
      77,   16,   16,   16, 0x0a,
     104,  101,   16,   16, 0x0a,
     139,   16,   16,   16, 0x0a,
     164,  101,   16,   16, 0x0a,
     200,   16,   16,   16, 0x0a,
     215,   16,   16,   16, 0x0a,
     240,   16,   16,   16, 0x0a,
     272,   16,   16,   16, 0x0a,
     304,  292,   16,   16, 0x0a,
     339,   16,   16,   16, 0x0a,
     359,   16,   16,   16, 0x0a,
     392,   16,   16,   16, 0x0a,
     417,  101,   16,   16, 0x0a,
     453,   16,   16,   16, 0x0a,
     479,  475,   16,   16, 0x0a,
     497,   16,   16,   16, 0x08,
     517,  511,   16,   16, 0x08,
     548,  511,   16,   16, 0x08,
     581,  511,   16,   16, 0x08,
     611,  511,   16,   16, 0x08,
     642,  511,   16,   16, 0x08,
     685,  674,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ipn__MainWindow[] = {
    "ipn::MainWindow\0\0popApp()\0instantPopApp()\0"
    "switchToWebPage()\0switchToMockUp()\0"
    "switchToElementTapped()\0el\0"
    "switchToElementTapped(QWebElement)\0"
    "switchToElementFisheye()\0"
    "switchToElementFisheye(QWebElement)\0"
    "switchToInfo()\0switchToChooseTool1App()\0"
    "switchToChooseToolBoxmodelApp()\0"
    "switchToBorderApp()\0cssproperty\0"
    "switchToSpecificBorderApp(QString)\0"
    "switchToNumberApp()\0"
    "elementTappedLeftButtonClicked()\0"
    "elementTappedInFisheye()\0"
    "elementTappedInFisheye(QWebElement)\0"
    "switchToMultiTapApp()\0app\0switchToApp(App*)\0"
    "moveOverlay()\0event\0handleMousePress(QMouseEvent*)\0"
    "handleMouseRelease(QMouseEvent*)\0"
    "handleMouseMove(QMouseEvent*)\0"
    "handleMouseHover(QMouseEvent*)\0"
    "forwardMouseEvent(QMouseEvent*)\0"
    "type,param\0handleGesture(GestureType,qreal)\0"
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
        case 0: popApp(); break;
        case 1: instantPopApp(); break;
        case 2: switchToWebPage(); break;
        case 3: switchToMockUp(); break;
        case 4: switchToElementTapped(); break;
        case 5: switchToElementTapped((*reinterpret_cast< QWebElement(*)>(_a[1]))); break;
        case 6: switchToElementFisheye(); break;
        case 7: switchToElementFisheye((*reinterpret_cast< QWebElement(*)>(_a[1]))); break;
        case 8: switchToInfo(); break;
        case 9: switchToChooseTool1App(); break;
        case 10: switchToChooseToolBoxmodelApp(); break;
        case 11: switchToBorderApp(); break;
        case 12: switchToSpecificBorderApp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: switchToNumberApp(); break;
        case 14: elementTappedLeftButtonClicked(); break;
        case 15: elementTappedInFisheye(); break;
        case 16: elementTappedInFisheye((*reinterpret_cast< QWebElement(*)>(_a[1]))); break;
        case 17: switchToMultiTapApp(); break;
        case 18: switchToApp((*reinterpret_cast< App*(*)>(_a[1]))); break;
        case 19: moveOverlay(); break;
        case 20: handleMousePress((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 21: handleMouseRelease((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 22: handleMouseMove((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 23: handleMouseHover((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 24: forwardMouseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 25: handleGesture((*reinterpret_cast< GestureType(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 26;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
