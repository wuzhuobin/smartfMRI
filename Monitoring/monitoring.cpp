#include "monitoring.h"

Monitoring::Monitoring(QWidget *parent)
	: QMainWindow(parent), path("D:/CCode/smartfMRI/smartfMRI/paradigm/PictureRT_Test2/PictureRT.ebs2"),
	thread(QFileInfo(path).absolutePath())
{
	ui.setupUi(this);
	thread.te = ui.textEdit;
	QObject::connect(ui.runPushButton, SIGNAL(clicked()), this, SLOT(runThread()));
	QObject::connect(ui.stopPushButton, SIGNAL(clicked()), &thread, SLOT(stop()));
	QObject::connect(&thread, SIGNAL(textChange(const QString&)), ui.textEdit, SLOT(append(const QString&)));

}

Monitoring::~Monitoring()
{

}

bool Monitoring::runThread() {

	if (QDesktopServices::openUrl(QUrl::fromLocalFile(path))) {
	//if(1){
		qDebug() << "run Thread";
		thread.start();
	}
	
	return true;
}