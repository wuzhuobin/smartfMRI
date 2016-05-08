#pragma once
#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QUrl>
#include <QDir>
#include <QDirIterator>
#include <QMessageBox>
#include "qcopydirrecursively.h"
#include "experiment.h"
#include "scanparametersmodel.h"
#include "ui_experimentmanager.h"

class ExperimentManager : public QDialog {
	Q_OBJECT

public:
	ExperimentManager(const QString paradigmFolder, QWidget * parent = Q_NULLPTR);
	~ExperimentManager();
	int copyParadigm();
	int updataParadigm();
	int loadParadigm();
	int setParadigmFile(const QFileInfo beforFile);
	QFileInfo getParadigmFile() const;


private:
	Ui::ExperimentManager ui;
	ScanParametersModel* spMod = nullptr;
	Experiment* e = nullptr;
	QString paradigmFolder;
	QFileInfo paradigmFile;
};
