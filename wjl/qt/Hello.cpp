#include<QApplication>
#include<QPushButton>
#include<QVBoxLayout>
#include <QLayout>
#include <QLabel>

int main( int argc, char **argv )
{
    QApplication app(argc, argv);

    QWidget *p = new QWidget;
    p->setSizeIncrement(100, 200);

    QLabel label(p);
    label.setText(QObject::tr("Hello, world!"));

    QPushButton *qb = new QPushButton("&Download", p);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(&label);
    layout->addWidget(qb);
    p->setLayout(layout);
    QObject::connect(qb, SIGNAL(clicked()), p, SLOT(close()));

    p->show();

    return app.exec();
}
