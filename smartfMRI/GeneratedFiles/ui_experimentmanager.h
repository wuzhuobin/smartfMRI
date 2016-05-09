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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExperimentManager
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLineEdit *experimentNameLineEdit;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_5;
    QLineEdit *paradigmNameLineEdit;
    QSpacerItem *verticalSpacer_3;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_6;
    QPushButton *confirmPushButton;
    QSpacerItem *horizontalSpacer_3;
    QTableView *scanParametersTableView;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ExperimentManager)
    {
        if (ExperimentManager->objectName().isEmpty())
            ExperimentManager->setObjectName(QStringLiteral("ExperimentManager"));
        ExperimentManager->resize(905, 353);
        horizontalLayout = new QHBoxLayout(ExperimentManager);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_4 = new QLabel(ExperimentManager);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font;
        font.setPointSize(12);
        label_4->setFont(font);

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        experimentNameLineEdit = new QLineEdit(ExperimentManager);
        experimentNameLineEdit->setObjectName(QStringLiteral("experimentNameLineEdit"));
        experimentNameLineEdit->setFont(font);

        gridLayout_3->addWidget(experimentNameLineEdit, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 1, 0, 1, 1);

        label_5 = new QLabel(ExperimentManager);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        paradigmNameLineEdit = new QLineEdit(ExperimentManager);
        paradigmNameLineEdit->setObjectName(QStringLiteral("paradigmNameLineEdit"));
        paradigmNameLineEdit->setFont(font);
        paradigmNameLineEdit->setReadOnly(true);

        gridLayout_3->addWidget(paradigmNameLineEdit, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 2, 2, 1, 1);

        label_6 = new QLabel(ExperimentManager);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setFont(font);

        gridLayout_4->addWidget(label_6, 0, 0, 1, 3);

        confirmPushButton = new QPushButton(ExperimentManager);
        confirmPushButton->setObjectName(QStringLiteral("confirmPushButton"));
        confirmPushButton->setFont(font);

        gridLayout_4->addWidget(confirmPushButton, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        scanParametersTableView = new QTableView(ExperimentManager);
        scanParametersTableView->setObjectName(QStringLiteral("scanParametersTableView"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scanParametersTableView->sizePolicy().hasHeightForWidth());
        scanParametersTableView->setSizePolicy(sizePolicy1);
        scanParametersTableView->setFont(font);
        scanParametersTableView->setTextElideMode(Qt::ElideLeft);

        gridLayout_4->addWidget(scanParametersTableView, 1, 0, 1, 3);


        horizontalLayout->addLayout(gridLayout_4);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        QWidget::setTabOrder(experimentNameLineEdit, paradigmNameLineEdit);
        QWidget::setTabOrder(paradigmNameLineEdit, scanParametersTableView);
        QWidget::setTabOrder(scanParametersTableView, confirmPushButton);

        retranslateUi(ExperimentManager);

        QMetaObject::connectSlotsByName(ExperimentManager);
    } // setupUi

    void retranslateUi(QWidget *ExperimentManager)
    {
        ExperimentManager->setWindowTitle(QApplication::translate("ExperimentManager", "ExperimentManager", 0));
        label_4->setText(QApplication::translate("ExperimentManager", "Experiment Name:", 0));
        label_5->setText(QApplication::translate("ExperimentManager", "Paradigm Name:", 0));
        label_6->setText(QApplication::translate("ExperimentManager", "Scan Parameters", 0));
        confirmPushButton->setText(QApplication::translate("ExperimentManager", "Confirm", 0));
    } // retranslateUi

};

namespace Ui {
    class ExperimentManager: public Ui_ExperimentManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPERIMENTMANAGER_H
