#include "pellettextitem.h"

pelletTextItem::pelletTextItem(QGraphicsItem *parent) : QGraphicsTextItem(parent) {

    setPlainText(QString("Power Time Left: ") + QString::number(pelletTime));
    setDefaultTextColor(Qt::green);
    setFont(QFont("Chalkboard", 20));
}

void pelletTextItem::update()
{
    if (updateText) {
        pelletTime--;

        setPlainText(QString("Power Time Left: ") + QString::number(pelletTime));

        if (pelletTime == 4) {
            setDefaultTextColor(Qt::yellow);
        } else if (pelletTime <= 2) {
            setDefaultTextColor(Qt::red);
        }
    }
}

void pelletTextItem::updateFalse()
{
    updateText = false;
}
