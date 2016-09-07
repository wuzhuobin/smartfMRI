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
/**
 * @class ExperimentManager
 * UI for the seting experiment name and scan parameters
 * @author
 * @version
 * 
 */
class ExperimentManager : public QDialog {
	Q_OBJECT

public:
	/**
	 * construcotr
	 * @param paradigmFolder where the paradigms are copied to 
	 * @param parent the parent QWidget pointer
	 */
	ExperimentManager(const QString paradigmFolder, QWidget * parent = Q_NULLPTR);
	/**
	 * destructor 
	 */
	~ExperimentManager();
	/**
	 * copy all files in selected *.ebs2 file's folder to paradigmFolder 
	 * this method will call updateParadigm() to save the changed scanParameters
	 * @param	clinicalFlag if clinicalFlag == true, update the ScanParameters 
	 *			as a clinical one, otherwise, as a research one, which 
	 *			means parameters cannot be changed in the future
	 * @return 1 succeed
	 *         0 fail
	 */
	int copyParadigm(bool clinicalFlag);
	/**
	 * updataParadigm updata the scan parameters of *e
	 * updata the Experiment name of *e and change its directory name
	 * create a log folder
	 * @param	clinicalFlag convert to updateParadigm
	 * @return 1 succeed
	 *         0 fail
	 */
	int updataParadigm(bool clinicalFlag);
	/**
	 * read all the scan parameters from the scan parameters from *.txt
	 * save it in ScanParametersModel for display or manipulate in a listView
	 * @param	clinicalFlag true the ScanParameterModel is updateable, otherwise
	 *          it is not updateable
	 * @return 1 succeed
	 *         0 fail
	 */
	int loadParadigm(bool clinicalFlag);
	/**
	 * set the paradigmFile which for reading scanParameters
	 * should be call before updataParadigm(), and loadParadigm()
	 * otherwise these 2 methods do not know which paradigm to load or update
	 * @param paradigmFile QFileInfo object of the paradigm *.ebs2 
	 * @return 1 succeed
	 *         0 fail
	 */
	int setParadigmFile(const QFileInfo paradigmFile);
	/**
	 * get the ParadigmFile which has been set in setParadigmFile()
	 * @return paradigmFile if it has been set in setParadigmFile()
	 *         QFileInfo() if it has not been set
	 */
	QFileInfo getParadigmFile() const;


private:
	//UI
	Ui::ExperimentManager ui;
	// pointer of ScanParametersModel
	ScanParametersModel* spMod = nullptr;
	// the pointer of Experiment to Load and update
	Experiment* e = nullptr;
	// the folder of the paradigmFile *.ebs2 file
	QString paradigmFolder;
	// QFileInfo of the paradigmFile *.ebs2 file
	QFileInfo paradigmFile;
};
