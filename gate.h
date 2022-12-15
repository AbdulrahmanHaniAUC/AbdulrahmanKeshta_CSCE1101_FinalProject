#ifndef GATE_H
#define GATE_H

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

class gate : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    gate(int, int);
};

#endif // GATE_H
