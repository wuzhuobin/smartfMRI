
#include <QtCore/QCoreApplication>
#include "monitoring.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QString file("D:/smart fMRI/PictureRT_Test2/PictureRT-1-1.txt");
	Monitoring m(file, 0);
	m.start();

	return a.exec();
}
