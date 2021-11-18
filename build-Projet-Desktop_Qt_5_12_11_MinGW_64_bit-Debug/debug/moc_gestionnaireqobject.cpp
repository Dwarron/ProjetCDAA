/****************************************************************************
** Meta object code from reading C++ file 'GestionnaireQObject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Projet/GestionnaireQObject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GestionnaireQObject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GestionnaireQObject_t {
    QByteArrayData data[14];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GestionnaireQObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GestionnaireQObject_t qt_meta_stringdata_GestionnaireQObject = {
    {
QT_MOC_LITERAL(0, 0, 19), // "GestionnaireQObject"
QT_MOC_LITERAL(1, 20, 19), // "listContactsUpdated"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 16), // "onContactCreated"
QT_MOC_LITERAL(4, 58, 8), // "Contact*"
QT_MOC_LITERAL(5, 67, 13), // "deleteContact"
QT_MOC_LITERAL(6, 81, 11), // "modifPrenom"
QT_MOC_LITERAL(7, 93, 11), // "std::string"
QT_MOC_LITERAL(8, 105, 8), // "modifNom"
QT_MOC_LITERAL(9, 114, 15), // "modifEntreprise"
QT_MOC_LITERAL(10, 130, 14), // "modifTelephone"
QT_MOC_LITERAL(11, 145, 9), // "modifMail"
QT_MOC_LITERAL(12, 155, 10), // "modifPhoto"
QT_MOC_LITERAL(13, 166, 13) // "createContact"

    },
    "GestionnaireQObject\0listContactsUpdated\0"
    "\0onContactCreated\0Contact*\0deleteContact\0"
    "modifPrenom\0std::string\0modifNom\0"
    "modifEntreprise\0modifTelephone\0modifMail\0"
    "modifPhoto\0createContact"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GestionnaireQObject[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   68,    2, 0x08 /* Private */,
       6,    2,   71,    2, 0x08 /* Private */,
       8,    2,   76,    2, 0x08 /* Private */,
       9,    2,   81,    2, 0x08 /* Private */,
      10,    2,   86,    2, 0x08 /* Private */,
      11,    2,   91,    2, 0x08 /* Private */,
      12,    2,   96,    2, 0x08 /* Private */,
      13,    6,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 7,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 7,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 7,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 7,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 7,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 7,    2,    2,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 7,    2,    2,    2,    2,    2,    2,

       0        // eod
};

void GestionnaireQObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GestionnaireQObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->listContactsUpdated(); break;
        case 1: _t->onContactCreated((*reinterpret_cast< Contact*(*)>(_a[1]))); break;
        case 2: _t->deleteContact((*reinterpret_cast< Contact*(*)>(_a[1]))); break;
        case 3: _t->modifPrenom((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 4: _t->modifNom((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 5: _t->modifEntreprise((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 6: _t->modifTelephone((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 7: _t->modifMail((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 8: _t->modifPhoto((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 9: _t->createContact((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< std::string(*)>(_a[3])),(*reinterpret_cast< std::string(*)>(_a[4])),(*reinterpret_cast< std::string(*)>(_a[5])),(*reinterpret_cast< std::string(*)>(_a[6]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GestionnaireQObject::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GestionnaireQObject::listContactsUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GestionnaireQObject::*)(Contact * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GestionnaireQObject::onContactCreated)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GestionnaireQObject::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_GestionnaireQObject.data,
    qt_meta_data_GestionnaireQObject,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GestionnaireQObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GestionnaireQObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GestionnaireQObject.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GestionnaireQObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void GestionnaireQObject::listContactsUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GestionnaireQObject::onContactCreated(Contact * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
