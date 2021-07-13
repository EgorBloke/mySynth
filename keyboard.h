#ifndef KEYBOARD_H
#define KEYBOARD_H

#include<QGraphicsItem>
#include<QWidget>
#include<QVector>
#include<QObject>  //!!!!
#include<QPaintEvent>
#include<QPainter>
#include<QWidget>
#include<QGraphicsScene>
#include<QStyleOptionGraphicsItem>

#include"key.h"
//#include"synth.h"

 class Keyboard:public QObject,public QGraphicsItem{
     Q_OBJECT

public:
     Keyboard(QVector<int> keysValue,  QObject *parent = nullptr);


  //////variables//////
 protected:
    QVector<int> keysValue;
    QVector<Key*> keys;
    BadKey badKey{0,this};
    int firstKey{0};
    int keysNumber{0};

 protected:
    void setKeys();
    bool isBlack(const int);

    // QGraphicsItem interface
 public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    Key& operator[](int);
    Key& getBadKey();
    friend class synth;
 };

#endif // KEYBOARD_H
