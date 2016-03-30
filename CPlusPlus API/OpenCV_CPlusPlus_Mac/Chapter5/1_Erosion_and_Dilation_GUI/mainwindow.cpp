#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPixmap>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),
                                                    "/Users/Haoyang/Downloads/Pics/",
                                                    "图片类型(*.png *.jpg *.bmp)");
    std::string stdFileName = fileName.toStdString();

    // 用openCV 打开，灰度图
    cv::Mat image = cv::imread(stdFileName,0);

    // 把 image 转为 Qt 格式，并在label中显示
    cv::cvtColor(image,image,CV_BGR2RGB);
    cv::flip(image,image,1);
    QImage img = QImage((const unsigned char*)(image.data),
                        image.cols, image.rows,QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->resize(ui->label->pixmap()->size());

}
