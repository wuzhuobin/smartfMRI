#pragma once
#include <QObject>
#include <qdom.h>
#include <qfile.h>

class MyScanParameters : public QObject {
	Q_OBJECT

public:
	enum status
	{
		CannotOpenTheFile = 0,
		Successful = 1,
		FileIncorrect = 2,
		ParametersIncorrect = 3
	};

	MyScanParameters(QString fileName = QString(), QDomDocument doc = QDomDocument("SmartfMRIParameters"), 
		QObject * parent = Q_NULLPTR);
	~MyScanParameters();
	
	int initialize();
	int read();
	int write();

private:

	void setValue(QString key, int value);
	int getValue(QString key);

	//the file name of *.txt file
	QString m_parametersFileName;
	QDomDocument m_doc;
};
