#include "smartfmri.h"

SmartfMRI::SmartfMRI(QWidget *parent)
	: QMainWindow(parent)
{
	//initialization UI setting
	qDebug() << "set up SmartfMRI UI.";
	ui.setupUi(this);
	if (dir.mkdir("paradigm")) 
		qDebug() << "paradigm directory created";
	expMod = new ExperimentModel(this, QDir(dir.path() + "/paradigm"));
	ui.experimentlistView->setModel(expMod);


	connect(ui.removeButton, SIGNAL(clicked()), this, SLOT(removeExperiment()));
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addExperiment()));
	connect(ui.runPushButton, SIGNAL(clicked()), this, SLOT(runExperiment()));
	connect(ui.updataPushButton, SIGNAL(clicked()), this, SLOT(updateExperiment()));
	connect(ui.experimentlistView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(selectExperiment(const QModelIndex&)));

}

SmartfMRI::~SmartfMRI()
{
	qDebug() << "Close SmartfMRI";
}

int SmartfMRI::removeExperiment()
{
	QDir dirr(ui.experimentlistView->
		currentIndex().data(Qt::ToolTipRole).toString());
	dirr.setFilter(QDir::NoDotAndDotDot);
	if (ui.experimentlistView->currentIndex().data().isValid() && dirr.removeRecursively()) {
		qDebug() << "remove successfully";
		delete expMod;
		expMod = new ExperimentModel(this, QDir(dir.path() + "/paradigm"));
		ui.experimentlistView->setModel(expMod);
		return 1;
	}
	else if (!ui.experimentlistView->currentIndex().data().isValid()) {
		QMessageBox::critical(this, tr("Fail to remove"),
			QString("Please select an item."));
		return 0;
	}
	else {
		QMessageBox::critical(this, tr("Fail to remove"),
			QString("Please remove ") + dirr.absolutePath() + " by yourself");
		return 0;
	}
}

int SmartfMRI::addExperiment() {

	QString fileName = QFileDialog::getOpenFileName(this, tr("Add Experiment"),
		QString(), tr("E-Run Script File (*.ebs2);; All files (*.*)"));
	if (fileName.isEmpty())
		return 0;
	expMan.setUpdataFlag(false);
	expMan.setBeforePath(fileName);
	expMan.setParadigmPath(dir.path() + "/paradigm/");
	qDebug() << expMan.getBeforePath() << "*******" << expMan.getParadigmPath();
	if (expMan.exec() == QDialog::Accepted) {
		if (expMod != nullptr) {
			delete expMod;
			expMod = new ExperimentModel(this, QDir(dir.path() + "/paradigm"));
			ui.experimentlistView->setModel(expMod);
		}
		return 1;
	}
	else {
		return 0;
	}

	//Experiment e(url, this);
	//qDebug() << &e;
	//qDebug() << e.getUrl().path();
	//expMod.insertRow(expMod.rowCount(), e);
	//expMod.insertRow(expMod.rowCount(), *new Experiment(url, this));


	return 1;
}

int SmartfMRI::runExperiment() {
	if (!ui.experimentlistView->currentIndex().data().isValid()) {
		QMessageBox::critical(this, tr("Fail to run"),
			QString("Please select an item."));
		return 0;
	}
	Experiment* e = expMod->getExperiment(ui.experimentlistView->
		currentIndex().data(Qt::DisplayRole).toString());
	if (QDesktopServices::openUrl(QUrl(e->getFi().absoluteFilePath()))) {
		qDebug() << "run";
		return 1;
	}
	else {
		QMessageBox::critical(this, tr("Fail to run"),
			QString("Cannot open the *.ebs2 file."));
		return 0;
	}

}

int SmartfMRI::updateExperiment()
{
	qDebug() << "update";
	return 0;
}

int SmartfMRI::selectExperiment(const QModelIndex& index)
{
	qDebug() << index.row();
	return 0;
}
