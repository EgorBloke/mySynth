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

Key::Key(int key, QGraphicsItem *parent) :  QObject(),QGraphicsItem(parent)
{
    this->key=key;
    penFont = new QPen();
    font = new QFont();
}

Key::~Key()
{

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
        penFont->setColor(Qt::black);
    } else
    {
        brush->setColor(Qt::green);
        brush->setColor(QColor(QRgb(0x07A838)));
        penFont->setColor(Qt::white);
    }

    painter->setBrush(*brush);
    painter->drawRect(xPos,yPos,width,height);

    if(this->isPressed()==false){
        penFont->setColor(Qt::black);
    } else
    {
       penFont->setColor(Qt::black);
    }
    font->setBold(true);
    font->setPixelSize(12);
    painter->setFont(*font);
    painter->setPen(*penFont);

    painter->drawText(QRectF(-width/2,yPos+height*0.8,width,height),Qt::AlignRight,QString(char(key)));

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
//        brush->setColor(Qt::green);
        brush->setColor(QColor(QRgb(0x07A838)));

    }
    painter->setBrush(*brush);
    painter->drawRect(-width/2,yPos,width,height);
    //draw key
    font->setBold(true);
    font->setPixelSize(12);
    painter->setFont(*font);


     if(this->isPressed()==false){
         penFont->setColor(Qt::white);
     } else
     {
        penFont->setColor(Qt::white);
     }
     painter->setPen(*penFont);
     painter->drawText(QRectF(-width/2,yPos+height*0.3,width,height),Qt::AlignCenter,QString(char(key)));

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
