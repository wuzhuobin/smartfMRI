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
		QUrl(), tr("E-Run Script File (*.ebs2)"));
	qDebug() << url.path();
	qDebug() << url.fileName();

	return 1;
}
