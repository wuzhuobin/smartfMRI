#ifndef SMARTFMRI_H
#define SMARTFMRI_H

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <Qdesktopservices>
#include "ui_smartfmri.h"
#include "experimentmodel.h"
#include "experimentmanager.hpp"
#include "scanparametersmodel.h"
#include "experimentstatus.h"


class SmartfMRI : public QMainWindow
{
	Q_OBJECT

public:
	SmartfMRI(QWidget *parent = Q_NULLPTR);
	~SmartfMRI();

public slots:
	int addExperiment();
	int removeExperiment();
	int runExperiment();
	int updateExperiment();
	int selectExperiment(const QModelIndex& index);

private:
	Ui::smartfMRIClass ui;
	QDir dir;
	ExperimentModel *expMod;
	ScanParametersModel *spMod;
	ExperimentManager expMan;
	ExperimentStatus expSta;

};

#endif // SMARTFMRI_H
