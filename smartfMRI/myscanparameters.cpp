#include "myscanparameters.hpp"

#include <qtextstream.h>

#include "experiment.h"

MyScanParameters::MyScanParameters(QString fileName, QDomDocument doc, QObject * parent) 
	:m_parametersFileName(fileName), m_doc(doc), QObject(parent) {
}

MyScanParameters::~MyScanParameters() {
	
}

int MyScanParameters::initialize()
{
	QFile file(m_parametersFileName);
	if (!file.open(QFile::WriteOnly | QFile::Text)) {
		return CannotOpenTheFile;
	}
	setValue("experimentType", (Experiment::NOT_DEFINE));
	setValue("tr", 3000);
	setValue("numberOfDummyScans", 2);
	setValue("numberOfCycles", 5);
	setValue("numberOfDynamicsPerTaskBlock", 10);
	setValue("durationOfTaskTrail", 3000);
	setValue("numberOfDynamicsPerRestBlock", 10);
	setValue("durationOfResetTrail", 3000);
	/*
	Scan time = ((Number of cycles * (Number of dynamics per task block + Number of dynamics per rest block)) + Number of dummy scans) * TR
	*/
	setValue("scanTime", 1);

	QTextStream(&file) << m_doc.toString();
	file.close();


	return Successful;
}

int MyScanParameters::read()
{
	QFile file(m_parametersFileName);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		return CannotOpenTheFile;
	}
	QString err;
	int l, c;
	//qDebug() << QTextStream(&file).readAll();
	if (!m_doc.setContent(QTextStream(&file).readAll(), &err, &l,&c)) {
		qDebug() << err << ' ' << l << ' ' << c;
		file.close();
		return FileIncorrect;
	}

	file.close();

	return Successful;
}

int MyScanParameters::write()
{
	return 0;
}

void MyScanParameters::setValue(QString key, int value)
{
	if (m_doc.documentElement().isNull()) {
		qDebug() << m_doc.localName();
		m_doc.appendChild(m_doc.createElement(m_doc.doctype().name()));
	}
	QDomElement parameters = m_doc.createElement(key);
	parameters.setAttribute("Parameter", value);
	m_doc.documentElement().appendChild(parameters);


}

int MyScanParameters::getValue(QString key)
{
	QDomElement root = m_doc.documentElement();
	if (root.isNull()) {
		return -1;
	}
	if (root.elementsByTagName(key).isEmpty()) {
		return -1;
	}
	return root.elementsByTagName(key).item(0).toElement().attributeNode("Parameter").value().toInt();

}
