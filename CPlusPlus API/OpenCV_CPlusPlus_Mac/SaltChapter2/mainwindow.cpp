#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>
#include <reducecolors.h>

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

//  open image in label

    QString fileName =
            QFileDialog::getOpenFileName(this,"Open Image",
                                         "/Users/Haoyang/Downloads/",
                                         tr("Image File(*.png *.jpg)"));


    image = cv::imread(fileName.toLatin1().data());

    cv::cvtColor(image,image,CV_BGR2RGB);
//    cv::cvtColor(image,image,CV_RGB2BGR);
    QImage img = QImage((const unsigned char*)(image.data),
                        image.cols,image.rows,QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img,Qt::AutoColor));


    ui->label->resize(ui->label->pixmap()->size());
    std::cout << image.rows << " "<< image.cols << std::endl;



}

void MainWindow::on_pushButton_2_clicked()
{
    cv::Mat newImg = salt(image,3000);
    cv::cvtColor(newImg, newImg,CV_BGR2RGB);
    QImage img = QImage((const unsigned char*)(newImg.data),
                        newImg.cols,newImg.rows,QImage::Format_RGB888);
    
    ui->label->setPixmap(QPixmap::fromImage(img,Qt::ColorOnly));
    ui->label->resize(ui->label->pixmap()->size());
//    cv::namedWindow("After Process");
//    cv::imshow("After Process",image);
}

void MainWindow::on_pushButton_3_clicked()
{
    cv::Mat newImage = ColorReduce(image,64);
    cv::cvtColor(newImage, newImage, CV_BGR2RGB);
    QImage img = QImage((const unsigned char*)(newImage.data),
                        newImage.cols, newImage.rows,QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img,Qt::ColorOnly));
    ui->label->resize(ui->label->pixmap()->size());
}
