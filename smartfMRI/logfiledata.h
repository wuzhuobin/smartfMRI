#ifndef LOGFILEDATA_H
#define LOGFILEDATA_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QDateTime>

class LogFileData : public QObject
{
public:
	static QList<QString> change(QString fileContent);
};

#endif // LOGFILEDATA_H
