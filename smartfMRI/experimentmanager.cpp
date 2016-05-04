#include "experimentmanager.hpp"

ExperimentManager::ExperimentManager(QWidget * parent) : QDialog(parent) {
	qDebug() << "set up ExperimentManager UI.";
	ui.setupUi(this);
	
	ui.scanParametersTableView->setModel(new ScanParametersModel(this));
	connect(ui.confirmPushButton, SIGNAL(clicked()), this, SLOT(copyParadigm()));
}

int ExperimentManager::setBeforePath(QString beforePath)
{
	this->beforePath = beforePath;
		ui.paradigmNameLineEdit->setText(QFileInfo(beforePath).baseName());
		ui.experimentNameLineEdit->setText(QFileInfo(beforePath).baseName());
	return 1;
}

QString ExperimentManager::getBeforePath()
{
	return this->beforePath;
}

int ExperimentManager::setParadigmPath(QString paradigmPath)
{
	this->paradigmPath = paradigmPath;
	return 1;
}

QString ExperimentManager::getParadigmPath()
{
	return paradigmPath;
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
	QDir beforeDir(QFileInfo(beforePath).absolutePath());
	QDir targetDir(paradigmPath);
	if (targetDir.mkdir(ui.experimentNameLineEdit->text()))
		qDebug() << " make directory" << ui.experimentNameLineEdit->text();
	qDebug() << beforeDir;
	qDebug() << targetDir;
	QCopyDirRecursively::copy(beforeDir.absolutePath(), targetDir.absolutePath() + "/" + ui.experimentNameLineEdit->text());
	//QFile experiment(targetDir.entryList(QStringList() << ui.paradigmNameLineEdit->text() << ".ebs2")[0]);
	//if (experiment.rename(ui.experimentNameLineEdit->text() + ".ebs2")) {
	//	qDebug() << ui.paradigmNameLineEdit->text() << "Rename successful to ." << ui.experimentNameLineEdit->text();
	//}
	//QFileInfoList files = beforeDir.entryInfoList();
	//
	//for (int i = 0; i < files.size(); ++i) {
	//	
	//	QFile targetFile(targetDir.path() + "/" + ui.paradigmNameLineEdit->text() + "/" + files[i].fileName());
	//	QFile beforeFile(files[i].absoluteFilePath());

	//	if (targetFile.exists())
	//		targetFile.remove();
	//	
	//	if (beforeFile.copy(targetFile.fileName()))
	//		qDebug() << files[i].absoluteFilePath() << "copied";
	//	
	//	if (files[i].absoluteFilePath().contains(".ebs2", Qt::CaseInsensitive)) {
	//		Experiment newE(files[i].absoluteFilePath(), this);
	//	}
	//		

	//}
	this->accept();
	return 1;
}
