#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>

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

    QString fileName =
            QFileDialog::getOpenFileName(this,"Open Image",
                                         "/Users/Haoyang/Downloads/",
                                         tr("Image File(*.png *.jpg)"));
    fileName = fileName.toLatin1().data();
    std::string file = fileName.toStdString();

    if(!pic.setInputImage(file))
        exit(1);
    cv::Mat image = pic.getInputImage();
    //store image in data member in order to use it by another button.
    // otherwise useless.
    imageBefore  = image;
    cv::namedWindow("Show Image");
    imshow("Show Image",image);
}

void MainWindow::on_pushButton_2_clicked()
{

  cv::namedWindow("Result");
  cv::imshow("Result",pic.process());

}
