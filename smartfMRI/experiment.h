#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <QObject>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include "scanparameters.h"
/**
 * @class Experiment 
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
	 * sps1: fi.absolutePath() + "/myDummy.txt"
	 * sps2: fi.absolutePath() + "/myCycleList.txt"
	 * sps3: fi.absolutePath() + "/myBlockList.txt"
	 *
	 */
	Experiment(const QFileInfo fi = QFileInfo(), QObject *parent = 0);
	/**
	 * Destructor
	 */
	~Experiment();
	/**
	 * get the Experiment's name
	 * @retrun Experiment's name	 
	 */
	QString getName() const;
	/**
	 * set the Experiment's name
	 * @param a Experiment's new name
	 * @return 1 if succeed.
	 *	       0 if fail
	 */
	int setName(const QString name);
	/**
	 * get the directory of the Experiment
	 * @return directory of the Experiment
	 */
	QDir getDir() const;
	/**
	 * set the directory of the Experiment
	 * @param the new Experiment's directory
	 * @return 1, if succeed
	 *         0, if fail
	 */
	int setDir(const QDir dir);
	/**
	 * get the QFileInfo of the *.ebs2 file
	 * @return QFileInfo of the *.ebs2 file
	 */
	QFileInfo getFi() const;
	/**
	 * set the QFileInfo of the *.ebs2 file
	 * @param the QFileInfo of the *.ebs2 file
	 * @return 1, if succeed
	 *         0, if fail
	 */
	int setFi(const QFileInfo fi);
	/**
	 * ScanParameters *.txt file
	 * loading the essential parameter of the Experiment
	 * filePaths have been settled as following
	 * sps1: fi.absolutePath() + "/myDummy.txt"
	 */
	ScanParameters sps1;
	/**
	 * ScanParameters *.txt file
	 * loading the essential parameter of the Experiment
	 * filePaths have been settled as following
	 * sps2: fi.absolutePath() + "/myCycleList.txt"
	 */
	ScanParameters sps2;
	/**
     * ScanParameters *.txt file
	 * loading the essential parameter of the Experiment
	 * filePaths have been settled as following
	 * sps3: fi.absolutePath() + "/myBlockList.txt"
	 */
	ScanParameters sps3;
	/**
	* ScanParameters *.txt file
	* loading the essential parameter of the Experiment
	* filePaths have been settled as following
	* sps3: fi.absolutePath() + "/myParameters.txt"
	*/
	ScanParameters sps4;

	
private:
	// name of the Experiment
	QString name;
	// directory of the Experiment
	QDir dir;
	// QFileInfo of the *.ebs2 file
	QFileInfo fi;

};

#endif // EXPERIMENT_H
