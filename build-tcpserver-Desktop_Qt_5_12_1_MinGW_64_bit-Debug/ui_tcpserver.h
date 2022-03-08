/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tcpserver
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *clientAddress;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLineEdit *clientPort;
    QPushButton *btn_connect;
    QTextEdit *textEdit;
    QGridLayout *gridLayout;
    QLineEdit *client_ip;
    QPushButton *btn_send;
    QLineEdit *client_port;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QTextEdit *sendmessage;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *tcpserver)
    {
        if (tcpserver->objectName().isEmpty())
            tcpserver->setObjectName(QString::fromUtf8("tcpserver"));
        tcpserver->resize(800, 600);
        centralwidget = new QWidget(tcpserver);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        clientAddress = new QLineEdit(centralwidget);
        clientAddress->setObjectName(QString::fromUtf8("clientAddress"));

        gridLayout_2->addWidget(clientAddress, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 3, 1, 1);

        clientPort = new QLineEdit(centralwidget);
        clientPort->setObjectName(QString::fromUtf8("clientPort"));

        gridLayout_2->addWidget(clientPort, 0, 4, 1, 1);

        btn_connect = new QPushButton(centralwidget);
        btn_connect->setObjectName(QString::fromUtf8("btn_connect"));

        gridLayout_2->addWidget(btn_connect, 0, 5, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_3->addWidget(textEdit, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        client_ip = new QLineEdit(centralwidget);
        client_ip->setObjectName(QString::fromUtf8("client_ip"));

        gridLayout->addWidget(client_ip, 0, 1, 1, 1);

        btn_send = new QPushButton(centralwidget);
        btn_send->setObjectName(QString::fromUtf8("btn_send"));

        gridLayout->addWidget(btn_send, 0, 6, 1, 1);

        client_port = new QLineEdit(centralwidget);
        client_port->setObjectName(QString::fromUtf8("client_port"));

        gridLayout->addWidget(client_port, 0, 5, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 3, 1, 1);


        gridLayout_3->addLayout(gridLayout, 2, 0, 1, 1);

        sendmessage = new QTextEdit(centralwidget);
        sendmessage->setObjectName(QString::fromUtf8("sendmessage"));

        gridLayout_3->addWidget(sendmessage, 3, 0, 1, 1);

        tcpserver->setCentralWidget(centralwidget);
        menubar = new QMenuBar(tcpserver);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        tcpserver->setMenuBar(menubar);
        statusbar = new QStatusBar(tcpserver);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        tcpserver->setStatusBar(statusbar);

        retranslateUi(tcpserver);

        QMetaObject::connectSlotsByName(tcpserver);
    } // setupUi

    void retranslateUi(QMainWindow *tcpserver)
    {
        tcpserver->setWindowTitle(QApplication::translate("tcpserver", "tcpserver", nullptr));
        label->setText(QApplication::translate("tcpserver", "\346\234\215\345\212\241\345\231\250IP", nullptr));
        clientAddress->setText(QApplication::translate("tcpserver", "192.168.205.1", nullptr));
        label_2->setText(QApplication::translate("tcpserver", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        clientPort->setText(QApplication::translate("tcpserver", "9000", nullptr));
        btn_connect->setText(QApplication::translate("tcpserver", "\347\273\221\345\256\232", nullptr));
        btn_send->setText(QApplication::translate("tcpserver", "\345\217\221\351\200\201", nullptr));
        label_3->setText(QApplication::translate("tcpserver", "\345\256\242\346\210\267\347\253\257IP", nullptr));
        label_4->setText(QApplication::translate("tcpserver", "\345\256\242\346\210\267\347\253\257\347\253\257\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tcpserver: public Ui_tcpserver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
