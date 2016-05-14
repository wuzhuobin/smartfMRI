/********************************************************************************
** Form generated from reading UI file 'monitoring.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITORING_H
#define UI_MONITORING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MonitoringClass
{
public:
    QWidget *centralWidget;
    QPushButton *runPushButton;
    QPushButton *stopPushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MonitoringClass)
    {
        if (MonitoringClass->objectName().isEmpty())
            MonitoringClass->setObjectName(QStringLiteral("MonitoringClass"));
        MonitoringClass->resize(600, 400);
        centralWidget = new QWidget(MonitoringClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        runPushButton = new QPushButton(centralWidget);
        runPushButton->setObjectName(QStringLiteral("runPushButton"));
        runPushButton->setGeometry(QRect(60, 260, 93, 28));
        stopPushButton = new QPushButton(centralWidget);
        stopPushButton->setObjectName(QStringLiteral("stopPushButton"));
        stopPushButton->setGeometry(QRect(400, 250, 93, 28));
        MonitoringClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MonitoringClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        MonitoringClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MonitoringClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MonitoringClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MonitoringClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MonitoringClass->setStatusBar(statusBar);

        retranslateUi(MonitoringClass);

        QMetaObject::connectSlotsByName(MonitoringClass);
    } // setupUi

    void retranslateUi(QMainWindow *MonitoringClass)
    {
        MonitoringClass->setWindowTitle(QApplication::translate("MonitoringClass", "Monitoring", 0));
        runPushButton->setText(QApplication::translate("MonitoringClass", "RUN!", 0));
        stopPushButton->setText(QApplication::translate("MonitoringClass", "STOP!", 0));
    } // retranslateUi

};

namespace Ui {
    class MonitoringClass: public Ui_MonitoringClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITORING_H
