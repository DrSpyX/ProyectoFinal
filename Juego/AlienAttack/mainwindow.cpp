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

    gameScene=new QGraphicsScene(0,0,500,320);
    ui->graphicsView->setScene(gameScene);

    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(animar()));

    timer->start(16);

    P1 = new player(300,150);
    gameScene->addItem(P1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::animar()
{
    if(moverLx)
    {
        P1->ax = 10;
        P1->setDireccion(2);
        P1->velocidadesN();
    }
    else
    {
        if(P1->vx < 0)
            P1->ax = -20;
        else
            P1->ax = 0;
        P1->velocidadesN();
    }
    if(moverRx)
    {
        P1->ax = 10;
        P1->setDireccion(1);
        P1->velocidadesP();
    }
    else
    {
        if(P1->vx > 0)
            P1->ax = -20;
        else
            P1->ax = 0;
        P1->velocidadesP();
    }
    if(moverUy)
    {
        P1->ay = 10;
        P1->setDireccion(4);
        P1->velocidadesN();
    }
    else
    {
        if(P1->vy < 0)
            P1->ay = -20;
        else
            P1->ay = 0;
        P1->velocidadesN();
    }
    if(moverDy)
    {
        P1->ay = 10;
        P1->setDireccion(3);
        P1->velocidadesP();
    }
    else
    {
        if(P1->vy > 0)
            P1->ay = -20;
        else
            P1->ay = 0;
        P1->velocidadesP();
    }

    P1->posiciones();
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
}
