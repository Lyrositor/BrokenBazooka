#include "selector.h"

#include "gui/broken_bazooka.h"

Selector::Selector(MapData *mapData, QObject *parent) : QGraphicsScene(parent), mMapData(mapData) {
    setBackgroundBrush(Qt::black);

    // Make the scene slightly bigger so that grid lines can be drawn on the edges
    setSceneRect(0, 0, NUM_TILES_X * Tile::WIDTH + 1, NUM_TILES_Y * Tile::HEIGHT + 1);

    // Create the tiles
    for (int x = 0, s = 0; x < NUM_TILES_X; x++) {
        for (int y = 0; y < NUM_TILES_Y; y++, s++) {
            auto *tile = new SelectorTile(s);
            addItem(tile);
            tile->setPos(x * Tile::WIDTH, y * Tile::WIDTH);
        }
    }

    // Create the grid lines
    for (int x = 0; x <= NUM_TILES_X; x++)
        mGridLines.append(
                QLine(x * Tile::WIDTH, 0, x * Tile::WIDTH, NUM_TILES_Y * Tile::HEIGHT)
        );
    for (int y = 0; y <= NUM_TILES_Y; y++)
        mGridLines.append(
                QLine(0, y * Tile::HEIGHT, NUM_TILES_X * Tile::WIDTH, y * Tile::HEIGHT)
        );
}

QPixmap * Selector::tile(int tileId) const {
    Sector *currentSector = dynamic_cast<BrokenBazooka *>(parent())->currentMapSector();
    if (currentSector == nullptr)
        return mMapData->tile(tileId, 0, 0);
    return mMapData->tile(tileId, currentSector->tileset(), currentSector->palette());
}

void Selector::drawForeground(QPainter *painter, const QRectF &rect) {
    QGraphicsScene::drawForeground(painter, rect);

    // Draw the grid's lines if the user has elected to display them
    painter->setBrush(QBrush(Qt::black));
    painter->drawLines(mGridLines);

    // Draw the currently selected tile, if applicable
    SelectorTile *currentTile = dynamic_cast<BrokenBazooka *>(parent())->currentMapSelectorTile();
    if (currentTile != nullptr) {
        painter->setPen(Qt::yellow);
        int x1 = (currentTile->id() / NUM_TILES_Y) * Tile::WIDTH;
        int x2 = x1 + Tile::WIDTH;
        int y1 = (currentTile->id() % NUM_TILES_Y) * Tile::HEIGHT;
        int y2 = y1 + Tile::HEIGHT;
        painter->drawLine(QLine(x1, y1, x2, y1));  // Top
        painter->drawLine(QLine(x1, y2, x2, y2));  // Bottom
        painter->drawLine(QLine(x1, y1, x1, y2));  // Left
        painter->drawLine(QLine(x2, y1, x2, y2));  // Right
    }
}
