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
#include <QMessageBox>
/**
 * @class ExperimentStatus
 * UI for supervising the running paradigm with a StatusThread.
 * If the paradigm ends, the generated files will be copied to the log folder.
 * If the paradigm is interrupted, the thread needs to be ended by clicked 
 * stop button.
 * Click the finish button, this UI will hide
 * @author
 * @version
 * 
 */
class ExperimentStatus : public QDialog
{
	Q_OBJECT

public:
	/**
	 * constructor
	 * @param parent parent object
	 */
	ExperimentStatus(QWidget *parent = 0);
	/**
	 * destructor
	 */
	~ExperimentStatus();
	/**
	 * run an experiment e and monitor it by a StatusThread
	 * delete all the old log files generated from the last run
	 * if the experiment ends, copy all the generated log files to the log folder
	 * @param e the pointer of an experiment
	 */
	int runExperiment(Experiment* e);
public slots:
	/**
	 * slots, connects to a Stop button, a Finish button and rejected signal
	 * stop the running thread and release it
	 */
	void stopThread();
	/**
	 * slots, connect to Log button, open the Log folder in browser
	 * 
	 */
	void openLogFolder();

private:
	// a pointer of StatusThread which monitoring the experiment
	StatusThread* thread = nullptr;
	// UI
	Ui::ExperimentStatus ui;
	// Log folder path
	QString log;


};

#endif // EXPERIMENTSTATUS_H
