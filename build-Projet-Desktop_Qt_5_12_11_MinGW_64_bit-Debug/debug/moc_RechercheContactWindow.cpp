/****************************************************************************
** Meta object code from reading C++ file 'RechercheContactWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Projet/RechercheContactWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RechercheContactWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RechercheContactWindow_t {
    QByteArrayData data[10];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RechercheContactWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RechercheContactWindow_t qt_meta_stringdata_RechercheContactWindow = {
    {
QT_MOC_LITERAL(0, 0, 22), // "RechercheContactWindow"
QT_MOC_LITERAL(1, 23, 15), // "contactSelected"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 8), // "Contact*"
QT_MOC_LITERAL(4, 49, 19), // "listContactsUpdated"
QT_MOC_LITERAL(5, 69, 19), // "std::list<Contact*>"
QT_MOC_LITERAL(6, 89, 18), // "updateListContacts"
QT_MOC_LITERAL(7, 108, 16), // "rechercheContact"
QT_MOC_LITERAL(8, 125, 13), // "selectContact"
QT_MOC_LITERAL(9, 139, 11) // "QModelIndex"

    },
    "RechercheContactWindow\0contactSelected\0"
    "\0Contact*\0listContactsUpdated\0"
    "std::list<Contact*>\0updateListContacts\0"
    "rechercheContact\0selectContact\0"
    "QModelIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RechercheContactWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   50,    2, 0x0a /* Public */,
       7,    1,   53,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x0a /* Public */,
       8,    1,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,

       0        // eod
};

void RechercheContactWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RechercheContactWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->contactSelected((*reinterpret_cast< Contact*(*)>(_a[1]))); break;
        case 1: _t->listContactsUpdated((*reinterpret_cast< std::list<Contact*>(*)>(_a[1]))); break;
        case 2: _t->updateListContacts((*reinterpret_cast< std::list<Contact*>(*)>(_a[1]))); break;
        case 3: _t->rechercheContact((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->rechercheContact(); break;
        case 5: _t->selectContact((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RechercheContactWindow::*)(Contact * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RechercheContactWindow::contactSelected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RechercheContactWindow::*)(std::list<Contact*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RechercheContactWindow::listContactsUpdated)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RechercheContactWindow::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_RechercheContactWindow.data,
    qt_meta_data_RechercheContactWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RechercheContactWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RechercheContactWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RechercheContactWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RechercheContactWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void RechercheContactWindow::contactSelected(Contact * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RechercheContactWindow::listContactsUpdated(std::list<Contact*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
