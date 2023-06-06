#include "enemy.h"

enemy::enemy(float _x, float _y, double _salud, QObject *parent) : QObject(parent)
{
    x = _x;
    y = _y;
    vx = 0;
    vy = 0;
    ax = 0;
    ay = 0;
    setPos(x,y);
    salud = _salud;

    pixelX = 0;
    pixelY = 0;

    pixmap = new QPixmap(":/sprites/Alien.png");

    timer = new QTimer();

    timer->start(100);

    connect(timer,&QTimer::timeout,this,&enemy::animacion);
}

enemy::~enemy()
{

}

void enemy::animacion()
{
    this->update(-50,-50,100,100);
}

QRectF enemy::boundingRect() const
{
    return QRect(-50,-50,100,100);
}

void enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-50,-50,*pixmap,pixelY,pixelX,100,100);
}

void enemy::velocidadesP()
{
    vx = vx + (ax*DT);
    vy = vy + (ay*DT);
}

void enemy::velocidadesN()
{
    vx = vx - (ax*DT);
    vy = vy - (ay*DT);
}

void enemy::posiciones()
{
    x = x + (vx * DT) + (0.5 * ax * pow(DT,2));
    y = y + (vy * DT) + (0.5 * ay * pow(DT,2));

    setPos((x), (y));
}
