#ifndef SECTOR_H
#define SECTOR_H

#include <QtCore/QAbstractTableModel>

class Sector : public QAbstractTableModel {
    Q_OBJECT

public:
    static const int WIDTH = 8;
    static const int HEIGHT = 4;

    enum SectorSetting {
        NONE,
        INDOORS,
        EXIT_MOUSE_USABLE,
        LOST_UNDERWORLD_SPRITES,
        MAGICANT_SPRITES,
        ROBOT_SPRITES,
        BUTTERFLIES,
        INDOORS_AND_BUTTERFLIES
    };

    Sector(
            int x, int y, int palette = 0, int tileset = 0, int item = 0, int music = 0,
            SectorSetting setting = NONE, bool teleport = false, int townMapX = 0, int townMapY = 0
    );

    int x() { return mX; }

    int y() { return mY; }

    int palette() { return mPalette; }

    int tileset() { return mTileset; }

    int columnCount(const QModelIndex &parent) const override;

    int rowCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    static const char *PROPERTY_NAMES[];

    const int mX;
    const int mY;

    int mPalette;
    int mTileset;

    int mItem;
    int mMusic;
    SectorSetting mSetting;
    bool mTeleport;

    //TownMap mTownMap;
    //TownMapArrow mTownMapArrow;
    int mTownMapX;
    int mTownMapY;
};

#endif // SECTOR_H
