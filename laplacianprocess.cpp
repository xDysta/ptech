#include "laplacianprocess.h"
#include "mainwindow.h"

LaplacianProcess::LaplacianProcess(MainWindow* parent)
    : _activeBlur(0), _sizeH(0), _sizeL(0), _sigmaX(0), _sigmaY(0)
{
    this->_parent = parent;
}

void LaplacianProcess::process() {
    cv::Mat mat, laplacian, grey, absLaplacian;
    mat = Utils::Convert::qImage::toCvMat(this->_parent->getPicture(), false);
    // reduce noise by blurring and convert in greyscale
    if (this->_activeBlur)
        cv::GaussianBlur(mat, mat, cv::Size(3,3), 0, 0);
    cv::cvtColor(mat, grey, cv::COLOR_BGR2GRAY);

    cv::Laplacian(grey, laplacian, CV_16S);
    cv::convertScaleAbs(laplacian, absLaplacian);
    QImage pic = Utils::Convert::CvMat::toQImage(&mat, false);
    this->_parent->setPicture(pic);
    this->updatePicture();
}

void LaplacianProcess::updatePicture() {
    std::cout << "Update de l'image" << std::endl;
    this->process();
    this->_parent->updateImage();
}

void LaplacianProcess::setActiveBlur(bool state) {
    this->_activeBlur = state;
    this->updatePicture();
}

void LaplacianProcess::setSizeH(int value) {
    this->_sizeH = value;
    this->updatePicture();
}

void LaplacianProcess::setSizeL(int value) {
    this->_sizeL = value;
    this->updatePicture();
}

void LaplacianProcess::setSigmaX(int value) {
    this->_sigmaX = value;
    this->updatePicture();
}

void LaplacianProcess::setSigmaY(int value) {
    this->_sigmaY = value;
    this->updatePicture();
}
