#include "sector.h"

#include <QtCore/QSize>

#include "map.h"
#include "util/constants.h"

const char *Sector::PROPERTY_NAMES[] = {
        /* 0 */ "Palette",
        /* 1 */ "Tileset",
        /* 2 */ "Item",
        /* 3 */ "Music",
        /* 4 */ "Setting",
        /* 5 */ "Teleport",
        /* 6 */ "Town Map",
        /* 7 */ "Town Map Arrow",
        /* 8 */ "Town Map X",
        /* 9 */ "Town Map Y"

};

Sector::Sector(int x, int y, int palette, int tileset, int item, int music,
        Sector::SectorSetting setting, bool teleport, int townMapX, int townMapY
) : QAbstractTableModel(), mX(x), mY(y), mPalette(palette), mTileset(tileset), mItem(item),
        mMusic(music), mSetting(setting), mTeleport(teleport), mTownMapX(townMapX),
        mTownMapY(townMapY) {
}

int Sector::columnCount(const QModelIndex &parent) const {
    return 2;
}

int Sector::rowCount(const QModelIndex &parent) const {
    return 10;
}

QVariant Sector::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    // The first column consists of the property labels
    if (index.column() == 0) {
        if (role == Qt::DisplayRole) {
            return QString(PROPERTY_NAMES[index.row()]);
        } else if (role == Qt::SizeHintRole) {
            return QSize(190, 0);
        } else if (role == Qt::FontRole) {
            QFont font;
            font.setBold(true);
            return font;
        }
        return QVariant();
    }

    // Any other column must be the second column, containing the values
    if (role == Qt::DisplayRole) {
        switch (index.row()) {
        case 0:
            return QString::number(mPalette);
        case 1:
            return QString::number(mTileset);
        case 2:
            return QString::number(mItem);
        case 3:
            return QString::number(mMusic);
        case 4:
            return QString::number(mSetting);
        case 5:
            return QString::number(mTeleport);
        case 6:
            return QString("");
        case 7:
            return QString("");
        case 8:
            return QString::number(mTownMapX);
        case 9:
            return QString::number(mTownMapY);
        default:
            return QVariant();
        }
    } else if (role == Qt::EditRole) {
        return data(index, Qt::DisplayRole);
    } else if (role == Bb::OptionsListRole) {
        QStringList optionsList;
        switch (index.row()) {
        case 0: {
            int numPalettes = 10;  // TODO Get the real value
            for (int i = 0; i < numPalettes; i++)
                optionsList.append(QString::number(i));
            return optionsList;
        }
        case 1: {
            for (int i = 0; i < MapData::NUM_TILESETS; i++)
                optionsList.append(QString::number(i));  // TODO Show the tileset names
            return optionsList;
        }
        case 4:
            break;
        default:
            return QVariant();
        }
    }

    return QVariant();
}

bool Sector::setData(const QModelIndex &index, const QVariant &value, int role) {
    return QAbstractTableModel::setData(index, value, role);
}

Qt::ItemFlags Sector::flags(const QModelIndex &index) const {
    Qt::ItemFlags flags = Qt::ItemIsEnabled;

    if (index.column() == 1) {
        flags |= Qt::ItemIsEditable;
        switch (index.row()) {
        case 5:
            flags |= Qt::ItemIsUserCheckable;
            break;
        default:
            break;
        }
    }

    return flags;
}
