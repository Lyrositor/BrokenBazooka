#ifndef MAP_EDITOR_H
#define MAP_EDITOR_H

#include <QtWidgets/QGraphicsView>

class MapEditor : public QGraphicsView {
    Q_OBJECT

public:
    explicit MapEditor(QWidget *parent = nullptr);
};

#endif // MAP_EDITOR_H
