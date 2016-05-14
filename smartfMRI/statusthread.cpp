#include "statusthread.h"

StatusThread::StatusThread(QListWidget* statusListWidget, Experiment* e, bool threadFlag)
	: QThread(), statusListWidget(statusListWidget), e(e) ,threadFlag(threadFlag), 
	log(e->getDir().absolutePath() + "/log")
{
	if (!QDir(e->getDir().absolutePath() + "/log").exists()) {
		e->getDir().mkdir("log");
	}
}



StatusThread::~StatusThread()
{
	qDebug() << "StatusThread desctruct";
}

void StatusThread::run()
{
	statusListWidget->clear();
	statusListWidget->addItem("Paradigm begins");
	statusListWidget->addItem("...");
	QDateTime time;
	while (1) {
		QList<QFileInfo> listEDAT2 = e->getDir().entryInfoList(QStringList(e->getFi().baseName() + "-*-*.edat2"), QDir::Files);
		QList<QFileInfo> listTXT = e->getDir().entryInfoList(QStringList(e->getFi().baseName() + "-*-*.txt"), QDir::Files);
		msleep(500);
		QMutexLocker locker(&mutex);
		if (!threadFlag)	break;
		qDebug() << "keep Monitoring";
		if (listEDAT2.size() != 0) {
			threadFlag = false;
			if (copyLogFiles(listEDAT2, listTXT))
				qDebug() << "log copied succeeded";
			else
				qDebug() << "log copied failed";

		}
		if (listTXT.size() != 0) {
			if(updateLog(listTXT, time))
				qDebug() << time;
		}

	}

	statusListWidget->addItem("Paradigm ends");
}

bool StatusThread::copyLogFiles(QList<QFileInfo> listEDAT2, QList<QFileInfo> listTXT)
{
	QString folderName(e->getFi().baseName() + (listEDAT2[0].created().toString("yyyyMMddhhmmss")));
	if (log.mkdir(folderName)) {
		for (int i = 0; i < listEDAT2.size(); ++i) {
			QFile::copy(listEDAT2[i].absoluteFilePath(), log.absolutePath() + "/" + folderName + "/" +
				folderName + ".edat2");
			QFileInfo edat2(log.absolutePath() + "/" + folderName + "/" + folderName + ".edat2");
			statusListWidget->addItem("Log file: " + edat2.fileName());
			statusListWidget->addItem("Location: " + edat2.absolutePath());
			qDebug() << "copy " << log.absolutePath() + "/" + folderName + "/" +
				folderName + ".edat2";
		}
		for (int i = 0; i < listTXT.size(); ++i) {
			QFile::copy(listTXT[i].absoluteFilePath(), log.absolutePath() + "/" + folderName + "/" +
				folderName + ".txt");
			QFileInfo txt(log.absolutePath() + "/" + folderName + "/" + folderName + ".txt");
			statusListWidget->addItem("Log file: " + txt.fileName());
			statusListWidget->addItem("Location: " + txt.absolutePath());
			qDebug() << "copy " << log.absolutePath() + "/" + folderName + "/" +
				folderName + ".txt";
		}
		return true;
	}
	else {
		return false;
	}
}

bool StatusThread::updateLog(QList<QFileInfo> listTXT, QDateTime& time)
{
	QDateTime timeNew = listTXT[0].lastModified();
	if (timeNew == time)	return false; 
	time = timeNew;
	QFile file(listTXT[0].absoluteFilePath());
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))	return false;
	QTextStream out(&file);
	statusListWidget->addItem(out.readAll());
	file.close();
	return true;

	

}

bool StatusThread::getThreadFlag()
{
	return this->threadFlag;
}



int StatusThread::setThreadFlag(bool threadFlag)
{
	QMutexLocker locker(&mutex);
	this->threadFlag = threadFlag;
	return 1;
}
