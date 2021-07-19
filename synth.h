#ifndef SYNTH_H
#define SYNTH_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMediaPlayer>
#include<QStack>
#include<QMap>
#include<QGraphicsScene>

#include"keyboard.h"
#include"note.h"
#include"audioRecord.h"
#include"metronome.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Synth; }
QT_END_NAMESPACE
class Metronome;
class Synth : public QMainWindow
{
    Q_OBJECT

public:
    Synth(QWidget *parent = nullptr);
    ~Synth();
    int getKeysQaunty();
    int getMetroTempValue();
private:
    ////variables////
    Ui::Synth *ui;
    QGraphicsScene * scene{nullptr};     //на ней отрисовывается клавиутара
    Keyboard * keyboard{nullptr};       //клава
    AudioRecorder * audioRecorder;
    Metronome * metronome;

    QVector<int> keysValue;

    int SCENE_SIZE_X{780};       //scene dimentions
    int SCENE_SIZE_Y{320};

    QMap<int,QMediaPlayer*> players;    //контейнер для объектов QmediaPlayer. Каждой ноте соответсвует свой плеер

    ///////methods////
 protected:
    void setBackground();
    void setKeysValue();
    void setScene();
    void setPlayers();
    void setKeyboard();        //установка клавиатуры
    void setAudioRecorder();
    void setMetronome();

    void playNote(const Note&);        //

    void setVolume(const int);
    void setMetronomeTemp();

 QMediaPlayer& getPlayer();     //возвращает очереной свободный плеер



protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
friend class Keyboard;
    /////for testing////
public:
    QMediaPlayer * soundTest;

private slots:
    void on_recordStartBtn_clicked();
    void on_recordStopBtn_clicked();

    void on_recordPlayBtn_clicked();
    void on_metroBtnStart_clicked();
    void on_metroBtnStop_clicked();

    void on_volSlider_actionTriggered(int action);
};
#endif // SYNTH_H
