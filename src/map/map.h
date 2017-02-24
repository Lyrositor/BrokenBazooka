#ifndef MAP_H
#define MAP_H

#include <QtCore/QLine>
#include <QtCore/QVector>
#include <QtWidgets/QGraphicsScene>

#include "layer.h"
#include "map_data.h"
#include "sector.h"

class BrokenBazooka;

class Map : public QGraphicsScene {
public:
    Map(MapData *mapData, BrokenBazooka *parent);

    void setCurrentSector(Sector *sector);

    QPixmap * tile(int tileId, int tilesetId, int paletteId) const;

protected:
    void drawForeground(QPainter *painter, const QRectF &rect) override;

private:
    MapData * const mMapData;

    Layer * const mTilesLayer;
    Layer * const mSpritesLayer;
    Layer * const mEnemiesLayer;
    Layer * const mDoorsLayer;
    Layer * const mHotspotsLayer;

    QVector<QLine> mGridLines;

    Sector *mCurrentSector;
};

#endif // MAP_H
