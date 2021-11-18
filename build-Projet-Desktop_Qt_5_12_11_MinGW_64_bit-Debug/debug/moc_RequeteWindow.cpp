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
    QByteArrayData data[9];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RequeteWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RequeteWindow_t qt_meta_stringdata_RequeteWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "RequeteWindow"
QT_MOC_LITERAL(1, 14, 14), // "NombreContacts"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 20), // "EvenementEntre2Dates"
QT_MOC_LITERAL(4, 51, 20), // "ListeTodoDateContact"
QT_MOC_LITERAL(5, 72, 21), // "ListeTodoDateContacts"
QT_MOC_LITERAL(6, 94, 20), // "LoadInfosEvent2Dates"
QT_MOC_LITERAL(7, 115, 22), // "LoadInfosSelectContact"
QT_MOC_LITERAL(8, 138, 17) // "LoadInfosContacts"

    },
    "RequeteWindow\0NombreContacts\0\0"
    "EvenementEntre2Dates\0ListeTodoDateContact\0"
    "ListeTodoDateContacts\0LoadInfosEvent2Dates\0"
    "LoadInfosSelectContact\0LoadInfosContacts"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RequeteWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RequeteWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RequeteWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NombreContacts(); break;
        case 1: _t->EvenementEntre2Dates(); break;
        case 2: _t->ListeTodoDateContact(); break;
        case 3: _t->ListeTodoDateContacts(); break;
        case 4: _t->LoadInfosEvent2Dates(); break;
        case 5: _t->LoadInfosSelectContact(); break;
        case 6: _t->LoadInfosContacts(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
