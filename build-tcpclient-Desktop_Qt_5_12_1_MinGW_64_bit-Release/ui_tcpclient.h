/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tcpclient
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *server_ip;
    QLabel *label_2;
    QLineEdit *server_port;
    QPushButton *btn_connect;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QTextEdit *chat_content;
    QTextEdit *input;
    QPushButton *btn_send;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QTableWidget *onlineUser;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Tcpclient)
    {
        if (Tcpclient->objectName().isEmpty())
            Tcpclient->setObjectName(QString::fromUtf8("Tcpclient"));
        Tcpclient->resize(550, 550);
        Tcpclient->setMinimumSize(QSize(550, 550));
        Tcpclient->setMaximumSize(QSize(16777215, 16777215));
        centralwidget = new QWidget(Tcpclient);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget_4);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        server_ip = new QLineEdit(widget_4);
        server_ip->setObjectName(QString::fromUtf8("server_ip"));

        horizontalLayout_2->addWidget(server_ip);

        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        server_port = new QLineEdit(widget_4);
        server_port->setObjectName(QString::fromUtf8("server_port"));

        horizontalLayout_2->addWidget(server_port);

        btn_connect = new QPushButton(widget_4);
        btn_connect->setObjectName(QString::fromUtf8("btn_connect"));

        horizontalLayout_2->addWidget(btn_connect);


        verticalLayout->addWidget(widget_4);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        chat_content = new QTextEdit(widget_2);
        chat_content->setObjectName(QString::fromUtf8("chat_content"));

        gridLayout_2->addWidget(chat_content, 0, 0, 1, 2);

        input = new QTextEdit(widget_2);
        input->setObjectName(QString::fromUtf8("input"));

        gridLayout_2->addWidget(input, 1, 0, 2, 2);

        btn_send = new QPushButton(widget_2);
        btn_send->setObjectName(QString::fromUtf8("btn_send"));

        gridLayout_2->addWidget(btn_send, 2, 1, 1, 1);


        horizontalLayout->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 0));
        widget_3->setMaximumSize(QSize(260, 16777215));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        onlineUser = new QTableWidget(widget_3);
        if (onlineUser->columnCount() < 2)
            onlineUser->setColumnCount(2);
        onlineUser->setObjectName(QString::fromUtf8("onlineUser"));
        onlineUser->setMaximumSize(QSize(242, 16777215));
        onlineUser->setRowCount(0);
        onlineUser->setColumnCount(2);

        gridLayout->addWidget(onlineUser, 0, 0, 1, 1);


        horizontalLayout->addWidget(widget_3);


        verticalLayout->addWidget(widget);

        Tcpclient->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Tcpclient);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Tcpclient->setStatusBar(statusbar);

        retranslateUi(Tcpclient);

        QMetaObject::connectSlotsByName(Tcpclient);
    } // setupUi

    void retranslateUi(QMainWindow *Tcpclient)
    {
        Tcpclient->setWindowTitle(QApplication::translate("Tcpclient", "Tcpclient", nullptr));
        label->setText(QApplication::translate("Tcpclient", "\346\234\215\345\212\241\345\231\250IP\357\274\232", nullptr));
        server_ip->setText(QApplication::translate("Tcpclient", "192.168.205.1", nullptr));
        label_2->setText(QApplication::translate("Tcpclient", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232", nullptr));
        server_port->setText(QApplication::translate("Tcpclient", "9000", nullptr));
        btn_connect->setText(QApplication::translate("Tcpclient", "\350\277\236\346\216\245", nullptr));
        btn_send->setText(QApplication::translate("Tcpclient", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tcpclient: public Ui_Tcpclient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
