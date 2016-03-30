#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <QFileDialog>  // used for opening image file
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    cv::Mat& AddTwoPics(cv::Mat& image1, cv::Mat& image2);


private slots:
    void on_pushButton_clicked();
    
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;

// add two private member data, in order to store two image file;
private:
    cv::Mat img1;
    cv::Mat img2;
};

#endif // MAINWINDOW_H
