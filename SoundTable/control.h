#ifndef CONTROL_H
#define CONTROL_H

#include <QMainWindow>
#include "filterProcessor.h"
#include "videoengine.h"

namespace Ui {
class Control;
}

class Control : public QMainWindow
{
    Q_OBJECT

public:
    explicit Control(QWidget *parent = 0);
    ~Control();

private slots:


    void on_captureButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Control *ui;
    VideoEngine *videoThread;
    FilterProcessor* filterProcessor;
};

#endif // CONTROL_H
