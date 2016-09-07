#include "experiment.h"


Experiment::Experiment(const QFileInfo fi, QObject * parent, EXPERIMENT_TYPE type)
	: QObject(parent),fi(fi), name(fi.absoluteDir().dirName()), type(type),
	dir(fi.absoluteDir()), sps1(fi.absolutePath() + "/myDummy.txt", this),
	sps2(fi.absolutePath() + "/myCycleList.txt", this),
	sps3(fi.absolutePath() + "/myBlockList.txt", this),
	sps4(fi.absolutePath() + "/myParameters.txt", this)

{
	if (sps4.getAttributes().contains("experiment type")) {
		if (sps4.getValue(0)[sps4.getAttributes().indexOf("experiment type")] == "clinical") {
			this->type = CLINICAL;
		}
		else {
			this->type = RESEARCH;
		}
	}
	else {
		sps4.getAttributes() += "experiment type";
		if (type == CLINICAL) {
			sps4.getValue(0) += "clinical";
		}
		else {
			sps4.getValue(0) += "research";
		}
	}
	qDebug() << "Experiment construction";
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

Experiment::EXPERIMENT_TYPE Experiment::getType()
{
	return this->type;
}

QString Experiment::getName() const
{
	return name;
}
