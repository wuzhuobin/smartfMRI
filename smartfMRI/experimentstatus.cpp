#include "experimentstatus.h"

ExperimentStatus::ExperimentStatus(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	thread = new StatusThread();
	connect(ui.finishPushButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(ui.finishPushButton, SIGNAL(clicked()), this, SLOT(stopThread()));
	connect(ui.stopPushButton, SIGNAL(clicked()), this, SLOT(stopThread()));
	connect(this, SIGNAL(rejected()), this, SLOT(stopThread()));

}

ExperimentStatus::~ExperimentStatus()
{
}

int ExperimentStatus::runExperiment(Experiment * e)
{
	//if (thread != nullptr) delete thread;
	thread = &StatusThread(e, true);
	//if (QDesktopServices::openUrl(QUrl(e->getFi().absoluteFilePath()))) {
	if (1) {
		qDebug() << "run";
		thread->start();
		return 1;
	}
	else {
		QMessageBox::critical(this, tr("Fail to run"),
			QString("Cannot open the *.ebs2 file."));
		return 0;
	}
}


void ExperimentStatus::stopThread() {
	if (thread != nullptr) {
		thread->setThreadFlag(false);
		thread->wait();
		//delete thread;
	}
}
