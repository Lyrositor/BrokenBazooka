#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtWidgets/QMainWindow>

#include "map/map.h"

namespace Ui {
    class BrokenBazooka;
}

class BrokenBazooka : public QMainWindow {
    Q_OBJECT

public:
    explicit BrokenBazooka(QWidget *parent = 0);

    ~BrokenBazooka();

    int currentTileId();

public slots:
    // General Slots
    void undo();
    void redo();

    // Map Editor Slots
    void setCurrentMapSector(Sector *sector);

private:
    static const char *WINDOW_TITLE;

    Map *mCurrentMap;
    int mCurrentTileId;
    Ui::BrokenBazooka *mUi;
};

#endif // MAIN_WINDOW_H
