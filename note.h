#ifndef NOTE_H
#define NOTE_H
#include<QString>
#include<QVector>
class Note{

    static QVector<Note*> Notes;
    QString note{""};
    unsigned int octave{0};
public:
    Note();
};

#endif // NOTE_H
