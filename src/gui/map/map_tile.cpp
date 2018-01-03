#include "map_tile.h"

#include <QGraphicsSceneMouseEvent>

#include "gui/broken_bazooka.h"

MapTile::MapTile(int id, Sector *sector, QGraphicsItem *parent) :
        Tile(id, parent), mSector(sector) {
}

QPixmap * MapTile::tile() const {
    auto *map = dynamic_cast<Map *>(scene());
    return map->tile(id(), mSector->tileset(), mSector->palette());
}

void MapTile::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    auto *brokenBazooka = dynamic_cast<BrokenBazooka *>(scene()->parent());

    // Set the current properties to this tile's sectors'
    brokenBazooka->setCurrentMapSector(mSector);

    // Replace this item's tile
    if (event->button() == Qt::LeftButton && brokenBazooka->currentMapSelectorTile() != nullptr) {
        setId(brokenBazooka->currentMapSelectorTile()->id());
        update();
    }
}
