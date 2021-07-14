#ifndef AUDIORECORD_H
#define AUDIORECORD_H

#include<QMediaRecorder>
#include<QAudioRecorder>
#include<QAudioEncoderSettings>
class AudioRecorder{
public:
    AudioRecorder();
protected:
    QAudioRecorder * audioRecorder;
    QAudioEncoderSettings * settings;
};

#endif // AUDIORECORD_H
