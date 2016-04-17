#include "smartfmri.h"

smartfMRI::smartfMRI(QWidget *parent)
	: QMainWindow(parent)
{

	qDebug() << "set up UI";
	ui.setupUi(this);
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addExperiment()));
}

smartfMRI::~smartfMRI()
{

}

int smartfMRI::addExperiment() {

	QUrl url = QFileDialog::getOpenFileUrl(this, tr("Add Experiment"),
		QUrl(), tr("E-Run Script File (*.ebs2);; All files (*.*)"));
	if (url.isEmpty())
		return 0;
	Experiment e(url, this);
	qDebug() << e.getUrl().path();
	qDebug() << e.getName();


	return 1;
}
