#ifndef TILE_H
#define TILE_H

#include <QtWidgets/QGraphicsItem>

#include "sector.h"

class Tile : public QGraphicsItem {
public:
    static const int WIDTH = 4 * 8;
    static const int HEIGHT = 4 * 8;

    Tile(int tileId, Sector *sector, QGraphicsItem *parent = Q_NULLPTR);

protected:
    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    int mTileId;
    Sector * const mSector;
};

#endif // TILE_H
