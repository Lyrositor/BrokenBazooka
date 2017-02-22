#ifndef MAP_EDITOR_H
#define MAP_EDITOR_H

#include <QtWidgets/QGraphicsView>
#include "map/map.h"

class MapEditor : public QGraphicsView {
    Q_OBJECT

public:
    MapEditor(QWidget *parent = 0) : QGraphicsView(parent) {}
};

#endif // MAP_EDITOR_H
