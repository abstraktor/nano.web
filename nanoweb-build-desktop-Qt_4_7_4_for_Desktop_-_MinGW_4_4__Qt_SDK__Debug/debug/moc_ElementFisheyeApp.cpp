/****************************************************************************
** Meta object code from reading C++ file 'ElementFisheyeApp.h'
**
** Created: Mon 9. Jan 19:38:05 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/apps/ElementFisheyeApp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ElementFisheyeApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__ElementFisheyeApp[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   24,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
      54,   23,   23,   23, 0x0a,
      66,   23,   23,   23, 0x0a,
      78,   23,   23,   23, 0x0a,
      88,   23,   23,   23, 0x0a,
     101,   23,   23,   23, 0x0a,
     113,   23,   23,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ipn__ElementFisheyeApp[] = {
    "ipn::ElementFisheyeApp\0\0el\0"
    "elementTapped(QWebElement)\0timerTick()\0"
    "swipeLeft()\0swipeUp()\0swipeRight()\0"
    "swipeDown()\0backButtonClick()\0"
};

const QMetaObject ipn::ElementFisheyeApp::staticMetaObject = {
    { &App::staticMetaObject, qt_meta_stringdata_ipn__ElementFisheyeApp,
      qt_meta_data_ipn__ElementFisheyeApp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::ElementFisheyeApp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::ElementFisheyeApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::ElementFisheyeApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__ElementFisheyeApp))
        return static_cast<void*>(const_cast< ElementFisheyeApp*>(this));
    return App::qt_metacast(_clname);
}

int ipn::ElementFisheyeApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = App::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: elementTapped((*reinterpret_cast< QWebElement(*)>(_a[1]))); break;
        case 1: timerTick(); break;
        case 2: swipeLeft(); break;
        case 3: swipeUp(); break;
        case 4: swipeRight(); break;
        case 5: swipeDown(); break;
        case 6: backButtonClick(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ipn::ElementFisheyeApp::elementTapped(QWebElement _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
