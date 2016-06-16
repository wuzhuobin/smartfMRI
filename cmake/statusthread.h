#ifndef STATUSTHREAD_H
#define STATUSTHREAD_H

#include <QThread>
#include <QDebug>
#include <QDateTime>
#include <QListWidget>
#include <QMutex>
#include <QFileInfo>
#include <QDataStream>
#include <QFile>
#include <QTextEdit>
#include "logfiledata.h"
#include "experiment.h"
/**
 * @class StatusThread
 * monitoring the log file and read its data in real time 
 * when the experiment is running 
 */
class StatusThread : public QThread
{
	Q_OBJECT
public:
	/**
	 * constructor 
	 * @param e running experiment
	 * @param threadFlag whether the thread keeps running
	 */
	StatusThread(Experiment *e = nullptr, bool threadFlag = true);
	/**
	 * destructor
	 */
	~StatusThread();
	/**
	 * monitoring the log file
	 * @override
	 */
	void run();
	/**
	 * when the experiment e is finished running, *.edat2 file will exist in
	 * experiment e's folder. when this file exists, copy all log files to log folders
	 * @param listEDAT2 list of QFileInfo of the *.edat2 files
	 * @param listTXT list of QFileInfo of the *.txt files
	 * @return true succeed
	 *         false fail
	 */
	bool copyLogFiles(QList<QFileInfo> listEDAT2, QList<QFileInfo> listTXT);
	/**
	 * when the *.txt file is modified, it will reload its content and display it in a text 
	 * area. 
	 * @param listTXT *.txt files
	 * @param time modified time of *.txt file
	 */
	bool updateLog(QList<QFileInfo> listTXT, QDateTime& time);
	/**
	 * get the threadFlag
	 * @return threadFlag
	 */
	bool getThreadFlag();
	/**
	 * set threadFlag
	 * @param threadFlag 
	 * @return 1 succeed
	 *         0 fail 
	 */
	int setThreadFlag(bool threadFlat);

signals:
	/**
	 * @deprecated
	 */
	void textAppend1(const QString&);
	/**
	 * signals
	 * set the text area as QString of the *.txt file content 
	 */
	void textAppend2(const QString&);

private:
	// Experiment e to keep monitoring
	Experiment* e;
	// folde where the log files being copied to 
	QDir log;
	// mutex of threadFlag
	QMutex mutex;
	// true thread keep running, false thread stops
	bool threadFlag;
	// times of *.txt file modified
	int i = 0;

};

#endif // STATUSTHREAD_H
