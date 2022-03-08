#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QDebug>
#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTableWidget>
#include <QPushButton>
#include "usr.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Tcpclient; }
QT_END_NAMESPACE

class Tcpclient : public QMainWindow
{
    Q_OBJECT

    public:
        Tcpclient(QWidget *parent = nullptr);
        ~Tcpclient();

    private slots:
        void on_btn_connect_clicked();
        void doProcessConnected();
        void doProcessReadyRead();
        void doProcessDisConnected();
        void doProcessError(QAbstractSocket::SocketError);

        void on_btn_send_clicked();
        void renewUserTable();

        void deleteUser();

//    public slots:
//        void setChater(usr* user);

    private:
        Ui::Tcpclient *ui;
        void init();

        QTcpSocket* myclient;
        QList<usr*> onlineUsers;//所有用户
        QString chater;//聊天对方
};

#endif // TCPCLIENT_H
