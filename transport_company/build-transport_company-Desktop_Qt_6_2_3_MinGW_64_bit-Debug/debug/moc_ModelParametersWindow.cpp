/****************************************************************************
** Meta object code from reading C++ file 'ModelParametersWindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../transport_company/ModelParametersWindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModelParametersWindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModelParametersWindow_t {
    const uint offsetsAndSize[18];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ModelParametersWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ModelParametersWindow_t qt_meta_stringdata_ModelParametersWindow = {
    {
QT_MOC_LITERAL(0, 21), // "ModelParametersWindow"
QT_MOC_LITERAL(22, 22), // "modelParametersChanged"
QT_MOC_LITERAL(45, 0), // ""
QT_MOC_LITERAL(46, 8), // "uint32_t"
QT_MOC_LITERAL(55, 4), // "cars"
QT_MOC_LITERAL(60, 9), // "cargoCars"
QT_MOC_LITERAL(70, 9), // "mechanics"
QT_MOC_LITERAL(80, 1), // "l"
QT_MOC_LITERAL(82, 30) // "on_setParametersButton_pressed"

    },
    "ModelParametersWindow\0modelParametersChanged\0"
    "\0uint32_t\0cars\0cargoCars\0mechanics\0l\0"
    "on_setParametersButton_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModelParametersWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   35,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, QMetaType::Double,    4,    5,    6,    7,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ModelParametersWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModelParametersWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->modelParametersChanged((*reinterpret_cast< uint32_t(*)>(_a[1])),(*reinterpret_cast< uint32_t(*)>(_a[2])),(*reinterpret_cast< uint32_t(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 1: _t->on_setParametersButton_pressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ModelParametersWindow::*)(uint32_t , uint32_t , uint32_t , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelParametersWindow::modelParametersChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ModelParametersWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ModelParametersWindow.offsetsAndSize,
    qt_meta_data_ModelParametersWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ModelParametersWindow_t
, QtPrivate::TypeAndForceComplete<ModelParametersWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ModelParametersWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModelParametersWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModelParametersWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ModelParametersWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ModelParametersWindow::modelParametersChanged(uint32_t _t1, uint32_t _t2, uint32_t _t3, double _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
