#include "tile.h"

#include <QtGui/QPainter>

#include "../broken_bazooka.h"

Tile::Tile(int tileId, Sector *sector, QGraphicsItem *parent) :
        QGraphicsItem(parent), mTileId(tileId), mSector(sector) {
}

QRectF Tile::boundingRect() const {
    return QRectF(0, 0, WIDTH, HEIGHT);
}

void Tile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Map *map = static_cast<Map *>(scene());
    painter->drawPixmap(0, 0, map->tile(mSector->tileset(), mTileId, mSector->palette()));
}

void Tile::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    BrokenBazooka *brokenBazooka = static_cast<BrokenBazooka *>(scene()->parent());

    // Set the current properties to this tile's sectors'
    brokenBazooka->setCurrentMapSector(mSector);

    // Replace this item's tile
    mTileId = brokenBazooka->currentTileId();
    update();
}
