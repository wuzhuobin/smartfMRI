#ifndef STATUSTHREAD_H
#define STATUSTHREAD_H

#include <QThread>
#include <QDebug>
#include <QDateTime>
#include <QListWidget>
#include <QMutex>
#include <QFileInfo>
#include <QDataStream>
#include <QFile>
#include "experiment.h"

class StatusThread : public QThread
{

public:
	StatusThread(QListWidget* statusListWidget = nullptr, Experiment *e = nullptr, bool threadFlag = true);
	~StatusThread();
	void run();

	bool copyLogFiles(QList<QFileInfo> listEDAT2, QList<QFileInfo> listTXT);
	bool updateLog(QList<QFileInfo> listTXT, QDateTime& time);
	bool getThreadFlag();
	int setThreadFlag(bool threadFlat);

private:
	QListWidget* statusListWidget;
	Experiment* e;
	QDir log;
	QMutex mutex;
	bool threadFlag;

};

#endif // STATUSTHREAD_H
