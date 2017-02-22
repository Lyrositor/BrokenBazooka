#include "broken_bazooka.h"
#include "ui_broken_bazooka.h"

#include "util/combo_box_item_delegate.h"

const char *BrokenBazooka::WINDOW_TITLE = "Broken Bazooka";

BrokenBazooka::BrokenBazooka(QWidget *parent) :
        QMainWindow(parent), mUi(new Ui::BrokenBazooka), mCurrentTileId(0) {
    // Load the UI for this window
    mUi->setupUi(this);
    setWindowTitle(WINDOW_TITLE);

    // Set up the various UI elements
    mCurrentMap = new Map(this);
    mUi->mapEditor->setScene(mCurrentMap);
    ComboBoxItemDelegate* cbid = new ComboBoxItemDelegate(mUi->properties);
    mUi->properties->setItemDelegate(cbid);
    mUi->properties->horizontalHeader()->setStretchLastSection(true);

    // Connect the relevant signals to their slots
    QObject::connect(mUi->actionUndo, SIGNAL(triggered()), this, SLOT(undo()));
    QObject::connect(mUi->actionRedo, SIGNAL(triggered()), this, SLOT(redo()));
}

BrokenBazooka::~BrokenBazooka() {
    delete mCurrentMap;
    delete mUi;
}

int BrokenBazooka::currentTileId() {
    return mCurrentTileId;
}

void BrokenBazooka::undo() {

}

void BrokenBazooka::redo() {

}

void BrokenBazooka::setCurrentMapSector(Sector *sector) {
    mUi->properties->setModel(sector);
    mUi->properties->setColumnWidth(0, mUi->properties->width()/2);
    mCurrentMap->setCurrentSector(sector);
}
