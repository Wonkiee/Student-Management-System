/****************************************************************************
** Meta object code from reading C++ file 'MainPage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainPage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainPage_t {
    QByteArrayData data[14];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainPage_t qt_meta_stringdata_MainPage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MainPage"
QT_MOC_LITERAL(1, 9, 7), // "onClose"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 8), // "onSubmit"
QT_MOC_LITERAL(4, 27, 8), // "onSearch"
QT_MOC_LITERAL(5, 36, 23), // "onClickScanFromDatabase"
QT_MOC_LITERAL(6, 60, 29), // "onClickSearchStudentByENumber"
QT_MOC_LITERAL(7, 90, 26), // "onClickSearchStudentByName"
QT_MOC_LITERAL(8, 117, 13), // "onIndexChange"
QT_MOC_LITERAL(9, 131, 5), // "index"
QT_MOC_LITERAL(10, 137, 16), // "onSubmitHostName"
QT_MOC_LITERAL(11, 154, 20), // "onChangeAcedemicYear"
QT_MOC_LITERAL(12, 175, 17), // "onSetAcedemicYear"
QT_MOC_LITERAL(13, 193, 14) // "onConfirmBatch"

    },
    "MainPage\0onClose\0\0onSubmit\0onSearch\0"
    "onClickScanFromDatabase\0"
    "onClickSearchStudentByENumber\0"
    "onClickSearchStudentByName\0onIndexChange\0"
    "index\0onSubmitHostName\0onChangeAcedemicYear\0"
    "onSetAcedemicYear\0onConfirmBatch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    1,   75,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainPage *_t = static_cast<MainPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onClose(); break;
        case 1: _t->onSubmit(); break;
        case 2: _t->onSearch(); break;
        case 3: _t->onClickScanFromDatabase(); break;
        case 4: _t->onClickSearchStudentByENumber(); break;
        case 5: _t->onClickSearchStudentByName(); break;
        case 6: _t->onIndexChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->onSubmitHostName(); break;
        case 8: _t->onChangeAcedemicYear(); break;
        case 9: _t->onSetAcedemicYear(); break;
        case 10: _t->onConfirmBatch(); break;
        default: ;
        }
    }
}

const QMetaObject MainPage::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MainPage.data,
      qt_meta_data_MainPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainPage.stringdata0))
        return static_cast<void*>(const_cast< MainPage*>(this));
    return QDialog::qt_metacast(_clname);
}

int MainPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
