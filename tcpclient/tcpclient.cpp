#include "tcpclient.h"
#include "ui_tcpclient.h"

Tcpclient::Tcpclient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tcpclient)
{
    ui->setupUi(this);
    init();
}

Tcpclient::~Tcpclient()
{
    delete ui;
}

void Tcpclient::init()
{
    myclient = new QTcpSocket(this);

    QStatusBar* stBar = statusBar();
    setStatusBar(stBar);

    //设置 QTableWidget 根据内容自适应
    ui->onlineUser->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度
    ui->onlineUser->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);//然后设置要根据内容使用宽度的列
    //加按钮
    onlineUsers.append(new usr());
    onlineUsers[0]->socket = "special\n";
    onlineUsers[0]->listBtn = new QPushButton("聊天",this);

    ui->onlineUser->insertRow(0);
    ui->onlineUser->setItem(0, 0, new QTableWidgetItem("群聊"));
    ui->onlineUser->setCellWidget(0, 1, onlineUsers[0]->listBtn);

    connect(onlineUsers[0]->listBtn, &QPushButton::clicked, this, [=](){
        qDebug() << "here2" << chater << endl;

        chater = onlineUsers[0]->socket;

        ui->chat_content->clear();
        ui->chat_content->append(onlineUsers[0]->history);
    });
}

void Tcpclient::on_btn_connect_clicked()
{
    QString serverIP = ui->server_ip->text();
    QString serverPort = ui->server_port->text();
    myclient->connectToHost(QHostAddress(serverIP),serverPort.toUInt());
    connect(myclient,SIGNAL(connected()),this,SLOT(doProcessConnected()));
    connect(myclient,SIGNAL(readyRead()),this,SLOT(doProcessReadyRead()));
    connect(myclient,SIGNAL(disconnected()),this,SLOT(doProcessDisConnected()));
    connect(myclient,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(doProcessError(QAbstractSocket::SocketError)));
}

void Tcpclient::doProcessConnected()
{
    ui->statusbar->showMessage(tr("连接成功"), 4000);
}

void Tcpclient::doProcessReadyRead()
{
    here:;
    QString first_line = myclient->readLine();

    qDebug() << first_line << endl;
    //判断是更新消息还是普通消息
    if (first_line == "通告\n")
    {
        QString msg = myclient->readLine();
        qDebug() << "here0" << msg << endl;
        msg = msg.left(msg.size() - 1);//删除换行符
        qDebug() << "here1" << msg << endl;

        QLabel* ip_port_on_server = new QLabel(msg);
        ui->statusbar->addPermanentWidget(ip_port_on_server);//显示在服务器上的ip和port，位于状态栏的右侧
        qDebug() << "here2" << endl;

        goto here;
    }
    else if (first_line == "更新在线用户列表开始\n")
    {
        renewUserTable();
    }
    else if (first_line == "删除一个用户\n")
    {
        qDebug() << "here 1" << endl;
        deleteUser();
    }
    else if (first_line == "群聊\n")
    {
        first_line = first_line.left(first_line.size() - 1);//删除换行符
        //找到用户
//        for(int i=0;i<onlineUsers.length();i++)
//        {
//            if(onlineUsers.at(i)->socket == first_line)
//            {
                qDebug()<<first_line;

                QString content = QString(myclient->readAll());
                onlineUsers.at(0)->history.append(content);
                onlineUsers.at(0)->history.append("\n");

//                break;
//            }
//        }
    }
    else
    {
        first_line = first_line.left(first_line.size() - 1);//删除换行符
        //找到用户
        for(int i=0;i<onlineUsers.length();i++)
        {
            if(onlineUsers.at(i)->socket == first_line)
            {
                qDebug()<<first_line;

                QString content = QString(myclient->readAll());
                onlineUsers.at(i)->history.append(content);
                onlineUsers.at(i)->history.append("\n");

                break;
            }
        }
    }
}

void Tcpclient::doProcessDisConnected()
{
    ui->statusbar->showMessage(tr("服务器断开"), 4000);
}

void Tcpclient::doProcessError(QAbstractSocket::SocketError err)
{
    qDebug() << err;
}

void Tcpclient::on_btn_send_clicked()
{
    QString content = ui->input->toPlainText();
    if (chater.isEmpty())
    {
        ui->statusbar->showMessage(tr("请先点击按钮选择聊天对象！"), 4000);
    }
    else
    {
        qDebug() << "1111111111" << onlineUsers.at(0)->socket << "22222" << chater << endl;

        //群聊
        if (onlineUsers.at(0)->socket == chater)
        {
//            onlineUsers.at(0)->history.append(str);
//            ui->chat_content->append(str);


            QString msg2 = chater + "\n" + content;
            int ret = myclient->write(msg2.toUtf8());
            if(ret <= 0)
                return;
            else
                ui->input->clear();
        }
        else {

            QString str = "我发送了：" + content + "\n";

            //加入chater的history并且更新聊天框消息
            for(int i=0; i<onlineUsers.length(); i++)
            {
                if(onlineUsers.at(i)->socket == chater)
                {
                    onlineUsers.at(i)->history.append(str);
                    ui->chat_content->append(str);
                    break;
                }
            }



    //        ui->textEdit->append(msg);

            QString msg = chater + "\n" + content;
            qDebug() << "1111111111" << msg ;
            int ret = myclient->write(msg.toUtf8());
            if(ret <= 0)
                return;
            else
                ui->input->clear();
        }




    }


}

void Tcpclient::renewUserTable()
{
    //删除表格所有行
//    for(int row = ui->onlineUser->rowCount() - 1;row >= 0; row--)
//        ui->onlineUser->removeRow(row);

    QString line = myclient->readLine();
//    qDebug() << "here1" << line << endl;

    for (; line != "更新在线用户列表结束\n";)
    {
        //判断用户是否存在
        bool flag = false;
        int pos = 0;
        for (; pos < onlineUsers.count(); pos++)
        {
            if((onlineUsers[pos]->socket + "\n") == line)
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            ;//无操作
        }
        else
        {
            onlineUsers.append(new usr());
            onlineUsers[pos]->socket = line.left(line.size() - 1);//删除换行符
            onlineUsers[pos]->listBtn = new QPushButton("聊天",this);

            //列表添加一行
            int rowPos = ui->onlineUser->rowCount();
//            qDebug() << "here4" << rowPos << endl;

            ui->onlineUser->insertRow(rowPos);
            ui->onlineUser->setItem(rowPos, 0, new QTableWidgetItem(line));
            ui->onlineUser->setCellWidget(rowPos, 1, onlineUsers[pos]->listBtn);

            //点击chat按钮
            //设置聊天对象，显示聊天记录
            qDebug() << "here1" << onlineUsers.count() << "    " << pos << endl;

            connect(onlineUsers[pos]->listBtn, &QPushButton::clicked, this, [=](){
                qDebug() << "here2" << chater << endl;

                chater = onlineUsers[pos]->socket;

                ui->chat_content->clear();
                ui->chat_content->append(onlineUsers[pos]->history);
            });
        }

        line = myclient->readLine();
    }
}

void Tcpclient::deleteUser()
{
    QString msg = myclient->readLine();
    int pos = 0;
    for (; pos < onlineUsers.count(); pos++)
    {
        qDebug() << "here 2" << pos << endl;
        if((onlineUsers[pos]->socket + "\n") == msg)
        {
            onlineUsers.removeAt(pos);
            ui->onlineUser->removeRow(pos);//表格里删除
            break;
        }
    }
}
