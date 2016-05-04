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
	QString folderName(ui.experimentNameLineEdit->text().remove(' '));
	if (targetDir.mkdir(folderName))
		qDebug() << " make directory" << folderName;
	qDebug() << beforeDir;
	qDebug() << targetDir;
	QCopyDirRecursively::copy(beforeDir.absolutePath(), targetDir.absolutePath() + "/" + folderName);
	this->accept();
	return 1;
}
