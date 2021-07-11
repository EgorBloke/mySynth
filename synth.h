#ifndef SYNTH_H
#define SYNTH_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMediaPlayer>
#include<QStack>
#include<QMap>
#include"note.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Synth; }
QT_END_NAMESPACE

class Synth : public QMainWindow
{
    Q_OBJECT

public:
    Synth(QWidget *parent = nullptr);

    ~Synth();

private:
    Ui::Synth *ui;

////variables////

//    QVector<QMediaPlayer*> players;     //контейнер для воспроизведения плееров, что будут воспроизводить ноты
    QMap<int,QMediaPlayer*> players;
    QStack<QMediaPlayer**> waitingPlayers;      //контейнер, откуда будут браться указатели на плееры воспроизведения новой ноты,
                //если он не пуст. При окончании воспроизведения ноты, указатель помещается обратно в стэк
    ///////methods////
 protected:
    void setPlayers();
    void setKeyboard();        //установка клавиатуры
    void playNote(const Note&);        //

 QMediaPlayer& getPlayer();     //возвращает очереной свободный плеер



protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    /////for testing////
public:
    QMediaPlayer * soundTest;
};
#endif // SYNTH_H
