/****************************************************************************
** Meta object code from reading C++ file 'item_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ebay_selling_list/x._series/untitledv1.1/untitledv1.1/item_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'item_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_item_widget_t {
    QByteArrayData data[19];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_item_widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_item_widget_t qt_meta_stringdata_item_widget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "item_widget"
QT_MOC_LITERAL(1, 12, 16), // "selectionChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 14), // "QItemSelection"
QT_MOC_LITERAL(4, 45, 8), // "selected"
QT_MOC_LITERAL(5, 54, 18), // "showAddEntryDialog"
QT_MOC_LITERAL(6, 73, 8), // "addEntry"
QT_MOC_LITERAL(7, 82, 6), // "itemId"
QT_MOC_LITERAL(8, 89, 5), // "brand"
QT_MOC_LITERAL(9, 95, 10), // "typeOfItem"
QT_MOC_LITERAL(10, 106, 11), // "colorOfItem"
QT_MOC_LITERAL(11, 118, 4), // "cost"
QT_MOC_LITERAL(12, 123, 4), // "sold"
QT_MOC_LITERAL(13, 128, 6), // "weight"
QT_MOC_LITERAL(14, 135, 6), // "profit"
QT_MOC_LITERAL(15, 142, 9), // "dateAdded"
QT_MOC_LITERAL(16, 152, 9), // "editEntry"
QT_MOC_LITERAL(17, 162, 11), // "totalProfit"
QT_MOC_LITERAL(18, 174, 11) // "removeEntry"

    },
    "item_widget\0selectionChanged\0\0"
    "QItemSelection\0selected\0showAddEntryDialog\0"
    "addEntry\0itemId\0brand\0typeOfItem\0"
    "colorOfItem\0cost\0sold\0weight\0profit\0"
    "dateAdded\0editEntry\0totalProfit\0"
    "removeEntry"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_item_widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x0a /* Public */,
       6,    9,   48,    2, 0x0a /* Public */,
      16,    0,   67,    2, 0x0a /* Public */,
      17,    0,   68,    2, 0x0a /* Public */,
      18,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Float, QMetaType::Int, QMetaType::QString,    7,    8,    9,   10,   11,   12,   13,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void item_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<item_widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1]))); break;
        case 1: _t->showAddEntryDialog(); break;
        case 2: _t->addEntry((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< float(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9]))); break;
        case 3: _t->editEntry(); break;
        case 4: _t->totalProfit(); break;
        case 5: _t->removeEntry(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QItemSelection >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (item_widget::*)(const QItemSelection & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&item_widget::selectionChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject item_widget::staticMetaObject = { {
    &QTabWidget::staticMetaObject,
    qt_meta_stringdata_item_widget.data,
    qt_meta_data_item_widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *item_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *item_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_item_widget.stringdata0))
        return static_cast<void*>(this);
    return QTabWidget::qt_metacast(_clname);
}

int item_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void item_widget::selectionChanged(const QItemSelection & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
