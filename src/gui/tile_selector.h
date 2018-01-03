#ifndef TILE_SELECTOR_H
#define TILE_SELECTOR_H

#include <QGraphicsView>

class TileSelector : public QGraphicsView {
    Q_OBJECT

public:
    explicit TileSelector(QWidget *parent = nullptr);
};

#endif // TILE_SELECTOR_H
