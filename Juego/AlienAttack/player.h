#ifndef PLAYER_H
#define PLAYER_H

#define DT 0.2

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <QObject>

class player : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit player(float _x, float _y, double _salud, QObject *parent = nullptr);
    ~player();
    float x, y, vx, vy, ax, ay;
    double salud;
    int armaID;
    QTimer *timer;
    QPixmap *pixmap;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    float pixelX, pixelY;
    int direccion;
    void setDireccion(int direccion);
    void velocidadesN();
    void velocidadesP();
    void posiciones();

public slots:
    void animacion();
};

#endif // PLAYER_H
