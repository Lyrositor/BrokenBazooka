#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtWidgets/QMainWindow>

#include "map/map.h"
#include "map/selector.h"

namespace Ui {
    class BrokenBazooka;
}

class BrokenBazooka : public QMainWindow {
    Q_OBJECT

public:
    explicit BrokenBazooka(QWidget *parent = 0);

    ~BrokenBazooka();

    SelectorTile * currentMapSelectorTile() const;

    void setCurrentMapSelectorTile(SelectorTile *tile);

    Sector * currentMapSector() const;

public slots:
    // Map Editor Slots
    void setCurrentMapSector(Sector *sector);

    void updateSector(const QModelIndex &topLeft, const QModelIndex & bottomRight);

    // General Slots
    void undo();
    void redo();

private:
    static const char *WINDOW_TITLE;

    SelectorTile *mCurrentMapSelectorTile;

    Map *mMap;
    MapData * const mMapData;
    Selector *mSelector;
    Ui::BrokenBazooka *mUi;
};

#endif // MAIN_WINDOW_H
