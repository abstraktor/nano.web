/****************************************************************************
** Meta object code from reading C++ file 'MenuApp.h'
**
** Created: Fri Jan 13 18:52:26 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nanoweb/src/apps/MenuApp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MenuApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ipn__MenuApp[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      34,   13,   13,   13, 0x05,
      57,   13,   13,   13, 0x05,
      81,   13,   13,   13, 0x05,
     107,   13,   13,   13, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ipn__MenuApp[] = {
    "ipn::MenuApp\0\0backButtonClicked()\0"
    "topLeftButtonClicked()\0topRightButtonClicked()\0"
    "bottomLeftButtonClicked()\0"
    "bottomRightButtonClicked()\0"
};

const QMetaObject ipn::MenuApp::staticMetaObject = {
    { &App::staticMetaObject, qt_meta_stringdata_ipn__MenuApp,
      qt_meta_data_ipn__MenuApp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ipn::MenuApp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ipn::MenuApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ipn::MenuApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ipn__MenuApp))
        return static_cast<void*>(const_cast< MenuApp*>(this));
    return App::qt_metacast(_clname);
}

int ipn::MenuApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = App::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: backButtonClicked(); break;
        case 1: topLeftButtonClicked(); break;
        case 2: topRightButtonClicked(); break;
        case 3: bottomLeftButtonClicked(); break;
        case 4: bottomRightButtonClicked(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ipn::MenuApp::backButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ipn::MenuApp::topLeftButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ipn::MenuApp::topRightButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ipn::MenuApp::bottomLeftButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void ipn::MenuApp::bottomRightButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
