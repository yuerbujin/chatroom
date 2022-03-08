#ifndef USR_H
#define USR_H

#include <QObject>
#include <QPushButton>
//#include "tcpclient.h"

class usr : public QObject
{
    Q_OBJECT

    public:
        explicit usr(QObject *parent = nullptr);

        QString name;//用户名
        QString socket;//当前聊天对象
        QPushButton* listBtn;//列表按钮
        QString history;//聊天记录

//        void on_btn_chat_clicked();
    signals:

    public slots:
};

#endif // USR_H
