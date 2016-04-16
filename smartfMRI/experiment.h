#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <QObject>

class Experiment : public QObject
{
	Q_OBJECT

public:
	Experiment(QObject *parent);
	Experiment(const QString URL, QObject *parent = 0);
	~Experiment();

	QString getURL();
	QString getName();
	
public slots:
	int setURL(const QString URL);
	int setName(const QString name);

private:
	QString URL;
	QString name;
	
};

#endif // EXPERIMENT_H
