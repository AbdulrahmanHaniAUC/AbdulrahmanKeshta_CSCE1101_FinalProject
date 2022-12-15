#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QFont>
#include <QList>
#include <QApplication>
#include <QFile>
#include <QTextStream>

#include "map.h"
#include "bullet.h"
#include "pellet.h"
#include "health.h"
#include "enemy.h"
#include "pellettextitem.h"
#include "gate.h"

class player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
    QString name;
    int pRow;
    int pColumn;
    int data[13][13];

    int playerHealth = 3;
    int savedBullet = 0;

    bool alive = true;

    bool power = false;

    bool up = false;
    bool down = false;
    bool right = false;
    bool left = false;
public:
    player(int [13][13], QString);

    void setHealth(int h);
    int getHealth();

    int getRow();
    int getColumn();

    void respawn();
public slots:
    void keyPressEvent(QKeyEvent* event);
    void collision();
    void powerPellet();
    void pelletTextUpdate();
};

#endif // PLAYER_H
