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



Experiment::Experiment(const QFileInfo fi, QObject * parent)
	: QObject(parent),fi(fi), name(fi.absoluteDir().dirName()), dir(fi.absoluteDir())
{
	//tr = 3000.0;
	//controlPeriod = 30000.0;
	//taskPeriod = 30000.0;
	//dummySamples = 2;
	//cycles = 4;
	//taskTrialPeriod = 4000.0;
	//controlTrialPeriod = 8000.0;

	qDebug() << "Experiment construction";
	qDebug() << this->dir;
	qDebug() << this->name;
	//qDebug() << this->dir;
}


Experiment::~Experiment()
{
	qDebug() << "Experiment destroied";
}



int Experiment::setName(const QString name) {
	if (this->name == name)
		return 0;
	this->name = name;
	return 1;

}

QDir Experiment::getDir() const
{
	return this->dir;
}

int Experiment::setDir(const QDir dir)
{
	this->dir = dir;
	return 1;
}

QFileInfo Experiment::getFi() const
{
	return this->fi;
}

int Experiment::setFi(const QFileInfo fi)
{
	this->fi = fi;
	return 1;
}

QString Experiment::getName() const
{
	return name;
}
