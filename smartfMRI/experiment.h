#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <QObject>
#include <QDir>
#include <QUrl>
#include <QDebug>

class Experiment : public QObject
{
	
public:
	Experiment(QObject *parent = 0);
	//Experiment(const Experiment& e);
	Experiment(const QUrl url, QObject *parent = 0);
	~Experiment();

	QUrl getUrl();
	QString getName();
	int setUrl(const QUrl url);
	int setName(const QString name);

private:
	QUrl url;
	QString name;
	QDir dir;
	/*
	more parameter should be insert here
	following is the parameter
	tr
	control period
	task period
	dummy samples
	cycles
	task trial period
	control trail period
	scan time
	*/
	
};

#endif // EXPERIMENT_H
