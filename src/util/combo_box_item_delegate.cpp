#include "combo_box_item_delegate.h"

#include <QComboBox>

#include "constants.h"

QWidget *ComboBoxItemDelegate::createEditor(
        QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index
) const {
    // Get the list of options from the model
    QVariant optionsData = index.data(Bb::OptionsListRole);
    if (!optionsData.isValid() || !optionsData.canConvert(QVariant::StringList)) {
        return QStyledItemDelegate::createEditor(parent, option, index);
    }
    optionsData.convert(QVariant::StringList);
    QStringList optionsList = optionsData.toStringList();

    // Populate the combo box with the options
    QComboBox *cb = new QComboBox(parent);
    int row = index.row();
    cb->addItems(optionsList);
    return cb;
}

void ComboBoxItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    if (QComboBox *cb = qobject_cast<QComboBox*>(editor)) {
        // Get the index of the text in the combobox that matches the current value of the item
        QString currentText = index.data(Qt::EditRole).toString();
        int cbIndex = cb->findText(currentText);
        // If it is valid, adjust the combobox
        if (cbIndex >= 0)
            cb->setCurrentIndex(cbIndex);
    } else {
        QStyledItemDelegate::setEditorData(editor, index);
    }
}

void ComboBoxItemDelegate::setModelData(
        QWidget* editor, QAbstractItemModel* model, const QModelIndex &index
) const {
    if (QComboBox* cb = qobject_cast<QComboBox*>(editor))
        model->setData(index, cb->currentText(), Qt::EditRole);
    else
        QStyledItemDelegate::setModelData(editor, model, index);
}
