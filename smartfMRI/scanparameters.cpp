#include "scanparameters.h"

ScanParameters::ScanParameters(QString parametersFileName, QObject * parent)
	: QObject(parent), parametersFileName(parametersFileName)
{
	qDebug() << QFileInfo(parametersFileName).absoluteFilePath ();
	qDebug() << "ScanParameters construct";
	if(!QFileInfo(parametersFileName).exists())
		this->write();
	this->read();
}

ScanParameters::status ScanParameters::read()
{
	QFile file(parametersFileName);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
		return ScanParameters::CannotOpenTheFile;
	}
	QStringList parameters(QString(file.readAll()).split("\n"));

	if (parameters.size() < 2) {
		return ScanParameters::FileIncorrect;
	}
	for (int i = 1; i < parameters.size(); ++i) {
		values[i] = parameters[i].split("\t");
		while (values[i].size() < attributes.size()) {
			values[i] += QString('0');

		}
	}
	file.close();
	return ScanParameters::Successful;
}

ScanParameters::status ScanParameters::write()
{
	QFile file(parametersFileName);
	QTextStream in(&file);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
		return ScanParameters::CannotOpenTheFile;
	}
	if (attributes.isEmpty() || values.isEmpty())
		return ScanParameters::ParametersIncorrect;
	QString line1 = attributes.join('\t') + "\n";
	in << line1;
	for (int i = 0; i < values.size(); ++i) {
		in << values[i].join('\t') << "\n";
	}
	file.close();
	return ScanParameters::Successful;
}

ScanParameters::~ScanParameters()
{
	qDebug() << "ScanParameters destruct";
}

QStringList& ScanParameters::getAttributes()
{
	return attributes;
}

QList<QStringList>& ScanParameters::getValues()
{
	return values;
}
