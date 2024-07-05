#include "drawingarea.h"

#include "drawingarea.h"
#include <QMouseEvent>
#include <QPainter>
#include <QFileDialog>
#include <QImage>
#include <QDebug>

DrawingArea::DrawingArea(QWidget *parent)
    : QFrame(parent), currentMode(Mode::None), movingIndex(-1)
{
    setFrameShape(QFrame::Box);
    setStyleSheet("background-color: white; border: 1px solid black;");
}

void DrawingArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        // Остановка рисования и удаление фигуры
        currentShape = nullptr;
        currentMode = Mode::None;
        update();
        return;
    }

    switch (currentMode) {
    case Mode::Move:
        if (event->button() == Qt::LeftButton) {
            for (int i = 0; i < shapes.size(); i++) {
                if (shapes[i]->contains(event->pos())) {
                    movingIndex = i;
                    lastMousePos = event->pos();
                    setCursor(Qt::ClosedHandCursor);
                    return;
                }
            }
        } else if (event->button() == Qt::RightButton) {
            movingIndex = -1;
            setCursor(Qt::ArrowCursor);
            update();
        }
        break;
    case Mode::Delete:
        if (event->button() == Qt::LeftButton) {
            for (int i = 0; i < shapes.size(); i++) {
                if (shapes[i]->contains(event->pos())) {
                    removeShape(i);
                    update();
                    return;
                }
            }
        } else if (event->button() == Qt::RightButton) {
            currentMode = Mode::None;
            update();
        }
        break;
    case Mode::Connection:
        if (event->button() == Qt::LeftButton) {
            for (int i = 0; i < shapes.size(); ++i) {
                if (shapes[i]->contains(event->pos())) {
                    if (connectionStartPoint.isNull()) {
                        connectionStartPoint = shapes[i]->boundingRect().center();
                        connectionEndPoint = connectionStartPoint;
                        startShapeIndex = i;
                    } else {
                        connectionEndPoint = shapes[i]->boundingRect().center();
                        if (startShapeIndex != i) {
                            connections.push_back(std::make_pair(startShapeIndex, i));
                        }
                        connectionStartPoint = QPoint();
                        connectionEndPoint = QPoint();
                        currentMode = Mode::None;
                    }
                    update();
                    return;
                }
            }
            connectionStartPoint = QPoint();
            connectionEndPoint = QPoint();
            currentMode = Mode::None;
            update();
        } else if (event->button() == Qt::RightButton) {
            connectionStartPoint = QPoint();
            connectionEndPoint = QPoint();
            currentMode = Mode::None;
            update();
        }
        break;
    case Mode::Rectangle:
    case Mode::Ellipse:
    case Mode::Triangle:
        if (event->button() == Qt::LeftButton) {
            startPoint = event->pos();
            QRect rect;
            rect.setTopLeft(startPoint);
            rect.setBottomRight(startPoint);
            if (currentMode == Mode::Rectangle) {
                currentShape = std::make_shared<RectangleShape>(rect);
            } else if (currentMode == Mode::Ellipse) {
                currentShape = std::make_shared<EllipseShape>(rect);
            } else if (currentMode == Mode::Triangle) {
                currentShape = std::make_shared<TriangleShape>(rect);
            }
            update();
        }
        update();
        break;
    default:
        break;
    }
}

void DrawingArea::mouseMoveEvent(QMouseEvent *event)
{
    if (currentMode == Mode::Move && movingIndex >= 0) {
        QPoint offset = event->pos() - lastMousePos;
        shapes[movingIndex]->move(offset);
        lastMousePos = event->pos();
        update();
    } else if (currentMode == Mode::Connection && !connectionStartPoint.isNull()) {
        connectionEndPoint = event->pos();
        update();
    } else if (currentMode != Mode::None && currentShape) {
        QRect rect = currentShape->boundingRect();
        rect.setBottomRight(event->pos());
        currentShape->setRect(rect);
        update();
    }
}

void DrawingArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (currentMode == Mode::Move && movingIndex >= 0 && event->button() == Qt::LeftButton) {
        movingIndex = -1;
        setCursor(Qt::ArrowCursor);
        update();
    } else if (currentShape && event->button() == Qt::LeftButton) {
        if (event->button() == Qt::RightButton){
            currentShape = nullptr;
            currentMode = Mode::None;
            return;
        }
        shapes.push_back(currentShape);
        currentShape = nullptr;
        currentMode = Mode::None;
        update();
    }
}

void DrawingArea::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);
    QPainter painter(this);

    for (const auto &shape : shapes) {
        shape->draw(painter);
    }

    for (const auto &connection : connections) {
        painter.drawLine(shapes[connection.first]->boundingRect().center(),
                         shapes[connection.second]->boundingRect().center());
    }

    if (currentShape) {
        currentShape->draw(painter);
    }

    if (currentMode == Mode::Connection && !connectionStartPoint.isNull()) {
        painter.drawLine(connectionStartPoint, connectionEndPoint);
    }
}

void DrawingArea::keyPressEvent(QKeyEvent *event) {
    if (currentMode != Mode::None && event->key() == Qt::Key_Escape) {
        currentShape = nullptr;
        currentMode = Mode::None;
        update();
    }
}

void DrawingArea::removeConnections(int shapeIndex)
{
    QVector<QPair<int, int>> newConnections;

    for (const auto &connection : connections) {
        if (connection.first != shapeIndex && connection.second != shapeIndex) {
            newConnections.push_back(connection);
        }
    }

    for (auto &connection : newConnections) {
        if (connection.first > shapeIndex) {
            --connection.first;
        }
        if (connection.second > shapeIndex) {
            --connection.second;
        }
    }
    connections = newConnections;
    update();
}

void DrawingArea::removeShape(int index)
{
    removeConnections(index);

    if (index >= 0 && index < shapes.size()) {
        shapes.remove(index);
    }
}

void DrawingArea::saveToFile(const QString &fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream out(&file);

        int count = shapes.size();
        out << count;
        for (const auto &shape : shapes) {
            if (dynamic_cast<RectangleShape*>(shape.get())) {
                out << QString("Rectangle") << shape->boundingRect();
            } else if (dynamic_cast<EllipseShape*>(shape.get())) {
                out << QString("Ellipse") << shape->boundingRect();
            } else if (dynamic_cast<TriangleShape*>(shape.get())) {
                out << QString("Triangle") << shape->boundingRect();
            }
        }

        int count2 = connections.size();
        out << count2;
        for (const auto &connection : connections) {
            out << connection.first << connection.second;
        }
    }
}

void DrawingArea::loadFromFile(const QString &fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);

        int shapeCount;
        in >> shapeCount;
        shapes.clear();
        for (int i = 0; i < shapeCount; ++i) {
            QString shapeType;
            QRect rect;
            in >> shapeType >> rect;

            if (shapeType == "Rectangle") {
                shapes.push_back(std::make_shared<RectangleShape>(rect));
            } else if (shapeType == "Ellipse") {
                shapes.push_back(std::make_shared<EllipseShape>(rect));
            } else if (shapeType == "Triangle") {
                shapes.push_back(std::make_shared<TriangleShape>(rect));
            }
        }

        int connectionCount;
        in >> connectionCount;
        connections.clear();
        for (int i = 0; i < connectionCount; ++i) {
            int first, second;
            in >> first >> second;
            connections.push_back(qMakePair(first, second));
        }
    }

    update();
}

