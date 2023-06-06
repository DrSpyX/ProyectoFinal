#ifndef ENEMY_H
#define ENEMY_H

#define DT 0.2

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <QObject>

class enemy : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit enemy(float _x, float _y, double _salud, QObject *parent = nullptr);
    ~enemy();
    float x, y, vx, vy, ax, ay;
    double salud;
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

#endif // ENEMY_H
