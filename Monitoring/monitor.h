#ifndef MONITOR_H
#define MONITOR_H

#include <QObject>
#include <QDebug>

class Monitor : public QObject
{
	Q_OBJECT

public:
	Monitor(QString path = QString(), QObject *parent = nullptr);
	~Monitor();
	public slots:
	bool stop();
	bool loop();

private:
	QString path;
	bool stopFlag = false;
};

#endif // MONITOR_H
