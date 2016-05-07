#include "experimentstatus.h"

ExperimentStatus::ExperimentStatus(QWidget *parent)
	: QDialog(parent), thread(nullptr)
{
	ui.setupUi(this);

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
	QFileInfoList listEDAT2 = e->getDir().entryInfoList(QStringList(e->getFi().baseName() + "-*-*.edat2"), QDir::Files);
	QFileInfoList listTXT = e->getDir().entryInfoList(QStringList(e->getFi().baseName() + "-*-*.txt"), QDir::Files);
	for (int i = 0 ; i < listEDAT2.size(); ++i) {
		QFile::remove(listEDAT2[i].absoluteFilePath());
	}
	for (int i = 0; i < listTXT.size(); ++i) {
		QFile::remove(listTXT[i].absoluteFilePath());
	}
	thread = new StatusThread(e, true);
	if (QDesktopServices::openUrl(QUrl(e->getFi().absoluteFilePath()))) {
	//if (1) {
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
		if (thread->isFinished()) {
			qDebug() << "is finished";
			delete thread;
			thread = nullptr;
		}

	}

}
