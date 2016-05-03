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
	if (dirr.removeRecursively()) {
		qDebug() << "remove successfully";
		delete expMod;
		expMod = new ExperimentModel(this, QDir(dir.path() + "/paradigm"));
		ui.experimentlistView->setModel(new ExperimentModel(this, QDir(dir.path() + "/paradigm")));
		return 1;
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
	QFileInfo(fileName).absoluteDir();
	expMan.setBeforePath(QFileInfo(fileName).absolutePath());
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

