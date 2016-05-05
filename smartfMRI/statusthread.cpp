#include "statusthread.h"

StatusThread::StatusThread(Experiment* e, bool threadFlag)
	: QThread(),e(e) ,threadFlag(threadFlag)
{

}



StatusThread::~StatusThread()
{
	qDebug() << "StatusThread desctruct";
}

void StatusThread::run()
{
	while (threadFlag) {
		qDebug() << e->getName();
		sleep(1);
	}
}

bool StatusThread::getThreadFlag()
{
	return this->threadFlag;
}



int StatusThread::setThreadFlag(bool threadFlag)
{
	this->threadFlag = threadFlag;
	return 1;
}
