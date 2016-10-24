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
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLineEdit *experimentNameLineEdit;
    QSpacerItem *verticalSpacer_4;
    QLineEdit *paradigmNameLineEdit;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *experimentLineEdit;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QLabel *label_6;
    QPushButton *confirmPushButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QTableView *scanParametersTableView;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QWidget *ExperimentManager)
    {
        if (ExperimentManager->objectName().isEmpty())
            ExperimentManager->setObjectName(QStringLiteral("ExperimentManager"));
        ExperimentManager->resize(1019, 419);
        QIcon icon;
        icon.addFile(QStringLiteral(":/smartfMRI/pm.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ExperimentManager->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(ExperimentManager);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 132, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_5 = new QLabel(ExperimentManager);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setPointSize(12);
        label_5->setFont(font);

        gridLayout_3->addWidget(label_5, 5, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_7 = new QLabel(ExperimentManager);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        horizontalLayout_3->addWidget(label_7);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        experimentNameLineEdit = new QLineEdit(ExperimentManager);
        experimentNameLineEdit->setObjectName(QStringLiteral("experimentNameLineEdit"));
        experimentNameLineEdit->setFont(font);

        gridLayout_3->addWidget(experimentNameLineEdit, 3, 1, 1, 2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 2, 0, 1, 1);

        paradigmNameLineEdit = new QLineEdit(ExperimentManager);
        paradigmNameLineEdit->setObjectName(QStringLiteral("paradigmNameLineEdit"));
        paradigmNameLineEdit->setFont(font);
        paradigmNameLineEdit->setReadOnly(true);

        gridLayout_3->addWidget(paradigmNameLineEdit, 5, 1, 1, 2);

        label_2 = new QLabel(ExperimentManager);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setPointSize(8);
        label_2->setFont(font1);

        gridLayout_3->addWidget(label_2, 4, 1, 1, 2);

        label_4 = new QLabel(ExperimentManager);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout_3->addWidget(label_4, 3, 0, 1, 1);

        experimentLineEdit = new QLineEdit(ExperimentManager);
        experimentLineEdit->setObjectName(QStringLiteral("experimentLineEdit"));
        experimentLineEdit->setEnabled(true);
        QFont font2;
        font2.setFamily(QStringLiteral("ADMUI3Lg"));
        font2.setPointSize(12);
        experimentLineEdit->setFont(font2);
        experimentLineEdit->setReadOnly(true);

        gridLayout_3->addWidget(experimentLineEdit, 0, 1, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 4, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 131, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_5 = new QSpacerItem(30, 17, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_3 = new QLabel(ExperimentManager);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font1);

        gridLayout_4->addWidget(label_3, 4, 0, 1, 3);

        label_6 = new QLabel(ExperimentManager);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setFont(font);

        gridLayout_4->addWidget(label_6, 0, 0, 1, 3);

        confirmPushButton = new QPushButton(ExperimentManager);
        confirmPushButton->setObjectName(QStringLiteral("confirmPushButton"));
        confirmPushButton->setMinimumSize(QSize(110, 0));
        confirmPushButton->setFont(font);

        gridLayout_4->addWidget(confirmPushButton, 5, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 5, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 5, 2, 1, 1);

        scanParametersTableView = new QTableView(ExperimentManager);
        scanParametersTableView->setObjectName(QStringLiteral("scanParametersTableView"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scanParametersTableView->sizePolicy().hasHeightForWidth());
        scanParametersTableView->setSizePolicy(sizePolicy1);
        scanParametersTableView->setFont(font);
        scanParametersTableView->setTextElideMode(Qt::ElideLeft);

        gridLayout_4->addWidget(scanParametersTableView, 2, 0, 1, 3);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_4->addItem(verticalSpacer_5, 3, 0, 1, 3);


        horizontalLayout->addLayout(gridLayout_4);

        QWidget::setTabOrder(experimentNameLineEdit, paradigmNameLineEdit);
        QWidget::setTabOrder(paradigmNameLineEdit, scanParametersTableView);
        QWidget::setTabOrder(scanParametersTableView, confirmPushButton);

        retranslateUi(ExperimentManager);

        QMetaObject::connectSlotsByName(ExperimentManager);
    } // setupUi

    void retranslateUi(QWidget *ExperimentManager)
    {
        ExperimentManager->setWindowTitle(QApplication::translate("ExperimentManager", "ExperimentManager", 0));
        label_5->setText(QApplication::translate("ExperimentManager", "Paradigm Name:", 0));
        label_7->setText(QApplication::translate("ExperimentManager", "Experiment Type:", 0));
        label_2->setText(QApplication::translate("ExperimentManager", "Please don't use the following characters:\n"
"][!\"#$%&'()*+,./:;<=>?@^`{|}~-", 0));
        label_4->setText(QApplication::translate("ExperimentManager", "Experiment Name:", 0));
        label_3->setText(QApplication::translate("ExperimentManager", "Parameters are supposed to be integers and greater than 0.", 0));
        label_6->setText(QApplication::translate("ExperimentManager", "Scan Parameters", 0));
        confirmPushButton->setText(QApplication::translate("ExperimentManager", "Confirm", 0));
    } // retranslateUi

};

namespace Ui {
    class ExperimentManager: public Ui_ExperimentManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPERIMENTMANAGER_H
