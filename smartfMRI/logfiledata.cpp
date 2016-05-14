#include "logfiledata.h"

LogFileData::LogFileData(QObject *parent)
	: QObject(parent)
{

}

LogFileData::~LogFileData()
{

}

QList<QString> LogFileData::change(QString fileContent)
{
	return QList<QString>();
}
