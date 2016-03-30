#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <opencv2/opencv.hpp>

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
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Open Image"), "/Users/Haoyang/Downloads/",
         tr ("Image File (*.png *.jpg *.jpeg *.bmp)"));

    image = cv::imread(fileName.toLatin1().data());
    QImage img = QImage ((const unsigned char *)(image.data),
                         image.cols,image.rows,
                         QImage::Format_RGB888);

    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->resize(ui->label->pixmap()->size());
//    cv::namedWindow("Original Image");
//    cv::imshow("Original Image", image);
}

void MainWindow::on_pushButton_2_clicked()
{
    cv::flip(image,image,0);
    cv::cvtColor(image,image,CV_BGR2RGB);
//    cv::namedWindow("Output Image");
//    cv::imshow("Output Image",image);
    QImage img = QImage ((const unsigned char *)(image.data),
                         image.cols,image.rows,
                         QImage::Format_RGB888);

    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->resize(ui->label->pixmap()->size());


}
