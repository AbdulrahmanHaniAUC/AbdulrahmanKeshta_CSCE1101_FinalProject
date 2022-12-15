#include "health.h"

health::health(QGraphicsItem *parent) : QGraphicsTextItem(parent) {

    Health = 3;

    setPlainText(QString("Lives: ") + QString::number(Health));
    setDefaultTextColor(Qt::green);
    setFont(QFont("Chalkboard", 20));
}

void health::decrease()
{
    Health--;

    setPlainText(QString("Lives: ") + QString::number(Health));

    if (Health == 2) {
        setDefaultTextColor(Qt::yellow);
    } else if (Health == 1) {
        setDefaultTextColor(Qt::red);
    }
}

void health::setHealth(int h)
{
    Health = h;

    setPlainText(QString("Lives: ") + QString::number(Health));
    if (Health >= 2) {
        setDefaultTextColor(Qt::green);
    }
}

int health::getHealth()
{
    return Health;
}
