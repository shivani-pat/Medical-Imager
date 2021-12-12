#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //open qss file
    QFile file(":/new/prefix1/SpyBot.qss");
    file.open(QIODevice::ReadOnly);

    QString styleSheet { QLatin1String(file.readAll()) };

    //setup stylesheet
    a.setStyleSheet(styleSheet);
    w.show();
    return a.exec();
}
