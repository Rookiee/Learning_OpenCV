#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

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
                            tr("Open File"),
                            "/Users/Haoyang/Downloads/",
                            tr("Image File (*.png *.jpg)"));
//    QString fileName = QFileDialog::getOpenFileName(this,
//         tr("Open Image"), ".",
//         tr ("Image File (*.png *.jpg *.jpeg *.bmp)"));
    image = cv::imread(fileName.toLatin1().data());
    cv::cvtColor(image,image,CV_BGR2RGB);

    QImage img = QImage ((const unsigned char *)(image.data),
                         image.cols,image.rows,
                         QImage::Format_RGB888);
    ui->pushButton->setText("Show");
    ui->pushButton->setText("Process");
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->resize(ui->label->pixmap()->size());
}

void MainWindow::on_pushButton_2_clicked()
{
    cv::flip(image,image,0);
    cv::cvtColor(image,image,CV_BGR2RGB);
    QImage img = QImage ((const unsigned char *)(image.data),
                         image.cols,image.rows,
                         QImage::Format_RGB888);

    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->resize(ui->label->pixmap()->size());
}
