#include "pellet.h"

pellet::pellet()
{

}

pellet::pellet(int PPcolumn, int PProw)
{
    QPixmap image(":/graphics/goldskull.png");
    QPixmap image2 = image.transformed(QTransform().rotate(360));
    image2 = image2.scaledToHeight(50);
    image2 = image2.scaledToWidth(50);
    setPixmap(image2);
    setPos(50 + 50 * PPcolumn, 50 + 50 * PProw);
}
