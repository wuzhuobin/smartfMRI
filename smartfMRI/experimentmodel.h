#ifndef EXPERIMENTMODEL_H
#define EXPERIMENTMODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include <QDir>
#include "experiment.h"
/**
 * @class ExperimentModel
 * ListModel for displaying all the experiments in the dir (./paradigm) folder
 * if this folder does not exist, it will make one
 * @author
 * @version
 *
 */
class ExperimentModel : public QAbstractListModel
{
public:
	/**
	 * constructor
	 * loading all the Experiment in the dir (./paradigm) and insert them into
	 * the model
	 * @param dir the folder where to read experiments
	 * @param *parent parent QObject
	 */
	ExperimentModel(QDir dir = QDir(), QObject *parent = 0);
	/**
	 * destructor
	 */
	~ExperimentModel();
	/**
	 * the row number of experimentModel
	 * @override
	 * @param parent 
	 * @return row number
	 */
	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	/**
	 * data display in the experimentmodel
	 * @override
	 * @param index index of the data in the model
	 * @param role display in which role
	 * @return the data to display
	 */
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	/**
	 * insert an Experiment e into the ExperimentModel
	 * invoked in the construcotr
	 * @param row which row to insert
	 * @param e Experiment objcect to insert
	 * @param parent parent Object
	 * @return true succeed
	 *         false fail
	 */
	bool insertRow(int row, Experiment& e, const QModelIndex& parent = QModelIndex());
	/**
	 * Not implemented yet
	 * @deprecated
	 * @override
	 * @param row
	 * @param count
	 * @param parent
	 */
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
	/**
	 * get Experiment pointer of qExpMap with a corresponding key
	 * @param key key to find corresponding key in qExpMap
	 * @return pointer of an Experiment im qExpMap whose key is key
	 */
	Experiment* getExperiment(const QString key) const;

private:
	//the content to display, key is an experiment name, value is the pointer of 
	// an experiment
	QMap<QString, Experiment*> qExpMap;
	// the directory where all experiments are saved.
	QDir dir;

};

#endif // EXPERIMENTMODEL_H
