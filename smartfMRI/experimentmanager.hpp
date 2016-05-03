#pragma once
#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QUrl>
#include <QDir>
#include <QDirIterator>
#include "experiment.h"
#include "scanparametersmodel.h"
#include "ui_experimentmanager.h"

class ExperimentManager : public QDialog {
	Q_OBJECT

public:
	ExperimentManager(QWidget * parent = Q_NULLPTR);
	~ExperimentManager();
	int setUpdataFlag(bool flag);
	bool getUpdataFlag();
	int setBeforePath(QString beforPath);
	QString getBeforePath();
	int setParadigmPath(QString Path);
	QString getParadigmPath();
public slots:
	int copyParadigm();


private:
	Ui::ExperimentManager ui;
	bool updataFlag;
	QString paradigmPath;
	QString beforePath;
};
