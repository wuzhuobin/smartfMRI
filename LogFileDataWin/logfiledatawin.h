#ifndef LOGFILEDATAWIN_H
#define LOGFILEDATAWIN_H

#include <QtWidgets/QMainWindow>
#include <QFile>
#include <QTextStream>
#include "ui_logfiledatawin.h"
#include "logfiledata.h"

class LogFileDataWin : public QMainWindow
{
	Q_OBJECT

public:
	LogFileDataWin(QWidget *parent = 0);
	~LogFileDataWin();

private:
	Ui::LogFileDataWinClass ui;

};

#endif // LOGFILEDATAWIN_H
