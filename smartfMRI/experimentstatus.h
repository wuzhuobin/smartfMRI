#ifndef EXPERIMENTSTATUS_H
#define EXPERIMENTSTATUS_H

#include <QWidget>
#include <QDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include <QUrl>
#include "experiment.h"
#include "ui_experimentstatus.h"
#include "statusthread.h"

class ExperimentStatus : public QDialog
{
	Q_OBJECT

public:
	ExperimentStatus(QWidget *parent = 0);
	~ExperimentStatus();
	int runExperiment(Experiment* e);
public slots:
	void stopThread();

private:
	Experiment* e;
	StatusThread* thread;
	Ui::ExperimentStatus ui;



};

#endif // EXPERIMENTSTATUS_H
