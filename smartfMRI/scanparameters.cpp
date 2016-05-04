#include "scanparameters.h"

ScanParameters::ScanParameters(QObject *parent)
	: QObject(parent)
{
	
}


ScanParameters::ScanParameters(QFileInfo fileName, QObject * parent):
	parametersFileName(fileName.absolutePath() + "/" + fileName.baseName() + ".txt")
{
	
	qDebug() << QFileInfo(parametersFileName).absoluteFilePath ();
	qDebug() << "ScanParameters construct";
		
}

ScanParameters::status ScanParameters::read()
{
	QFile file(parametersFileName);
	if (!attributes.isEmpty()) attributes.clear();
	if (!values.isEmpty()) values.clear();
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
		qFatal("Could not open the file");
		return ScanParameters::CannotOpenTheFile;
	}
	QStringList parameters(QString(file.readAll()).split("\n"));
	if (parameters.size() < 2) {
		parameters = (QString(file.readAll()).split("\n\r"));
		if (parameters.size() < 2) {
			qFatal("File incorrect");
			return ScanParameters::FileIncorrect;
		}

	}
	attributes = parameters[0].split(QRegExp("\\s"));
	values = parameters[1].split(QRegExp("\\s"));

	//if(attributes.size() != values.size())
	//	return ScanParameters::FileIncorrect;
	file.close();
	return ScanParameters::Successful;
}

bool ScanParameters::write()
{
	return false;
}

ScanParameters::~ScanParameters()
{
	qDebug() << "ScanParameters destruct";
	qDebug() << "";
	qDebug() << "";
	qDebug() << "";
	qDebug() << "";

}

QList<QString> ScanParameters::getAttributes()
{
	return attributes;
}

QList<QString> ScanParameters::getValues()
{
	return values;
}
