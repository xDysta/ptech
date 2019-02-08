#ifndef DISPARITYBOX_H
#define DISPARITYBOX_H

#include <iostream>
#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QSlider>
#include <QLabel>
#include <QComboBox>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>

#include "disparityprocess.h"

class DisparityBox : public QGroupBox
{
    Q_OBJECT

public:
    DisparityBox(const QString &title, QWidget* parent = nullptr);
    virtual ~DisparityBox();
    QPushButton* getBackToMainButton() { return _backToMain; }

private slots:
    void onModeChange(int index);

    //SBM
    void onSBMnumDisparityChange(int);
    void onSBMblockSizeChange(int);
    //SGBM
    void onMinDisparityChange(int);
    void onSGBMnumDisparityChange(int);
    void onSGBMblockSizeChange(int);
    void onP1Change(int);
    void onP2Change(int);
    void onDisp12MaxDiffChange(int);
    void onPreFilterChange(int);
    void onUniquenessRatioChange(int);
    void onSpeckleWindowsSizeChange(int);
    void onSpeckleRangeChange(int);
    void onSGBMmodeChange(int);


private:
    enum MODE {
        SBM,
        SGBM
    };
    enum SGBM_MODE {
        MODE_SGBM = cv::StereoSGBM::MODE_SGBM,
        MODE_SGBM_3WAY = cv::StereoSGBM::MODE_SGBM_3WAY,
        MODE_HH = cv::StereoSGBM::MODE_HH,
        MODE_HH4 = cv::StereoSGBM::MODE_HH4
    };

    void createSlider(void);

    QGridLayout* _disparityGrid;
    QPushButton* _backToMain;

    DisparityProcess* _process;

    QComboBox* _mode;

    //For SBM mode
    QLabel* _SBMnumDisparityLabel;
    QSlider* _SBMnumDisparitySlider;
    QLabel* _SBMblockSizeLabel;
    QSlider* _SBMblockSizeSlider;

    //For SGBM mode
    QLabel* _minDisparityLabel;
    QSlider* _minDisparitySlider;
    QLabel* _SGBMnumDisparityLabel;
    QSlider* _SGBMnumDisparitySlider;
    QLabel* _SGBMblockSizeLabel;
    QSlider* _SGBMblockSizeSlider;
    QLabel* _p1Label;
    QSlider* _p1Slider;
    QLabel* _p2Label;
    QSlider* _p2Slider;
    QLabel* _disp12MaxDiffLabel;
    QSlider* _disp12MaxDiffSlider;
    QLabel* _preFilterLabel;
    QSlider* _preFilterSlider;
    QLabel* _uniquenessRatioLabel;
    QSlider* _uniquenessRatioSlider;
    QLabel* _speckleWindowsSizeLabel;
    QSlider* _speckleWindowsSizeSlider;
    QLabel* _speckleRangeLabel;
    QSlider* _speckleRangeSlider;
    QLabel* _SGBMmodeLabel;
    QComboBox* _SGBMmodeCombo;

};

#endif // DISPARITYBOX_H