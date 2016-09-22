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
 * @class SmartfMRI
 * The Main window class
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
	 * @param parent parent QWideget
	 */
	SmartfMRI(QWidget *parent = Q_NULLPTR);
	/**
	 * destructor
	 */
	~SmartfMRI();

public slots:
	/**
	 * slots, connect to the Add button, this method will be triger
	 * adding a new experiment, select an *.ebs2 file in a browser
	 * setting the Scan parameters of a new experiment
	 * @return 1 succeed
	 *         0 fail
	 */
	int addExperiment();
	/**
	 * slots, connect to the Remove button, this method will be triger
	 * when an experiment is highlight, it will be removed form the list
	 * and directory without a warning
	 * @return 1 succeed
	 *         0 fail
	 */
	int removeExperiment();
	/**
	 * slots, connect to the Run button, this method will be triger by when 
	 * an experiment is hightlighted, run the *.ebs2 file and a superizing thread
	 * @return 1 succeed
	 *         0 fail
	 */
	int runExperiment();
	/**
	 * slots, connect to Update button pop up the experimentManger, this method will 
	 * be trigger by an experiment is hightlighted. expMan will pop up
	 * for updating scanParameters
	 * return 1 succeed
	 *        0 fail
	 */
	int updateExperiment();
	/**
	 * slots, when an exeperiment is highlighted, display its scanParameters in the Scan Parameters
	 * list, and the spMod is updated to the related experiment
	 * @return 1 succeed
	 *         0 fail
	 */
	int selectExperiment(const QModelIndex& index);
	/**
	 * slots, connect to Log button, open the Log folder in browser
	 * @return 1 succeed
	 *         0 fail
	 */
	int openLogFolder();
	/**
	 * (put the logo of smartfmri) Smart fMRI¡ªProfessional fMRI paradigm managing and operating program.
	 * Warning : This computer program is protected by copyright law and international treaties. 
	 * Unauthorized or distribution of this program, or any portion of it, may result in severe civil
	 * and criminal penalties, and will be prosecuted to the maximum extent possible under law.
	 */
	int openAbout();

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
