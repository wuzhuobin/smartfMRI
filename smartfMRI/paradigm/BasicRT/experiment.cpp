#include "experiment.h"

Experiment::Experiment(QObject *parent)
	: QObject(parent)
{

}

//Experiment::Experiment(const Experiment & e)
//{
//	this->name = e.name;
//	this->url = e.url;
//	qDebug() << "NEW EXPERIMENT";
//}


Experiment::Experiment(const QUrl url, QObject *parent)
	: QObject(parent), url(url), name(url.fileName().split('.').constFirst()), dir(QDir(url.path().remove(url.fileName())))
{
	tr = 3000.0;
	controlPeriod = 30000.0;
	taskPeriod = 30000.0;
	dummySamples = 2;
	cycles = 4;
	taskTrialPeriod = 4000.0;
	controlTrialPeriod = 8000.0;

	qDebug() << "Experiment construction";
	qDebug() << this->url;
	qDebug() << this->name;
	//qDebug() << this->dir;
}


Experiment::~Experiment()
{
	qDebug() << "Experiment destroied";
}

int Experiment::setUrl(const QUrl url) {
	if (this->url == url)
		return 0;
	this->url = url;
	return 1;
}

int Experiment::setName(const QString name) {
	if (this->name == name)
		return 0;
	this->name = name;
	return 1;

}

QUrl Experiment::getUrl() {
	return this->url;
}

QString Experiment::getName() {
	return name;
}
