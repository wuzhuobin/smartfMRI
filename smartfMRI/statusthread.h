#ifndef STATUSTHREAD_H
#define STATUSTHREAD_H

#include <QThread>
#include <QDebug>
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
	bool threadFlag;

};

#endif // STATUSTHREAD_H
