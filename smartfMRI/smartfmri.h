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

/**
 * The Main window class
 * 
 * @author
 * @version
 * 
 *
*/

class SmartfMRI : public QMainWindow
{
	Q_OBJECT

public:
	/**
	 * constructor
	 * @param *parent parent QWideget
	 */
	SmartfMRI(QWidget *parent = Q_NULLPTR);
	/**
	 * destructor
	 */
	~SmartfMRI();

public slots:
	/**
	 * slots, when click the Add button, this method will be triger
	 * adding a new experiment, select an *.ebs2 file in a browser
	 * @return 1 succeed
	 *         0 fail
	 */
	int addExperiment();
	/**
	 * slots, when click the Remove button, this method will be triger
	 * when an experiment is highlight, it will be removed form the list
	 * and directory
	 * @return 1 succeed
	 *         0 fail
	 */
	int removeExperiment();
	/**
	 * run the *.ebs2 file and a superizing thread
	 * @return 1 succeed
	 *         0 fail
	 */
	int runExperiment();
	/**
	 * pop up the experimentManger for updating scanParameters
	 * return 1 succeed
	 *        0 fail
	 */
	int updateExperiment();
	/**
	 * when an exeperiment is highlighted, display its scanParameters in a list
	 * @return 1 succeed
	 *         0 fail
	 */
	int selectExperiment(const QModelIndex& index);
	/**
	 * connect to Log button, open the Log folder in browser
	 * @return 1 succeed
	 *         0 fail
	 */
	int openLogFolder();

private:
	// the UI class
	Ui::smartfMRIClass ui;
	// the pointer of experimentModel
	ExperimentModel *expMod = nullptr;
	// the pointer of scanParametersModel
	ScanParametersModel *spMod = nullptr;
	// the ExperimentManager dialog
	ExperimentManager expMan;
	// the ExperimentStatus dialog
	ExperimentStatus expSta;

};

#endif // SMARTFMRI_H
