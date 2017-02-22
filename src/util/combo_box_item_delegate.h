#ifndef COMBO_BOX_ITEM_DELEGATE_H
#define COMBO_BOX_ITEM_DELEGATE_H

#include <QStyledItemDelegate>

class ComboBoxItemDelegate : public QStyledItemDelegate {
    Q_OBJECT

public:
    ComboBoxItemDelegate(QObject *parent=0) : QStyledItemDelegate(parent) {}

    virtual QWidget *createEditor(
            QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index
    ) const;
    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const;
    virtual void setModelData(
            QWidget *editor, QAbstractItemModel *model, const QModelIndex &index
    ) const;
};

#endif // COMBO_BOX_ITEM_DELEGATE_H
