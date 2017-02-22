#ifndef TILE_SELECTOR_H
#define TILE_SELECTOR_H

#include <QGraphicsView>

class TileSelector : public QGraphicsView {
    Q_OBJECT

public:
    TileSelector(QWidget *parent = 0) : QGraphicsView(parent) {}
};

#endif // TILE_SELECTOR_H
