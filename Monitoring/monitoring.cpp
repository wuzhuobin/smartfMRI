#include "monitoring.h"

Monitoring::Monitoring(QString filePath, QObject *parent)
	: QThread(parent), filePath(filePath)
{

}

Monitoring::~Monitoring()
{
	qDebug() << "thread destruct";
}

void Monitoring::run()
{
	QFile file(filePath);
	QFileInfo fileInfo(filePath);
	QString time = fileInfo.lastModified().toString("hh:mm:ss.zzz");
	int a = 0;
	QFile out("C:/Users/jieji/Desktop/a.txt");
	while (!stopFlag) {


		if (file.exists()) {
			qDebug() << "file exists";
			qDebug() << time;
			qDebug() << file.permissions();
			if ((time == QFileInfo(filePath).lastModified().toString("hh:mm:ss.zzz")))
				qDebug() << "The same";
			else {
				++a;
				out.open(QIODevice::Append);
				time = QFileInfo(filePath).lastModified().toString("hh:mm:ss.zzz");
				file.open(QIODevice::ReadOnly);
				qDebug() << "***********************************";
				out.write(file.readAll());
				qDebug() << "***********************************";
				file.close();
				out.close();
			}
		}
		msleep(100);
		qDebug() << QString::number(a);
	}
}

void Monitoring::stop()
{
	this->stopFlag = true;
}
