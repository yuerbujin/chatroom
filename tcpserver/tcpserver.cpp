#include "tcpserver.h"
#include "ui_tcpserver.h"
#include "server.h"

tcpserver::tcpserver(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tcpserver)
{
    ui->setupUi(this);
    init();
}

tcpserver::~tcpserver()
{
    delete ui;
}
void tcpserver::init()
{
    myserver = new QTcpServer(this);

    QStatusBar* stBar = statusBar();
    setStatusBar(stBar);
}

void tcpserver::on_btn_connect_clicked()
{
    //自动配置ip
//    QList<QHostAddress>add = QNetworkInterface::allAddresses();
//    for (int i=0;i<add.length();i++) {
//        QHostAddress addr = add.at(i);
//        qDebug()<<addr.toString();
//    }
    //手动配置ip
    QString myadd = ui->clientAddress->text();
    QString myport = ui->clientPort->text();
    bool connectResult = myserver->listen(QHostAddress(myadd),myport.toInt());
    if(!connectResult)
    {
        ui->statusbar->showMessage(tr("绑定失败"), 4000);
    }
    else
    {
        ui->statusbar->showMessage(tr("绑定成功"), 4000);
    }

    myserver->setMaxPendingConnections(100);
//    connect(myserver,SIGNAL(newConnection()),this,  [=](){
//       doprocessOnConnect();
//    });

    connect(myserver,SIGNAL(newConnection()),this,SLOT(doprocessOnConnect()));
    connect(myserver,SIGNAL(acceptError(QAbstractSocket::SocketError)),
            this,SLOT(doprocessOnConnectError(QAbstractSocket::SocketError)));
}

void tcpserver::newThread()
{
    doprocessOnConnect();
}

void tcpserver::doprocessOnConnect()
{
//    qDebug() << "doprocessOnConnect()!!!!" << endl;
    QTcpSocket *client = myserver->nextPendingConnection();//当前的连接者
    clients.append(client);
    //告知对方ip和port
    QString flag = "通告\n";
    client->write(flag.toUtf8());

    QString port = QString("%1").arg(client->peerPort());
    QString msg = client->peerAddress().toString() + ":" + port + "\n";
    qDebug() << msg;
    client->write(msg.toUtf8());

    renewUserTable();    //更新在线用户列表

    connect(client,SIGNAL(disconnected()),this,SLOT(doprocessOnDisconnect()));//客户端退出
    connect(client,SIGNAL(readyRead()),this,SLOT(doprocessOnReadyRead()));//读取客户端内容
    connect(client,SIGNAL(connected()),this,SLOT(doprocessOnConnected()));
}

void tcpserver::doprocessOnConnectError(QAbstractSocket::SocketError err)
{
    qDebug() << err;
}

void tcpserver::doprocessOnDisconnect()
{
    QTcpSocket *client = (QTcpSocket *)this->sender();
    QString msg = QString("客户端[%1:%2] 退出！")
            .arg(client->peerAddress().toString())//客户端地址和端口
            .arg(client->peerPort()) ;
    ui->textEdit->append(msg);
    for (int i=0;i<clients.length();i++)
    {//删除对应的client
        if(clients.at(i)->peerAddress().toString() == client->peerAddress().toString()
                &&clients.at(i)->peerPort() == client->peerPort())
        {
            QString port = QString("%1").arg(clients.at(i)->peerPort());
            QString socket = clients.at(i)->peerAddress().toString() + ":" + port + "\n";
            for(int j=0; j<clients.length(); j++)
            {
                QString msg_begin = "删除一个用户\n";
                clients.at(j)->write(msg_begin.toUtf8());
                clients.at(j)->write(socket.toUtf8());
            }

            clients.removeAt(i);
            break;
        }
    }

    qDebug() << "here!!!" << clients.count() << endl;
}

void tcpserver::doprocessOnReadyRead()//读取客户端发送的东西
{
//        server* tcp = new server();

        //新线程
//        std::thread* t = new std::thread(doprocessOnConnect, this);
//        t->join();

//    //client 给 clients.at(i) 发送
    QTcpSocket *client = (QTcpSocket *)this->sender();
    QString msg;
    QString target = client->readLine();

    while (!client->atEnd()) {
        QString pro = QString("客户端[%1:%2]发送：").arg(client->peerAddress().toString()).arg(client->peerPort());
        msg = QString(pro + client->readAll());
    }
     ui->textEdit->append(msg);

     if (target == "special\n")
     {
         qDebug() << "22222222" ;

         //flood
         for(int i=0;i<clients.length();i++)
         {
//             if(clients.at(i)->peerAddress().toString() == ip
//                     &&clients.at(i)->peerPort() == port)
//             {
                 qDebug()<<msg;
                 QString ip2 = clients.at(i)->peerAddress().toString();
                 QString port2 = QString("%1").arg(clients.at(i)->peerPort());
                 msg = "群聊\n" + msg;
                 qDebug() << "333333" << msg << " " << i ;

                 clients.at(i)->write(msg.toUtf8());


//             }
         }

     }
     else {
         //转发
         target = target.left(target.size() - 1);//删除换行符
         QStringList list = target.split(":");
         QString ip = list.at(0);
         quint16 port = list.at(1).toUInt();

         //找到用户
         for(int i=0;i<clients.length();i++)
         {
             if(clients.at(i)->peerAddress().toString() == ip
                     &&clients.at(i)->peerPort() == port)
             {
                 qDebug()<<msg;
                 QString ip2 = client->peerAddress().toString();
                 QString port2 = QString("%1").arg(client->peerPort());
                 msg = ip2+ ":" + port2 + '\n' + msg;
                 clients.at(i)->write(msg.toUtf8());

                 break;
             }
         }
     }
}

void doprocessOnReadyRead(tcpserver* tcpserver)
{
    //client 给 clients.at(i) 发送
    QTcpSocket *client = (QTcpSocket *)tcpserver->sender();
    QString msg;
    QString target = client->readLine();

    while (!client->atEnd()) {
        QString pro = QString("客户端[%1:%2]发送：").arg(client->peerAddress().toString()).arg(client->peerPort());
        msg = QString(pro + client->readAll());
    }
//    tcpserver->ui->textEdit->append(msg);

     //转发
     target = target.left(target.size() - 1);//删除换行符
     QStringList list = target.split(":");
     QString ip = list.at(0);
     quint16 port = list.at(1).toUInt();

     //找到用户
     for(int i=0;i<tcpserver->clients.length();i++)
     {
         if(tcpserver->clients.at(i)->peerAddress().toString() == ip
                 &&tcpserver->clients.at(i)->peerPort() == port)
         {
             qDebug()<<msg;
             QString ip2 = client->peerAddress().toString();
             QString port2 = QString("%1").arg(client->peerPort());
             msg = ip2+ ":" + port2 + '\n' + msg;
             tcpserver->clients.at(i)->write(msg.toUtf8());

             break;
         }
     }
}

void tcpserver::doprocessOnConnected()
{
    QTcpSocket *client = (QTcpSocket *)this->sender();
    QString msg = QString("客户端[%1:%2]连入")
            .arg(client->peerAddress().toString())//客户端地址和端口
            .arg(client->peerPort());
    ui->textEdit->append(msg);
}

void tcpserver::on_btn_send_clicked()//转发消息
{
    QString ip = ui->client_ip->text();
    quint16 port = ui->client_port->text().toUInt();

    for(int i=0;i<clients.length();i++)
    {
        if(clients.at(i)->peerAddress().toString() == ip
                &&clients.at(i)->peerPort() == port)
        {
            QString msg = ui->sendmessage->toPlainText();
            qDebug()<<msg;
            clients.at(i)->write(msg.toUtf8());

            break;
        }
    }
}

void tcpserver::renewUserTable()
{
    for(int i=0;i<clients.length();i++)
    {
        QString msg_begin = "更新在线用户列表开始\n";
        clients.at(i)->write(msg_begin.toUtf8());

        for(int j=0; j<clients.length(); j++)
        {
            QString port = QString("%1").arg(clients.at(j)->peerPort());
            QString msg = clients.at(j)->peerAddress().toString() + ":" + port + "\n";
            clients.at(i)->write(msg.toUtf8());
        }

        QString msg_end = "更新在线用户列表结束\n";
        clients.at(i)->write(msg_end.toUtf8());
    }
}

void tcpserver::deleteUser(QString socket)
{
    for(int j=0; j<clients.length(); j++)
    {
        QString msg_begin = "删除一个用户\n";
        clients.at(j)->write(msg_begin.toUtf8());
        clients.at(j)->write(socket.toUtf8());
//        QString msg_end = "完毕\n";
//        clients.at(j)->write(msg_end.toUtf8());
    }
}
