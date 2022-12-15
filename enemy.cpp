#include "enemy.h"

enemy::enemy(int dataItem[13][13], int column, int row) {

    Erow = row;
    Ecolumn = column;

    QPixmap enemyImage(":/graphics/Goblin_idle (1).png");
    enemyImage = enemyImage.scaledToHeight(50);
    enemyImage = enemyImage.scaledToWidth(50);
    setPixmap(enemyImage);
    setPos(50 + 50 * column, 50 + 50 * row);

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            data[i][j] = dataItem[i][j];
        }
    }

    timer();
}

void enemy::timer()
{
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(enemyMovement()));
    if (alive) {
        timer->start(500);
    }

    QTimer* collision = new QTimer();
    connect(collision, SIGNAL(timeout()), this, SLOT(enemyDeath()));
    if (alive) {
        collision->start(100);
    }
}

void enemy::respawn()
{
    QPixmap enemyImage(":/graphics/Goblin_idle (1).png");
    enemyImage = enemyImage.scaledToHeight(50);
    enemyImage = enemyImage.scaledToWidth(50);
    setPixmap(enemyImage);
    setPos(50 + 50 * Ecolumn, 50 + 50 * Erow);
}

void enemy::enemyMovement()
{
      if (alive) {

        direction = wasd[arc4random() % 4];

        if ((direction = 'w') && (data[Erow - 1][Ecolumn]) != -1) {
            Erow--;
        } else if ((direction = 's') && (data[Erow + 1][Ecolumn]) != -1) {
            Erow++;
        } else if ((direction = 'a') && (data[Erow][Ecolumn - 1]) != -1) {
            Ecolumn--;
        } else if ((direction = 'd') && (data[Erow][Ecolumn + 1]) != -1) {
            Ecolumn++;
        }
        setPos(50 + 50 * Ecolumn, 50 + 50 * Erow);
//        qDebug() << "enemy moving";
      }
}


void enemy::enemyDeath()
{
    QList <QGraphicsItem*> colliding_items = collidingItems();

    for (int i = 0; i < colliding_items.size(); i++) {
        if (typeid (*colliding_items[i]) == typeid (bullet)) {
            delete colliding_items[i];

            health = health - 50;

            if(health == 0) {
                QGraphicsPixmapItem::scene()->removeItem(this);
                enemiesKilled++;
                alive = false;
            }

        } else if (typeid (*colliding_items[i]) == typeid (player)) {
            respawn();
        }
    }
}

