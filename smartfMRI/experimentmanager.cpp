#include "experimentmanager.hpp"

ExperimentManager::ExperimentManager(const QString paradigmFolder, QWidget * parent)
	: QDialog(parent), paradigmFolder(paradigmFolder)
{
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
	QDir beforeDir(paradigmFile.absolutePath());
	QDir targetDir(paradigmFolder);
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
		setParadigmFile(fil[0].absoluteFilePath());
		updataParadigm();
	}
	return 1;
}

int ExperimentManager::loadParadigm()
{
	ui.paradigmNameLineEdit->setText(paradigmFile.baseName());
	ui.experimentNameLineEdit->setText(paradigmFile.dir().dirName());
	if (spMod != nullptr) {
		delete spMod;
	} 
	if (e != nullptr) {
		delete e;
	} 
	e = new Experiment(paradigmFile, this);
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


int ExperimentManager::updataParadigm()
{
	if (e != nullptr) {
		delete e;
		e = nullptr;
	}
	e = new Experiment(paradigmFile, this);
	spMod->setValuesToExperiment(*e);
	if (ScanParameters::Successful == e->sps1.write() && ScanParameters::Successful == e->sps2.write() && 
		ScanParameters::Successful == e->sps3.write()) {
		qDebug() << "updataParadigm";
	}
	QDir dir = paradigmFile.dir();
	if (paradigmFile.dir().dirName() == ui.experimentNameLineEdit->text())
		return 1;
	if (dir.cdUp() && !dir.rename(paradigmFile.dir().dirName(), ui.experimentNameLineEdit->text())) {
		QMessageBox::critical(this, tr("Fail to rename experiment name"),
			QString("name has not been changed."));
		return 0;
	}
	else return 1;
}


int ExperimentManager::setParadigmFile(const QFileInfo paradigmFile)
{
	this->paradigmFile = paradigmFile;

	return 1;
}

QFileInfo ExperimentManager::getParadigmFile() const
{
	return this->paradigmFile;
}
