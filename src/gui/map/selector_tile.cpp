#include "selector_tile.h"

#include "gui/broken_bazooka.h"

SelectorTile::SelectorTile(int id, QGraphicsItem *parent) :
        Tile(id, parent) {
}

QPixmap * SelectorTile::tile() const {
    auto *selector = dynamic_cast<Selector *>(scene());
    return selector->tile(id());
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
void SelectorTile::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    auto *brokenBazooka = dynamic_cast<BrokenBazooka *>(scene()->parent());
    brokenBazooka->setCurrentMapSelectorTile(
            brokenBazooka->currentMapSelectorTile() != this ? this : nullptr
    );
}
#pragma clang diagnostic pop
