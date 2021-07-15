#include"metronome.h"


Metronome::Metronome()
{
    metroPlayer = new QMediaPlayer;
    metroPlayer->setMedia(QUrl("qrc:/sounds/piano-bb_Am_major.wav"));

}

void Metronome::start()
{

    metroTimer->start(1000*60/temp);
}

void Metronome::stop()
{
    metroTimer->stop();
}

void Metronome::setTemp()
{
    temp=w->getMetroTempValue();
}

void Metronome::setVolume(int vol = 20)
{
    metroPlayer->setVolume(vol);
}
