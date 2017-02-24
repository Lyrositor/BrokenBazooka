#include "tile_selector.h"

#include <QScrollBar>

#include "map/tile.h"

TileSelector::TileSelector(QWidget *parent) : QGraphicsView(parent) {
    setAlignment(Qt::AlignTop | Qt::AlignLeft);
    horizontalScrollBar()->setSingleStep(Tile::WIDTH);
}
