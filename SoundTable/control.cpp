#include "control.h"
#include "ui_control.h"

Control::Control(QWidget *parent) :
    QMainWindow(parent)
  , ui(new Ui::Control)
  , videoThread(new VideoEngine)
  , filterProcessor(new FilterProcessor())
{
    ui->setupUi(this);
    videoThread->setProcessor(filterProcessor);
    connect(videoThread, SIGNAL(sendInputImage(const QImage&)), ui->inputFrame, SLOT(setImage(const QImage&)));
    connect(videoThread, SIGNAL(sendProcessedImage(const QImage&)), ui->processedFrame , SLOT(setImage(const QImage&)));
}

Control::~Control()
{
    delete videoThread;
    delete filterProcessor;
    delete ui;
}


void Control::on_captureButton_clicked()
{
    videoThread->openCamera(0,0);
    videoThread->start();
}

