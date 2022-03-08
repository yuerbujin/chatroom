#ifndef ONLINEUSERS_H
#define ONLINEUSERS_H

#include <QTcpSocket>
#include <QPushButton>

class onlineUsers
{
    public:
        QTcpSocket* you;//当前聊天对象
        QList<QPushButton*> listBtn;//列表按钮
        QList<QString> history;//聊天记录

        onlineUsers();

};

#endif // ONLINEUSERS_H
