#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QFont>

class health : public QGraphicsTextItem {
public:
    health(QGraphicsItem* parent = 0);

    void decrease();
    void setHealth(int);
    int getHealth();

    int Health;
};

#endif // HEALTH_H
