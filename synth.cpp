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

    setBackground();
    setKeysValue();
    setScene();     //set the scene into graphic view

    setPlayers();   //set the music players
    setKeyboard();  //draw keyboard
    setAudioRecorder();    
    setMetronome();
    setVolume(15);
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

int Synth::getMetroTempValue()
{
    return this->ui->metronomeSpinBox->value();
}

void Synth::setBackground()
{
    QPixmap bkgnd(":/img/bgnd.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
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

      players.find(Qt::Key_Q).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/19-203500__tesabob2001__f-4.mp3"));
      players.find(Qt::Key_2).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/20-203492__tesabob2001__g4.mp3"));
      players.find(Qt::Key_W).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/21-203491__tesabob2001__g-4.mp3"));
      players.find(Qt::Key_3).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/22-203465__tesabob2001__a4.mp3"));
      players.find(Qt::Key_E).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/23-203460__tesabob2001__a-4.mp3"));
      players.find(Qt::Key_R).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/24-203462__tesabob2001__b4.mp3"));
      players.find(Qt::Key_5).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/25-203485__tesabob2001__c5.mp3"));
      players.find(Qt::Key_T).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/26-203480__tesabob2001__c-5.mp3"));
      players.find(Qt::Key_6).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/27-203473__tesabob2001__d5.mp3"));
      players.find(Qt::Key_Y).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/28-203487__tesabob2001__d-5.mp3"));
      players.find(Qt::Key_7).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/29-203476__tesabob2001__e5.mp3"));
      players.find(Qt::Key_U).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/30-203489__tesabob2001__f5.mp3"));
      players.find(Qt::Key_I).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/31-203499__tesabob2001__f-5.mp3"));
      players.find(Qt::Key_9).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/32-203495__tesabob2001__g5.mp3"));
      players.find(Qt::Key_O).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/33-203490__tesabob2001__g-5.mp3"));
      players.find(Qt::Key_0).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/34-203464__tesabob2001__a5.mp3"));
      players.find(Qt::Key_P).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/35-203459__tesabob2001__a-5.mp3"));
      players.find(91).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/36-203467__tesabob2001__b5.mp3"));
      players.find(61).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/37-203484__tesabob2001__c6.mp3"));
      players.find(93).value()->setMedia(QUrl("qrc:/sounds/12995__tesabob2001__piano-keys-c3-c6/68442__pinkyfinger__piano-d.wav"));

      //устанавливаем плееру свой сэмпл
//   players.find(Qt::Key_Q).value()->setMedia(QUrl("qrc:/sounds/piano-bb_Am_major.wav"));
//   players.find(Qt::Key_2).value()->setMedia(QUrl("qrc:/sounds/piano-b_B_major.wav"));
//   players.find(Qt::Key_W).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
//   players.find(Qt::Key_3).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
//   players.find(Qt::Key_E).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
//   players.find(Qt::Key_R).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
//   players.find(Qt::Key_5).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
//   players.find(Qt::Key_T).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
//   players.find(Qt::Key_6).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
//   players.find(Qt::Key_Y).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
//   players.find(Qt::Key_7).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
//   players.find(Qt::Key_U).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
//   players.find(Qt::Key_I).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
//   players.find(Qt::Key_9).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
//   players.find(Qt::Key_O).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
//   players.find(Qt::Key_0).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
//   players.find(Qt::Key_P).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
//   players.find(91).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
//   players.find(61).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
//   players.find(93).value()->setMedia(QUrl("qrc:/sounds/piano-c_C_major.wav"));
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

void Synth::setAudioRecorder()
{
    audioRecorder = new AudioRecorder();
}

void Synth::setMetronome()
{
    metronome = new Metronome();
    setMetronomeTemp();
}

void Synth::setVolume(const int value)
{
    for(auto p:players){
        p->setVolume(value);
    }
    metronome->setVolume(value);
}

void Synth::setMetronomeTemp()
{
    this->metronome->setTemp(this->ui->metronomeSpinBox->value());
}

void Synth::keyPressEvent(QKeyEvent *event)

{
    qDebug()<<"key pressed"<<char(event->key())<<event->key();

    auto p = players.find(event->key());

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
//    auto p = players.find(event->key());
//    p.value()->stop();
//    p.value()->setPosition(0);

    if(keyboard->operator[](event->key())!=keyboard->getBadKey())
    {
        keyboard->operator[](event->key()).setPressedStatus(false);
    }
    scene->update();
}


void Synth::on_recordStartBtn_clicked()
{
    audioRecorder->startRecord();
}


void Synth::on_recordStopBtn_clicked()
{
    audioRecorder->stopRecord();
    audioRecorder->stopPlaying();

}

void Synth::on_recordPlayBtn_clicked()
{
    audioRecorder->playRecord();
}


void Synth::on_metroBtnStart_clicked()
{
    this->metronome->start();
}


void Synth::on_metroBtnStop_clicked()
{
    this->metronome->stop();
}


void Synth::on_volSlider_actionTriggered(int action)
{
    this->setVolume(ui->volSlider->value());
}


void Synth::on_metronomeSpinBox_valueChanged(int arg1)
{
    this->metronome->setTemp(this->ui->metronomeSpinBox->value());
}

