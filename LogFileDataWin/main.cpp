#include "logfiledatawin.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LogFileDataWin w;
	w.show();
	return a.exec();
}
