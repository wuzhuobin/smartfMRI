#ifndef MTHREAD_H
#define MTHREAD_H

#include <QThread>
#include <QMutex>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QTextStream>
#include <QTextEdit>

class MThread : public QThread
{
	Q_OBJECT

public:
	MThread(QString path = QString() , QObject *parent = nullptr);
	~MThread();
	QTextEdit* te = nullptr;

	void run();
	public slots:
	void stop();
signals:
	void textChange(const QString&);


private:
	QMutex mutex;
	QString path;

	bool stopFlag = false;
};

#endif // MTHREAD_H
