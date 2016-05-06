#pragma once
#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QUrl>
#include <QDir>
#include <QDirIterator>
#include "qcopydirrecursively.h"
#include "experiment.h"
#include "scanparametersmodel.h"
#include "ui_experimentmanager.h"

class ExperimentManager : public QDialog {
	Q_OBJECT

public:
	ExperimentManager(QWidget * parent = Q_NULLPTR);
	~ExperimentManager();
	int copyParadigm();
	int updataParadigm();
	int setUpdataFlag(bool flag);
	bool getUpdataFlag();
	int loadParadigm();
	int setBeforeFilePath(QString beforFilePath);
	QString getBeforeFilePath();
	int setParadigmPath(QString Path);
	QString getParadigmPath();



private:
	Ui::ExperimentManager ui;
	bool updataFlag;
	ScanParametersModel* spMod;
	Experiment* e;
	QString paradigmPath;
	QString beforeFilePath;
};
