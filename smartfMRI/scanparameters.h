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

	ScanParameters(QObject *parent = 0);
	ScanParameters(QString fileName, QObject *parent = 0);
	enum status
	{	CannotOpenTheFile,
		FileIncorrect,
		Successful,
		ParametersIncorrect
	};
	status read();
	status write();
	~ScanParameters();
	QList<QString> getAttributes();
	QList<QString> getValues();

private:
	QString parametersFileName;
	QList<QString> attributes;
	QList<QString> values;
};

#endif // SCANPARAMETERS_H
