#include"audioRecord.h"

AudioRecorder::AudioRecorder()
{

    audioRecorder = new QAudioRecorder();
    settings = new QAudioEncoderSettings();
    QStringList inputsList = audioRecorder->audioInputs();
    qDebug()<<inputsList;

//    settings.setCodec(boxValue(ui->audioCodecBox).toString());
//    settings.setSampleRate(boxValue(ui->sampleRateBox).toInt());
//    settings.setBitRate(boxValue(ui->bitrateBox).toInt());
//    settings.setQuality(QMultimedia::EncodingQuality(ui->qualitySlider->value()));
//    settings.setEncodingMode(ui->constantQualityRadioButton->isChecked() ?
//                             QMultimedia::ConstantQualityEncoding :
//                             QMultimedia::ConstantBitRateEncoding);

//    QString container = boxValue(ui->containerBox).toString();

//    audioRecorder->setEncodingSettings(settings, QVideoEncoderSettings(), container);
//    audioRecorder->record();

}
