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
#include <QTextEdit>
#include "logfiledata.h"
#include "experiment.h"

class StatusThread : public QThread
{
	Q_OBJECT
public:
	StatusThread(Experiment *e = nullptr, bool threadFlag = true);
	~StatusThread();
	void run();

	bool copyLogFiles(QList<QFileInfo> listEDAT2, QList<QFileInfo> listTXT);
	bool updateLog(QList<QFileInfo> listTXT, QDateTime& time);
	bool getThreadFlag();
	int setThreadFlag(bool threadFlat);

signals:
	void textAppend1(const QString&);
	void textAppend2(const QString&);

private:
	Experiment* e;
	QDir log;
	QMutex mutex;
	bool threadFlag;
	int i = 0;

};

#endif // STATUSTHREAD_H
