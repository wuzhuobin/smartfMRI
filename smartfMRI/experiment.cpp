#include "experiment.h"


Experiment::Experiment(const QFileInfo fi, QObject * parent)
	: QObject(parent),fi(fi), name(fi.absoluteDir().dirName()), 
	dir(fi.absoluteDir()), sps1(fi.absolutePath() + "/myBlockList.txt", this),
	sps2(fi.absolutePath() + "/myTrialListParameters.txt", this),
	sps3(fi.absolutePath() + "/otherParameters.txt", this)
{

	qDebug() << "Experiment construction";
	qDebug() << this->dir;
	qDebug() << this->name;
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
