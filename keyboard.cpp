#include"keyboard.h"





Keyboard::Keyboard(QVector<int> keysValue, QObject *parent) : QObject(parent)
{
    this->keysValue=keysValue;
    keysNumber=20;
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


}

bool Keyboard::isBlack(const int num)
{
    int lst=num%12;
    return lst==1||lst==3||lst==6||lst==8||lst==10;
}

QRectF Keyboard::boundingRect() const
{
    return QRectF(0,0,0,0);
}

void Keyboard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

Key &Keyboard::operator[](int val)
{
    for(auto k:keys){
        if(k->getKey()==val){
            return *k;
        }
    }
    return badKey;
}

Key &Keyboard::getBadKey()
{
    return this->badKey;
}
