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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_smartfMRIClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QListView *experimentlistView;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QTableView *scanParameterTableView;
    QGridLayout *gridLayout_3;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *updataPushButton;
    QPushButton *aboutPushButton;
    QPushButton *logPushButton;
    QPushButton *runPushButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *smartfMRIClass)
    {
        if (smartfMRIClass->objectName().isEmpty())
            smartfMRIClass->setObjectName(QStringLiteral("smartfMRIClass"));
        smartfMRIClass->resize(1228, 571);
        QIcon icon;
        icon.addFile(QStringLiteral(":/smartfMRI/pm.ico"), QSize(), QIcon::Normal, QIcon::Off);
        smartfMRIClass->setWindowIcon(icon);
        centralWidget = new QWidget(smartfMRIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        experimentlistView = new QListView(centralWidget);
        experimentlistView->setObjectName(QStringLiteral("experimentlistView"));
        experimentlistView->setFont(font);

        gridLayout->addWidget(experimentlistView, 1, 0, 1, 2);


        horizontalLayout->addLayout(gridLayout);

        horizontalSpacer_6 = new QSpacerItem(13, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 2);

        scanParameterTableView = new QTableView(centralWidget);
        scanParameterTableView->setObjectName(QStringLiteral("scanParameterTableView"));
        scanParameterTableView->setFont(font);

        gridLayout_2->addWidget(scanParameterTableView, 1, 0, 1, 2);


        verticalLayout->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy);
        addButton->setMinimumSize(QSize(110, 0));
        addButton->setFont(font);

        gridLayout_3->addWidget(addButton, 0, 0, 1, 1);

        removeButton = new QPushButton(centralWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        sizePolicy.setHeightForWidth(removeButton->sizePolicy().hasHeightForWidth());
        removeButton->setSizePolicy(sizePolicy);
        removeButton->setMinimumSize(QSize(110, 0));
        removeButton->setFont(font);

        gridLayout_3->addWidget(removeButton, 0, 2, 1, 1);

        updataPushButton = new QPushButton(centralWidget);
        updataPushButton->setObjectName(QStringLiteral("updataPushButton"));
        sizePolicy.setHeightForWidth(updataPushButton->sizePolicy().hasHeightForWidth());
        updataPushButton->setSizePolicy(sizePolicy);
        updataPushButton->setMinimumSize(QSize(110, 0));
        updataPushButton->setFont(font);

        gridLayout_3->addWidget(updataPushButton, 0, 4, 1, 1);

        aboutPushButton = new QPushButton(centralWidget);
        aboutPushButton->setObjectName(QStringLiteral("aboutPushButton"));
        sizePolicy.setHeightForWidth(aboutPushButton->sizePolicy().hasHeightForWidth());
        aboutPushButton->setSizePolicy(sizePolicy);
        aboutPushButton->setMinimumSize(QSize(110, 0));
        aboutPushButton->setFont(font);

        gridLayout_3->addWidget(aboutPushButton, 1, 0, 1, 1);

        logPushButton = new QPushButton(centralWidget);
        logPushButton->setObjectName(QStringLiteral("logPushButton"));
        sizePolicy.setHeightForWidth(logPushButton->sizePolicy().hasHeightForWidth());
        logPushButton->setSizePolicy(sizePolicy);
        logPushButton->setMinimumSize(QSize(110, 0));
        logPushButton->setFont(font);

        gridLayout_3->addWidget(logPushButton, 1, 2, 1, 1);

        runPushButton = new QPushButton(centralWidget);
        runPushButton->setObjectName(QStringLiteral("runPushButton"));
        sizePolicy.setHeightForWidth(runPushButton->sizePolicy().hasHeightForWidth());
        runPushButton->setSizePolicy(sizePolicy);
        runPushButton->setMinimumSize(QSize(110, 0));
        runPushButton->setFont(font);

        gridLayout_3->addWidget(runPushButton, 1, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 3, 2, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 2, 1);


        verticalLayout->addLayout(gridLayout_3);


        horizontalLayout->addLayout(verticalLayout);

        smartfMRIClass->setCentralWidget(centralWidget);
        addButton->raise();
        statusBar = new QStatusBar(smartfMRIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        smartfMRIClass->setStatusBar(statusBar);

        retranslateUi(smartfMRIClass);

        QMetaObject::connectSlotsByName(smartfMRIClass);
    } // setupUi

    void retranslateUi(QMainWindow *smartfMRIClass)
    {
        smartfMRIClass->setWindowTitle(QApplication::translate("smartfMRIClass", "Smart fMRI", 0));
        label->setText(QApplication::translate("smartfMRIClass", "Experiment List", 0));
        label_2->setText(QApplication::translate("smartfMRIClass", "Scan Parameters", 0));
        addButton->setText(QApplication::translate("smartfMRIClass", "Add", 0));
        removeButton->setText(QApplication::translate("smartfMRIClass", "Remove", 0));
        updataPushButton->setText(QApplication::translate("smartfMRIClass", "Update", 0));
        aboutPushButton->setText(QApplication::translate("smartfMRIClass", "About", 0));
        logPushButton->setText(QApplication::translate("smartfMRIClass", "Log", 0));
        runPushButton->setText(QApplication::translate("smartfMRIClass", "Run", 0));
    } // retranslateUi

};

namespace Ui {
    class smartfMRIClass: public Ui_smartfMRIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTFMRI_H
