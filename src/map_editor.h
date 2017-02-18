#ifndef MAP_EDITOR_H
#define MAP_EDITOR_H

#include <QGraphicsView>

class MapEditor : public QGraphicsView
{
    Q_OBJECT

public:
    MapEditor(QWidget *parent = 0);
    ~MapEditor();
};

#endif // MAP_EDITOR_H
