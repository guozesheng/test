#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <ui_dialog.h>
#include <QAbstractSocket>
#include <QHostAddress>
#include <QMessageBox>

/*
namespace Ui {
    class Dialog;
}*/

class Dialog : public QDialog, public Ui_Dialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    //void enter();
    void sendMsg();
    void resvMsg();
    void error();

private:
    Ui::Dialog *ui;
    //QString buf;
    QTcpSocket *tcpSocket;
    QString msgBuffer;
};

#endif // DIALOG_H
