#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::keyPressEvent(QKeyEvent *event) {
//     if ((ui->drawingArea->currentMode != DrawingArea::Mode::None) &&
//         (event->key() == Qt::Key_Escape || event->key() == Qt::Key_Right)) {
//         ui->drawingArea->keyPressEvent(event);
//     }
// }

void MainWindow::on_rectangleButton_clicked()
{
    ui->drawingArea->currentMode = DrawingArea::Mode::Rectangle;
    ui->drawingArea->update();
}

void MainWindow::on_ellipseButton_clicked()
{
    ui->drawingArea->currentMode = DrawingArea::Mode::Ellipse;
    ui->drawingArea->update();
}

void MainWindow::on_triangleButton_clicked()
{
    ui->drawingArea->currentMode = DrawingArea::Mode::Triangle;
    ui->drawingArea->update();
}

void MainWindow::on_connectButton_clicked()
{
    ui->drawingArea->currentMode = DrawingArea::Mode::Connection;
    ui->drawingArea->update();
}

void MainWindow::on_moveButton_clicked()
{
    ui->drawingArea->currentMode = DrawingArea::Mode::Move;
}

void MainWindow::on_deleteButton_clicked()
{
    ui->drawingArea->currentMode = DrawingArea::Mode::Delete;
}

void MainWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Drawing"), "", tr("Data Files (*.dat)"));
    if (!fileName.isEmpty()) {
        ui->drawingArea->saveToFile(fileName);
    }
}

void MainWindow::on_loadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load Drawing"), "", tr("Data Files (*.dat)"));
    if (!fileName.isEmpty()) {
        ui->drawingArea->loadFromFile(fileName);
    }
}
