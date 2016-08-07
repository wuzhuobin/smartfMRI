#include "statusthread.h"

StatusThread::StatusThread(Experiment* e, bool threadFlag)
	: QThread(), e(e) ,threadFlag(threadFlag),
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
	emit textAppend1("Paradigm begins");
	emit textAppend1("...");
	QDateTime time;
	while (true) {
		QList<QFileInfo> listEDAT2 = e->getDir().entryInfoList(QStringList(e->getFi().baseName() + "-*-*.edat2"), QDir::Files);
		QList<QFileInfo> listTXT = e->getDir().entryInfoList(QStringList(e->getFi().baseName() + "-*-*.txt"), QDir::Files);
		qDebug() << QStringList(e->getFi().baseName() + "-*-*.edat2").size();
		qDebug() << QStringList(e->getFi().baseName() + "-*-*.txt").size();
		msleep(1000);
		QMutexLocker locker(&mutex);
		qDebug() << "keep Monitoring";
		if (listEDAT2.size() != 0) {
			threadFlag = false;
			if (copyLogFiles(listEDAT2, listTXT))
				qDebug() << "log copied succeeded";
			else
				qDebug() << "log copied failed";

		}
		if (listTXT.size() != 0) {
			qDebug() << listTXT[0].lastModified();
			if(updateLog(listTXT, time))
				qDebug() << time;
		}
		if (!threadFlag)	break;

	}

	emit textAppend1("Paradigm ends");
}

bool StatusThread::copyLogFiles(QList<QFileInfo> listEDAT2, QList<QFileInfo> listTXT)
{
	QString folderName(e->getFi().baseName() + (listEDAT2[0].created().toString("yyyyMMddhhmmss")));
	if (log.mkdir(folderName)) {
		for (int i = 0; i < listEDAT2.size(); ++i) {
			QFile::copy(listEDAT2[i].absoluteFilePath(), log.absolutePath() + "/" + folderName + "/" +
				folderName + ".edat2");
			QFileInfo edat2(log.absolutePath() + "/" + folderName + "/" + folderName + ".edat2");
			emit textAppend1("Log file: " + edat2.fileName());
			emit textAppend1("Location: " + edat2.absolutePath());
			qDebug() << "copy " << log.absolutePath() + "/" + folderName + "/" +
				folderName + ".edat2";
		}
		for (int i = 0; i < listTXT.size(); ++i) {
			QFile::copy(listTXT[i].absoluteFilePath(), log.absolutePath() + "/" + folderName + "/" +
				folderName + ".txt");
			QFileInfo txt(log.absolutePath() + "/" + folderName + "/" + folderName + ".txt");
			emit textAppend1("Log file: " + txt.fileName());
			emit textAppend1("Location: " + txt.absolutePath());
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
	QDateTime timeNew = QFileInfo(listTXT[0].absoluteFilePath()).lastModified();
	if (timeNew == time)	return false; 
	qDebug() << ++i;
	time = timeNew;
	QFile file(listTXT[0].absoluteFilePath());
	qDebug() << file.fileName();
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))	return false;
	QTextStream out(&file);
	QString fileContent(out.readAll());
	//emit textAppend2("\n");
	//emit textAppend2("*************************************************");
	//emit textAppend2("*********************UPDATE**********************");
	//emit textAppend2("*************************************************");
	//emit textAppend2("\n");
	//emit textAppend2(fileContent);
	//emit textAppend1(fileContent);
	emit textAppend1(LogFileData::change(fileContent).join("\n"));
	emit textAppend1("\n");
	emit textAppend1("*************************************************");
	emit textAppend1("*********************UPDATE**********************");
	emit textAppend1("*************************************************");
	emit textAppend1("\n");

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
