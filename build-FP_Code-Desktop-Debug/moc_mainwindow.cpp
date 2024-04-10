/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../FP_Code/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[26];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 5), // "start"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 3), // "log"
QT_MOC_LITERAL(4, 22, 5), // "power"
QT_MOC_LITERAL(5, 28, 2), // "on"
QT_MOC_LITERAL(6, 31, 3), // "off"
QT_MOC_LITERAL(7, 35, 13), // "updateBattery"
QT_MOC_LITERAL(8, 49, 5), // "intil"
QT_MOC_LITERAL(9, 55, 9), // "dataEntry"
QT_MOC_LITERAL(10, 65, 4), // "stop"
QT_MOC_LITERAL(11, 70, 5), // "pause"
QT_MOC_LITERAL(12, 76, 6), // "resume"
QT_MOC_LITERAL(13, 83, 10), // "disconnect"
QT_MOC_LITERAL(14, 94, 17), // "updateProgressBar"
QT_MOC_LITERAL(15, 112, 9), // "inputData"
QT_MOC_LITERAL(16, 122, 20), // "updateLightIndicator"
QT_MOC_LITERAL(17, 143, 5), // "color"
QT_MOC_LITERAL(18, 149, 4), // "math"
QT_MOC_LITERAL(19, 154, 12), // "SignalData[]"
QT_MOC_LITERAL(20, 167, 5), // "array"
QT_MOC_LITERAL(21, 173, 4), // "size"
QT_MOC_LITERAL(22, 178, 9), // "treatment"
QT_MOC_LITERAL(23, 188, 8), // "double[]"
QT_MOC_LITERAL(24, 197, 1), // "t"
QT_MOC_LITERAL(25, 199, 11) // "handleFlash"

    },
    "MainWindow\0start\0\0log\0power\0on\0off\0"
    "updateBattery\0intil\0dataEntry\0stop\0"
    "pause\0resume\0disconnect\0updateProgressBar\0"
    "inputData\0updateLightIndicator\0color\0"
    "math\0SignalData[]\0array\0size\0treatment\0"
    "double[]\0t\0handleFlash"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08 /* Private */,
       3,    0,  105,    2, 0x08 /* Private */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    2,  118,    2, 0x08 /* Private */,
      18,    2,  123,    2, 0x08 /* Private */,
      22,    1,  128,    2, 0x08 /* Private */,
      25,    0,  131,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   17,    2,
    QMetaType::Double, 0x80000000 | 19, QMetaType::Int,   20,   21,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->start(); break;
        case 1: _t->log(); break;
        case 2: _t->power(); break;
        case 3: _t->on(); break;
        case 4: _t->off(); break;
        case 5: _t->updateBattery(); break;
        case 6: _t->intil(); break;
        case 7: _t->dataEntry(); break;
        case 8: _t->stop(); break;
        case 9: _t->pause(); break;
        case 10: _t->resume(); break;
        case 11: _t->disconnect(); break;
        case 12: _t->updateProgressBar(); break;
        case 13: _t->inputData(); break;
        case 14: _t->updateLightIndicator((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 15: { double _r = _t->math((*reinterpret_cast< SignalData(*)[]>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->treatment((*reinterpret_cast< double(*)[]>(_a[1]))); break;
        case 17: _t->handleFlash(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
