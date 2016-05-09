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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_smartfMRIClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *addButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *removeButton;
    QLabel *label;
    QListView *experimentlistView;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QPushButton *logPushButton;
    QLabel *label_2;
    QPushButton *updataPushButton;
    QPushButton *runPushButton;
    QTableView *scanParameterTableView;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *smartfMRIClass)
    {
        if (smartfMRIClass->objectName().isEmpty())
            smartfMRIClass->setObjectName(QStringLiteral("smartfMRIClass"));
        smartfMRIClass->resize(1214, 673);
        centralWidget = new QWidget(smartfMRIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 100, 441, 471));
        QFont font;
        font.setPointSize(12);
        layoutWidget->setFont(font);
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setFont(font);

        gridLayout->addWidget(addButton, 3, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 1, 1, 1);

        removeButton = new QPushButton(layoutWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setFont(font);

        gridLayout->addWidget(removeButton, 3, 2, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 3);

        experimentlistView = new QListView(layoutWidget);
        experimentlistView->setObjectName(QStringLiteral("experimentlistView"));
        experimentlistView->setFont(font);

        gridLayout->addWidget(experimentlistView, 1, 0, 1, 3);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(590, 100, 431, 471));
        layoutWidget1->setFont(font);
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        logPushButton = new QPushButton(layoutWidget1);
        logPushButton->setObjectName(QStringLiteral("logPushButton"));

        gridLayout_2->addWidget(logPushButton, 3, 2, 1, 1);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 5);

        updataPushButton = new QPushButton(layoutWidget1);
        updataPushButton->setObjectName(QStringLiteral("updataPushButton"));
        updataPushButton->setFont(font);

        gridLayout_2->addWidget(updataPushButton, 3, 0, 1, 1);

        runPushButton = new QPushButton(layoutWidget1);
        runPushButton->setObjectName(QStringLiteral("runPushButton"));
        runPushButton->setFont(font);

        gridLayout_2->addWidget(runPushButton, 3, 4, 1, 1);

        scanParameterTableView = new QTableView(layoutWidget1);
        scanParameterTableView->setObjectName(QStringLiteral("scanParameterTableView"));
        scanParameterTableView->setFont(font);

        gridLayout_2->addWidget(scanParameterTableView, 1, 0, 1, 5);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_2, 2, 0, 1, 5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 3, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 3, 3, 1, 1);

        smartfMRIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(smartfMRIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1214, 26));
        smartfMRIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(smartfMRIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        smartfMRIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(smartfMRIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        smartfMRIClass->setStatusBar(statusBar);

        retranslateUi(smartfMRIClass);

        QMetaObject::connectSlotsByName(smartfMRIClass);
    } // setupUi

    void retranslateUi(QMainWindow *smartfMRIClass)
    {
        smartfMRIClass->setWindowTitle(QApplication::translate("smartfMRIClass", "Paradigm Manager", 0));
        addButton->setText(QApplication::translate("smartfMRIClass", "Add", 0));
        removeButton->setText(QApplication::translate("smartfMRIClass", "Remove", 0));
        label->setText(QApplication::translate("smartfMRIClass", "Experiment List", 0));
        logPushButton->setText(QApplication::translate("smartfMRIClass", "Log", 0));
        label_2->setText(QApplication::translate("smartfMRIClass", "Scan Parameters", 0));
        updataPushButton->setText(QApplication::translate("smartfMRIClass", "Update", 0));
        runPushButton->setText(QApplication::translate("smartfMRIClass", "Run", 0));
    } // retranslateUi

};

namespace Ui {
    class smartfMRIClass: public Ui_smartfMRIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTFMRI_H
