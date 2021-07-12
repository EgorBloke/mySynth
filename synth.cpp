#include "synth.h"
#include "ui_synth.h"
#include<QDebug>
#include<QDir>

Synth::Synth(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Synth)
{
    ui->setupUi(this);
    setKeysValue();
    setScene();     //set the scene into graphic view
    setKeyboard();  //draw keyboard
    setPlayers();   //set the music players
    setVolume(10);
    //qDebug() << QDir::toNativeSeparators(QApplication::applicationDirPath()) ;

}

Synth::~Synth()
{
    delete ui;
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
        Qt::Key_I
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

   //устанавливаем плееру свой сэмпл
   players.find(Qt::Key_Q).value()->setMedia(QUrl("qrc:/sounds/piano-bb_Am_major.wav"));
   players.find(Qt::Key_2).value()->setMedia(QUrl("qrc:/sounds/piano-b_B_major.wav"));
   players.find(Qt::Key_W).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));

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

