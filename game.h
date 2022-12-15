#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>

#include "player.h"
#include "health.h"
#include "bullet.h"
#include "pellet.h"

class game{
public:
    game();

    QGraphicsScene* scene;
    player* franklin;
    bullet* bullet;
    pellet* power;
};

#endif // GAME_H
