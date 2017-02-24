#ifndef MAP_TILE_H
#define MAP_TILE_H

#include <QtWidgets/QGraphicsItem>

#include "sector.h"
#include "tile.h"

class MapTile : public Tile {
public:
    MapTile(int id, Sector *sector, QGraphicsItem *parent = Q_NULLPTR);

protected:
    QPixmap * tile() const;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    Sector * const mSector;
};

#endif // MAP_TILE_H
