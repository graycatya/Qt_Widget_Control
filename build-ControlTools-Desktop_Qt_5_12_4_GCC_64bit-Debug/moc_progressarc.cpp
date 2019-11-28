/****************************************************************************
** Meta object code from reading C++ file 'progressarc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ControlTools/ProgressBar/progressarc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'progressarc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProgressArc_t {
    QByteArrayData data[13];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProgressArc_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProgressArc_t qt_meta_stringdata_ProgressArc = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ProgressArc"
QT_MOC_LITERAL(1, 12, 15), // "ProgressOutSlot"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "Update_Value"
QT_MOC_LITERAL(4, 42, 5), // "value"
QT_MOC_LITERAL(5, 48, 14), // "Update_Cortoon"
QT_MOC_LITERAL(6, 63, 12), // "m_plineWidth"
QT_MOC_LITERAL(7, 76, 12), // "m_plineColor"
QT_MOC_LITERAL(8, 89, 14), // "m_pborderWidth"
QT_MOC_LITERAL(9, 104, 14), // "m_pborderColor"
QT_MOC_LITERAL(10, 119, 10), // "m_pbgColor"
QT_MOC_LITERAL(11, 130, 8), // "m_yvalue"
QT_MOC_LITERAL(12, 139, 10) // "m_bCortoon"

    },
    "ProgressArc\0ProgressOutSlot\0\0Update_Value\0"
    "value\0Update_Cortoon\0m_plineWidth\0"
    "m_plineColor\0m_pborderWidth\0m_pborderColor\0"
    "m_pbgColor\0m_yvalue\0m_bCortoon"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProgressArc[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       7,   34, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   30,    2, 0x0a /* Public */,
       5,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::Int, 0x00095003,
       7, QMetaType::QColor, 0x00095003,
       8, QMetaType::Int, 0x00095003,
       9, QMetaType::QColor, 0x00095003,
      10, QMetaType::QColor, 0x00095003,
      11, QMetaType::Int, 0x00095003,
      12, QMetaType::Bool, 0x00095003,

       0        // eod
};

void ProgressArc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProgressArc *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ProgressOutSlot(); break;
        case 1: _t->Update_Value((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->Update_Cortoon(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ProgressArc::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProgressArc::ProgressOutSlot)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ProgressArc *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->GetLineWidth(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->GetLineColor(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->GetBorderWidth(); break;
        case 3: *reinterpret_cast< QColor*>(_v) = _t->GetBorderColor(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = _t->GetBgColor(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->GetValue(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->GetCortoon(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ProgressArc *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->SetLineWidth(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->SetLineColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->SetBorderWidth(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->SetBorderColor(*reinterpret_cast< QColor*>(_v)); break;
        case 4: _t->SetBgColor(*reinterpret_cast< QColor*>(_v)); break;
        case 5: _t->SetValue(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->SetCortoon(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ProgressArc::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ProgressArc.data,
    qt_meta_data_ProgressArc,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProgressArc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProgressArc::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProgressArc.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ProgressArc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ProgressArc::ProgressOutSlot()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
