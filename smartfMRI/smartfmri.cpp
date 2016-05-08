#include "smartfmri.h"

SmartfMRI::SmartfMRI(QWidget *parent)
	: QMainWindow(parent), expMan("./paradigm", parent)
{
	qDebug() << "set up SmartfMRI UI.";
	ui.setupUi(this);

	if (QDir::current().mkdir("paradigm")) 
		qDebug() << "SmartfMRI construct";
	expMod = new ExperimentModel(QDir("./paradigm"), this);
	ui.experimentlistView->setModel(expMod);

	connect(ui.removeButton, SIGNAL(clicked()), this, SLOT(removeExperiment()));
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addExperiment()));
	connect(ui.runPushButton, SIGNAL(clicked()), this, SLOT(runExperiment()));
	connect(ui.updataPushButton, SIGNAL(clicked()), this, SLOT(updateExperiment()));
	connect(ui.experimentlistView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(selectExperiment(const QModelIndex&)));

}

SmartfMRI::~SmartfMRI()
{
	qDebug() << "SmartfMRI destruct";
}

int SmartfMRI::removeExperiment()
{
	QDir dirToBeDeleted(ui.experimentlistView->
		currentIndex().data(Qt::ToolTipRole).toString());
	dirToBeDeleted.setFilter(QDir::NoDotAndDotDot);
	if (ui.experimentlistView->currentIndex().data().isValid() 
		&& dirToBeDeleted.removeRecursively()) {
		if (expMod != nullptr) {
			delete expMod;
		}
		expMod = new ExperimentModel(QDir("./paradigm"), this);
		ui.experimentlistView->setModel(expMod);

		qDebug() << "remove successfully";
		return 1;
	}
	else if (!ui.experimentlistView->currentIndex().data().isValid()) {
		QMessageBox::critical(this, tr("Fail to remove"),
			QString("Please select an item."));
		return 0;
	}
	else {
		QMessageBox::critical(this, tr("Fail to remove"),
			QString("Please remove ") + dirToBeDeleted.absolutePath() + " by yourself");
		return 0;
	}
}

int SmartfMRI::addExperiment() {

	QString filePath = QFileDialog::getOpenFileName(this, tr("Add Experiment"),
		QString(), tr("E-Run Script File (*.ebs2);; All files (*.*)"));
	if (filePath.isEmpty())
		return 0;
	expMan.setParadigmFile(QFileInfo(filePath));
	expMan.loadParadigm();
	if (expMan.exec() == QDialog::Accepted) {
		expMan.copyParadigm();
		if (expMod != nullptr) {
			delete expMod;
		}
		expMod = new ExperimentModel(QDir("./paradigm"), this);
		ui.experimentlistView->setModel(expMod);
		return 1;
	}
	else {
		return 0;
	}

}

int SmartfMRI::runExperiment() {
	if (!ui.experimentlistView->currentIndex().data().isValid()) {
		QMessageBox::critical(this, tr("Fail to run"),
			QString("Please select an item."));
		return 0;
	}
	Experiment* e = expMod->getExperiment(ui.experimentlistView->
		currentIndex().data(Qt::DisplayRole).toString());
	expSta.runExperiment(e);
	expSta.exec();
	return 1;

}

int SmartfMRI::updateExperiment()
{
	if (!ui.experimentlistView->currentIndex().data().isValid()) {
		QMessageBox::critical(this, tr("Fail to remove"),
			QString("Please select an item."));
		return 0;
	}
	qDebug() << "update";
	Experiment*e = expMod->getExperiment(ui.experimentlistView->
		currentIndex().data().toString());
	expMan.setParadigmFile(e->getFi().absoluteFilePath());
	expMan.loadParadigm();

	if (expMan.exec() == QDialog::Accepted) {
		expMan.updataParadigm();
		delete expMod;
		expMod = new ExperimentModel(QDir("./paradigm"), this);
		ui.experimentlistView->setModel(expMod);
		return 1;
	}
	else {
		return 0;
	}


}

int SmartfMRI::selectExperiment(const QModelIndex& index)
{
	Experiment* e = expMod->getExperiment(index.data().toString());
	if (spMod != nullptr) {
		delete spMod;
	}
	if (ScanParameters::Successful == e->sps1.read() && ScanParameters::Successful == e->sps2.read()) {
		e->sps3.read();
		spMod = new ScanParametersModel(*e, false, this);
	}
	else {
		spMod = new ScanParametersModel(this);
	}
	ui.scanParameterTableView->setModel(spMod);
	return 0;
}
