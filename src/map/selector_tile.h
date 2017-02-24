#ifndef SELECTOR_TILE_H
#define SELECTOR_TILE_H

#include <QtGui/QPainter>

#include "tile.h"

class SelectorTile : public Tile {
public:
    SelectorTile(int id, QGraphicsItem *parent = Q_NULLPTR);

protected:
    QPixmap * tile() const;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SELECTOR_TILE_H
