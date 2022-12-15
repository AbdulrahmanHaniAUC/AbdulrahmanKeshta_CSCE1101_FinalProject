#include <QApplication>
#include "map.h"
#include "enemy.h"
#include "health.h"
#include "pellettextitem.h"
#include "pellet.h"
#include "player.h"

map* m;
enemy* e;
health* h;
pelletTextItem* pti;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    m = new map("Game");
    m->show();

    return a.exec();
}
