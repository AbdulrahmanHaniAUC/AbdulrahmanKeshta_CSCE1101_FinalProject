#ifndef PELLET_H
#define PELLET_H

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

class pellet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    pellet();
    pellet(int, int);
};

#endif // PELLET_H
