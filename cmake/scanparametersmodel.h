#ifndef SCANPARAMETERSLISTMODEL_H
#define SCANPARAMETERSLISTMODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include "experiment.h"
/**
 * @class ScanParamtersModel
 * display and manage to alter the scan parameters of the selected experiment 
 * parameters of experiment e will be loaded into this list
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
	ScanParametersModel(QObject *parent);
	/**
	 * constructor 
	 * when an experiment is selected, this constructor is invoked to load scan parameters of e 
	 * into this list. if editFlag is true, parameters are alterable. it is supposed to be true
	 * in ExpermentManager, false in SmartfMRI
	 * @param e reference of an Experiment which is loaded
	 * @param editFlag whether the parameters are alterable
	 * @param parent parent object
	 */
	ScanParametersModel(Experiment& e, bool editFlag, QObject *parent);
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
	int rowCount(const QModelIndex &parent) const;
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
	int setValuesFromExperiment(Experiment& e);

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
