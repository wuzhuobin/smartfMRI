/********************************************************************************
** Form generated from reading UI file 'keyconfirm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYCONFIRM_H
#define UI_KEYCONFIRM_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_keyConfirm
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *macLineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitPushButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;

    void setupUi(QWidget *keyConfirm)
    {
        if (keyConfirm->objectName().isEmpty())
            keyConfirm->setObjectName(QStringLiteral("keyConfirm"));
        keyConfirm->resize(558, 141);
        gridLayout_2 = new QGridLayout(keyConfirm);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(keyConfirm);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        macLineEdit = new QLineEdit(keyConfirm);
        macLineEdit->setObjectName(QStringLiteral("macLineEdit"));
        macLineEdit->setFont(font);
        macLineEdit->setReadOnly(true);

        gridLayout->addWidget(macLineEdit, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(255, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 0, 1, 1);

        exitPushButton = new QPushButton(keyConfirm);
        exitPushButton->setObjectName(QStringLiteral("exitPushButton"));
        exitPushButton->setFont(font);

        gridLayout_2->addWidget(exitPushButton, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(254, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        label_2 = new QLabel(keyConfirm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 3);


        retranslateUi(keyConfirm);

        QMetaObject::connectSlotsByName(keyConfirm);
    } // setupUi

    void retranslateUi(QWidget *keyConfirm)
    {
        keyConfirm->setWindowTitle(QApplication::translate("keyConfirm", "keyConfirm", 0));
        label->setText(QApplication::translate("keyConfirm", "ID", 0));
        exitPushButton->setText(QApplication::translate("keyConfirm", "Exit", 0));
        label_2->setText(QApplication::translate("keyConfirm", "File:licence.dat does not exist or is incorrect.\n"
" Please contact the producer.", 0));
    } // retranslateUi

};

namespace Ui {
    class keyConfirm: public Ui_keyConfirm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYCONFIRM_H
