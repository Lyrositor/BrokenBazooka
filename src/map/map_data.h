#ifndef MAP_DATA_H
#define MAP_DATA_H

#include <QPixmap>
#include <QVector>

#include "sector.h"

class MapData {
public:
    static const int MAP_TILES_X = 256;
    static const int MAP_TILES_Y = 320;
    static const int NUM_TILESETS = 20;
    static const int NUM_TILES_PER_TILESET = 1024;

    MapData();

    virtual ~MapData();

    Sector *sector(int x, int y) const;

    QPixmap *tile(int tileId, int tilesetId, int paletteId) const;

private:
    Sector *mSectors[MAP_TILES_X/Sector::WIDTH][MAP_TILES_Y/Sector::HEIGHT];
    QVector<QPixmap *> mTiles[NUM_TILESETS][NUM_TILES_PER_TILESET];
};

#endif // MAP_DATA_H
