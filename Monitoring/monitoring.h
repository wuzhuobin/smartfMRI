#ifndef MONITORING_H
#define MONITORING_H

#include <QtWidgets/QMainWindow>
#include "ui_monitoring.h"

class Monitoring : public QMainWindow
{
	Q_OBJECT

public:
	Monitoring(QWidget *parent = 0);
	~Monitoring();

private:
	Ui::MonitoringClass ui;
};

#endif // MONITORING_H
