#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    setupUi(this);
    //connect(pushButton, SIGNAL(clicked()), this, SLOT(enter()));
    tcpSocket = new QTcpSocket(this);

    connect(pushButton, SIGNAL(clicked()), this, SLOT(sendMsg()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(resvMsg()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error()));

    tcpSocket->connectToHost(QHostAddress::LocalHost, 8000);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::sendMsg()
{
    QTextStream out(tcpSocket);
    out<<lineEdit->text()<<endl;
    lineEdit->clear();
}

void Dialog::resvMsg()
{
    if (!tcpSocket->canReadLine())
        return;

    QString resposeLine;
    do
    {
        resposeLine += tcpSocket->readLine();
    }
    while (tcpSocket->canReadLine());

    msgBuffer += resposeLine;

    textBrowser->setText(msgBuffer);
    textBrowser->moveCursor(QTextCursor::End);
}

void Dialog::error()
{
    QMessageBox::critical(this, "socket error", tcpSocket->errorString());
    tcpSocket->close();
}

/*
void Dialog::enter()
{
    buf += lineEdit->text() + '\n';
    lineEdit->clear();

    textBrowser->setText(buf);
    textBrowser->moveCursor(QTextCursor::End);
}
*/
