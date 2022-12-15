#include "player.h"

extern map* m;
extern health* h;
extern pelletTextItem* pti;

player::player(int dataItem [13][13], QString name) {
    this->name = name;

    pRow = 7;
    pColumn = 6;

    QPixmap franklin(":/graphics/franklin_v2.png");

    franklin = franklin.scaledToWidth(50);
    franklin = franklin.scaledToHeight(50);

    setPixmap(franklin);

    setPos(50 + 50 * pColumn, 50 + 50 * pRow);

    QGraphicsRectItem().setRect(50*25, 0, 50, 500);

    for (int i = 0; i < 13; i++)
        for (int j = 0; j < 13; j++) {
            data[i][j] = dataItem[i][j];
        }

    QTimer* coll;
    coll = new QTimer();
    connect(coll, SIGNAL(timeout()), this, SLOT(collision()));
    coll->start(100);
}

void player::setHealth(int h)
{
    playerHealth = h;
}

int player::getHealth()
{
    return playerHealth;
}

int player::getRow()
{
    return (50 + 50 * pRow);
}

int player::getColumn()
{
    return (50 + 50 * pColumn);
}

void player::respawn()
{
    pRow = 6;
    pColumn = 6;

    QPixmap franklin(":/graphics/franklin_v2.png");

    franklin = franklin.scaledToWidth(50);
    franklin = franklin.scaledToHeight(50);

    setPixmap(franklin);

    setPos(50 + 50 * pColumn, 50 + 50 * pRow);
}

void player::powerPellet()
{
    power = false;
    m->powerful->updateText = false;
    delete m->powerful;
}

void player::pelletTextUpdate()
{
    m->powerful->update();
}

void player::keyPressEvent(QKeyEvent *event) {
    if (alive) {
        if (event->key() == Qt::Key_A && (data[pRow][pColumn - 1]) > 0) {
            pColumn--;
            up = false;
            down = false;
            right = false;
            left = true;
        } else if (event->key() == Qt::Key_D && (data[pRow][pColumn + 1]) > 0) {
            pColumn++;
            up = false;
            down = false;
            right = true;
            left = false;
        } else if (event->key() == Qt::Key_W && (data[pRow - 1][pColumn]) > 0) {
            pRow--;
            up = true;
            down = false;
            right = false;
            left = false;
        } else if (event->key() == Qt::Key_S && (data[pRow + 1][pColumn]) > 0) {
            pRow++;
            up = false;
            down = true;
            right = false;
            left = false;
        }
    }
    if (alive) {
        if (event->key() == Qt::Key_Left && (data[pRow][pColumn - 1]) > 0) {
            pColumn--;
            up = false;
            down = false;
            right = false;
            left = true;
        } else if (event->key() == Qt::Key_Right && (data[pRow][pColumn + 1]) > 0) {
            pColumn++;
            up = false;
            down = false;
            right = true;
            left = false;
        } else if (event->key() == Qt::Key_Up && (data[pRow - 1][pColumn]) > 0) {
            pRow--;
            up = true;
            down = false;
            right = false;
            left = false;
        } else if (event->key() == Qt::Key_Down && (data[pRow + 1][pColumn]) > 0) {
            pRow++;
            up = false;
            down = true;
            right = false;
            left = false;
        }
    }

    if (alive && savedBullet > 0) {
        if (event->key() == Qt::Key_Space && up) {
            bullet* Bullet = new bullet(false, false, true, false, data);
            Bullet->setPos(50 + 50 * pColumn, 0 + 50 * pRow);
            scene()->addItem(Bullet);
            savedBullet--;
        } else if (event->key() == Qt::Key_Space && down) {
            bullet* Bullet = new bullet(false, false, false, true, data);
            Bullet->setPos(50 + 50 * pColumn, 100 + 50 * pRow);
            scene()->addItem(Bullet);
            savedBullet--;
        } else if (event->key() == Qt::Key_Space && right) {
            bullet* Bullet = new bullet(true, false, false, false, data);
            Bullet->setPos(100 + 50 * pColumn, 50 + 50 * pRow);
            scene()->addItem(Bullet);
            savedBullet--;
        } else if (event->key() == Qt::Key_Space && left) {
            bullet* Bullet = new bullet(false, true, false, false, data);
            Bullet->setPos(0 + 50 * pColumn, 50 + 50 * pRow);
            scene()->addItem(Bullet);
            savedBullet--;
        }
    }

    setPos((50 + 50 * pColumn), (50 + 50 * pRow));
}

void player::collision() {
    QList <QGraphicsItem*> colliding_items = collidingItems();

    for(int i = 0 && alive; i < colliding_items.size(); i++) {
        if (typeid(*colliding_items[i]) == typeid (bullet)) {
            delete colliding_items[i];
            savedBullet++;

            //texture change

        } else if (typeid(*colliding_items[i]) == typeid (pellet)) {

            power = true;
            delete colliding_items[i];

            m->powerful->setPos(275, 50);
            m->scene->addItem(m->powerful);
            m->powerful->updateText = true;

            QTimer* pellet = new QTimer();
            connect(pellet, SIGNAL(timeout()), this, SLOT(powerPellet()));
            pellet->start(5500);

            QTimer* pelletUpdate = new QTimer();
            connect(pelletUpdate, SIGNAL(timeout()), this, SLOT(pelletTextUpdate()));
            pelletUpdate->start(1000);


        } else if (typeid(*colliding_items[i]) == typeid (enemy)) {
            if (!power) {
            playerHealth--;
            respawn();
            m->life->decrease();

            //End Game if Health = 0 (lose option: game over)
            if(m->life->Health == 0) {
                m->exit();
            }
            }
        } else if (typeid(*colliding_items[i]) == typeid (gate)) {
            //end game you won
        }
    }
}
