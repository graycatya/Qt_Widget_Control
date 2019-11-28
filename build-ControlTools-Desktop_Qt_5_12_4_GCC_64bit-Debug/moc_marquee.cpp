/****************************************************************************
** Meta object code from reading C++ file 'marquee.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ControlTools/Marquee/marquee.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'marquee.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Marquee_t {
    QByteArrayData data[8];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Marquee_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Marquee_t qt_meta_stringdata_Marquee = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Marquee"
QT_MOC_LITERAL(1, 8, 21), // "Update_Marquee_Signal"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 19), // "Update_Marquee_Slot"
QT_MOC_LITERAL(4, 51, 5), // "SPEED"
QT_MOC_LITERAL(5, 57, 4), // "Slow"
QT_MOC_LITERAL(6, 62, 9), // "Secondary"
QT_MOC_LITERAL(7, 72, 5) // "Quick"

    },
    "Marquee\0Update_Marquee_Signal\0\0"
    "Update_Marquee_Slot\0SPEED\0Slow\0Secondary\0"
    "Quick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Marquee[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       1,   26, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // enums: name, alias, flags, count, data
       4,    4, 0x0,    3,   31,

 // enum data: key, value
       5, uint(Marquee::Slow),
       6, uint(Marquee::Secondary),
       7, uint(Marquee::Quick),

       0        // eod
};

void Marquee::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Marquee *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Update_Marquee_Signal(); break;
        case 1: _t->Update_Marquee_Slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Marquee::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Marquee::Update_Marquee_Signal)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Marquee::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Marquee.data,
    qt_meta_data_Marquee,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Marquee::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Marquee::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Marquee.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Marquee::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Marquee::Update_Marquee_Signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
