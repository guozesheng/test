#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton *button = new QPushButton("Quit");
    button->resize(200, 100);
    QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));
    button->show();

    //QPushButton hello("Hello world!", 0);
    //hello.resize(500, 30);
    //hello.show();

    //QLabel *label = new QLabel("Hello, world!");
    //label->show();
    
    return app.exec();
}
