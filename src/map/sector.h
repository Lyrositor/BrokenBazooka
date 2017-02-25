#ifndef SECTOR_H
#define SECTOR_H

#include <QtCore/QAbstractTableModel>

class Sector : public QAbstractTableModel {
    Q_OBJECT

public:
    static const int WIDTH = 8;
    static const int HEIGHT = 4;

    Sector(
            int x, int y, int palette = 0, int tileset = 0, int item = 0, int music = 0,
            int setting = 0, bool teleport = false, int townMap = 0, int townMapArrow = 0,
            int townMapImage = 0, int townMapX = 0, int townMapY = 0
    );

    int x() { return mX; }

    int y() { return mY; }

    int palette() { return mPalette; }

    int tileset() { return mTileset; }

    int columnCount(const QModelIndex &parent) const override { return 2; }

    int rowCount(const QModelIndex &parent) const override { return 11; }

    QVariant data(const QModelIndex &index, int role) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    enum struct Properties {
        Palette,
        Tileset,
        Item,
        Music,
        Setting,
        Teleport,
        TownMap,
        TownMapArrow,
        TownMapImage,
        TownMapX,
        TownMapY,
    };

    static const QStringList PROPERTY_NAMES;
    static const QStringList SECTOR_SETTING_LABELS;
    static const QStringList TOWN_MAP_LABELS;
    static const QStringList TOWN_MAP_ARROW_LABELS;

    const int mX;
    const int mY;

    int mPalette;
    int mTileset;

    int mItem;
    int mMusic;
    int mSetting;
    bool mTeleport;

    int mTownMap;
    int mTownMapArrow;
    int mTownMapImage;
    int mTownMapX;
    int mTownMapY;
};

#endif // SECTOR_H
