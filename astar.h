#ifndef ASTAR_H
#define ASTAR_H

#include <QMainWindow>
#include <QObject>
#include <player.h>
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

class astar
{
public:
    astar();
};

#endif // ASTAR_H
