#include "experiment.h"

Experiment::Experiment(QObject *parent)
	: QObject(parent)
{

}


Experiment::Experiment(const QUrl url, QObject *parent)
	: QObject(parent), url(url)
{
	name = url.fileName().split('.').constFirst();
}


Experiment::~Experiment()
{

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
