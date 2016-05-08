#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <QObject>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include "scanparameters.h"

class Experiment : public QObject
{
	
public:
	Experiment(QObject *parent = 0);
	Experiment(const QFileInfo fi, QObject *parent = 0);
	~Experiment();

	QString getName() const;
	int setName(const QString name);

	QDir getDir() const;
	int setDir(const QDir dir);

	QFileInfo getFi() const;
	int setFi(const QFileInfo fi);

	ScanParameters sps1;
	ScanParameters sps2;
	ScanParameters sps3;

	
private:
	QString name;
	QDir dir;
	QFileInfo fi;

};

#endif // EXPERIMENT_H
