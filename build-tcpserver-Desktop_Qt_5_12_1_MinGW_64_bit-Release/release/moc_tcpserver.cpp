/****************************************************************************
** Meta object code from reading C++ file 'tcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tcpserver/tcpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_tcpserver_t {
    QByteArrayData data[14];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tcpserver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tcpserver_t qt_meta_stringdata_tcpserver = {
    {
QT_MOC_LITERAL(0, 0, 9), // "tcpserver"
QT_MOC_LITERAL(1, 10, 22), // "on_btn_connect_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 9), // "newThread"
QT_MOC_LITERAL(4, 44, 18), // "doprocessOnConnect"
QT_MOC_LITERAL(5, 63, 23), // "doprocessOnConnectError"
QT_MOC_LITERAL(6, 87, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(7, 116, 21), // "doprocessOnDisconnect"
QT_MOC_LITERAL(8, 138, 20), // "doprocessOnReadyRead"
QT_MOC_LITERAL(9, 159, 19), // "on_btn_send_clicked"
QT_MOC_LITERAL(10, 179, 20), // "doprocessOnConnected"
QT_MOC_LITERAL(11, 200, 14), // "renewUserTable"
QT_MOC_LITERAL(12, 215, 10), // "deleteUser"
QT_MOC_LITERAL(13, 226, 6) // "socket"

    },
    "tcpserver\0on_btn_connect_clicked\0\0"
    "newThread\0doprocessOnConnect\0"
    "doprocessOnConnectError\0"
    "QAbstractSocket::SocketError\0"
    "doprocessOnDisconnect\0doprocessOnReadyRead\0"
    "on_btn_send_clicked\0doprocessOnConnected\0"
    "renewUserTable\0deleteUser\0socket"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tcpserver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    1,   67,    2, 0x0a /* Public */,
       7,    0,   70,    2, 0x0a /* Public */,
       8,    0,   71,    2, 0x0a /* Public */,
       9,    0,   72,    2, 0x0a /* Public */,
      10,    0,   73,    2, 0x0a /* Public */,
      11,    0,   74,    2, 0x0a /* Public */,
      12,    1,   75,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,

       0        // eod
};

void tcpserver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<tcpserver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_connect_clicked(); break;
        case 1: _t->newThread(); break;
        case 2: _t->doprocessOnConnect(); break;
        case 3: _t->doprocessOnConnectError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->doprocessOnDisconnect(); break;
        case 5: _t->doprocessOnReadyRead(); break;
        case 6: _t->on_btn_send_clicked(); break;
        case 7: _t->doprocessOnConnected(); break;
        case 8: _t->renewUserTable(); break;
        case 9: _t->deleteUser((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject tcpserver::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_tcpserver.data,
    qt_meta_data_tcpserver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *tcpserver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tcpserver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tcpserver.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int tcpserver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
