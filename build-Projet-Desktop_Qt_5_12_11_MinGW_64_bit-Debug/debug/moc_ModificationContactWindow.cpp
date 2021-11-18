/****************************************************************************
** Meta object code from reading C++ file 'ModificationContactWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Projet/ModificationContactWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModificationContactWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModificationContactWindow_t {
    QByteArrayData data[17];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModificationContactWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModificationContactWindow_t qt_meta_stringdata_ModificationContactWindow = {
    {
QT_MOC_LITERAL(0, 0, 25), // "ModificationContactWindow"
QT_MOC_LITERAL(1, 26, 13), // "imageSelected"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 14), // "contactDeleted"
QT_MOC_LITERAL(4, 56, 8), // "Contact*"
QT_MOC_LITERAL(5, 65, 14), // "prenomModified"
QT_MOC_LITERAL(6, 80, 11), // "std::string"
QT_MOC_LITERAL(7, 92, 11), // "nomModified"
QT_MOC_LITERAL(8, 104, 18), // "entrepriseModified"
QT_MOC_LITERAL(9, 123, 17), // "telephoneModified"
QT_MOC_LITERAL(10, 141, 12), // "mailModified"
QT_MOC_LITERAL(11, 154, 13), // "photoModified"
QT_MOC_LITERAL(12, 168, 11), // "loadContact"
QT_MOC_LITERAL(13, 180, 10), // "ModifFiche"
QT_MOC_LITERAL(14, 191, 10), // "ChangeFile"
QT_MOC_LITERAL(15, 202, 16), // "supprimerContact"
QT_MOC_LITERAL(16, 219, 9) // "showImage"

    },
    "ModificationContactWindow\0imageSelected\0"
    "\0contactDeleted\0Contact*\0prenomModified\0"
    "std::string\0nomModified\0entrepriseModified\0"
    "telephoneModified\0mailModified\0"
    "photoModified\0loadContact\0ModifFiche\0"
    "ChangeFile\0supprimerContact\0showImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModificationContactWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    1,   82,    2, 0x06 /* Public */,
       5,    2,   85,    2, 0x06 /* Public */,
       7,    2,   90,    2, 0x06 /* Public */,
       8,    2,   95,    2, 0x06 /* Public */,
       9,    2,  100,    2, 0x06 /* Public */,
      10,    2,  105,    2, 0x06 /* Public */,
      11,    2,  110,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,  115,    2, 0x0a /* Public */,
      13,    0,  118,    2, 0x0a /* Public */,
      14,    0,  119,    2, 0x0a /* Public */,
      15,    0,  120,    2, 0x0a /* Public */,
      16,    1,  121,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void ModificationContactWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModificationContactWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageSelected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->contactDeleted((*reinterpret_cast< Contact*(*)>(_a[1]))); break;
        case 2: _t->prenomModified((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 3: _t->nomModified((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 4: _t->entrepriseModified((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 5: _t->telephoneModified((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 6: _t->mailModified((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 7: _t->photoModified((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 8: _t->loadContact((*reinterpret_cast< Contact*(*)>(_a[1]))); break;
        case 9: _t->ModifFiche(); break;
        case 10: _t->ChangeFile(); break;
        case 11: _t->supprimerContact(); break;
        case 12: _t->showImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ModificationContactWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModificationContactWindow::imageSelected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ModificationContactWindow::*)(Contact * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModificationContactWindow::contactDeleted)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ModificationContactWindow::*)(Contact * , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModificationContactWindow::prenomModified)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ModificationContactWindow::*)(Contact * , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModificationContactWindow::nomModified)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ModificationContactWindow::*)(Contact * , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModificationContactWindow::entrepriseModified)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ModificationContactWindow::*)(Contact * , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModificationContactWindow::telephoneModified)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ModificationContactWindow::*)(Contact * , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModificationContactWindow::mailModified)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ModificationContactWindow::*)(Contact * , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModificationContactWindow::photoModified)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ModificationContactWindow::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ModificationContactWindow.data,
    qt_meta_data_ModificationContactWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ModificationContactWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModificationContactWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModificationContactWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ModificationContactWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ModificationContactWindow::imageSelected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ModificationContactWindow::contactDeleted(Contact * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ModificationContactWindow::prenomModified(Contact * _t1, std::string _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ModificationContactWindow::nomModified(Contact * _t1, std::string _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ModificationContactWindow::entrepriseModified(Contact * _t1, std::string _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ModificationContactWindow::telephoneModified(Contact * _t1, std::string _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ModificationContactWindow::mailModified(Contact * _t1, std::string _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ModificationContactWindow::photoModified(Contact * _t1, std::string _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
