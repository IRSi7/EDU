/****************************************************************************
** Meta object code from reading C++ file 'EventWindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../transport_company/EventWindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EventWindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EventWindow_t {
    const uint offsetsAndSize[22];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_EventWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_EventWindow_t qt_meta_stringdata_EventWindow = {
    {
QT_MOC_LITERAL(0, 11), // "EventWindow"
QT_MOC_LITERAL(12, 16), // "serviceRequested"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 8), // "uint32_t"
QT_MOC_LITERAL(39, 5), // "carId"
QT_MOC_LITERAL(45, 11), // "carRepaired"
QT_MOC_LITERAL(57, 21), // "onCompanyStateChanged"
QT_MOC_LITERAL(79, 7), // "Company"
QT_MOC_LITERAL(87, 7), // "company"
QT_MOC_LITERAL(95, 28), // "on_requestPushButton_pressed"
QT_MOC_LITERAL(124, 27) // "on_repairPushButton_pressed"

    },
    "EventWindow\0serviceRequested\0\0uint32_t\0"
    "carId\0carRepaired\0onCompanyStateChanged\0"
    "Company\0company\0on_requestPushButton_pressed\0"
    "on_repairPushButton_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EventWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,
       5,    1,   47,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   50,    2, 0x0a,    5 /* Public */,
       9,    0,   53,    2, 0x08,    7 /* Private */,
      10,    0,   54,    2, 0x08,    8 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EventWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EventWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->serviceRequested((*reinterpret_cast< uint32_t(*)>(_a[1]))); break;
        case 1: _t->carRepaired((*reinterpret_cast< uint32_t(*)>(_a[1]))); break;
        case 2: _t->onCompanyStateChanged((*reinterpret_cast< const Company(*)>(_a[1]))); break;
        case 3: _t->on_requestPushButton_pressed(); break;
        case 4: _t->on_repairPushButton_pressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EventWindow::*)(uint32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EventWindow::serviceRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EventWindow::*)(uint32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EventWindow::carRepaired)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject EventWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_EventWindow.offsetsAndSize,
    qt_meta_data_EventWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_EventWindow_t
, QtPrivate::TypeAndForceComplete<EventWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Company const &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *EventWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EventWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EventWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int EventWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void EventWindow::serviceRequested(uint32_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EventWindow::carRepaired(uint32_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
