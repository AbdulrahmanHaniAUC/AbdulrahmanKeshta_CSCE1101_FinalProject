#ifndef PELLETTEXTITEM_H
#define PELLETTEXTITEM_H

#include <QGraphicsTextItem>
#include <QTimer>
#include <QFont>

class pelletTextItem : public QGraphicsTextItem {
public:
    pelletTextItem(QGraphicsItem* parent = 0);
public slots:
    void update();
    void updateFalse();

    int pelletTime = 5;
    bool updateText = false;
};

#endif // PELLETTEXTITEM_H
