#include "monitor.h"

Monitor::Monitor(QString path, QObject *parent)
	: path(path), QObject(parent)
{

}

Monitor::~Monitor()
{

}

bool Monitor::stop()
{
	stopFlag = true;
	return false;
}

bool Monitor::loop()
{
	while (true)
	{
		if (stopFlag)	break;
		qDebug() << "looping";
		qDebug() << path;
	}
	return false;
}
