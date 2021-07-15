#include"audioRecord.h"

AudioRecorder::AudioRecorder()
{

    audioRecorder = new QAudioRecorder();
    settings = new QAudioEncoderSettings();
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
