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
	ScanParameters(QObject *parent);
	ScanParameters(QObject *parent, QFileInfo fileName);
	enum status
	{	CannotOpenTheFile,
		FileIncorrect,
		Successful
	};
	status read();
	bool write();
	~ScanParameters();
	QList<QString> getAttributes();
	QList<QString> getValues();

private:
	QString parametersFileName;
	QList<QString> attributes;
	QList<QString> values;
};

#endif // SCANPARAMETERS_H
