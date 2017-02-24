#ifndef MAP_EDITOR_H
#define MAP_EDITOR_H

#include <QtWidgets/QGraphicsView>

class MapEditor : public QGraphicsView {
    Q_OBJECT

public:
    MapEditor(QWidget *parent = 0);
};

#endif // MAP_EDITOR_H
