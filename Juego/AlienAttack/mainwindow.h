#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "player.h"

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene* gameScene;
    QTimer *timer;
    player* P1;

    bool moverLx;
    bool moverRx;
    bool moverUy;
    bool moverDy;

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
};
#endif // MAINWINDOW_H
