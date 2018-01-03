#ifndef TILE_H
#define TILE_H

#include <QtWidgets/QGraphicsItem>
#include <QtGui/QPainter>

class Tile : public QGraphicsItem {
public:
    static const int WIDTH = 4 * 8;
    static const int HEIGHT = 4 * 8;

    explicit Tile(int id, QGraphicsItem *parent = Q_NULLPTR) : QGraphicsItem(parent), mId(id) {}

    int id() const { return mId; }

    void setId(int id) { mId = id; }

    QRectF boundingRect() const override {
        return {0, 0, static_cast<qreal>(WIDTH), static_cast<qreal>(HEIGHT)};
    }

    void paint(
            QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget
    ) override { painter->drawPixmap(0, 0, *tile()); }

protected:
    virtual QPixmap * tile() const = 0;

private:
    int mId;
};

#endif // TILE_H
