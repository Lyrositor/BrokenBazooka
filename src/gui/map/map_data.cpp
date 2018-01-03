#include "map_data.h"

#include "tile.h"

MapData::MapData() {
    // Set up the tilesets
    // TODO Remove this once tiles can be correctly loaded
    for (int tilesetId = 0; tilesetId < NUM_TILESETS; tilesetId++) {
        for (int tileId = 0; tileId < NUM_TILES_PER_TILESET; tileId++) {
            for (int paletteId = 0; paletteId < 5; paletteId++) {
                QPixmap *pixmap = new QPixmap(Tile::WIDTH, Tile::HEIGHT);
                pixmap->fill(QColor(rand() % 255, rand() % 255, rand() % 255));
                mTiles[tilesetId][tileId].push_back(pixmap);
            }
        }
    }

    // Create the sectors
    for (int x = 0; x < MAP_TILES_X; x += Sector::WIDTH)
        for (int y = 0; y < MAP_TILES_Y; y += Sector::HEIGHT)
            mSectors[x/Sector::WIDTH][y/Sector::HEIGHT] = new Sector(x, y);
}

MapData::~MapData() {
    // Delete the tiles
    for (int tilesetId = 0; tilesetId < NUM_TILESETS; tilesetId++)
        for (int tileId = 0; tileId < NUM_TILES_PER_TILESET; tileId++)
            for (int paletteId = 0; paletteId < mTiles[tilesetId][tileId].size(); paletteId++)
                delete mTiles[tilesetId][tileId][paletteId];

    // Delete the sectors
    for (int x = 0; x < MAP_TILES_X; x += Sector::WIDTH)
        for (int y = 0; y < MAP_TILES_Y; y += Sector::HEIGHT)
            delete mSectors[x/Sector::WIDTH][y/Sector::HEIGHT];
}

Sector *MapData::sector(int x, int y) const {
    return mSectors[x][y];
}

QPixmap *MapData::tile(int tileId, int tilesetId, int paletteId) const {
    return mTiles[tilesetId][tileId][paletteId];
}
