#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>
#include <QEvent>

//openCV
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

//color detector, controller
#include "colordetectcontroller.h"
#include "colordetector.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//protected:
//    void changeEvent(QEvent *e);
    void displayMat(const cv::Mat& img);

private:
    Ui::MainWindow *ui;

private slots:
    void processColorDetection();

    void setColor();
    void setImage();
};

#endif // MAINWINDOW_H
