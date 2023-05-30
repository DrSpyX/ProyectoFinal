#ifndef PLAYER_H
#define PLAYER_H

#define DT 0.1

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <QObject>

class player : public QObject, public QGraphicsItem
{
    Q_OBJECT
protected:
    float x, y;
public:
    explicit player(float _x, float _y, QObject *parent = nullptr);
    ~player();
    float vx, vy, ax, ay;
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
    void muerte();

public slots:
    void animacion();
};

#endif // PLAYER_H
