#include"audioRecord.h"

AudioRecorder::AudioRecorder()
{

    audioRecorder = new QAudioRecorder();
    settings = new QAudioEncoderSettings();
    player = new QMediaPlayer();
    QStringList inputsList = audioRecorder->audioInputs();
    qDebug()<<inputsList;

    settings->setCodec("audio/amr");
    settings->setQuality(QMultimedia::HighQuality);
    audioRecorder->setEncodingSettings(*settings);
    audioRecorder->setOutputLocation(QUrl::fromLocalFile("C:/myprograms/summerSchool/synth/mySynth/sounds/test.arm"));

}

void AudioRecorder::startRecord()
{
    audioRecorder->record();
}

void AudioRecorder::stopRecord()
{
    audioRecorder->stop();
}

void AudioRecorder::playRecord()
{
    player->setMedia(QUrl("C:/myprograms/summerSchool/synth/mySynth/sounds/test.arm.wav"));
    if(player->state()==QMediaPlayer::PlayingState)
    {
        player->setPosition(0);

    }
    player->play();
}

void AudioRecorder::stopPlaying()
{
    player->stop();
}
