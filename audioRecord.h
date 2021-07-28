#ifndef AUDIORECORD_H
#define AUDIORECORD_H

#include<QMediaRecorder>
#include<QAudioRecorder>
#include<QAudioEncoderSettings>
#include<QMediaPlayer>
#include<QUrl>
class AudioRecorder{
public:
    AudioRecorder();
    void startRecord();
    void stopRecord();
    void playRecord();
    void stopPlaying();
protected:
    QMediaPlayer * player;
    QAudioRecorder * audioRecorder;
    QAudioEncoderSettings * settings;
};

#endif // AUDIORECORD_H
