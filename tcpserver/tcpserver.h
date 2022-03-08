#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QList>
#include <thread>
#include <windows.h>

class server;

QT_BEGIN_NAMESPACE
namespace Ui { class tcpserver; }
QT_END_NAMESPACE

class tcpserver : public QMainWindow
{
    Q_OBJECT

public:
    tcpserver(QWidget *parent = nullptr);
    ~tcpserver();

public slots:
    void on_btn_connect_clicked();
    void newThread();
    void doprocessOnConnect();
    void doprocessOnConnectError(QAbstractSocket::SocketError);
    void doprocessOnDisconnect();
    void doprocessOnReadyRead();
    void on_btn_send_clicked();
    void doprocessOnConnected();

    void renewUserTable();
    void deleteUser(QString socket);

public:
    Ui::tcpserver *ui;
    QTcpServer* myserver;
    QList<QTcpSocket*>clients;
    void init();

};

//DWORD WINAPI Fun(LPVOID lpParamter);
void doprocessOnReadyRead(tcpserver* tcpserver);

#endif // TCPSERVER_H
