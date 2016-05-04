/********************************************************************************
** Form generated from reading UI file 'experimentmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPERIMENTMANAGER_H
#define UI_EXPERIMENTMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExperimentManager
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLineEdit *experimentNameLineEdit;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_5;
    QLineEdit *paradigmNameLineEdit;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *confirmPushButton;
    QTableView *scanParametersTableView;
    QLabel *label_6;

    void setupUi(QWidget *ExperimentManager)
    {
        if (ExperimentManager->objectName().isEmpty())
            ExperimentManager->setObjectName(QStringLiteral("ExperimentManager"));
        ExperimentManager->resize(1218, 580);
        layoutWidget = new QWidget(ExperimentManager);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 220, 361, 98));
        QFont font;
        font.setPointSize(12);
        layoutWidget->setFont(font);
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        experimentNameLineEdit = new QLineEdit(layoutWidget);
        experimentNameLineEdit->setObjectName(QStringLiteral("experimentNameLineEdit"));
        experimentNameLineEdit->setFont(font);

        gridLayout_3->addWidget(experimentNameLineEdit, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 1, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        paradigmNameLineEdit = new QLineEdit(layoutWidget);
        paradigmNameLineEdit->setObjectName(QStringLiteral("paradigmNameLineEdit"));
        paradigmNameLineEdit->setFont(font);
        paradigmNameLineEdit->setReadOnly(true);

        gridLayout_3->addWidget(paradigmNameLineEdit, 2, 1, 1, 1);

        layoutWidget_2 = new QWidget(ExperimentManager);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(660, 80, 421, 411));
        layoutWidget_2->setFont(font);
        gridLayout_4 = new QGridLayout(layoutWidget_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 2, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        confirmPushButton = new QPushButton(layoutWidget_2);
        confirmPushButton->setObjectName(QStringLiteral("confirmPushButton"));
        confirmPushButton->setFont(font);

        gridLayout_4->addWidget(confirmPushButton, 2, 1, 1, 1);

        scanParametersTableView = new QTableView(layoutWidget_2);
        scanParametersTableView->setObjectName(QStringLiteral("scanParametersTableView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scanParametersTableView->sizePolicy().hasHeightForWidth());
        scanParametersTableView->setSizePolicy(sizePolicy);
        scanParametersTableView->setFont(font);
        scanParametersTableView->setTextElideMode(Qt::ElideLeft);

        gridLayout_4->addWidget(scanParametersTableView, 1, 0, 1, 3);

        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setFont(font);

        gridLayout_4->addWidget(label_6, 0, 0, 1, 3);


        retranslateUi(ExperimentManager);

        QMetaObject::connectSlotsByName(ExperimentManager);
    } // setupUi

    void retranslateUi(QWidget *ExperimentManager)
    {
        ExperimentManager->setWindowTitle(QApplication::translate("ExperimentManager", "ExperimentManager", 0));
        label_4->setText(QApplication::translate("ExperimentManager", "Experiment Name:", 0));
        label_5->setText(QApplication::translate("ExperimentManager", "Paradigm Name:", 0));
        confirmPushButton->setText(QApplication::translate("ExperimentManager", "Confirm", 0));
        label_6->setText(QApplication::translate("ExperimentManager", "Scan Parameters", 0));
    } // retranslateUi

};

namespace Ui {
    class ExperimentManager: public Ui_ExperimentManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPERIMENTMANAGER_H
