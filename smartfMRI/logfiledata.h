#ifndef LOGFILEDATA_H
#define LOGFILEDATA_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QDateTime>
/**
 * transform function
 * transform the Log file to a readable format
 * only on static funtion
 * @authro
 * @version
 */
class LogFileData : public QObject
{
public:
	/**
	 * static function
	 * doing format transformation
	 * @param fileContent all file content of a log
	 * @retrun each item of QList is a row QString
	 */
	static QList<QString> change(QString fileContent);
};

#endif // LOGFILEDATA_H
