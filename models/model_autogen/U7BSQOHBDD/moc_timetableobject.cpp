/****************************************************************************
** Meta object code from reading C++ file 'timetableobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/timetableobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timetableobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TimetableObject_t {
    QByteArrayData data[5];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimetableObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimetableObject_t qt_meta_stringdata_TimetableObject = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TimetableObject"
QT_MOC_LITERAL(1, 16, 2), // "id"
QT_MOC_LITERAL(2, 19, 10), // "timeslotId"
QT_MOC_LITERAL(3, 30, 10), // "auditoryId"
QT_MOC_LITERAL(4, 41, 7) // "blockId"

    },
    "TimetableObject\0id\0timeslotId\0auditoryId\0"
    "blockId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimetableObject[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       4,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095003,
       2, QMetaType::Int, 0x00095003,
       3, QMetaType::Int, 0x00095003,
       4, QMetaType::Int, 0x00095003,

       0        // eod
};

void TimetableObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<TimetableObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getid(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->gettimeslotId(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getauditoryId(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getblockId(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<TimetableObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setid(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->settimeslotId(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setauditoryId(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setblockId(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject TimetableObject::staticMetaObject = { {
    &TSqlObject::staticMetaObject,
    qt_meta_stringdata_TimetableObject.data,
    qt_meta_data_TimetableObject,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TimetableObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimetableObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TimetableObject.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(this);
    return TSqlObject::qt_metacast(_clname);
}

int TimetableObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
