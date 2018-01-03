#include "combo_box_item_delegate.h"

#include <QtWidgets/QAbstractItemView>
#include <QtWidgets/QComboBox>

#include "constants.h"

// Remove IDE warnings related to qobject_cast
#pragma clang diagnostic push
#pragma ide diagnostic ignored "CannotResolve"

QWidget *ComboBoxItemDelegate::createEditor(
        QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index
) const {
    // Get the list of options from the model
    QVariant optionsData = index.data(Bb::OptionsListRole);
    if (!optionsData.isValid() || !optionsData.canConvert(QVariant::StringList)) {
        return QStyledItemDelegate::createEditor(parent, option, index);
    }

    // Populate the combo box with the options
    auto *cb = new QComboBox(parent);
    cb->addItems(optionsData.toStringList());
    cb->setProperty("index", index);  // Hack: store the index here for later retrieval
    QObject::connect(cb, SIGNAL(currentIndexChanged(int)), this, SLOT(updateData(int)));
    return cb;
}

void ComboBoxItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    if (auto *cb = qobject_cast<QComboBox *>(editor)) {
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
        QWidget *editor, QAbstractItemModel *model, const QModelIndex &index
) const {
    if (auto *cb = qobject_cast<QComboBox *>(editor))
        model->setData(index, cb->currentIndex(), Qt::EditRole);
    else
        QStyledItemDelegate::setModelData(editor, model, index);
}

void ComboBoxItemDelegate::updateData(int index) {
    // Hack: we don't have access to the model through a parameter, so we get it through the
    // parent's current model
    auto *view = qobject_cast<QAbstractItemView *>(parent());
    auto *cb = qobject_cast<QComboBox *>(sender());
    setModelData(cb, view->model(), cb->property("index").toModelIndex());
}

#pragma clang diagnostic pop
