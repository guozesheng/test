#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(enter()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::enter()
{
    buf += ui->lineEdit->text() + '\n';
    ui->lineEdit->clear();

    ui->textBrowser->setText(buf);
    ui->textBrowser->moveCursor(QTextCursor::End);
}
