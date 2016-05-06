#include "scanparameters.h"

ScanParameters::ScanParameters(QObject *parent)
	: QObject(parent)
{
	
}


ScanParameters::ScanParameters(QString fileName, QObject * parent):
	parametersFileName(fileName)
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
		return ScanParameters::CannotOpenTheFile;
	}
	QStringList parameters(QString(file.readAll()).split("\n"));

	if (parameters.size() < 2) {
		return ScanParameters::FileIncorrect;
	}

	attributes = parameters[0].split("\t");
	values = parameters[1].split("\t");
	while (values.size() < attributes.size()) {
		values += QString('0');
	}
	//if(attributes.size() != values.size())
	//	return ScanParameters::FileIncorrect;
	file.close();
	return ScanParameters::Successful;
}

ScanParameters::status ScanParameters::write()
{
	QFile file(parametersFileName);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
		return ScanParameters::CannotOpenTheFile;
	}
	if (attributes.isEmpty() || values.isEmpty() || attributes.size() != values.size())
		return ScanParameters::ParametersIncorrect;
	QString line1 = attributes.join('\t') + "\n";
	QString line2 = values.join('\t');
	QTextStream(&file) << line1 << line2;
	file.close();
	return ScanParameters::Successful;
}

ScanParameters::~ScanParameters()
{
	qDebug() << "ScanParameters destruct";
}

QList<QString> ScanParameters::getAttributes()
{
	return attributes;
}

QList<QString> ScanParameters::getValues()
{
	return values;
}
