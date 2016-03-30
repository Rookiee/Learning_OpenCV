#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

#include <QDebug>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
