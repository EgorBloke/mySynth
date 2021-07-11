#include"mygraphicsview.h"
#include<QDebug>


MyGraphicsView::MyGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    setMouseTracking(true);
}

void MyGraphicsView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}
