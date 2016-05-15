#include "logfiledatawin.h"

LogFileDataWin::LogFileDataWin(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QString path = "C:/Users/jieji/Desktop/PictureRT-1-1.txt";
	QFile file(path);
	file.open(QIODevice::ReadOnly);
	QTextStream out(&file);
	QString fileContent = out.readAll();
	ui.textEdit->append(LogFileData::change(fileContent).join("\n"));
	qDebug() << LogFileData::change(fileContent).join("\n");

}

LogFileDataWin::~LogFileDataWin()
{

}
