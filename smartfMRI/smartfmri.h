#ifndef SMARTFMRI_H
#define SMARTFMRI_H

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include "ui_smartfmri.h"
#include "experimentmodel.h"
#include "experimentmanager.hpp"


class SmartfMRI : public QMainWindow
{
	Q_OBJECT

public:
	SmartfMRI(QWidget *parent = Q_NULLPTR);
	~SmartfMRI();

public slots:
	int addExperiment();
	int removeExperiment();

private:
	Ui::smartfMRIClass ui;
	QDir dir;
	ExperimentModel *expMod;
	ExperimentManager expMan;

};

#endif // SMARTFMRI_H
