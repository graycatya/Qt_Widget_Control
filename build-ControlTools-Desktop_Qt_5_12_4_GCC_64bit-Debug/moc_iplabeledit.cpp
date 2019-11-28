/****************************************************************************
** Meta object code from reading C++ file 'iplabeledit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ControlTools/IpLabel/iplabeledit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'iplabeledit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IpLabelEdit_t {
    QByteArrayData data[23];
    char stringdata0[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IpLabelEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IpLabelEdit_t qt_meta_stringdata_IpLabelEdit = {
    {
QT_MOC_LITERAL(0, 0, 11), // "IpLabelEdit"
QT_MOC_LITERAL(1, 12, 5), // "SetIp"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 2), // "ip"
QT_MOC_LITERAL(4, 22, 5), // "Clear"
QT_MOC_LITERAL(5, 28, 18), // "SetBackGroundColor"
QT_MOC_LITERAL(6, 47, 15), // "backgroundcolor"
QT_MOC_LITERAL(7, 63, 14), // "SetBorderColor"
QT_MOC_LITERAL(8, 78, 11), // "bordercolor"
QT_MOC_LITERAL(9, 90, 15), // "SetBorderRadius"
QT_MOC_LITERAL(10, 106, 12), // "borderradius"
QT_MOC_LITERAL(11, 119, 12), // "SetTextColor"
QT_MOC_LITERAL(12, 132, 9), // "textColor"
QT_MOC_LITERAL(13, 142, 11), // "SetTextFont"
QT_MOC_LITERAL(14, 154, 8), // "textfont"
QT_MOC_LITERAL(15, 163, 11), // "textChanged"
QT_MOC_LITERAL(16, 175, 4), // "text"
QT_MOC_LITERAL(17, 180, 5), // "m_qIp"
QT_MOC_LITERAL(18, 186, 18), // "m_qBackGroundColor"
QT_MOC_LITERAL(19, 205, 14), // "m_qBorderColor"
QT_MOC_LITERAL(20, 220, 7), // "m_qFont"
QT_MOC_LITERAL(21, 228, 12), // "m_qTextColor"
QT_MOC_LITERAL(22, 241, 15) // "m_nBorderRadius"

    },
    "IpLabelEdit\0SetIp\0\0ip\0Clear\0"
    "SetBackGroundColor\0backgroundcolor\0"
    "SetBorderColor\0bordercolor\0SetBorderRadius\0"
    "borderradius\0SetTextColor\0textColor\0"
    "SetTextFont\0textfont\0textChanged\0text\0"
    "m_qIp\0m_qBackGroundColor\0m_qBorderColor\0"
    "m_qFont\0m_qTextColor\0m_nBorderRadius"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IpLabelEdit[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       6,   76, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       4,    0,   57,    2, 0x0a /* Public */,
       5,    1,   58,    2, 0x0a /* Public */,
       7,    1,   61,    2, 0x0a /* Public */,
       9,    1,   64,    2, 0x0a /* Public */,
      11,    1,   67,    2, 0x0a /* Public */,
      13,    1,   70,    2, 0x0a /* Public */,
      15,    1,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,    6,
    QMetaType::Void, QMetaType::QColor,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QColor,   12,
    QMetaType::Void, QMetaType::QFont,   14,
    QMetaType::Void, QMetaType::QString,   16,

 // properties: name, type, flags
      17, QMetaType::QString, 0x00095003,
      18, QMetaType::QColor, 0x00095003,
      19, QMetaType::QColor, 0x00095003,
      20, QMetaType::QFont, 0x00095003,
      21, QMetaType::QColor, 0x00095003,
      22, QMetaType::Int, 0x00095003,

       0        // eod
};

void IpLabelEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IpLabelEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SetIp((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->Clear(); break;
        case 2: _t->SetBackGroundColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 3: _t->SetBorderColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 4: _t->SetBorderRadius((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 5: _t->SetTextColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 6: _t->SetTextFont((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 7: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<IpLabelEdit *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->GetIp(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->GetBackGroundColor(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->GetBorderColor(); break;
        case 3: *reinterpret_cast< QFont*>(_v) = _t->GetTextFont(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = _t->GetTextColor(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->GetBorderRadius(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<IpLabelEdit *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->SetIp(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->SetBackGroundColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->SetBorderColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: _t->SetTextFont(*reinterpret_cast< QFont*>(_v)); break;
        case 4: _t->SetTextColor(*reinterpret_cast< QColor*>(_v)); break;
        case 5: _t->SetBorderRadius(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject IpLabelEdit::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_IpLabelEdit.data,
    qt_meta_data_IpLabelEdit,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IpLabelEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IpLabelEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IpLabelEdit.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int IpLabelEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
