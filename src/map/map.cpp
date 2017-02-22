#include "map.h"

#include <QtGui/QPainter>

#include "../broken_bazooka.h"
#include "tile.h"

Map::Map(BrokenBazooka *parent) : QGraphicsScene(parent), mCurrentSector(nullptr) {
    setBackgroundBrush(Qt::black);

    // Make the scene slightly bigger so that grid lines can be drawn on the edges
    setSceneRect(0, 0, NUM_TILES_X * Tile::WIDTH + 1, NUM_TILES_Y * Tile::HEIGHT + 1);

    // Set up the layers
    mTilesLayer = new Layer();
    mSpritesLayer = new Layer();
    mEnemiesLayer = new Layer();
    mDoorsLayer = new Layer();
    mHotspotsLayer = new Layer();
    addItem(mTilesLayer);
    addItem(mSpritesLayer);
    addItem(mEnemiesLayer);
    addItem(mDoorsLayer);
    addItem(mHotspotsLayer);

    // Set up the tilesets
    for (int tilesetId = 0; tilesetId < NUM_TILESETS; tilesetId++) {
        for (int tileId = 0; tileId < NUM_TILES_PER_TILESET; tileId++) {
            QPixmap pixmap = QPixmap(Tile::WIDTH, Tile::HEIGHT);
            pixmap.fill(Qt::green);
            mTilesets[tilesetId][tileId].push_back(pixmap);
        }
    }

    // Create the sectors
    for (int x = 0, s = 0; x < NUM_TILES_X; x += Sector::WIDTH)
        for (int y = 0; y < NUM_TILES_Y; y += Sector::HEIGHT)
            mSectors[x/Sector::WIDTH][y/Sector::HEIGHT] = new Sector(x, y);

    // Create the background tiles and associated sectors
    int s = 0;
    for (int x = 0; x < NUM_TILES_X; x++) {
        for (int y = 0; y < NUM_TILES_Y; y++) {
            Tile *tile = new Tile(0, mSectors[x/Sector::WIDTH][y/Sector::HEIGHT], mTilesLayer);
            tile->setPos(x * Tile::WIDTH, y * Tile::WIDTH);
        }
    }

    // Create the grid lines
    for (int x = 0; x <= NUM_TILES_X; x++)
        mGridLines.append(QLine(x * Tile::WIDTH, 0, x * Tile::WIDTH, NUM_TILES_Y * Tile::HEIGHT));
    for (int y = 0; y <= NUM_TILES_Y; y++)
        mGridLines.append(QLine(0, y * Tile::HEIGHT, NUM_TILES_X * Tile::WIDTH, y * Tile::HEIGHT));
}

void Map::setCurrentSector(Sector *sector) {
    mCurrentSector = sector;
    update();
}

QPixmap Map::tile(int tilesetId, int tileId, int paletteId) {
    return mTilesets[tilesetId][tileId][paletteId];
}

void Map::drawForeground(QPainter *painter, const QRectF &rect) {
    QGraphicsScene::drawForeground(painter, rect);

    // Draw the grid's lines if the user has elected to display them
    painter->setBrush(QBrush(Qt::black));
    painter->drawLines(mGridLines);

    // Draw the currently selected store, if applicable
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

