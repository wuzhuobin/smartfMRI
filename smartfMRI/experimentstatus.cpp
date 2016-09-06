#include "experimentstatus.h"

ExperimentStatus::ExperimentStatus(QWidget *parent)
	: QDialog(parent, Qt::Window), thread(nullptr), log()
{
	ui.setupUi(this);
	qDebug() << "ExperimentStatus constructor";

	this->setWindowIcon(QIcon(":/smartfMRI/pm.ico"));
	connect(ui.finishPushButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(ui.finishPushButton, SIGNAL(clicked()), this, SLOT(stopThread()));
	connect(ui.stopPushButton, SIGNAL(clicked()), this, SLOT(stopThread()));
	connect(ui.logPushButton, SIGNAL(clicked()), this, SLOT(openLogFolder()));
	connect(this, SIGNAL(rejected()), this, SLOT(stopThread()));



}

ExperimentStatus::~ExperimentStatus()
{
	qDebug() << "ExperimentStatus destructor";
}

int ExperimentStatus::runExperiment(Experiment * e)
{
	QFileInfoList listEDAT2 = e->getDir().entryInfoList(QStringList(e->getFi().baseName() + "-*-*.edat2"), QDir::Files);
	QFileInfoList listTXT = e->getDir().entryInfoList(QStringList(e->getFi().baseName() + "-*-*.txt"), QDir::Files);
	log = e->getDir().absolutePath() + "/log";
	ui.statusTextEdit1->clear();
	//ui.statusTextEdit2->clear();
	for (int i = 0 ; i < listEDAT2.size(); ++i) {
		QFile::remove(listEDAT2[i].absoluteFilePath());
	}
	for (int i = 0; i < listTXT.size(); ++i) {
		QFile::remove(listTXT[i].absoluteFilePath());
	}
	thread = new StatusThread(e, true);

	connect(thread, SIGNAL(textAppend1(const QString&)), ui.statusTextEdit1, SLOT(append(const QString&)));
	//connect(thread, SIGNAL(textAppend2(const QString&)), ui.statusTextEdit2, SLOT(append(const QString&)));

	if (QDesktopServices::openUrl(QUrl::fromLocalFile(e->getFi().absoluteFilePath()))) {
	//if(1){
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

void ExperimentStatus::openLogFolder()
{
	qDebug() << "Open log folder";
	if (!QDesktopServices::openUrl(QUrl::fromLocalFile(log))) {
		QMessageBox::critical(this, tr("Fail to open"),
			QString("No Log files has been created yet"));
	}
}


void ExperimentStatus::stopThread() {

	if (thread != nullptr) {
		if (thread->getThreadFlag()) {
			QMessageBox::critical(this, "Paradigm abortion!",
				"Log files will not be saved!");
		}
		thread->setThreadFlag(false);
		if (thread->isFinished()) {
			qDebug() << "is finished";
			delete thread;
			thread = nullptr;
		}

	}

}
