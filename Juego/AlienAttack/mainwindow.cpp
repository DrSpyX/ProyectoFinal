#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    moverLx=false;
    moverRx=false;
    moverUy=false;
    moverDy=false;
    moverdash=false;
    activardash=false;

    gameScene = new QGraphicsScene(0,0,1900,950);
    ui->graphicsView->setScene(gameScene);

    imagenFondo = new QPixmap(":/sprites/Fondo.png");

    itemFondo = new QGraphicsPixmapItem(*imagenFondo);

    gameScene->addItem(itemFondo);

    itemFondo->setPos(0,0);
    itemFondo->setZValue(-1);

    timerAnimar = new QTimer();

    connect(timerAnimar,SIGNAL(timeout()),this,SLOT(animar()));

    connect(timerAnimar,SIGNAL(timeout()),this,SLOT(muerte()));

    timerAnimar->start(16);

    timerCooldown = new QTimer();

    connect(timerCooldown,SIGNAL(timeout()),this,SLOT(cooldown()));

    timerCooldown->start(1000);

    cooldowndash = 0;

    P1 = new player(175,175,100);
    gameScene->addItem(P1);

    sierra=new QGraphicsRectItem(-50,-50,100,100);
    gameScene->addItem(sierra);
    sierra->setPos(500,500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::animar()
{
    if(moverRx)
    {
        if(P1->x>1725)
        {
            P1->vx = 0;
        }
        else
        {
            if(P1->vx > 20)
                P1->ax = 0;
            else
                P1->ax = 10;
            P1->velocidadesP();
        }
        P1->setDireccion(1);
    }
    else
    {
        if(P1->vx > 0)
            P1->ax = -10;
        else
            P1->ax = 0;
        P1->velocidadesP();
    }
    if(moverLx)
    {
        if(P1->x<175)
        {
            P1->vx = 0;
        }
        else
        {
            if(P1->vx < -20)
                P1->ax = 0;
            else
                P1->ax = 10;
            P1->velocidadesN();
        }
        P1->setDireccion(2);
    }
    else
    {
        if(P1->vx < 0)
            P1->ax = -10;
        else
            P1->ax = 0;
        P1->velocidadesN();
    }
    if(moverDy)
    {
        if(P1->y>775)
        {
            P1->vy = 0;
        }
        else
        {
            if(P1->vy > 20)
                P1->ay = 0;
            else
                P1->ay = 10;
            P1->velocidadesP();
        }
        P1->setDireccion(3);
    }
    else
    {
        if(P1->vy > 0)
            P1->ay = -10;
        else
            P1->ay = 0;
        P1->velocidadesP();
    }
    if(moverUy)
    {
        if(P1->y<175)
        {
            P1->vy = 0;
        }
        else
        {
            if(P1->vy < -20)
                P1->ay = 0;
            else
                P1->ay = 10;
            P1->velocidadesN();
        }
        P1->setDireccion(4);
    }
    else
    {
        if(P1->vy < 0)
            P1->ay = -10;
        else
            P1->ay = 0;
        P1->velocidadesN();
    }
    if(activardash)
    {
        if(P1->direccion==1)
        {
            P1->ax = 100;
            P1->velocidadesP();
        }
        if(P1->direccion==2)
        {
            P1->ax = 100;
            P1->velocidadesN();
        }
        if(P1->direccion==3)
        {
            P1->ay = 100;
            P1->velocidadesP();
        }
        if(P1->direccion==4)
        {
            P1->ay = 100;
            P1->velocidadesN();
        }
        activardash = false;
    }
    P1->posiciones();
}

void MainWindow::cooldown()
{
    if(moverdash && cooldowndash==0)
    {
        activardash = true;
        cooldowndash = 15;
    }
    P1->posiciones();
    if(cooldowndash>0)
        cooldowndash--;
    ui->lcdCooldown->display(cooldowndash);
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverLx=true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverRx=true;
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverUy=true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverDy=true;
    }
    else if(ev->key()==Qt::Key_Space)
    {
        moverdash=true;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverLx=false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverRx=false;
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverUy=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverDy=false;
    }
    else if(ev->key()==Qt::Key_Space)
    {
        moverdash=false;
    }
}

void MainWindow::muerte()
{
    if(P1->collidesWithItem(sierra))
    {
        P1->salud -= 1;
    }
    if(P1->salud <= 0)
    {
        P1->x = 175;
        P1->y = 175;
        P1->salud = 100;
    }
    ui->lcdSalud->display(P1->salud);
}
