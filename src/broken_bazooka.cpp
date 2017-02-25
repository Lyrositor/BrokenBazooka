#include "broken_bazooka.h"
#include "ui_broken_bazooka.h"

#include "util/combo_box_item_delegate.h"

const char *BrokenBazooka::WINDOW_TITLE = "Broken Bazooka";

BrokenBazooka::BrokenBazooka(QWidget *parent) :
        QMainWindow(parent), mCurrentMapSelectorTile(nullptr), mUi(new Ui::BrokenBazooka),
        mMapData(new MapData) {
    // Load the UI for this window
    mUi->setupUi(this);
    setWindowTitle(WINDOW_TITLE);

    // Set up an empty map
    mMap = new Map(mMapData, this);
    mUi->mapEditor->setScene(mMap);
    mUi->mapEditor->centerOn(0, 0);

    // Set up an empty tile selector
    mSelector = new Selector(mMapData, this);
    mUi->tileSelector->setScene(mSelector);
    mUi->tileSelector->setFixedHeight(
            static_cast<int>(mSelector->height()) +
                    qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent) + 2
    );
    mUi->tileSelector->centerOn(0, 0);

    // Set up the delegates for the properties viewer
    ComboBoxItemDelegate* cbid = new ComboBoxItemDelegate(mUi->properties);
    mUi->properties->setItemDelegate(cbid);
    mUi->properties->horizontalHeader()->setStretchLastSection(true);

    // Connect the relevant signals to their slots
    for (int x = 0; x < MapData::MAP_TILES_X; x += Sector::WIDTH)
        for (int y = 0; y < MapData::MAP_TILES_Y; y += Sector::HEIGHT)
            QObject::connect(
                    mMapData->sector(x/Sector::WIDTH, y/Sector::HEIGHT),
                    SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this,
                    SLOT(updateSector(const QModelIndex &, const QModelIndex &))
            );
    QObject::connect(mUi->actionUndo, SIGNAL(triggered()), this, SLOT(undo()));
    QObject::connect(mUi->actionRedo, SIGNAL(triggered()), this, SLOT(redo()));
}

BrokenBazooka::~BrokenBazooka() {
    delete mMap;
    delete mMapData;
    delete mUi;
}

SelectorTile * BrokenBazooka::currentMapSelectorTile() const {
    return mCurrentMapSelectorTile;
}

void BrokenBazooka::setCurrentMapSelectorTile(SelectorTile *tile) {
    mCurrentMapSelectorTile = tile;
    mSelector->update();
}

Sector * BrokenBazooka::currentMapSector() const {
    return mMap->currentSector();
}

void BrokenBazooka::updateSector(const QModelIndex &topLeft, const QModelIndex &bottomRight) {
    mMap->update();
    mSelector->update();
}

void BrokenBazooka::setCurrentMapSector(Sector *sector) {
    mUi->properties->setModel(sector);
    mUi->properties->setColumnWidth(0, mUi->properties->width()/2);
    mMap->setCurrentSector(sector);
}

void BrokenBazooka::undo() {

}

void BrokenBazooka::redo() {

}
