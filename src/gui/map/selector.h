#ifndef SELECTOR_H
#define SELECTOR_H

#include <QtCore/QLine>
#include <QtCore/QVector>
#include <QtWidgets/QGraphicsScene>

#include "map_data.h"
#include "selector_tile.h"

class Selector : public QGraphicsScene {
public:
    static const int NUM_TILES_X = MapData::NUM_TILES_PER_TILESET / 4;
    static const int NUM_TILES_Y = 4;

    Selector(MapData *mapData, QObject *parent);

    QPixmap * tile(int tileId) const;

protected:
    void drawForeground(QPainter *painter, const QRectF &rect) override;

private:
    MapData *mMapData;

    QVector<QLine> mGridLines;
};

#endif // SELECTOR_H
