#include "scanparameters.h"

ScanParameters::ScanParameters(QString parametersFileName, QObject * parent)
	: QObject(parent), parametersFileName(parametersFileName), 
	fileStatus(this->read())
{
	qDebug() << QFileInfo(parametersFileName).absoluteFilePath ();
	qDebug() << "ScanParameters construct";
	//if(!QFileInfo(m_parametersFileName).exists())
	//	this->write();
}

int ScanParameters::read()
{
	QFile file(parametersFileName);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
		return ScanParameters::CannotOpenTheFile;
	}
	QStringList parameters(QString(file.readAll()).split("\n"));

	if (parameters.size() < 2) {
		return ScanParameters::FileIncorrect;
	}
	// the frist row is attributes valuses begin at the second row
	attributes = parameters[0].split("\t");
	for (int i = 1; i < parameters.size(); ++i) {
		values += parameters[i].split("\t");
		//while (values[i -1].size() < attributes.size()) {
		//	values[i - 1] += QString('0');

		//}
	}
	file.close();
	return ScanParameters::Successful;
}

int ScanParameters::write()
{
	QFile file(parametersFileName);
	QTextStream in(&file);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
		return ScanParameters::CannotOpenTheFile;
	}
	if (attributes.isEmpty() || values.isEmpty())
		return ScanParameters::FileIncorrect;
	QString line1 = attributes.join('\t') + "\n";
	in << line1;
	for (int i = 0; i < values.size(); ++i) {
		in << values[i].join('\t');
		if (i != values.size() - 1) {
			in << '\n';
		}
	}
	file.close();
	return ScanParameters::Successful;
}

int ScanParameters::getFileStatus()
{
	return fileStatus;
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

QStringList & ScanParameters::getValue(int row)
{
	while (values.size() <= row) {
		values += QStringList();
	}
	return values[row];
	// TODO: 在此处插入 return 语句
}
