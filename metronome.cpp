#include"metronome.h"


Metronome::Metronome(QObject *parent):QObject(parent)
{
    timer = new QTimer(this);
    player = new QMediaPlayer(this);
    player->setMedia(QUrl("qrc:/sounds/piano-b_B_major.wav"));
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(playBit())); ///FIXIT!!!!
}

void Metronome::start()
{

    timer->start(1000*60/temp);
}

void Metronome::stop()
{
    timer->stop();
}

void Metronome::playBit()
{
    player->setPosition(0);
    player->play();
}

void Metronome::setTemp(int temp=100)
{
    this->temp=temp;
}




void Metronome::setVolume(int vol = 20)
{
    player->setVolume(vol);
}
