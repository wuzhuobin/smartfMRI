#ifndef SCANPARAMETERS_H
#define SCANPARAMETERS_H

#include <QObject>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QFile>

class ScanParameters : public QObject
{
public:
	enum status
	{
		CannotOpenTheFile,
		FileIncorrect,
		Successful,
		ParametersIncorrect
	};
	ScanParameters(QString fileName = QString(), QObject *parent = 0);
	status read();
	status write();
	~ScanParameters();
	
	QList<QString>& getAttributes();
	QList<QString>& getValues();

private:
	QString parametersFileName;
	QList<QString> attributes;
	QList<QString> values;
};

#endif // SCANPARAMETERS_H
