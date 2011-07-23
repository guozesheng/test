#include <QCoreApplication>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    QList<int>::iterator li;
    QList<int>::const_iterator cli;

    for (int j = 0; j < 10; j++)
    {
        list.insert(list.end(), j);
    }

    for (li = list.begin(); li != list.end(); li++)
    {
        qDebug()<<(*li);
        *li = *li * 10;
    }

    for (cli = list.begin(); cli != list.end(); cli++)
    {
        qDebug()<<*cli;
    }

    return a.exec();
}
