#include "synth.h"
#include "ui_synth.h"

Synth::Synth(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Synth)
{
    ui->setupUi(this);
    setKeyboard();
}

Synth::~Synth()
{
    delete ui;
}
void Synth::setKeyboard()
{

}

void Synth::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Q){

    }

}

void Synth::keyReleaseEvent(QKeyEvent *event)
{

}

