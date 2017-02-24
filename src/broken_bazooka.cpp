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

void BrokenBazooka::undo() {

}

void BrokenBazooka::redo() {

}

void BrokenBazooka::setCurrentMapSector(Sector *sector) {
    mUi->properties->setModel(sector);
    mUi->properties->setColumnWidth(0, mUi->properties->width()/2);
    mMap->setCurrentSector(sector);
}
