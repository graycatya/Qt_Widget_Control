/****************************************************************************
** Meta object code from reading C++ file 'framelesswidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ControlTools/ControlWidget/framelesswidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'framelesswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FramelessWidget_t {
    QByteArrayData data[11];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FramelessWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FramelessWidget_t qt_meta_stringdata_FramelessWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FramelessWidget"
QT_MOC_LITERAL(1, 16, 10), // "setPadding"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "padding"
QT_MOC_LITERAL(4, 36, 13), // "setMoveEnable"
QT_MOC_LITERAL(5, 50, 10), // "moveEnable"
QT_MOC_LITERAL(6, 61, 15), // "setResizeEnable"
QT_MOC_LITERAL(7, 77, 12), // "resizeEnable"
QT_MOC_LITERAL(8, 90, 9), // "setWidget"
QT_MOC_LITERAL(9, 100, 8), // "QWidget*"
QT_MOC_LITERAL(10, 109, 6) // "widget"

    },
    "FramelessWidget\0setPadding\0\0padding\0"
    "setMoveEnable\0moveEnable\0setResizeEnable\0"
    "resizeEnable\0setWidget\0QWidget*\0widget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FramelessWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       6,    1,   40,    2, 0x0a /* Public */,
       8,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void FramelessWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FramelessWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setPadding((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setMoveEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setResizeEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setWidget((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FramelessWidget::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_FramelessWidget.data,
    qt_meta_data_FramelessWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FramelessWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FramelessWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FramelessWidget.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FramelessWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
