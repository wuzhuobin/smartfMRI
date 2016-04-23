#include "smartfmri.h"

SmartfMRI::SmartfMRI(QWidget *parent)
	: QMainWindow(parent)
{
	//initialization UI setting
	qDebug() << "set up UI.";
	ui.setupUi(this);
	if (dir.mkdir("experiment")) 
		qDebug() << "experiment directory created";


	ui.experimentlistView->setModel(&expMod);
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addExperiment()));
}

SmartfMRI::~SmartfMRI()
{

}

int SmartfMRI::addExperiment() {

	QUrl url = QFileDialog::getOpenFileUrl(this, tr("Add Experiment"),
		QUrl(), tr("E-Run Script File (*.ebs2);; All files (*.*)"));
	if (url.isEmpty())
		return 0;
	//Experiment e(url, this);
	//qDebug() << &e;
	//qDebug() << e.getUrl().path();
	//expMod.insertRow(expMod.rowCount(), e);
	expMod.insertRow(expMod.rowCount(), *new Experiment(url, this));


	return 1;
}
