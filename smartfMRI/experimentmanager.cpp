#include "experimentmanager.hpp"

ExperimentManager::ExperimentManager(QWidget * parent) 
	: QDialog(parent), spMod(nullptr), e(nullptr) {
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
	QDir beforeDir(beforeFile.absolutePath());
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
		setBeforeFile(fil[0].absoluteFilePath());
		updataParadigm();
	}
	return 1;
}

int ExperimentManager::loadParadigm()
{
	if (spMod != nullptr) {
		delete spMod;
		spMod = nullptr;
	} 
	if (e != nullptr) {
		delete e;
		e = nullptr;
	} 
	e = new Experiment(beforeFile, this);
	if (ScanParameters::Successful == e->sps1.read() && ScanParameters::Successful == e->sps2.read()
		) {
		e->sps3.read();
		spMod = new ScanParametersModel(*e, true, this);
	}
	else {
		spMod = new ScanParametersModel(this);
	}

	ui.scanParametersTableView->setModel(spMod);

	return 1;
}

int ExperimentManager::setBeforeFile(const QFileInfo beforeFile)
{
	this->beforeFile = beforeFile;
		ui.paradigmNameLineEdit->setText(beforeFile.baseName());
		ui.experimentNameLineEdit->setText(beforeFile.dir().dirName());
	return 1;
}

QFileInfo ExperimentManager::getBeforeFile() const
{
	return this->beforeFile;
}

int ExperimentManager::setParadigmPath(QString paradigmPath)
{
	this->paradigmPath = paradigmPath;
	return 1;
}

QString ExperimentManager::getParadigmPath() const 
{
	return paradigmPath;
}

int ExperimentManager::updataParadigm()
{
	if (e != nullptr) {
		delete e;
		e = nullptr;
	}
	e = new Experiment(beforeFile, this);
	e->sps1.read(); e->sps2.read(); e->sps3.read();
	spMod->setValuesToExperiment(*e);
	if (ScanParameters::Successful == e->sps1.write() && ScanParameters::Successful == e->sps2.write() && 
		ScanParameters::Successful == e->sps3.write()) {
		qDebug() << "updataParadigm";
	}
	QDir dir = beforeFile.dir();
	if (beforeFile.dir().dirName() == ui.experimentNameLineEdit->text())
		return 1;
	if (dir.cdUp() && !dir.rename(beforeFile.dir().dirName(), ui.experimentNameLineEdit->text())) {
		QMessageBox::critical(this, tr("Fail to rename experiment name"),
			QString("name has not been changed."));
		return 0;
	}
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


