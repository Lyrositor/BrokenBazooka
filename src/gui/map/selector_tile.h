#ifndef SELECTOR_TILE_H
#define SELECTOR_TILE_H

#include <QtGui/QPainter>

#include "tile.h"

class SelectorTile : public Tile {
public:
    explicit SelectorTile(int id, QGraphicsItem *parent = Q_NULLPTR);

protected:
    QPixmap * tile() const override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SELECTOR_TILE_H
