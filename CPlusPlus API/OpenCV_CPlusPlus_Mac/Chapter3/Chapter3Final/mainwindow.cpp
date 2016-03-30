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

/*
void MainWindow::displayMat(const cv::Mat &img)
{
    //BGR openCV Mat to QImage and dispaly
    QImage img_qt = QImage((const uchar *)img.data,img.cols,img.rows,img.step,
                           QImage::Format_RGB888);
    //For binary images
    if(img_qt.isNull()){
        //colorTable for binary images
        QVector<QRgb> colorTable;
        for(int i=0; i< 256; ++i) {
            colorTable.push_back(qRgb(i,i,i));
        }
        img_qt = QImage((const uchar*)img.data,img.cols,img.rows,
                        QImage::Format_Indexed8);
        img_qt.setColorTable(colorTable);
    }
    //Display the Qimage in Label
//    QPixmap img_pix = QPixmap::fromImage(img_qt.rgbSwapped()); // BGR to RGB


}
*/
void MainWindow::setImage()
{
    QFileDialog::Options options;
    QString selectedFilter;
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image File"),
                                                    "",
                                                    tr("Image file(*.jpg *.jpeg *.png *.gif *.bmp"),
                                                    &selectedFilter,
                                                    options);
    if( !fileName.isEmpty()) {
        cv::Mat img_mat = cv::imread(fileName.toStdString(),1); // 0 for grayscale
        displayMat(img_mat);
    }

    //set FileName
    ColorDetectController::getInstance()->setInputImage(fileName.toStdString());
}
