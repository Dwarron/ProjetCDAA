/****************************************************************************
** Meta object code from reading C++ file 'RequeteWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Projet/RequeteWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RequeteWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RequeteWindow_t {
    QByteArrayData data[13];
    char stringdata0[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RequeteWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RequeteWindow_t qt_meta_stringdata_RequeteWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "RequeteWindow"
QT_MOC_LITERAL(1, 14, 15), // "todoSetEffectue"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "Todo*"
QT_MOC_LITERAL(4, 37, 18), // "updateListContacts"
QT_MOC_LITERAL(5, 56, 19), // "std::list<Contact*>"
QT_MOC_LITERAL(6, 76, 27), // "loadInfosInteractions2Dates"
QT_MOC_LITERAL(7, 104, 16), // "loadInfosContact"
QT_MOC_LITERAL(8, 121, 8), // "Contact*"
QT_MOC_LITERAL(9, 130, 20), // "loadInfosAllContacts"
QT_MOC_LITERAL(10, 151, 30), // "todoItemCheckedListViewContact"
QT_MOC_LITERAL(11, 182, 14), // "QStandardItem*"
QT_MOC_LITERAL(12, 197, 34) // "todoItemCheckedListViewAllCon..."

    },
    "RequeteWindow\0todoSetEffectue\0\0Todo*\0"
    "updateListContacts\0std::list<Contact*>\0"
    "loadInfosInteractions2Dates\0"
    "loadInfosContact\0Contact*\0"
    "loadInfosAllContacts\0"
    "todoItemCheckedListViewContact\0"
    "QStandardItem*\0todoItemCheckedListViewAllContacts"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RequeteWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   59,    2, 0x08 /* Private */,
       6,    0,   62,    2, 0x08 /* Private */,
       7,    1,   63,    2, 0x08 /* Private */,
       7,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    1,   68,    2, 0x08 /* Private */,
      12,    1,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 11,    2,

       0        // eod
};

void RequeteWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RequeteWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->todoSetEffectue((*reinterpret_cast< Todo*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->updateListContacts((*reinterpret_cast< std::list<Contact*>(*)>(_a[1]))); break;
        case 2: _t->loadInfosInteractions2Dates(); break;
        case 3: _t->loadInfosContact((*reinterpret_cast< Contact*(*)>(_a[1]))); break;
        case 4: _t->loadInfosContact(); break;
        case 5: _t->loadInfosAllContacts(); break;
        case 6: _t->todoItemCheckedListViewContact((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 7: _t->todoItemCheckedListViewAllContacts((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RequeteWindow::*)(Todo * , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RequeteWindow::todoSetEffectue)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RequeteWindow::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_RequeteWindow.data,
    qt_meta_data_RequeteWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RequeteWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RequeteWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RequeteWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RequeteWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void RequeteWindow::todoSetEffectue(Todo * _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
