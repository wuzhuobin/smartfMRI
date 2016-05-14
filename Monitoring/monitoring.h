#ifndef MONITORING_H
#define MONITORING_H

#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include "monitor.h"
#include "mthread.h"
#include "ui_monitoring.h"

class Monitoring : public QMainWindow
{
	Q_OBJECT

public:
	Monitoring(QWidget *parent = 0);
	~Monitoring();

	public slots:
	bool runThread();

private:
	QString path;
	Ui::MonitoringClass ui;
	MThread thread;
};

#endif // MONITORING_H
