#include "smartfmri.h"

#include "about.hpp"

#include <QMessageBox>

SmartfMRI::SmartfMRI(QWidget *parent)
	: QMainWindow(parent), expMan("./paradigm", parent)
{
	qDebug() << "set up SmartfMRI UI.";
	ui.setupUi(this);
	this->setWindowIcon(QIcon(":/smartfMRI/pm.ico"));
	if (QDir::current().mkdir("paradigm")) 
		qDebug() << "SmartfMRI construct";
	expMod = new ExperimentModel(QDir("./paradigm"), this);
	ui.experimentlistView->setModel(expMod);

	connect(ui.removeButton, SIGNAL(clicked()), this, SLOT(removeExperiment()));
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addExperiment()));
	connect(ui.runPushButton, SIGNAL(clicked()), this, SLOT(runExperiment()));
	connect(ui.updataPushButton, SIGNAL(clicked()), this, SLOT(updateExperiment()));
	connect(ui.logPushButton, SIGNAL(clicked()), this, SLOT(openLogFolder()));
	connect(ui.experimentlistView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(selectExperiment(const QModelIndex&)));
	connect(ui.aboutPushButton, SIGNAL(clicked()), this, SLOT(openAbout()));
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
	QMessageBox sureToDelete;
	sureToDelete.setIcon(QMessageBox::Question);
	sureToDelete.setText("Are you sure to remove this Experiment?\n"
		"It will remove all data(including paradigm, parameters, log, etc)"
		" in this experiment folder and cannot be recovered!");
	sureToDelete.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	sureToDelete.setDefaultButton(QMessageBox::No);
	
	if (sureToDelete.exec() == QMessageBox::Yes) {
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
	return 0;
}

int SmartfMRI::addExperiment() {

	QString filePath = QFileDialog::getOpenFileName(this, tr("Add Experiment"),
		QString(), tr("E-Run Script File (*.ebs2);; All files (*.*)"));
	if (filePath.isEmpty())
		return 0;
	QMessageBox experimentTypeQuestionBox;
	experimentTypeQuestionBox.setIcon(QMessageBox::Question);
	experimentTypeQuestionBox.setText("Please select your paradigm type."
		"Clinical or Research\n");
	experimentTypeQuestionBox.setInformativeText(
		"Research paradigm: parameters are unchagngeable alterable\n"
		"Clinical paradigm: parameters are alterable\n");
	QPushButton *clinicalButton = experimentTypeQuestionBox.addButton(tr("Clinical"), QMessageBox::YesRole);
	QPushButton *reserachButton = experimentTypeQuestionBox.addButton(tr("Research"), QMessageBox::NoRole);
	experimentTypeQuestionBox.exec();
	
	int experimentType;
	// research paradigm
	if (experimentTypeQuestionBox.clickedButton() == clinicalButton) {
		experimentType = Experiment::CLINICAL;
	}
	else if (experimentTypeQuestionBox.clickedButton() == reserachButton) {
		experimentType = Experiment::RESEARCH;
	}
	else {
		return 0;
	}
	expMan.setParadigmFile(QFileInfo(filePath));
	expMan.loadParadigm(experimentType);
	if (expMan.exec() == QDialog::Accepted) {
		expMan.copyParadigm(experimentType);
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
		QMessageBox::critical(this, tr("Fail to update"),
			QString("Please select an item."));
		return 0;
	}
	qDebug() << "update";
	Experiment*e = expMod->getExperiment(ui.experimentlistView->
		currentIndex().data().toString());
	expMan.setParadigmFile(e->getFi().absoluteFilePath());
	// using its own type
	expMan.loadParadigm(e->getType());

	if (expMan.exec() == QDialog::Accepted) {
		expMan.updataParadigm(e->getType());
		delete expMod;
		expMod = new ExperimentModel(QDir("./paradigm"), this);
		ui.experimentlistView->setModel(expMod);
		// to be upgrade
		if (spMod != nullptr) {
			delete spMod;
			spMod = nullptr;
		}
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

int SmartfMRI::openLogFolder()
{
	if (!ui.experimentlistView->currentIndex().data().isValid()) {
		QMessageBox::critical(this, tr("Fail to open"),
			QString("Please select an item."));
		return 0;
	}
	else {
		Experiment* e = expMod->getExperiment(ui.experimentlistView->currentIndex().data().toString());
		qDebug() << "Open log folder";
		if (!QDesktopServices::openUrl(
			QUrl::fromLocalFile(e->getDir().absolutePath() + "/log"))) {
			QMessageBox::critical(this, tr("Fail to open"),
				QString("No Log files has been created yet"));
		}
		return 1;
	}

}

int SmartfMRI::openAbout()
{
	About about(this);
	about.exec();

	return 0;
}
