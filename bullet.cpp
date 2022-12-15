#include "bullet.h"

bullet::bullet(bool r, bool l, bool u, bool d, int b[13][13]) {
    //drawing bullet
    QPixmap image(":/graphics/bullet.png");
    QPixmap image2 = image.transformed(QTransform().rotate(90));
    image2 = image2.scaledToWidth(25);
    image2 = image2.scaledToHeight(25);
    setPixmap(image2);

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            board[i][j] = b[i][j];
        }
    }

    right = r;
    left = l;
    up = u;
    down = d;

    //connect
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(200);

//    QTimer* collision = new QTimer();
//    connect(collision, SIGNAL(timeout()), this, SLOT(bulletCollision()));
//    collision->start(500);
}

bullet::bullet(int Bcolumn, int Brow)
{
    QPixmap image(":/graphics/bullet.png");
    QPixmap image2 = image.transformed(QTransform().rotate(360));
    image2 = image2.scaledToHeight(50);
    image2 = image2.scaledToWidth(50);
    setPixmap(image2);
    setPos(50 + 50 * Bcolumn, 50 + 50 * Brow);
}

void bullet::move() {
    int i = (pos().y()/50)-1;
    int j = (pos().x()/50)-1;

    if (board[i][j] > 0) {
        if (up) {
            setPos(x(), y() - 50);
        } else if (down) {
            setPos(x(), y() + 50);
        } else if (left) {
            setPos(x() - 50, y());
        } else if (right) {
            setPos(x() + 50, y());
        }
    } else {
        delete this;
    }
}


/*
void bullet::bulletCollision()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for (int i = 0; i < colliding_items.size(); i++) {
        if ((typeid (*colliding_items[i]) == typeid (enemy))) {
            delete colliding_items[i];
        }
    }
}
*/

