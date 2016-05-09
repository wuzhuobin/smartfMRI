#ifndef STATUSTHREAD_H
#define STATUSTHREAD_H

#include <QThread>
#include <QDebug>
#include <QDateTime>
#include <QListWidget>
#include "experiment.h"

class StatusThread : public QThread
{

public:
	StatusThread(QListWidget* statusListWidget = nullptr, Experiment *e = nullptr, bool threadFlag = true);
	~StatusThread();
	void run();

	bool getThreadFlag();
	int setThreadFlag(bool threadFlat);

private:
	QListWidget* statusListWidget;
	Experiment* e;
	QDir log;
	bool threadFlag;

};

#endif // STATUSTHREAD_H
