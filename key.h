#ifndef KEY_H
#define KEY_H
#include<QGraphicsItem>
#include<QWidget>

 class Key:public QGraphicsItem, public QWidget{

 protected:
     double width{0};
     double hight{0};

     // QPaintDevice interface
 public:
     virtual QPaintEngine *paintEngine() const override;

     // QWidget interface
 protected:
     virtual void keyPressEvent(QKeyEvent *event)override = 0;
     virtual void keyReleaseEvent(QKeyEvent *event)override = 0;

     // QGraphicsItem interface
 public:
     virtual QRectF boundingRect() const override;
     virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
 };


 class WhiteKey:public Key{

 };

 class BlackKey:public Key{

 };

#endif // KEY_H
