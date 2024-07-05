#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include <QFrame>
#include <QPoint>
#include <QVector>
#include <memory>
#include "figure.h"

class DrawingArea : public QFrame
{
    Q_OBJECT

public:
    DrawingArea(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    enum class Mode { None, Rectangle, Ellipse, Triangle, Connection, Move, Delete };
    Mode currentMode;

    QPoint startPoint;
    std::shared_ptr<Figure> currentShape;
    QVector<std::shared_ptr<Figure>> shapes;

    QPoint connectionStartPoint;
    QPoint connectionEndPoint;
    int startShapeIndex;

    int movingIndex;
    QPoint lastMousePos;
    QVector<QPair<int, int>> connections;

    void removeConnections(int shapeIndex);
    void removeShape(int index);

    void saveToFile(const QString &fileName);
    void loadFromFile(const QString &fileName);

    friend class MainWindow;
};


#endif // DRAWINGAREA_H
