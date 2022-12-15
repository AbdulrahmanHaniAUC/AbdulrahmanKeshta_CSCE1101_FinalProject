#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QList>

#include "map.h"
#include "bullet.h"
#include "pellet.h"
#include "player.h"
#include "gate.h"


class enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
    int data[13][13];
    char wasd[4] = {'w', 'a', 's', 'd'};
    char direction;
    int Ecolumn;
    int Erow;
public:
    int health = 100;
    int enemiesKilled = 0;
    bool alive = true;

    enemy(int [13][13], int, int);
    void timer();
    void respawn();
public slots:
    void enemyMovement();
    void enemyDeath();
};

#endif // ENEMY_H
