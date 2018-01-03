#include "map.h"

#include <QtGui/QPainter>

#include "../broken_bazooka.h"
#include "map_tile.h"

Map::Map(MapData *mapData, BrokenBazooka *parent) :
        QGraphicsScene(parent), mMapData(mapData), mTilesLayer(new Layer()),
        mSpritesLayer(new Layer()), mEnemiesLayer(new Layer()), mDoorsLayer(new Layer()),
        mHotspotsLayer(new Layer()), mCurrentSector(nullptr) {
    setBackgroundBrush(Qt::black);

    // Make the scene slightly bigger so that grid lines can be drawn on the edges
    setSceneRect(0, 0, MapData::MAP_TILES_X*Tile::WIDTH + 1, MapData::MAP_TILES_Y*Tile::HEIGHT + 1);

    // Set up the layers
    addItem(mTilesLayer);
    addItem(mSpritesLayer);
    addItem(mEnemiesLayer);
    addItem(mDoorsLayer);
    addItem(mHotspotsLayer);

    // Create the background tiles and associated sectors
    for (int x = 0; x < MapData::MAP_TILES_X; x++) {
        for (int y = 0; y < MapData::MAP_TILES_Y; y++) {
            MapTile *tile = new MapTile(
                    0, mapData->sector(x/Sector::WIDTH, y/Sector::HEIGHT), mTilesLayer
            );
            tile->setPos(x * Tile::WIDTH, y * Tile::WIDTH);
        }
    }

    // Create the grid lines
    for (int x = 0; x <= MapData::MAP_TILES_X; x++)
        mGridLines.append(
                QLine(x * Tile::WIDTH, 0, x * Tile::WIDTH, MapData::MAP_TILES_Y * Tile::HEIGHT)
        );
    for (int y = 0; y <= MapData::MAP_TILES_Y; y++)
        mGridLines.append(
                QLine(0, y * Tile::HEIGHT, MapData::MAP_TILES_X * Tile::WIDTH, y * Tile::HEIGHT)
        );
}

Sector * Map::currentSector() const {
    return mCurrentSector;
}

void Map::setCurrentSector(Sector *sector) {
    mCurrentSector = sector;
    update();
}

QPixmap * Map::tile(int tileId, int tilesetId, int paletteId) const {
    return mMapData->tile(tileId, tilesetId, paletteId);
}

void Map::drawForeground(QPainter *painter, const QRectF &rect) {
    QGraphicsScene::drawForeground(painter, rect);

    // Draw the grid's lines if the user has elected to display them
    painter->setBrush(QBrush(Qt::black));
    painter->drawLines(mGridLines);

    // Draw the currently selected sector, if applicable
    if (mCurrentSector != nullptr) {
        painter->setPen(Qt::yellow);
        int x1 = mCurrentSector->x() * Tile::WIDTH;
        int x2 = x1 + Sector::WIDTH * Tile::WIDTH;
        int y1 = mCurrentSector->y() * Tile::HEIGHT;
        int y2 = y1 + Sector::HEIGHT * Tile::HEIGHT;
        painter->drawLine(QLine(x1, y1, x2, y1));  // Top
        painter->drawLine(QLine(x1, y2, x2, y2));  // Bottom
        painter->drawLine(QLine(x1, y1, x1, y2));  // Left
        painter->drawLine(QLine(x2, y1, x2, y2));  // Right
    }
}
