#ifndef KEY_H
#define KEY_H
#include<QGraphicsItem>
#include<QWidget>
#include<QBrush>
#include<QPen>
#include<QObject>
#include<QFont>

 class Key:public QObject,public QGraphicsItem
 {
Q_OBJECT

 protected:
     double width{0};
     double height{0};
     int key{0};
     QBrush * brush{nullptr};
     QPen * pen{nullptr};
     QPen * penFont{nullptr};
     double xPos{0};  //позиция вставки
     double yPos{0};
     bool pressed{false};
     QFont *font{nullptr};


 public:
    void setPressedStatus(bool);
    bool isPressed();
    int getKey();
    bool operator!=(Key& other);
     // QWidget interface
 protected:
//     virtual void keyPressEvent(QKeyEvent *event) override = 0;
//     virtual void keyReleaseEvent(QKeyEvent *event) override = 0;

     // QGraphicsItem interface
 public:
/////get/////

     double getWidth();

     Key(int key, QGraphicsItem *parent = nullptr);
     virtual ~Key();
     virtual QRectF boundingRect() const override;
     friend class keyboard;

 };


 class WhiteKey:public Key{
 public:
    WhiteKey(int key, QGraphicsItem *parent = nullptr);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
 protected:

 };



 class BlackKey:public Key
 {
 public:
    BlackKey(int key, QGraphicsItem *parent = nullptr);    
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
 };



 class BadKey :public Key
 {
 public:
     BadKey(int key, QGraphicsItem *parent = nullptr);
     virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
 };

#endif // KEY_H
