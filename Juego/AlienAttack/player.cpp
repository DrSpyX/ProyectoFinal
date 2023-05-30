#include "player.h"

player::player(float _x, float _y, QObject *parent) : QObject(parent)
{
    x = _x;
    y = _y;
    vx = 0;
    vy = 0;
    ax = 0;
    ay = 0;
    setPos(x,y);
    salud = 100;
    armaID = 0;

    pixelX = 0;
    pixelY = 0;

    pixmap = new QPixmap(":/sprites/Astronauta.png");

    timer = new QTimer();

    timer->start(100);

    connect(timer,&QTimer::timeout,this,&player::animacion);
}

player::~player()
{

}

void player::animacion()
{
    if(direccion == 1){ //derecha
        pixelX = 100;
        pixelY += 100;
        if(pixelY >= 800){
            pixelY = 0;
        }
    }
    if(direccion == 2){ //izquierda
        pixelX = 200;
        pixelY += 100;
        if(pixelY >= 800){
            pixelY = 0;
        }
    }
    if(direccion == 3){ //abajo
        pixelX = 300;
        pixelY += 100;
        if(pixelY >= 800){
            pixelY = 0;
        }
    }
    if(direccion == 4){ //arriba
        pixelX = 400;
        pixelY += 100;
        if(pixelY >= 800){
            pixelY = 0;
        }
    }

    this->update(-50,-50,100,100);
}

QRectF player::boundingRect() const
{
    return QRect(-50,-50,100,100);
}

void player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-50,-50,*pixmap,pixelY,pixelX,100,100);
}

void player::setDireccion(int _direccion)
{
    direccion = _direccion;
}

void player::velocidadesP()
{
    vx = vx + (ax*DT);
    vy = vy + (ay*DT);
}

void player::velocidadesN()
{
    vx = vx - (ax*DT);
    vy = vy - (ay*DT);
}

void player::posiciones()
{
    x = x + (vx * DT) + (0.5 * ax * pow(DT,2));
    y = y + (vy * DT) + (0.5 * ay * pow(DT,2));

    setPos((x), (y));
}

