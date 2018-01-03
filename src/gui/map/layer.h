#ifndef LAYER_H
#define LAYER_H

#include <QtWidgets/QGraphicsItem>

class Layer : public QGraphicsItem {
public:
    explicit Layer(QGraphicsItem *parent = Q_NULLPTR) : QGraphicsItem(parent) { }

    QRectF boundingRect() const override { return {0, 0, 0, 0}; }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override { }
};

#endif // LAYER_H
