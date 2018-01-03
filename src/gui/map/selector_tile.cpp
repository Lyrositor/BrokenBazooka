#include "selector_tile.h"

#include "gui/broken_bazooka.h"

SelectorTile::SelectorTile(int id, QGraphicsItem *parent) :
        Tile(id, parent) {
}

QPixmap * SelectorTile::tile() const {
    Selector *selector = static_cast<Selector *>(scene());
    return selector->tile(id());
}

void SelectorTile::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    BrokenBazooka *brokenBazooka = static_cast<BrokenBazooka *>(scene()->parent());
    brokenBazooka->setCurrentMapSelectorTile(
            brokenBazooka->currentMapSelectorTile() != this ? this : nullptr
    );
}
