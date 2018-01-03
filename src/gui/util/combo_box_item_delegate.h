#ifndef COMBO_BOX_ITEM_DELEGATE_H
#define COMBO_BOX_ITEM_DELEGATE_H

#include <QtWidgets/QStyledItemDelegate>

class ComboBoxItemDelegate : public QStyledItemDelegate {
    Q_OBJECT

public:
    explicit ComboBoxItemDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    QWidget *createEditor(
            QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index
    ) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    void setModelData(
            QWidget *editor, QAbstractItemModel *model, const QModelIndex &index
    ) const override;

protected slots:
    void updateData(int index);
};

#endif // COMBO_BOX_ITEM_DELEGATE_H
