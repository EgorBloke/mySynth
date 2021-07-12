#include"keyboard.h"





Keyboard::Keyboard(QVector<int> keysValue, QObject *parent) : QObject(parent)
{
    this->keysValue=keysValue;
    keysNumber=12;
    setKeys();
}

void Keyboard::setKeys()
{
    int pos =0;
    for(int i=0; i<keysNumber;++i){
        if(!isBlack(i+firstKey)){
            keys.push_back(new WhiteKey(keysValue[i],this));
            keys[i]->setPos(pos,0);

            pos+=keys[i]->getWidth();

        }
        else {
            keys.push_back(new BlackKey(keysValue[i],this));
            keys[i]->setPos(pos,0);
            keys[i]->setZValue(1);
        }

    }


//    keys.push_back(new WhiteKey(Qt::Key_Q,this));

//    this->scene()->addItem(keys[0]);

}

bool Keyboard::isBlack(const int num)
{
    int lst=num%11;
    return lst==1||lst==3||lst==6||lst==8||lst==10;
}

QRectF Keyboard::boundingRect() const
{
    return QRectF(0,0,0,0);
}

void Keyboard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}
