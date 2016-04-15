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
        layoutWidget->setGeometry(QRect(100, 120, 381, 331));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        gridLayout->addWidget(addButton, 3, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 1, 1, 1);

        removeButton = new QPushButton(layoutWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        gridLayout->addWidget(removeButton, 3, 2, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 3);

        experimentlistView = new QListView(layoutWidget);
        experimentlistView->setObjectName(QStringLiteral("experimentlistView"));

        gridLayout->addWidget(experimentlistView, 1, 0, 1, 3);

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
        smartfMRIClass->setWindowTitle(QApplication::translate("smartfMRIClass", "smartfMRI", 0));
        addButton->setText(QApplication::translate("smartfMRIClass", "Add", 0));
        removeButton->setText(QApplication::translate("smartfMRIClass", "Remove", 0));
        label->setText(QApplication::translate("smartfMRIClass", "Experiment List", 0));
    } // retranslateUi

};

namespace Ui {
    class smartfMRIClass: public Ui_smartfMRIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTFMRI_H
