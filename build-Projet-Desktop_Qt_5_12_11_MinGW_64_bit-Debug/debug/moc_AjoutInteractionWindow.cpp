/****************************************************************************
** Meta object code from reading C++ file 'AjoutInteractionWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Projet/AjoutInteractionWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AjoutInteractionWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AjoutInteractionWindow_t {
    QByteArrayData data[11];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AjoutInteractionWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AjoutInteractionWindow_t qt_meta_stringdata_AjoutInteractionWindow = {
    {
QT_MOC_LITERAL(0, 0, 22), // "AjoutInteractionWindow"
QT_MOC_LITERAL(1, 23, 16), // "ajoutInteraction"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 8), // "Contact*"
QT_MOC_LITERAL(4, 50, 12), // "Interaction*"
QT_MOC_LITERAL(5, 63, 19), // "listContactsUpdated"
QT_MOC_LITERAL(6, 83, 19), // "std::list<Contact*>"
QT_MOC_LITERAL(7, 103, 17), // "onEndModifContact"
QT_MOC_LITERAL(8, 121, 13), // "selectContact"
QT_MOC_LITERAL(9, 135, 14), // "ajoutEvenement"
QT_MOC_LITERAL(10, 150, 17) // "selectInteraction"

    },
    "AjoutInteractionWindow\0ajoutInteraction\0"
    "\0Contact*\0Interaction*\0listContactsUpdated\0"
    "std::list<Contact*>\0onEndModifContact\0"
    "selectContact\0ajoutEvenement\0"
    "selectInteraction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AjoutInteractionWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       1,    2,   54,    2, 0x06 /* Public */,
       5,    1,   59,    2, 0x06 /* Public */,
       7,    0,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   63,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    1,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

       0        // eod
};

void AjoutInteractionWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AjoutInteractionWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ajoutInteraction((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->ajoutInteraction((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< Interaction*(*)>(_a[2]))); break;
        case 2: _t->listContactsUpdated((*reinterpret_cast< std::list<Contact*>(*)>(_a[1]))); break;
        case 3: _t->onEndModifContact(); break;
        case 4: _t->selectContact((*reinterpret_cast< Contact*(*)>(_a[1]))); break;
        case 5: _t->ajoutEvenement(); break;
        case 6: _t->selectInteraction((*reinterpret_cast< Interaction*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AjoutInteractionWindow::*)(Contact * , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AjoutInteractionWindow::ajoutInteraction)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AjoutInteractionWindow::*)(Contact * , Interaction * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AjoutInteractionWindow::ajoutInteraction)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AjoutInteractionWindow::*)(std::list<Contact*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AjoutInteractionWindow::listContactsUpdated)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AjoutInteractionWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AjoutInteractionWindow::onEndModifContact)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AjoutInteractionWindow::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_AjoutInteractionWindow.data,
    qt_meta_data_AjoutInteractionWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AjoutInteractionWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AjoutInteractionWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AjoutInteractionWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AjoutInteractionWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void AjoutInteractionWindow::ajoutInteraction(Contact * _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AjoutInteractionWindow::ajoutInteraction(Contact * _t1, Interaction * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AjoutInteractionWindow::listContactsUpdated(std::list<Contact*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AjoutInteractionWindow::onEndModifContact()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
