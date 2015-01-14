/********************************************************************************
** Form generated from reading UI file 'control.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_H
#define UI_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "videowidget.h"

QT_BEGIN_NAMESPACE

class Ui_Control
{
public:
    QWidget *centralWidget;
    VideoWidget *inputFrame;
    VideoWidget *processedFrame;
    QPushButton *captureButton;
    QGroupBox *groupBox;
    QCheckBox *checkBox;
    QSlider *horizontalSlider;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_5;
    QSlider *horizontalSlider_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Control)
    {
        if (Control->objectName().isEmpty())
            Control->setObjectName(QStringLiteral("Control"));
        Control->resize(704, 562);
        centralWidget = new QWidget(Control);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        inputFrame = new VideoWidget(centralWidget);
        inputFrame->setObjectName(QStringLiteral("inputFrame"));
        inputFrame->setGeometry(QRect(20, 10, 320, 240));
        inputFrame->setFrameShape(QFrame::Box);
        inputFrame->setScaledContents(false);
        inputFrame->setAlignment(Qt::AlignCenter);
        processedFrame = new VideoWidget(centralWidget);
        processedFrame->setObjectName(QStringLiteral("processedFrame"));
        processedFrame->setGeometry(QRect(360, 10, 320, 240));
        processedFrame->setFrameShape(QFrame::Box);
        processedFrame->setScaledContents(false);
        processedFrame->setAlignment(Qt::AlignCenter);
        captureButton = new QPushButton(centralWidget);
        captureButton->setObjectName(QStringLiteral("captureButton"));
        captureButton->setGeometry(QRect(20, 270, 321, 81));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(370, 260, 321, 221));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(20, 120, 89, 20));
        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 30, 281, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(20, 150, 89, 20));
        checkBox_5 = new QCheckBox(groupBox);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setGeometry(QRect(20, 180, 89, 20));
        horizontalSlider_3 = new QSlider(groupBox);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(20, 70, 281, 22));
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        Control->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Control);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 704, 22));
        Control->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Control);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Control->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Control);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Control->setStatusBar(statusBar);

        retranslateUi(Control);

        QMetaObject::connectSlotsByName(Control);
    } // setupUi

    void retranslateUi(QMainWindow *Control)
    {
        Control->setWindowTitle(QApplication::translate("Control", "Control", 0));
        inputFrame->setText(QString());
        processedFrame->setText(QString());
        captureButton->setText(QApplication::translate("Control", "Capture", 0));
        groupBox->setTitle(QApplication::translate("Control", "Filtereinstellungen", 0));
        checkBox->setText(QApplication::translate("Control", "CheckBox", 0));
        checkBox_2->setText(QApplication::translate("Control", "CheckBox", 0));
        checkBox_5->setText(QApplication::translate("Control", "CheckBox", 0));
    } // retranslateUi

};

namespace Ui {
    class Control: public Ui_Control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_H
