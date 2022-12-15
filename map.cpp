#include "map.h"

map::map(QString name, QWidget* parent) : QGraphicsView(parent) {
    this->name = name;

    panel = new QGraphicsView;
    panel->setFixedSize(650, 650);
    panel->setWindowTitle("GTA Maze Game v0.0.1");

    // creating a scene
    scene = new QGraphicsScene;
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(0, 0);
    scene->setSceneRect(50, 50, 650, 650);

    // creating a file object
    QFile file(":/map/boardmap.txt");
    file.open(QIODevice::ReadOnly);

    QTextStream stream(& file);

    QString temp;

    // reading the board map file and inserting into array
    for (int i = 0; i < row; i++)
        for(int j = 0; j < column; j++) {
            stream >> temp;
            boardData[i][j] = temp.toInt();
        }

    dataImage = new QGraphicsPixmapItem* [row];
    for (int i = 0; i < row; i++) {
        dataImage[i] = new QGraphicsPixmapItem[column];
    }

    // setting game textures/graphics
    grass = new QPixmap(":/graphics/Grass.png");
    street = new QPixmap(":/graphics/street.png");
    asphalt = new QPixmap(":/graphics/asphalt.png");
    house = new QPixmap(":/graphics/house.png");
    brickwall = new QPixmap(":/graphics/wall.png");
    car1 = new QPixmap(":/graphics/car1.png");
    car2 = new QPixmap(":/graphics/yellowCar.png");



    // setting graphics sizes
    *grass = grass->scaledToHeight(50);
    *grass = grass->scaledToHeight(50);

    *street = street->scaledToHeight(50);
    *street = street->scaledToHeight(50);

    *asphalt = asphalt->scaledToHeight(50);
    *asphalt = asphalt->scaledToHeight(50);

    *house = house->scaledToHeight(50);
    *house = house->scaledToHeight(50);

    *brickwall = brickwall->scaledToHeight(50);
    *brickwall = brickwall->scaledToHeight(50);

    *car1 = car1->scaledToHeight(50);
    *car1 = car1->scaledToHeight(50);

    *car2 = car2->scaledToHeight(50);
    *car2 = car2->scaledToHeight(50);

    // putting the graphics in place
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++) {
            if(boardData[i][j] <= 0) {
                dataImage[i][j].setPixmap(*brickwall);
            } else if (boardData[i][j] == 99) {
                dataImage[i][j].setPixmap(*house);
            } else if (boardData[i][j] == 88) {
                dataImage[i][j].setPixmap(*asphalt);
            } else if (boardData[i][j] == 20) {
                dataImage[i][j].setPixmap(*street);
            } else if (boardData[i][j] == 10) {
                dataImage[i][j].setPixmap(*grass);
            } else if (boardData[i][j] == 16) {
                dataImage[i][j].setPixmap(*car1);
            }  else if (boardData[i][j] == 55) {
                dataImage[i][j].setPixmap(*car2);
            }

            dataImage[i][j].setPos(50+50*j, 50+50*i);
            scene->addItem(&dataImage[i][j]);
        }

    player* franklin;
    franklin = new player(boardData, name);
    franklin->setFlag(QGraphicsItem::ItemIsFocusable);
    franklin->setFocus();
    scene->addItem(franklin);

    life->setPos(50, 50);
    scene->addItem(life);

    bullet* b1;
    b1 = new bullet(10, 11);
    scene->addItem(b1);
    bullet* b2;
    b2 = new bullet(1, 1);
    scene->addItem(b2);
    bullet* b3;
    b3 = new bullet(10, 3);
    scene->addItem(b3);
    bullet* b4;
    b4 = new bullet(1, 11);
    scene->addItem(b4);

    pellet* p1;
    p1 = new pellet(3, 4);
    scene->addItem(p1);
    pellet* p2;
    p2 = new pellet(7, 11);
    scene->addItem(p2);

    enemy* e1 = new enemy(boardData, 9, 5);
    scene->addItem(e1);
    enemy* e2 = new enemy(boardData, 3, 9);
    scene->addItem(e2);

    gate* g = new gate(6, 5);
    scene->addItem(g);

    panel->setScene(scene);
    panel->show();

    timer();
}

void map::exit() {
    this->close();
}

void map::timer() {
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(check()));
    timer->start(1000);

    QTimer* bulletSpawn = new QTimer(this);
    connect(bulletSpawn, SIGNAL(timeout()), this, SLOT(spawnBullet()));
    bulletSpawn->start(20000);
}

void map::check() {



    if (!panel->isVisible()) {
        this->close();
    }
}

void map::spawnBullet()
{
    bullet* b1;
    b1 = new bullet(10, 11);
    scene->addItem(b1);
    bullet* b2;
    b2 = new bullet(1, 1);
    scene->addItem(b2);
    bullet* b3;
    b3 = new bullet(10, 3);
    scene->addItem(b3);
    bullet* b4;
    b4 = new bullet(1, 11);
    scene->addItem(b4);
}
