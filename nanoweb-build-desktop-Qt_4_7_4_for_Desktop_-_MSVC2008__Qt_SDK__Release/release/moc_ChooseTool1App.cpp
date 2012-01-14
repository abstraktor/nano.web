/****************************************************************************
** Meta object code from reading C++ file 'ChooseTool1App.h'
**
** Created: Fri Jan 13 18:52:29 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/apps/ChooseTool1App.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChooseTool1App.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__ChooseTool1App[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,
      45,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   20,   20,   20, 0x0a,
      80,   20,   20,   20, 0x0a,
      92,   20,   20,   20, 0x0a,
     105,   20,   20,   20, 0x0a,
     123,   20,   20,   20, 0x0a,
     150,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ipn__ChooseTool1App[] = {
    "ipn::ChooseTool1App\0\0boxmodelButtonClicked()\0"
    "anotherButtonClicked()\0timerTick()\0"
    "swipeLeft()\0swipeRight()\0backButtonClick()\0"
    "anotherButtonClickedSlot()\0"
    "boxmodelButtonClickedSlot()\0"
};

const QMetaObject ipn::ChooseTool1App::staticMetaObject = {
    { &App::staticMetaObject, qt_meta_stringdata_ipn__ChooseTool1App,
      qt_meta_data_ipn__ChooseTool1App, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::ChooseTool1App::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::ChooseTool1App::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::ChooseTool1App::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__ChooseTool1App))
        return static_cast<void*>(const_cast< ChooseTool1App*>(this));
    return App::qt_metacast(_clname);
}

int ipn::ChooseTool1App::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = App::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: boxmodelButtonClicked(); break;
        case 1: anotherButtonClicked(); break;
        case 2: timerTick(); break;
        case 3: swipeLeft(); break;
        case 4: swipeRight(); break;
        case 5: backButtonClick(); break;
        case 6: anotherButtonClickedSlot(); break;
        case 7: boxmodelButtonClickedSlot(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ipn::ChooseTool1App::boxmodelButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ipn::ChooseTool1App::anotherButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
