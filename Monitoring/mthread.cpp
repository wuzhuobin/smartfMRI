#include "mthread.h"

MThread::MThread(QString path, QObject* parent)
	: path(path), QThread(parent)
{
	qDebug() << "thread construct";
}

MThread::~MThread()
{
	qDebug() << "thread destuct";
}

void MThread::run()
{
	QFile file(path + "/PictureRT-1-1.txt");
	QDateTime time1 = QFileInfo(path + "/PictureRT-1-1.txt").lastModified();


	stopFlag = false;
	qDebug() << "run";
	int i = 0;
	while (1) {
		if (file.exists()) {
			qDebug() << "exist";
			QDateTime time2 = QFileInfo(path + "/PictureRT-1-1.txt").lastModified();
			QMutexLocker locker(&mutex);
			qDebug() << time2;
			if (time1 != time2 && file.open(QFile::ReadOnly | QFile::Text)) {
					QTextStream out(&file);
				qDebug() << ++i;
				emit textChange("*************************");
				emit textChange( out.readAll());
				file.close();
				time1 = time2;
			}
			if (stopFlag)	break;
			
			this->msleep(1000);
		}
	}

}

void MThread::stop() {
	QMutexLocker locker(&mutex);
	stopFlag = true;
}
