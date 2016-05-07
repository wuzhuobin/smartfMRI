#ifndef STATUSTHREAD_H
#define STATUSTHREAD_H

#include <QThread>
#include <QDebug>
#include <QDateTime>
#include "experiment.h"

class StatusThread : public QThread
{

public:
	StatusThread(Experiment *e = nullptr, bool threadFlag = true);
	~StatusThread();
	void run();

	bool getThreadFlag();
	int setThreadFlag(bool threadFlat);

private:
	Experiment* e;
	QDir log;
	bool threadFlag;

};

#endif // STATUSTHREAD_H
