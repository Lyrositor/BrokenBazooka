#include "map_editor.h"

#include <QScrollBar>

#include "map/tile.h"

MapEditor::MapEditor(QWidget *parent) : QGraphicsView(parent) {
    setAlignment(Qt::AlignTop | Qt::AlignLeft);
    horizontalScrollBar()->setSingleStep(Tile::WIDTH);
    verticalScrollBar()->setSingleStep(Tile::HEIGHT);
}
