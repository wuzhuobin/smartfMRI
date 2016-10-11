#ifndef SCANPARAMETERSLISTMODEL_H
#define SCANPARAMETERSLISTMODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include "experiment.h"
/**
 * @class ScanParamtersModel
 * display and manage to alter the scan parameters of the selected experiment 
 * parameters of experiment e will be loaded into this list
 * <Scan parameters>
 * 1. TR (default: 3000ms)
 * 2. number of dummy scans  (default: 2 dynamics)
 * 3. number of cycles (default: 5 cycles)
 * 4. number of dynamics per task block (default: 10 dynamics)
 * 5. duration of task trial (default: 3000 ms)
 * 6. number of dynamics per rest block (default: 10 dynamics)
 * 7. duration of rest trial (default: 3000 ms)
 *
 * The 7 input will control 4 value in 3 text files.
 * In "myDummy.txt", the value of "Duration" is equal to TR*number of dummy scans. 
 * In "myCycle.txt", the value of "Weight" is equal to number of cycles
 * In "myBlock.txt", the value of "Weight" in 1st row is equal to number of dynamics per task block*TR/duration of task trial.
 * The value of "Weight" in 2nd row is equal to number of dynamics per rest block*TR/duration of rest trial.
 * SmartFMRI should give an error message when user add paradigm or modify parameters if one or multiple value of Weight is/are not integer.
 * @author
 * @version
 */
class ScanParametersModel : public QAbstractListModel
{
public:
	/**
	 * default constructor
	 * param parent parent object
	 */
	ScanParametersModel(QObject *parent = nullptr);
	/**
	 * constructor 
	 * when an experiment is selected, this constructor is invoked to load scan parameters of e 
	 * into this list. if editFlag is true, parameters are alterable. it is supposed to be true
	 * in ExpermentManager, false in SmartfMRI
	 * @param e reference of an Experiment which is loaded
	 * @param editFlag whether the parameters are alterable
	 * @param parent parent object
	 */
	ScanParametersModel(Experiment& e, bool editFlag = true, QObject *parent = nullptr);
	/**
	 * destructor
	 * 
	 */
	~ScanParametersModel();
	/**
	 * return the row number of the list
	 * @override
	 * param parent 
	 * @return the row number
	 */
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	/**
	 * return the data to display in the list
	 * @override
	 * @param index the index of the data to display
	 * @param role display the data in which role
	 * @return the data to display
	 */
	QVariant data(const QModelIndex &index, int role) const;
	/**
	 * the header of the list
	 * @override
	 * @param section section of the header
	 * @param orientation the header is in which orientation
	 * @param role the header display in which role
	 * @return header to display
	 */
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	/**
	 * whether scan parameters are alterable
	 * @override 
	 * @param index index of the data
	 * @return whether data is alterable of this index
	 */
	Qt::ItemFlags flags(const QModelIndex &index) const;
	/**
	 * setting scan parameters 
	 * @override
	 * @param index index of a parameter 
	 * @param value value to be set to a parameter
	 * @role role of a parameter
	 * @return true, alter success
	 *         false, alter fail
	 */
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	/**
	 * alter scan parameter in the file of experiment e
	 * it will change the the value of the scan parameter files of experment e
	 * scan parameter is a *.txt file in experiment e's folder
	 * @param e which experiment's scan parameters to be alter permanently
	 * @return 1 success
	 *         0 fail
	 */
	int setValuesToExperiment(Experiment& e);
	/**
	 * load scan parameter in the file of experiment e
	 * the value of the scan parameter files of experment e
	 * scan parameter is a *.txt file in experiment e's folder
	 * @param e which experiment's scan parameters to be loaded
	 * @return 1 success
	 *         0 fail
	 */
	int getValuesFromExperiment(Experiment& e);

private:
	// whether data is alterable
	bool editFlag;
	// length of the list
	int length;
	// QList<QString> to store the header
	QList<QString> headerList;
	// Qlist<QString> to store the scanparameter of experiment e
	QList<double> values;
	// the scanTime calculate from the scan parameters
	// it also do a format transform
	QString scanTime;

};

#endif // SCANPARAMETERSLISTMODEL_H
