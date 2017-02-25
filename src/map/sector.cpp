#include "sector.h"

#include <QtCore/QSize>

#include "map.h"
#include "util/constants.h"

const QStringList Sector::PROPERTY_NAMES = {
        /* 0  */ "Palette",
        /* 1  */ "Tileset",
        /* 2  */ "Item",
        /* 3  */ "Music",
        /* 4  */ "Setting",
        /* 5  */ "Teleport",
        /* 6  */ "Town Map",
        /* 7  */ "Town Map Arrow",
        /* 8  */ "Town Map Image",
        /* 9  */ "Town Map X",
        /* 10 */ "Town Map Y"
};

const QStringList Sector::SECTOR_SETTING_LABELS = {
        /* 0 */ "None",
        /* 1 */ "Indoors",
        /* 2 */ "Exit mouse usable",
        /* 3 */ "Lost underworld sprites",
        /* 4 */ "Magicant sprites",
        /* 5 */ "Robot sprites",
        /* 6 */ "Butterflies",
        /* 7 */ "Indoors and butterflies"
};

const QStringList Sector::TOWN_MAP_LABELS = {
        /* 0 */ "None",
        /* 1 */ "Onett",
        /* 2 */ "Twoson",
        /* 3 */ "Threed",
        /* 4 */ "Fourside",
        /* 5 */ "Scaraba",
        /* 6 */ "Summers",
        /* 7 */ "None 2"
};

const QStringList Sector::TOWN_MAP_ARROW_LABELS = {
        /* 0 */ "None",
        /* 1 */ "Up",
        /* 2 */ "Down",
        /* 3 */ "Right",
        /* 4 */ "Left"
};

Sector::Sector(
        int x, int y, int palette, int tileset, int item, int music, int setting, bool teleport,
        int townMap, int townMapArrow, int townMapImage, int townMapX, int townMapY
) : QAbstractTableModel(), mX(x), mY(y), mPalette(palette), mTileset(tileset), mItem(item),
        mMusic(music), mSetting(setting), mTeleport(teleport), mTownMap(townMap),
        mTownMapArrow(townMapArrow), mTownMapImage(townMapImage), mTownMapX(townMapX),
        mTownMapY(townMapY) {
}

QVariant Sector::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    // The first column consists of the property labels
    if (index.column() == 0) {
        if (role == Qt::DisplayRole) {
            return QString(PROPERTY_NAMES[index.row()]);
        } else if (role == Qt::FontRole) {
            QFont font;
            font.setBold(true);
            return font;
        }
        return QVariant();
    }

    // Any other column must be the second column, containing the values
    if (role == Qt::DisplayRole) {
        switch (static_cast<Properties>(index.row())) {
        case Properties::Palette:
            return mPalette;
        case Properties::Tileset:
            return mTileset;
        case Properties::Item:
            return data(index, Bb::OptionsListRole).toStringList()[mItem];  // TODO Return the item's name instead
        case Properties::Music:
            return mMusic;
        case Properties::Setting:
            return SECTOR_SETTING_LABELS[mSetting];
        case Properties::TownMap:
            return TOWN_MAP_LABELS[mTownMap];
        case Properties::TownMapArrow:
            return TOWN_MAP_ARROW_LABELS[mTownMapArrow];
        case Properties::TownMapImage:
            return TOWN_MAP_LABELS[mTownMapImage];
        case Properties::TownMapX:
            return mTownMapX;
        case Properties::TownMapY:
            return mTownMapY;
        default:
            return QVariant();
        }
    } else if (role == Qt::EditRole) {
        return data(index, Qt::DisplayRole);
    } else if (role == Qt::CheckStateRole) {
        switch (static_cast<Properties>(index.row())) {
        case Properties::Teleport:
            return mTeleport ? Qt::Checked : Qt::Unchecked;
        default:
            return QVariant();
        }
    } else if (role == Bb::OptionsListRole) {
        QStringList optionsList;
        switch (static_cast<Properties>(index.row())) {
        case Properties::Palette: {
            int numPalettes = 10;  // TODO Get the real value
            for (int i = 0; i < numPalettes; i++)
                optionsList.append(QString::number(i));
            return optionsList;
        }
        case Properties::Tileset: {
            for (int i = 0; i < MapData::NUM_TILESETS; i++)
                optionsList.append(QString::number(i));  // TODO Show the tileset names
            return optionsList;
        }
        case Properties::Item: {
            QVector<QString> items = {
                    "Exit Mouse", "Burger", "Broken Bazooka"
            }; // TODO Get the actual item names
            for (QString item : items)
                optionsList.append(item);
            return optionsList;
        }
        case Properties::Music: {
            int numMusicEntries = 165; // TODO Get the real value
            for (int i = 0; i < numMusicEntries; i++)
                optionsList.append(QString::number(i));
            return optionsList;
        }
        case Properties::Setting:
            return SECTOR_SETTING_LABELS;
        case Properties::TownMap:
            return TOWN_MAP_LABELS;
        case Properties::TownMapArrow:
            return TOWN_MAP_ARROW_LABELS;
        case Properties::TownMapImage:
            optionsList = QStringList(TOWN_MAP_LABELS);
            optionsList.removeLast();  // Remove the "None 2" label for images
            return optionsList;
        default:
            return QVariant();
        }
    }

    return QVariant();
}

bool Sector::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (!index.isValid())
        return false;

    if (role == Qt::EditRole) {
        bool ok = false;
        int v = value.toInt(&ok);
        if (v < 0)
            ok = false;
        if (ok) {
            switch (static_cast<Properties>(index.row())) {
            case Properties::Palette:
                mPalette = v;
                break;
            case Properties::Tileset:
                mTileset = v;
                break;
            case Properties::Item:
                mItem = v;
                break;
            case Properties::Music:
                mMusic = v;
                break;
            case Properties::Setting:
                mSetting = v;
                break;
            case Properties::TownMap:
                mTownMap = v;
                break;
            case Properties::TownMapArrow:
                mTownMapArrow = v;
                break;
            case Properties::TownMapImage:
                mTownMapImage = v;
                break;
            case Properties::TownMapX:
                mTownMapX = v;
                break;
            case Properties::TownMapY:
                mTownMapY = v;
                break;
            default:
                return false;
            }
            emit dataChanged(index, index);
        }
        return ok;
    } else if (role == Qt::CheckStateRole) {
        switch (static_cast<Properties>(index.row())) {
        case Properties::Teleport:
            mTeleport = value == Qt::Checked;
            break;
        default:
            return false;
        }
        emit dataChanged(index, index);
        return true;
    }

    return false;
}

Qt::ItemFlags Sector::flags(const QModelIndex &index) const {
    Qt::ItemFlags flags = Qt::ItemIsEnabled;

    if (index.column() == 1) {
        switch (static_cast<Properties>(index.row())) {
        case Properties::Teleport:
            flags |= Qt::ItemIsUserCheckable;
            break;
        default:
            flags |= Qt::ItemIsEditable;
            break;
        }
    }

    return flags;
}
