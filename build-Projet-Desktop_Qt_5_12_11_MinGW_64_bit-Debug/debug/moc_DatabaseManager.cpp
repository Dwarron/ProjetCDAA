/****************************************************************************
** Meta object code from reading C++ file 'DatabaseManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Projet/DatabaseManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DatabaseManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DatabaseManager_t {
    QByteArrayData data[29];
    char stringdata0[485];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DatabaseManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DatabaseManager_t qt_meta_stringdata_DatabaseManager = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DatabaseManager"
QT_MOC_LITERAL(1, 16, 11), // "loadContact"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "std::string"
QT_MOC_LITERAL(4, 41, 24), // "loadAndCreateInteraction"
QT_MOC_LITERAL(5, 66, 8), // "Contact*"
QT_MOC_LITERAL(6, 75, 15), // "loadInteraction"
QT_MOC_LITERAL(7, 91, 12), // "Interaction*"
QT_MOC_LITERAL(8, 104, 8), // "loadTodo"
QT_MOC_LITERAL(9, 113, 13), // "createContact"
QT_MOC_LITERAL(10, 127, 13), // "contactLoaded"
QT_MOC_LITERAL(11, 141, 16), // "updateContactNom"
QT_MOC_LITERAL(12, 158, 19), // "updateContactPrenom"
QT_MOC_LITERAL(13, 178, 23), // "updateContactEntreprise"
QT_MOC_LITERAL(14, 202, 22), // "updateContactTelephone"
QT_MOC_LITERAL(15, 225, 17), // "updateContactMail"
QT_MOC_LITERAL(16, 243, 18), // "updateContactPhoto"
QT_MOC_LITERAL(17, 262, 22), // "updateContactDateModif"
QT_MOC_LITERAL(18, 285, 29), // "updateDateDerniereSuppression"
QT_MOC_LITERAL(19, 315, 13), // "deleteContact"
QT_MOC_LITERAL(20, 329, 17), // "interactionLoaded"
QT_MOC_LITERAL(21, 347, 21), // "updateInteractionDate"
QT_MOC_LITERAL(22, 369, 23), // "updateInteractionResume"
QT_MOC_LITERAL(23, 393, 17), // "createInteraction"
QT_MOC_LITERAL(24, 411, 22), // "addExistingInteraction"
QT_MOC_LITERAL(25, 434, 11), // "createTodos"
QT_MOC_LITERAL(26, 446, 16), // "std::list<Todo*>"
QT_MOC_LITERAL(27, 463, 11), // "deleteTodos"
QT_MOC_LITERAL(28, 475, 9) // "deleteAll"

    },
    "DatabaseManager\0loadContact\0\0std::string\0"
    "loadAndCreateInteraction\0Contact*\0"
    "loadInteraction\0Interaction*\0loadTodo\0"
    "createContact\0contactLoaded\0"
    "updateContactNom\0updateContactPrenom\0"
    "updateContactEntreprise\0updateContactTelephone\0"
    "updateContactMail\0updateContactPhoto\0"
    "updateContactDateModif\0"
    "updateDateDerniereSuppression\0"
    "deleteContact\0interactionLoaded\0"
    "updateInteractionDate\0updateInteractionResume\0"
    "createInteraction\0addExistingInteraction\0"
    "createTodos\0std::list<Todo*>\0deleteTodos\0"
    "deleteAll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DatabaseManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    9,  129,    2, 0x06 /* Public */,
       4,    4,  148,    2, 0x06 /* Public */,
       6,    2,  157,    2, 0x06 /* Public */,
       8,    4,  162,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    3,  171,    2, 0x08 /* Private */,
      10,    2,  178,    2, 0x08 /* Private */,
      11,    2,  183,    2, 0x08 /* Private */,
      12,    2,  188,    2, 0x08 /* Private */,
      13,    2,  193,    2, 0x08 /* Private */,
      14,    2,  198,    2, 0x08 /* Private */,
      15,    2,  203,    2, 0x08 /* Private */,
      16,    2,  208,    2, 0x08 /* Private */,
      17,    2,  213,    2, 0x08 /* Private */,
      18,    1,  218,    2, 0x08 /* Private */,
      19,    1,  221,    2, 0x08 /* Private */,
      20,    2,  224,    2, 0x08 /* Private */,
      21,    2,  229,    2, 0x08 /* Private */,
      22,    2,  234,    2, 0x08 /* Private */,
      23,    3,  239,    2, 0x08 /* Private */,
      24,    2,  246,    2, 0x08 /* Private */,
      25,    2,  251,    2, 0x08 /* Private */,
      27,    1,  256,    2, 0x08 /* Private */,
      28,    0,  259,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5, 0x80000000 | 3, 0x80000000 | 3,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 5,    2,    2,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 3, 0x80000000 | 3, QMetaType::Bool,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 3, 0x80000000 | 3,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,    2,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 7,    2,    2,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 5, 0x80000000 | 3,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 5,    2,    2,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 26,    2,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,

       0        // eod
};

void DatabaseManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DatabaseManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadContact((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< std::string(*)>(_a[3])),(*reinterpret_cast< std::string(*)>(_a[4])),(*reinterpret_cast< std::string(*)>(_a[5])),(*reinterpret_cast< std::string(*)>(_a[6])),(*reinterpret_cast< std::string(*)>(_a[7])),(*reinterpret_cast< std::string(*)>(_a[8])),(*reinterpret_cast< std::string(*)>(_a[9]))); break;
        case 1: _t->loadAndCreateInteraction((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Contact*(*)>(_a[2])),(*reinterpret_cast< std::string(*)>(_a[3])),(*reinterpret_cast< std::string(*)>(_a[4]))); break;
        case 2: _t->loadInteraction((*reinterpret_cast< Interaction*(*)>(_a[1])),(*reinterpret_cast< Contact*(*)>(_a[2]))); break;
        case 3: _t->loadTodo((*reinterpret_cast< Interaction*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< std::string(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 4: _t->createContact((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< std::string(*)>(_a[3]))); break;
        case 5: _t->contactLoaded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Contact*(*)>(_a[2]))); break;
        case 6: _t->updateContactNom((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 7: _t->updateContactPrenom((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 8: _t->updateContactEntreprise((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 9: _t->updateContactTelephone((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 10: _t->updateContactMail((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 11: _t->updateContactPhoto((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 12: _t->updateContactDateModif((*reinterpret_cast< Contact*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 13: _t->updateDateDerniereSuppression((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 14: _t->deleteContact((*reinterpret_cast< Contact*(*)>(_a[1]))); break;
        case 15: _t->interactionLoaded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Interaction*(*)>(_a[2]))); break;
        case 16: _t->updateInteractionDate((*reinterpret_cast< Interaction*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 17: _t->updateInteractionResume((*reinterpret_cast< Interaction*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 18: _t->createInteraction((*reinterpret_cast< Interaction*(*)>(_a[1])),(*reinterpret_cast< Contact*(*)>(_a[2])),(*reinterpret_cast< std::string(*)>(_a[3]))); break;
        case 19: _t->addExistingInteraction((*reinterpret_cast< Interaction*(*)>(_a[1])),(*reinterpret_cast< Contact*(*)>(_a[2]))); break;
        case 20: _t->createTodos((*reinterpret_cast< Interaction*(*)>(_a[1])),(*reinterpret_cast< std::list<Todo*>(*)>(_a[2]))); break;
        case 21: _t->deleteTodos((*reinterpret_cast< Interaction*(*)>(_a[1]))); break;
        case 22: _t->deleteAll(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DatabaseManager::*)(int , std::string , std::string , std::string , std::string , std::string , std::string , std::string , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatabaseManager::loadContact)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DatabaseManager::*)(int , Contact * , std::string , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatabaseManager::loadAndCreateInteraction)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DatabaseManager::*)(Interaction * , Contact * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatabaseManager::loadInteraction)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DatabaseManager::*)(Interaction * , std::string , std::string , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatabaseManager::loadTodo)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DatabaseManager::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DatabaseManager.data,
    qt_meta_data_DatabaseManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DatabaseManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatabaseManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DatabaseManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DatabaseManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void DatabaseManager::loadContact(int _t1, std::string _t2, std::string _t3, std::string _t4, std::string _t5, std::string _t6, std::string _t7, std::string _t8, std::string _t9)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DatabaseManager::loadAndCreateInteraction(int _t1, Contact * _t2, std::string _t3, std::string _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DatabaseManager::loadInteraction(Interaction * _t1, Contact * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DatabaseManager::loadTodo(Interaction * _t1, std::string _t2, std::string _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
