#ifndef SMARTFMRI_H
#define SMARTFMRI_H

#include <QtWidgets/QMainWindow>
#include "ui_smartfmri.h"
#include "qfiledialog.h"
#include "qdebug.h"
#include "experimentmodel.h"


class smartfMRI : public QMainWindow
{
	Q_OBJECT

public:
	smartfMRI(QWidget *parent = 0);
	~smartfMRI();

public slots:
	int addExperiment();

private:
	Ui::smartfMRIClass ui;
	ExperimentModel expMod;

};

#endif // SMARTFMRI_H
