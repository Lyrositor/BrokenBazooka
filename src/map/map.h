#ifndef MAP_H
#define MAP_H

#include <QtWidgets/QGraphicsScene>
#include <vector>

#include "layer.h"
#include "sector.h"

class BrokenBazooka;

class Map : public QGraphicsScene {
public:
    static const int NUM_TILES_X = 256;
    static const int NUM_TILES_Y = 320;
    static const int NUM_TILESETS = 20;
    static const int NUM_TILES_PER_TILESET = 1024;

    Map(BrokenBazooka *parent);

    void setCurrentSector(Sector *sector);

    QPixmap tile(int tilesetId, int tileId, int paletteId);

protected:
    void drawForeground(QPainter *painter, const QRectF &rect) override;

private:
    Layer *mTilesLayer;
    Layer *mSpritesLayer;
    Layer *mEnemiesLayer;
    Layer *mDoorsLayer;
    Layer *mHotspotsLayer;

    Sector *mSectors[NUM_TILES_X/Sector::WIDTH][NUM_TILES_Y/Sector::HEIGHT];
    std::vector<QPixmap> mTilesets[NUM_TILESETS][NUM_TILES_PER_TILESET];

    QVector<QLine> mGridLines;

    Sector *mCurrentSector;
};

#endif // MAP_H
