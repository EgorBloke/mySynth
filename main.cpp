#include "synth.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Synth w;
    w.show();
    return a.exec();
}
