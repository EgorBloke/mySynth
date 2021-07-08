#ifndef KEYBOARD_H
#define KEYBOARD_H
#include<QGraphicsItem>
#include<QWidget>
#include<QVector>
#include<QObject>  //!!!!
#include<QPaintEvent>
#include<QPainter>
#include<QWidget>

#include<QStyleOptionGraphicsItem>



#include"key.h"

 class Keyboard:public QObject,public QGraphicsItem{
     Q_OBJECT



     Keyboard(QObject *parent = nullptr);

  //////variables//////
 protected:
    QVector<Key*> keys;



 };

#endif // KEYBOARD_H
