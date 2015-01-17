#include "control.h"
#include "ui_control.h"

Control::Control(QWidget *parent) :
    QMainWindow(parent)
  , ui(new Ui::Control)
  , videoThread(new VideoEngine)
{
    ui->setupUi(this);
    connect(videoThread, SIGNAL(sendInputImage(const QImage&)), ui->inputFrame, SLOT(setImage(const QImage&)));
    connect(videoThread, SIGNAL(sendProcessedImage(const QImage&)), ui->ProcessedImage, SLOT(setImage(const QImage&)));
}

Control::~Control()
{
    delete videoThread;
    delete ui;
}


void Control::on_captureButton_clicked()
{
    videoThread->openCamera(0,0);
    videoThread->start();
}

