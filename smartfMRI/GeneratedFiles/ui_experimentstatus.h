/********************************************************************************
** Form generated from reading UI file 'experimentstatus.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPERIMENTSTATUS_H
#define UI_EXPERIMENTSTATUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExperimentStatus
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *stopPushButton;
    QSpacerItem *horizontalSpacer;
    QListWidget *statusListWidget;
    QPushButton *finishPushButton;
    QPushButton *logPushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ExperimentStatus)
    {
        if (ExperimentStatus->objectName().isEmpty())
            ExperimentStatus->setObjectName(QStringLiteral("ExperimentStatus"));
        ExperimentStatus->resize(978, 412);
        layoutWidget = new QWidget(ExperimentStatus);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(240, 50, 511, 281));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        stopPushButton = new QPushButton(layoutWidget);
        stopPushButton->setObjectName(QStringLiteral("stopPushButton"));

        gridLayout->addWidget(stopPushButton, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        statusListWidget = new QListWidget(layoutWidget);
        statusListWidget->setObjectName(QStringLiteral("statusListWidget"));

        gridLayout->addWidget(statusListWidget, 0, 0, 1, 5);

        finishPushButton = new QPushButton(layoutWidget);
        finishPushButton->setObjectName(QStringLiteral("finishPushButton"));

        gridLayout->addWidget(finishPushButton, 1, 4, 1, 1);

        logPushButton = new QPushButton(layoutWidget);
        logPushButton->setObjectName(QStringLiteral("logPushButton"));

        gridLayout->addWidget(logPushButton, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);


        retranslateUi(ExperimentStatus);

        QMetaObject::connectSlotsByName(ExperimentStatus);
    } // setupUi

    void retranslateUi(QWidget *ExperimentStatus)
    {
        ExperimentStatus->setWindowTitle(QApplication::translate("ExperimentStatus", "ExperimentStatus", 0));
        stopPushButton->setText(QApplication::translate("ExperimentStatus", "Stop", 0));
        finishPushButton->setText(QApplication::translate("ExperimentStatus", "Finish", 0));
        logPushButton->setText(QApplication::translate("ExperimentStatus", "Log", 0));
    } // retranslateUi

};

namespace Ui {
    class ExperimentStatus: public Ui_ExperimentStatus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPERIMENTSTATUS_H
