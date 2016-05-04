
#include <QtCore/QCoreApplication>
#include <QFileInfo>
#include "scanparameters.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QString path("D:/CCode/smartfMRI/smartfMRI/paradigm/PictureRT/PictureRT.ebs2");
	QFileInfo fi(path);

	ScanParameters para(a.parent(), fi);
	para.read();
	qDebug() << para.getAttributes();
	qDebug() << para.getValues();

	return a.exec();
}
