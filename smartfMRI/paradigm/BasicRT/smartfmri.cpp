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
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addExperiment()));
}

SmartfMRI::~SmartfMRI()
{
	qDebug() << "Close SmartfMRI";
}

int SmartfMRI::addExperiment() {

	QUrl url = QFileDialog::getOpenFileUrl(this, tr("Add Experiment"),
		QUrl(), tr("E-Run Script File (*.ebs2);; All files (*.*)"));
	if (url.isEmpty())
		return 0;
	expMan.setUpdataFlag(false);
	expMan.setBeforeUrl(url);
	expMan.setParadigmUrl(QUrl(dir.path() + "/paradigm/"));
	qDebug() << expMan.getBeforeUrl() << "*******" << expMan.getParadigmUrl();
	if (expMan.exec() == QDialog::Accepted) {
		if (expMod != nullptr) {
			delete expMod;
			expMod = new ExperimentModel(this, QDir(dir.path() + "/paradigm"));
		}
		ui.experimentlistView->setModel(new ExperimentModel(this, QDir(dir.path() + "/paradigm")));
		
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