#ifndef AUDIORECORD_H
#define AUDIORECORD_H

#include<QMediaRecorder>
#include<QAudioRecorder>
#include<QAudioEncoderSettings>
#include<QUrl>
class AudioRecorder{
public:
    AudioRecorder();
    void startRecord();
    void stopRecord();
protected:
    QAudioRecorder * audioRecorder;
    QAudioEncoderSettings * settings;
};

#endif // AUDIORECORD_H
