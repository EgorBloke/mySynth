#include<key.h>
#include<QPainter>


void Key::setPressedStatus(bool val)
{
    this->pressed=val;
}

bool Key::isPressed()
{
    return pressed;
}

int Key::getKey()
{
    return key;
}

bool Key::operator!=(Key &other)
{
    return this->key!=other.key;
}



double Key::getWidth()
{
    return width;
}

Key::Key(int key, QGraphicsItem *parent) : QGraphicsItem(parent), QObject()
{
    this->key=key;
}

QRectF Key::boundingRect() const
{
    return QRectF(0,0,0,0);
}

WhiteKey::WhiteKey(int key, QGraphicsItem *parent) : Key(key, parent)
{

    width = 65.;
    height = 320.;
    brush = new QBrush(Qt::black);
    pen = new QPen(Qt::black);
}
void WhiteKey::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(this->isPressed()==false){
        brush->setColor(Qt::white);
    } else
    {
        brush->setColor(Qt::green);
    }

    painter->setBrush(*brush);
    painter->drawRect(xPos,yPos,width,height);


    Q_UNUSED(option);
    Q_UNUSED(widget);
}


BlackKey::BlackKey(int key, QGraphicsItem *parent) : Key(key, parent)
{
    width = 40.;
    height = 200.;
    brush = new QBrush(Qt::black);
    pen = new QPen(Qt::black);
}

void BlackKey::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(this->isPressed()==false){
        brush->setColor(Qt::black);
    } else
    {
        brush->setColor(Qt::green);
    }
    painter->setBrush(*brush);
    painter->drawRect(-width/2,yPos,width,height);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}





BadKey::BadKey(int key, QGraphicsItem *parent) : Key(key, parent)
{

}

void BadKey::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
