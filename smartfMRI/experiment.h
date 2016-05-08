#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <QObject>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include "scanparameters.h"
/**
 * class Experiment 
 * containing a single Experiment
 * @author 
 * @version
 */
class Experiment : public QObject
{
	
public:
	/**
	 * Constructor
	 * @param fi a *.ebs2 file
	 * @param parent the parent 
	 *
	 */
	Experiment(const QFileInfo fi = QFileInfo(), QObject *parent = 0);
	/**
	 * Destructor
	 */
	~Experiment();
	/**
	 * get the Experiment's name
	 * @retrun the Experiment's name	 
	 */
	QString getName() const;
	/**
	 * set the Experiment's name
	 * @param a Experiment's new name
	 * @return if succeed, 1. Otherwise 0
	 */
	int setName(const QString name);
	/**
	 * get the directory of the Experiment
	 * @return the directory of the Experiment
	 */
	QDir getDir() const;
	/**
	 * set the directory of the Experiment
	 * @param the new Experiment's directory
	 * @return if succeed, 1. Otherwise 0
	 */
	int setDir(const QDir dir);
	/**
	 * get the QFileInfo of the *.ebs2 file
	 * @return the QFileInfo of the *.ebs2 file
	 */
	QFileInfo getFi() const;
	/**
	 * set the QFileInfo of the *.ebs2 file
	 * @param the QFileInfo of the *.ebs2 file
	 * @return if succeed, 1. Otherwise, 0
	 */
	int setFi(const QFileInfo fi);
	/**
	 * three ScanParameters *.txt file
	 * loading the essential parameter of the Experiment
	 * filePaths have been settled as following
	 * sps1: fi.absolutePath() + "/myBlockList.txt"
	 * sps2: fi.absolutePath() + "/myTrialListParameters.txt"
	 * sps3: fi.absolutePath() + "/otherParameters.txt"
	 */
	ScanParameters sps1;
	ScanParameters sps2;
	ScanParameters sps3;

	
private:
	// name of the Experiment
	QString name;
	// directory of the Experiment
	QDir dir;
	// QFileInfo of the *.ebs2 file
	QFileInfo fi;

};

#endif // EXPERIMENT_H
