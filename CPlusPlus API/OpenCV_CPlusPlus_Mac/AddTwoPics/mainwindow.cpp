#include "mainwindow.h"
#include "ui_mainwindow.h"




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

cv::Mat& MainWindow::AddTwoPics(cv::Mat &image1, cv::Mat &image2)
{
    cv::Mat result;
    cv::add(image1, image2,result);
    return result;
}


void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"First Image",
                                                    "/Users/Haoyang/Downloads/",
                                                    "Image File(*.png *.jpg)");
    cv::Mat image = cv::imread(fileName.toLatin1().data());
    img1 = image;
    cv::cvtColor(image,image,CV_BGR2RGB);

    QImage img = QImage((const uchar*)(image.data),image.cols,image.rows,QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img,Qt::ColorOnly));
    ui->label->resize(ui->label->pixmap()->size());
}

void MainWindow::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Second Image",
                                                    "/Users/Haoyang/Downloads/",
                                                    "Image File(*.png *.jpg)");
    cv::Mat image = cv::imread(fileName.toLatin1().data());
    img2 = image;
    cv::cvtColor(image,image,CV_BGR2RGB);
    QImage img = QImage((const uchar *)(image.data),image.cols,image.rows,QImage::Format_RGB888);
    ui->label_2->setPixmap(QPixmap::fromImage(img,Qt::ColorOnly));
    ui->label_2->resize(ui->label_2->pixmap()->size());
}

void MainWindow::on_pushButton_3_clicked()
{

//    cv::Mat image1 = cv::imread("/Users/Haoyang/Downloads/boldt.jpg");
//    cv::Mat image2 = cv::imread("/Users/Haoyang/Downloads/rain.jpg");
//    cv::Mat result = AddTwoPics(image1,image2);
    cv::Mat result = 0.7*img1 + 0.5*img2;
//    cv::add(image1,image2,result);

//    cv::namedWindow("Result");
//    cv::imshow("Result",result);

//    cv::cvtColor(result,result,CV_BGR2RGB);
    QImage img = QImage((const uchar *)(result.data),result.cols,result.rows,QImage::Format_RGB888);
    ui->label_3->setPixmap(QPixmap::fromImage(img,Qt::ColorOnly));
    ui->label_3->resize(ui->label_3->pixmap()->size());
}
