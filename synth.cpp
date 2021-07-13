#include "synth.h"
#include "ui_synth.h"
#include<QDebug>
#include<QDir>
#include<key.h>

Synth::Synth(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Synth)
{
    ui->setupUi(this);
    setKeysValue();
    setScene();     //set the scene into graphic view

    setPlayers();   //set the music players
    setKeyboard();  //draw keyboard
    setVolume(10);
    //qDebug() << QDir::toNativeSeparators(QApplication::applicationDirPath()) ;

}

Synth::~Synth()
{
    delete ui;
}

int Synth::getKeysQaunty()
{
    return keysValue.size();
}

void Synth::setKeysValue()
{
    keysValue={
        Qt::Key_Q,
        Qt::Key_2,
        Qt::Key_W,
        Qt::Key_3,
        Qt::Key_E,
        Qt::Key_R,
        Qt::Key_5,
        Qt::Key_T,
        Qt::Key_6,
        Qt::Key_Y,
        Qt::Key_7,
        Qt::Key_U,
        Qt::Key_I,
        Qt::Key_9,
        Qt::Key_O,
        Qt::Key_0,
        Qt::Key_P,
        91,
        61,
        93
    };
}

void Synth::setScene()
{
    if (scene){     //на всякий случай
        delete scene;
    }

    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    ui->graphicsView->resize(SCENE_SIZE_X+2,SCENE_SIZE_Y+2);
    ui->graphicsView->setScene(scene);      //установка сцены на грифический виджет
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    //сглаживание
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);     //дб
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);     //дб
    scene->setSceneRect(0,0,SCENE_SIZE_X,SCENE_SIZE_Y);
//    ui->graphicsView->setFixedSize(652,852);
}

void Synth::setPlayers()
{
   //заполняем контейнер  парами <клавиша, плеер>
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
   players.insert(91,new QMediaPlayer());
   players.insert(61,new QMediaPlayer());
   players.insert(93,new QMediaPlayer());

   //устанавливаем плееру свой сэмпл
   players.find(Qt::Key_Q).value()->setMedia(QUrl("qrc:/sounds/piano-bb_Am_major.wav"));
   players.find(Qt::Key_2).value()->setMedia(QUrl("qrc:/sounds/piano-b_B_major.wav"));
   players.find(Qt::Key_W).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
   players.find(Qt::Key_3).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
   players.find(Qt::Key_E).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
   players.find(Qt::Key_R).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
   players.find(Qt::Key_5).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
   players.find(Qt::Key_T).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
   players.find(Qt::Key_6).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
   players.find(Qt::Key_Y).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
   players.find(Qt::Key_7).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
   players.find(Qt::Key_U).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
   players.find(Qt::Key_I).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
   players.find(Qt::Key_9).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
   players.find(Qt::Key_O).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
   players.find(Qt::Key_0).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
   players.find(Qt::Key_P).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
   players.find(91).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
   players.find(61).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
   players.find(93).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
//   players.find().value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));

}
void Synth::setKeyboard()
{
    if(keyboard){
        delete keyboard;
    }
    keyboard = new Keyboard(keysValue, this);
    scene->addItem(keyboard);
}

void Synth::setVolume(const int value)
{
    for(auto p:players){
        p->setVolume(value);
    }
}

void Synth::keyPressEvent(QKeyEvent *event)

{
    qDebug()<<"key pressed"<<char(event->key())<<event->key();
    auto p = players.find(event->key());
    if(p!=players.end()){

//        if(p.value()->state()==QMediaPlayer::StoppedState)
//        {
//            p.value()->play();
//        }


    }
    if(keyboard->operator[](event->key())!=keyboard->getBadKey())
    {
        if(keyboard->operator[](event->key()).isPressed()==false)
        {
            if(p.value()->state()==QMediaPlayer::PlayingState)
            {
                p.value()->setPosition(0);
            }
            p.value()->play();
        }
        keyboard->operator[](event->key()).setPressedStatus(true);
    }
    scene->update();
}


void Synth::keyReleaseEvent(QKeyEvent *event)
{
    qDebug()<<"key released"<<char(event->key())<<event->key();
    auto p = players.find(event->key());
    p.value()->stop();
    p.value()->setPosition(0);

    if(keyboard->operator[](event->key())!=keyboard->getBadKey())
    {
        keyboard->operator[](event->key()).setPressedStatus(false);
    }
    scene->update();
}

