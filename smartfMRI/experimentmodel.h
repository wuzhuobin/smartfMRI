#ifndef EXPERIMENTMODEL_H
#define EXPERIMENTMODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include <QDir>
#include "experiment.h"
/**
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
	 * constructor of ExperimentModel
	 * @param dir the folder where to read experiments
	 * @param *parent parent QObject
	 */
	ExperimentModel(QDir dir = QDir(), QObject *parent = 0);
	/**
	 * destructor of Experiment 
	 */
	~ExperimentModel();
	/**
	 *
	 */
	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	bool insertRow(int row, Experiment& e,const QModelIndex& parent = QModelIndex());
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
	Experiment* getExperiment(const QString key) const;

private:
	QMap<QString, Experiment*> qExpMap;
	QDir dir;

};

#endif // EXPERIMENTMODEL_H
