#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QPixmap>
#include <cmath>
#include "player.h"
#include "enemy.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void animar();
    void cooldown();
    void muerte();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* gameScene;
    QPixmap *imagenFondo;
    QGraphicsPixmapItem *itemFondo;
    QTimer *timerAnimar;
    QTimer *timerCooldown;
    player* P1;
    enemy* E1;
    QGraphicsRectItem* sierra;
    QPixmap *imagenSierra;
    QGraphicsPixmapItem *itemSierra;

    int cooldowndash;

    bool moverLx;
    bool moverRx;
    bool moverUy;
    bool moverDy;
    bool moverdash;
    bool activardash;

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
};
#endif // MAINWINDOW_H
