#include "synth.h"

#include <QApplication>
Synth * w;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Synth w;
    w = new Synth;
    w->show();
    return a.exec();
}
