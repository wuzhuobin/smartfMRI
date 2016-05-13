#include "monitoring.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Monitoring w;
	w.show();
	return a.exec();
}
