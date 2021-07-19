#ifndef METRONOME_H
#define METRONOME_H

#include<QObject>
#include<synth.h>
#include<QMediaPlayer>
#include<QTimer>
//class Synth;
//extern Synth * w;
class Metronome:public QObject{
    Q_OBJECT
public:
    Metronome(QObject *parent = nullptr);
    void start();
    void stop();

    void setTemp(int);
    void setVolume(int);
protected:
    QMediaPlayer * player{nullptr};
    QTimer * timer{nullptr};
    int temp{100};
public slots:
    void playBit();

};

#endif // METRONOME_H
