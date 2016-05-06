#include "experimentmanager.hpp"

ExperimentManager::ExperimentManager(QWidget * parent) 
	: QDialog(parent), spMod() {
	qDebug() << "set up ExperimentManager UI.";
	ui.setupUi(this);
	
	connect(ui.confirmPushButton, SIGNAL(clicked()), this, SLOT(accept()));
}

ExperimentManager::~ExperimentManager() {
	qDebug() << " Close ExperimentManager";
}

int ExperimentManager::copyParadigm()
{
	qDebug() << "Copy Paradigm>>>";
	QDir beforeDir(QFileInfo(beforeFilePath).absolutePath());
	QDir targetDir(paradigmPath);
	QString folderName(ui.experimentNameLineEdit->text().remove(' '));
	if (targetDir.mkdir(folderName))
		qDebug() << " make directory" << folderName;
	qDebug() << beforeDir;
	qDebug() << targetDir;
	QCopyDirRecursively::copy(beforeDir.absolutePath(), targetDir.absolutePath() + "/" + folderName);

	QFileInfoList fil(QDir(targetDir.absolutePath() + "/" + folderName).entryInfoList(
		QStringList("*.ebs2")));
	if (fil.size() > 0) {
		qDebug() << fil[0].absoluteFilePath();
		Experiment e(QFileInfo(fil[0].absoluteFilePath()), this);

	}
	return 1;
}

int ExperimentManager::loadParadigm()
{
	Experiment* e = new Experiment(QFileInfo(beforeFilePath), this);
	if (spMod != nullptr) delete spMod;

	if (ScanParameters::Successful == e->sps1.read() && ScanParameters::Successful == e->sps2.read()) {

		spMod = new ScanParametersModel(*e, true, this);
	}
	else {
		spMod = new ScanParametersModel(this);
	}

	ui.scanParametersTableView->setModel(spMod);

	return 1;
}

int ExperimentManager::setBeforeFilePath(QString beforePath)
{
	this->beforeFilePath = beforePath;
		ui.paradigmNameLineEdit->setText(QFileInfo(beforePath).baseName());
		ui.experimentNameLineEdit->setText(QFileInfo(beforePath).baseName());
	return 1;
}

QString ExperimentManager::getBeforeFilePath()
{
	return this->beforeFilePath;
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

int ExperimentManager::updataParadigm()
{
	return 1;
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


