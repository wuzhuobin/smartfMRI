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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExperimentStatus
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *stopPushButton;
    QPushButton *finishPushButton;
    QPushButton *logPushButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *statusTextEdit1;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *ExperimentStatus)
    {
        if (ExperimentStatus->objectName().isEmpty())
            ExperimentStatus->setObjectName(QStringLiteral("ExperimentStatus"));
        ExperimentStatus->resize(658, 652);
        horizontalLayout = new QHBoxLayout(ExperimentStatus);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ExperimentStatus);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        stopPushButton = new QPushButton(ExperimentStatus);
        stopPushButton->setObjectName(QStringLiteral("stopPushButton"));
        stopPushButton->setFont(font);

        gridLayout->addWidget(stopPushButton, 2, 0, 1, 1);

        finishPushButton = new QPushButton(ExperimentStatus);
        finishPushButton->setObjectName(QStringLiteral("finishPushButton"));
        finishPushButton->setFont(font);

        gridLayout->addWidget(finishPushButton, 2, 4, 1, 1);

        logPushButton = new QPushButton(ExperimentStatus);
        logPushButton->setObjectName(QStringLiteral("logPushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logPushButton->sizePolicy().hasHeightForWidth());
        logPushButton->setSizePolicy(sizePolicy);
        logPushButton->setFont(font);

        gridLayout->addWidget(logPushButton, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 3, 1, 1);

        statusTextEdit1 = new QTextEdit(ExperimentStatus);
        statusTextEdit1->setObjectName(QStringLiteral("statusTextEdit1"));
        statusTextEdit1->setFont(font);
        statusTextEdit1->setReadOnly(true);

        gridLayout->addWidget(statusTextEdit1, 1, 0, 1, 5);


        horizontalLayout->addLayout(gridLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        retranslateUi(ExperimentStatus);

        QMetaObject::connectSlotsByName(ExperimentStatus);
    } // setupUi

    void retranslateUi(QWidget *ExperimentStatus)
    {
        ExperimentStatus->setWindowTitle(QApplication::translate("ExperimentStatus", "ExperimentStatus", 0));
        label->setText(QApplication::translate("ExperimentStatus", "Log:", 0));
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
