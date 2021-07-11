#include "synth.h"
#include "ui_synth.h"
#include<QDebug>
#include<QDir>

Synth::Synth(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Synth)
{
    ui->setupUi(this);
    setKeyboard();
    setPlayers();

    //qDebug() << QDir::toNativeSeparators(QApplication::applicationDirPath()) ;

//    soundTest = new QMediaPlayer();
//    soundTest->setMedia(QUrl("qrc:/sounds/piano-b_B_major.wav"));
//    soundTest->play();
}

Synth::~Synth()
{
    delete ui;
}

void Synth::setPlayers()
{
       players.insert(Qt::Key_Q,new QMediaPlayer());
       players.insert(Qt::Key_2,new QMediaPlayer());
       players.insert(Qt::Key_W,new QMediaPlayer());
       players.insert(Qt::Key_3,new QMediaPlayer());
       players.insert(Qt::Key_E,new QMediaPlayer());
       players.insert(Qt::Key_R,new QMediaPlayer());
       players.insert(Qt::Key_5,new QMediaPlayer());
       players.insert(Qt::Key_T,new QMediaPlayer());
       players.insert(Qt::Key_6,new QMediaPlayer());
       players.insert(Qt::Key_Y,new QMediaPlayer());
       players.insert(Qt::Key_7,new QMediaPlayer());
       players.insert(Qt::Key_U,new QMediaPlayer());
       players.insert(Qt::Key_I,new QMediaPlayer());
       players.insert(Qt::Key_9,new QMediaPlayer());
       players.insert(Qt::Key_O,new QMediaPlayer());
       players.insert(Qt::Key_0,new QMediaPlayer());
       players.insert(Qt::Key_P,new QMediaPlayer());

       players.find(Qt::Key_Q).value()->setMedia(QUrl("qrc:/sounds/piano-bb_Am_major.wav"));
       players.find(Qt::Key_2).value()->setMedia(QUrl("qrc:/sounds/piano-b_B_major.wav"));
       players.find(Qt::Key_W).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));

//       players.insert(Qt::Key_[,new QMediaPlayer());


//    players.push_back(new QMediaPlayer());
//    players[0]->setMedia(QUrl("qrc:/sounds/piano-b_B_major.wav"));
//    players.push_back(new QMediaPlayer());
//    players[1]->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
}
void Synth::setKeyboard()
{

}

void Synth::keyPressEvent(QKeyEvent *event)

{
    qDebug()<<"key pressed";
    auto p = players.find(event->key());
    if(p!=players.end()){
        if(p.value()->state()==QMediaPlayer::PlayingState)
        {
            p.value()->setPosition(0);
        }
//        if(p.value()->state()==QMediaPlayer::StoppedState)
//        {
//            p.value()->play();
//        }
        p.value()->play();
    }
}

void Synth::keyReleaseEvent(QKeyEvent *event)
{

}

