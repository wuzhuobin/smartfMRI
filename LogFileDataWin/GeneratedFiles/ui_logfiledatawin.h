/********************************************************************************
** Form generated from reading UI file 'logfiledatawin.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGFILEDATAWIN_H
#define UI_LOGFILEDATAWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogFileDataWinClass
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LogFileDataWinClass)
    {
        if (LogFileDataWinClass->objectName().isEmpty())
            LogFileDataWinClass->setObjectName(QStringLiteral("LogFileDataWinClass"));
        LogFileDataWinClass->resize(802, 702);
        centralWidget = new QWidget(LogFileDataWinClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 30, 691, 561));
        LogFileDataWinClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LogFileDataWinClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 802, 26));
        LogFileDataWinClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LogFileDataWinClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LogFileDataWinClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LogFileDataWinClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LogFileDataWinClass->setStatusBar(statusBar);

        retranslateUi(LogFileDataWinClass);

        QMetaObject::connectSlotsByName(LogFileDataWinClass);
    } // setupUi

    void retranslateUi(QMainWindow *LogFileDataWinClass)
    {
        LogFileDataWinClass->setWindowTitle(QApplication::translate("LogFileDataWinClass", "LogFileDataWin", 0));
    } // retranslateUi

};

namespace Ui {
    class LogFileDataWinClass: public Ui_LogFileDataWinClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGFILEDATAWIN_H
