#ifndef METRONOME_H
#define METRONOME_H

#include<synth.h>
#include<QMediaPlayer>
#include<QTimer>
class Synth;
extern Synth * w;
class Metronome{
public:
    Metronome();
    void start();
    void stop();
    void setTemp();
    void setVolume(int);
protected:
    QMediaPlayer * metroPlayer;
    QTimer * metroTimer;
    int temp{};


};

#endif // METRONOME_H
