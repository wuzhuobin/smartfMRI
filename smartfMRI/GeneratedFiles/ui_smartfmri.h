/********************************************************************************
** Form generated from reading UI file 'smartfmri.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMARTFMRI_H
#define UI_SMARTFMRI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_smartfMRIClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;
    QPushButton *removeButton;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QListView *experimentlistView;
    QGridLayout *gridLayout_2;
    QPushButton *logPushButton;
    QLabel *label_2;
    QPushButton *updataPushButton;
    QPushButton *runPushButton;
    QTableView *scanParameterTableView;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *aboutPushButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *smartfMRIClass)
    {
        if (smartfMRIClass->objectName().isEmpty())
            smartfMRIClass->setObjectName(QStringLiteral("smartfMRIClass"));
        smartfMRIClass->resize(1215, 523);
        QIcon icon;
        icon.addFile(QStringLiteral(":/smartfMRI/pm.ico"), QSize(), QIcon::Normal, QIcon::Off);
        smartfMRIClass->setWindowIcon(icon);
        centralWidget = new QWidget(smartfMRIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 1, 1, 1);

        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setMinimumSize(QSize(110, 0));
        QFont font;
        font.setPointSize(12);
        addButton->setFont(font);

        gridLayout->addWidget(addButton, 4, 0, 1, 1);

        removeButton = new QPushButton(centralWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setMinimumSize(QSize(110, 0));
        removeButton->setFont(font);

        gridLayout->addWidget(removeButton, 4, 2, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        experimentlistView = new QListView(centralWidget);
        experimentlistView->setObjectName(QStringLiteral("experimentlistView"));
        experimentlistView->setFont(font);

        gridLayout->addWidget(experimentlistView, 1, 0, 1, 3);


        gridLayout_3->addLayout(gridLayout, 0, 1, 2, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        logPushButton = new QPushButton(centralWidget);
        logPushButton->setObjectName(QStringLiteral("logPushButton"));
        logPushButton->setMinimumSize(QSize(110, 0));
        logPushButton->setFont(font);

        gridLayout_2->addWidget(logPushButton, 3, 2, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 5);

        updataPushButton = new QPushButton(centralWidget);
        updataPushButton->setObjectName(QStringLiteral("updataPushButton"));
        updataPushButton->setMinimumSize(QSize(110, 0));
        updataPushButton->setFont(font);

        gridLayout_2->addWidget(updataPushButton, 3, 0, 1, 1);

        runPushButton = new QPushButton(centralWidget);
        runPushButton->setObjectName(QStringLiteral("runPushButton"));
        runPushButton->setMinimumSize(QSize(110, 0));
        runPushButton->setFont(font);

        gridLayout_2->addWidget(runPushButton, 3, 4, 1, 1);

        scanParameterTableView = new QTableView(centralWidget);
        scanParameterTableView->setObjectName(QStringLiteral("scanParameterTableView"));
        scanParameterTableView->setFont(font);

        gridLayout_2->addWidget(scanParameterTableView, 1, 0, 1, 5);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_2, 2, 0, 1, 5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 3, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 3, 3, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 4, 2, 1);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 0, 5, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(148, 450, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 2, 1, 2);

        aboutPushButton = new QPushButton(centralWidget);
        aboutPushButton->setObjectName(QStringLiteral("aboutPushButton"));
        aboutPushButton->setFont(font);

        gridLayout_3->addWidget(aboutPushButton, 1, 2, 1, 2);

        smartfMRIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(smartfMRIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        smartfMRIClass->setStatusBar(statusBar);
        QWidget::setTabOrder(addButton, removeButton);
        QWidget::setTabOrder(removeButton, scanParameterTableView);
        QWidget::setTabOrder(scanParameterTableView, updataPushButton);
        QWidget::setTabOrder(updataPushButton, logPushButton);
        QWidget::setTabOrder(logPushButton, runPushButton);

        retranslateUi(smartfMRIClass);

        QMetaObject::connectSlotsByName(smartfMRIClass);
    } // setupUi

    void retranslateUi(QMainWindow *smartfMRIClass)
    {
        smartfMRIClass->setWindowTitle(QApplication::translate("smartfMRIClass", "Smart fMRI", 0));
        addButton->setText(QApplication::translate("smartfMRIClass", "Add", 0));
        removeButton->setText(QApplication::translate("smartfMRIClass", "Remove", 0));
        label->setText(QApplication::translate("smartfMRIClass", "Experiment List", 0));
        logPushButton->setText(QApplication::translate("smartfMRIClass", "Log", 0));
        label_2->setText(QApplication::translate("smartfMRIClass", "Scan Parameters", 0));
        updataPushButton->setText(QApplication::translate("smartfMRIClass", "Update", 0));
        runPushButton->setText(QApplication::translate("smartfMRIClass", "Run", 0));
        aboutPushButton->setText(QApplication::translate("smartfMRIClass", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class smartfMRIClass: public Ui_smartfMRIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTFMRI_H
