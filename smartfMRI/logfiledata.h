#ifndef LOGFILEDATA_H
#define LOGFILEDATA_H

#include <QObject>

class LogFileData : public QObject
{
public:
	LogFileData(QObject *parent);
	~LogFileData();
	static QList<QString> change(QString fileContent);

private:
	
};

#endif // LOGFILEDATA_H
