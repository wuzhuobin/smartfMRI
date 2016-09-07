#include "experimentmanager.hpp"

ExperimentManager::ExperimentManager(const QString paradigmFolder, QWidget * parent)
	: QDialog(parent, Qt::Window), paradigmFolder(paradigmFolder)
{
	qDebug() << "set up ExperimentManager UI.";
	ui.setupUi(this);
	
	this->setWindowIcon(QIcon(":/smartfMRI/pm.ico"));

	//Set correct dialog size
	//ui.scanParametersTableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	//ui.scanParametersTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	//ui.scanParametersTableView->adjustSize();
	//ui.scanParametersTableView->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
	//ui.scanParametersTableView->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
	//ui.scanParametersTableView->resizeColumnsToContents();
	//ui.scanParametersTableView->resizeRowsToContents();

	//int w = ui.scanParametersTableView->verticalHeader()->width() + 145; // +4 seems to be needed
	//for (int i = 0; i < ui.scanParametersTableView->columnCount(); i++)
	//	w += ui.scanParametersTableView->columnWidth(i); // seems to include gridline (on my machine)

	//int h = ui.scanParametersTableView->horizontalHeader()->height();
	//for (int i = 0; i < ui.scanParametersTableView->rowCount(); i++)
	//	h += ui.scanParametersTableView->rowHeight(i);

	//w += ui.scanParametersTableView->contentsMargins().left() + ui.scanParametersTableView->contentsMargins().right();
	//h += ui.scanParametersTableView->contentsMargins().top() + ui.scanParametersTableView->contentsMargins().bottom();

	//ui.scanParametersTableView->setMaximumSize(QSize(w, h));
	//ui.scanParametersTableView->setMinimumSize(QSize(w, h));

	connect(ui.confirmPushButton, SIGNAL(clicked()), this, SLOT(accept()));
}

ExperimentManager::~ExperimentManager() {
	qDebug() << " Close ExperimentManager";
}

int ExperimentManager::copyParadigm(bool updateFlag)
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
	if (fil.size() > 0 && updateFlag) {
		qDebug() << fil[0].absoluteFilePath();
		setParadigmFile(fil[0].absoluteFilePath());
		updataParadigm();
	}
	return 1;
}

int ExperimentManager::loadParadigm()
{
	ui.paradigmNameLineEdit->setText(paradigmFile.fileName());
	ui.experimentNameLineEdit->setText(paradigmFile.dir().dirName());
	if (spMod != nullptr) {
		delete spMod;
	} 
	if (e != nullptr) {
		delete e;
	} 
	e = new Experiment(paradigmFile, this);
	if (ScanParameters::Successful == e->sps1.read() && 
		ScanParameters::Successful == e->sps2.read() && 
		ScanParameters::Successful == e->sps3.read()
		) {
		e->sps4.read();
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

	if (!QDir(e->getDir().absolutePath() + "/log").exists()) {
		e->getDir().mkdir("log");
	}

	spMod->setValuesToExperiment(*e);
	if (ScanParameters::Successful == e->sps1.write() &&
		ScanParameters::Successful == e->sps2.write() && 
		ScanParameters::Successful == e->sps3.write() &&
		ScanParameters::Successful == e->sps4.write()) {
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
