#include "smartfmri.h"
#include <QtWidgets/QApplication>



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	SmartfMRI w;
	w.show();
	return a.exec();
}
