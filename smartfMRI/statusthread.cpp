#include "statusthread.h"

StatusThread::StatusThread(Experiment* e, bool threadFlag)
	: QThread(),e(e) ,threadFlag(threadFlag), log(e->getDir().absolutePath() + "/log")
{
	if (!QDir(e->getDir().absolutePath() + "/log").exists()) {
		e->getDir().mkdir("log");
	}
}



StatusThread::~StatusThread()
{
	qDebug() << "StatusThread desctruct";
}

void StatusThread::run()
{
	while (threadFlag) {
		QFileInfoList listEDAT2 = e->getDir().entryInfoList(QStringList(e->getFi().baseName() + "-*-*.edat2"), QDir::Files);
		QFileInfoList listTXT = e->getDir().entryInfoList(QStringList(e->getFi().baseName() + "-*-*.txt"), QDir::Files);
		if (listEDAT2.size() != 0) {
			threadFlag = false;
			QString folderName(e->getFi().baseName() + (listEDAT2[0].created().toString("yyyyMMddhhmmss")));
			if (log.mkdir(folderName)) {
				for (int i = 0; i < listEDAT2.size(); ++i) {
					QFile::copy(listEDAT2[i].absoluteFilePath(), log.absolutePath() + "/" + folderName + "/" +
						folderName + ".edat2");
					qDebug() << "copy " << log.absolutePath() + "/" + folderName + "/" +
						folderName + ".edat2";
				}
				for (int i = 0; i < listTXT.size(); ++i) {
					QFile::copy(listTXT[i].absoluteFilePath(), log.absolutePath() + "/" + folderName + "/" + 
						folderName + ".txt");
					qDebug() << "copy " << log.absolutePath() + "/" + folderName + "/" +
						folderName + ".txt";
				}			
			}

		}
		qDebug() << "keep watching";
		msleep(500);
	}

}

bool StatusThread::getThreadFlag()
{
	return this->threadFlag;
}



int StatusThread::setThreadFlag(bool threadFlag)
{
	this->threadFlag = threadFlag;
	return 1;
}
