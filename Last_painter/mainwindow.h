#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


protected:
     //void keyPressEvent(QKeyEvent *event) override;

private slots:
    void on_rectangleButton_clicked();
    void on_ellipseButton_clicked();
    void on_triangleButton_clicked();
    void on_connectButton_clicked();
    void on_moveButton_clicked();
    void on_deleteButton_clicked();
    void on_saveButton_clicked();
    void on_loadButton_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
