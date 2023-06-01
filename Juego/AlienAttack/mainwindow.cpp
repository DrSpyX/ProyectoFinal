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

    gameScene= new QGraphicsScene(0,0,500,320);
    ui->graphicsView->setScene(gameScene);

    timerAnimar= new QTimer();

    connect(timerAnimar,SIGNAL(timeout()),this,SLOT(animar()));

    timerAnimar->start(16);

    timerCooldown= new QTimer();

    connect(timerCooldown,SIGNAL(timeout()),this,SLOT(cooldown()));

    timerCooldown->start(1000);

    cooldowndash = 0;

    P1 = new player(300,150);
    gameScene->addItem(P1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::animar()
{
    if(moverRx)
    {
        if(P1->vx > 20)
            P1->ax = 0;
        else
            P1->ax = 10;
        P1->setDireccion(1);
        P1->velocidadesP();
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
        if(P1->vx < -20)
            P1->ax = 0;
        else
            P1->ax = 10;
        P1->setDireccion(2);
        P1->velocidadesN();
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
        if(P1->vy > 20)
            P1->ay = 0;
        else
            P1->ay = 10;
        P1->setDireccion(3);
        P1->velocidadesP();
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
        if(P1->vy < -20)
            P1->ay = 0;
        else
            P1->ay = 10;
        P1->setDireccion(4);
        P1->velocidadesN();
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
            P1->ax = 200;
            P1->velocidadesP();
        }
        if(P1->direccion==2)
        {
            P1->ax = 200;
            P1->velocidadesN();
        }
        if(P1->direccion==3)
        {
            P1->ay = 200;
            P1->velocidadesP();
        }
        if(P1->direccion==4)
        {
            P1->ay = 200;
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
        cooldowndash = 10;
    }
    P1->posiciones();
    if(cooldowndash>0)
        cooldowndash--;
    ui->lcdNumber->display(cooldowndash);
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
