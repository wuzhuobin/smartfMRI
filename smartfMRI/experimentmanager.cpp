#include "experimentmanager.hpp"

ExperimentManager::ExperimentManager(QWidget * parent) : QDialog(parent) {
	qDebug() << "set up ExperimentManager UI.";
	ui.setupUi(this);

	//connect(ui.confirmPushButton, SIGNAL(clicked()), this, SIGNAL(t))
	connect(ui.confirmPushButton, SIGNAL(clicked()), this, SLOT(copyParadigm()));
}

int ExperimentManager::setBeforeUrl(QUrl url)
{
	this->beforeUrl = url;
		ui.paradigmNamelineEdit->setText(url.fileName().split('.').constFirst());
		ui.experimentNameLineEdit->setText(url.fileName().split('.').constFirst());
	return 1;
}

QUrl ExperimentManager::getBeforeUrl()
{
	return this->beforeUrl;
}

int ExperimentManager::setParadigmUrl(QUrl url)
{
	this->paradigmUrl = url;
	return 1;
}

QUrl ExperimentManager::getParadigmUrl()
{
	return paradigmUrl;
}

ExperimentManager::~ExperimentManager() {
	qDebug() << " Close ExperimentManager";
}

int ExperimentManager::setUpdataFlag(bool flag)
{
	this->updataFlag = flag;
	return 1;
}

bool ExperimentManager::getUpdataFlag()
{
	return this->updataFlag;
}

int ExperimentManager::copyParadigm()
{
	if (getUpdataFlag() == true)
		return 0;
	qDebug() << "Copy Paradigm>>>";
	QDir beforeDir(beforeUrl.path().remove(beforeUrl.fileName()).remove(0,1));
	QDir targetDir(paradigmUrl.path());
	if (targetDir.mkdir(ui.paradigmNamelineEdit->text()))
		qDebug() << " make directory" << ui.paradigmNamelineEdit->text();
	qDebug() << beforeDir;
	qDebug() << targetDir;
	QFileInfoList files = beforeDir.entryInfoList(QDir::Files);
	
	for (int i = 0; i < files.size(); ++i) {
		QFile targetFile(targetDir.path() + "/" + ui.paradigmNamelineEdit->text() + "/" + files[i].fileName());
		QFile beforeFile(files[i].absoluteFilePath());
		if (targetFile.exists())
			targetFile.remove();
		if (beforeFile.copy(targetFile.fileName()))
			qDebug() << files[i].absoluteFilePath() << "copied";

	}
	this->accept();
	return 1;
}
