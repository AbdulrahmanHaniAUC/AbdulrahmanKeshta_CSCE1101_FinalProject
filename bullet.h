#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QObject>
#include <QList>
#include <QtCore>
#include <time.h>

#include "player.h"
#include "map.h"
#include "enemy.h"

class bullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
    bool right;
    bool left;
    bool up;
    bool down;

    int board[13][13];

public:
    bullet(bool, bool, bool, bool, int [13][13]);
    bullet(int, int);

public slots:
    void move();
//    void bulletCollision();
};

#endif // BULLET_H
