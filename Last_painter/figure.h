#ifndef FIGURE_H
#define FIGURE_H

#include <QPainter>
#include <QPoint>
#include <QRect>

class Figure {
public:
    virtual ~Figure() {}
    virtual void draw(QPainter &painter) const = 0;
    virtual bool contains(const QPoint &point) const = 0;
    virtual void move(const QPoint &offset) = 0;
    virtual QRect boundingRect() const = 0;
    virtual void setRect(const QRect &newRect) = 0;
};

class RectangleShape : public Figure {
private:
    QRect rect;
public:
    RectangleShape(const QRect &otherRect);
    void draw(QPainter &painter) const override;
    bool contains(const QPoint &point) const override;
    void move(const QPoint &offset) override;
    QRect boundingRect() const override;
    void setRect(const QRect &newRect) override;
};

class EllipseShape : public Figure {
private:
    QRect rect;
public:
    EllipseShape(const QRect &otherRect);
    void draw(QPainter &painter) const override;
    bool contains(const QPoint &point) const override;
    void move(const QPoint &offset) override;
    QRect boundingRect() const override;
    void setRect(const QRect &newRect) override;
};

class TriangleShape : public Figure {
private:
    QRect rect;
public:
    TriangleShape(const QRect &otherRect);
    void draw(QPainter &painter) const override;
    bool contains(const QPoint &point) const override;
    void move(const QPoint &offset) override;
    QRect boundingRect() const override;
    void setRect(const QRect &newRect) override;
};

#endif // FIGURE_H
