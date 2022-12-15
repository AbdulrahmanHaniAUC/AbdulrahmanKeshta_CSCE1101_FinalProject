#ifndef MAP_H
#define MAP_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QApplication>
#include <QFile>
#include <QTextStream>

#include "player.h"
#include "health.h"
#include "bullet.h"
#include "pellet.h"
#include "gate.h"
#include "pellettextitem.h"
#include "enemy.h"

class map : public QGraphicsView {
    Q_OBJECT

    bool lvl1 = false;
    bool lvl2 = false;
    bool lvl3 = false;

    QString name;
public:
    QGraphicsScene* scene;
    QGraphicsView* panel;

    int row = 13;
    int column = 13;
    int boardData[13][13];

    QGraphicsPixmapItem** dataImage;
    QPixmap* street;
    QPixmap* house;
    QPixmap* brickwall;
    QPixmap* grass;
    QPixmap* asphalt;
    QPixmap* car1;
    QPixmap* car2;

    health* life = new health();

    pelletTextItem* powerful = new pelletTextItem();

    map(QString name, QWidget* parent = 0);
    void exit();
    void timer();
public slots:
    void check();
    void spawnBullet();
};

#endif // MAP_H
