#ifndef KEY_H
#define KEY_H
#include<QGraphicsItem>
#include<QWidget>
#include<QBrush>
#include<QPen>
#include<QObject>

 class Key:public QObject,public QGraphicsItem
 {
Q_OBJECT

 protected:
     double width{0};
     double height{0};
     int key{0};
     QBrush * brush{nullptr};
     QPen * pen{nullptr};
     double xPos{0};  //позиция вставки
     double yPos{0};

     // QWidget interface
 protected:
//     virtual void keyPressEvent(QKeyEvent *event) override = 0;
//     virtual void keyReleaseEvent(QKeyEvent *event) override = 0;

     // QGraphicsItem interface
 public:
/////get/////

     double getWidth();

     Key(int key, QGraphicsItem *parent = nullptr);

     virtual QRectF boundingRect() const override;
     virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
 };


 class WhiteKey:public Key{
 public:
    WhiteKey(int key, QGraphicsItem *parent = nullptr);

 };

 class BlackKey:public Key{
 public:
    BlackKey(int key, QGraphicsItem *parent = nullptr);


    // QGraphicsItem interface
 public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
 };

#endif // KEY_H
