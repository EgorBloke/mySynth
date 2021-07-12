#include<key.h>
#include<QPainter>


double Key::getWidth()
{
    return width;
}

Key::Key(int key, QGraphicsItem *parent) : QGraphicsItem(parent), QObject()
{

    this->key=key;
}
void Key::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(*brush);
    painter->drawRect(xPos,yPos,width,height);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
QRectF Key::boundingRect() const
{
    return QRectF(0,0,0,0);
}

WhiteKey::WhiteKey(int key, QGraphicsItem *parent) : Key(key, parent)
{

    width = 65.;
    height = 320.;
    brush = new QBrush(Qt::white);
    pen = new QPen(Qt::black);
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
    painter->setBrush(*brush);
    painter->drawRect(-width/2,yPos,width,height);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}




