#ifndef MONITORING_H
#define MONITORING_H

#include <QThread>
#include <QDebug>
#include <QFileInfo>
#include <QFile>
#include <QDateTime>


class Monitoring : public QThread
{
	Q_OBJECT

public:
	Monitoring(QString filePath = QString(), QObject *parent = 0);
	~Monitoring();

	void run();
public slots:
	void stop();

private:
	bool stopFlag = false;
	QString filePath;
};

#endif // MONITORING_H
