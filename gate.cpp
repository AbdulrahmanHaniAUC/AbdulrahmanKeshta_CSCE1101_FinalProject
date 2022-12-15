#include "gate.h"

gate::gate(int Gcolumn, int Grow)
{
    QPixmap image(":/graphics/castledoors.png");
    QPixmap image2 = image.transformed(QTransform().rotate(360));
    image2 = image2.scaledToHeight(50);
    image2 = image2.scaledToWidth(50);
    setPixmap(image2);

    setPos(50 + 50 * Gcolumn, 50 + 50 * Grow);
}
