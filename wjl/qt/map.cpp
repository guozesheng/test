#include <QApplication>
#include <QMap>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, QString> map;

    map.insert("Beijing", "010");
    map.insert("Changch", "0431");
    map.insert("Chifeng", "0476");
    map.insert("Jinan", "0531");

    QMap<QString, QString>::const_iterator i;

    for (i = map.constBegin(); i != map.constEnd(); i++)
    {
        qDebug()<<i.key()<<"\t"<<i.value();
    }

    QMap<QString, QString>::iterator mi;
    mi = map.find("Jinan");
    if (mi != map.end())
    {
        mi.value() = "020";
    }

    QMap<QString, QString>::const_iterator modi;
    qDebug()<<"";
    for (modi = map.constBegin(); modi != map.constEnd(); modi++)
    {
        qDebug()<<modi.key()<<"\t"<<modi.value();
    }

    return a.exec();
}
