#include "figure.h"

RectangleShape::RectangleShape(const QRect &otherRect) : rect(otherRect) {}

void RectangleShape::draw(QPainter &painter) const {
    painter.drawRect(rect);
}

bool RectangleShape::contains(const QPoint &point) const {
    return rect.contains(point);
}

void RectangleShape::move(const QPoint &offset) {
    rect.translate(offset);
}

QRect RectangleShape::boundingRect() const {
    return rect;
}

void RectangleShape::setRect(const QRect &newRect){
    rect = newRect;
}

// EllipseShape
EllipseShape::EllipseShape(const QRect &otherRect) : rect(otherRect) {}

void EllipseShape::draw(QPainter &painter) const {
    painter.drawEllipse(rect);
}

bool EllipseShape::contains(const QPoint &point) const {
    return rect.contains(point);
}

void EllipseShape::move(const QPoint &offset) {
    rect.translate(offset);
}

QRect EllipseShape::boundingRect() const {
    return rect;
}

void EllipseShape::setRect(const QRect &newRect){
    rect = newRect;
}

// TriangleShape
TriangleShape::TriangleShape(const QRect &otherRect) : rect(otherRect) {}

void TriangleShape::draw(QPainter &painter) const {
    QPolygon triangle;
    triangle << QPoint(rect.left() + rect.width() / 2, rect.top())
             << QPoint(rect.bottomLeft())
             << QPoint(rect.bottomRight());
    painter.drawPolygon(triangle);
}

bool TriangleShape::contains(const QPoint &point) const {
    return rect.contains(point);
}

void TriangleShape::move(const QPoint &offset) {
    rect.translate(offset);
}

QRect TriangleShape::boundingRect() const {
    return rect;
}

void TriangleShape::setRect(const QRect &newRect){
    rect = newRect;
}
