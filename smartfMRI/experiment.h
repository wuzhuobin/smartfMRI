#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <QObject>
#include <qurl.h>

class Experiment : public QObject
{
	Q_OBJECT

public:
	Experiment(QObject *parent);
	Experiment(const QUrl url, QObject *parent = 0);
	~Experiment();

	QUrl getUrl();
	QString getName();
	
public slots:
	int setUrl(const QUrl url);
	int setName(const QString name);

private:
	QUrl url;
	QString name;
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
