#ifndef LAYER_H
#define LAYER_H

#include <QtWidgets/QGraphicsItem>

class Layer : public QGraphicsItem {
public:
    Layer(QGraphicsItem *parent = Q_NULLPTR) : QGraphicsItem(parent) { }

    QRectF boundingRect() const { return QRectF(0, 0, 0, 0); }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) { }
};

#endif // LAYER_H
