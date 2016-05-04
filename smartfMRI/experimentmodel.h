#ifndef EXPERIMENTMODEL_H
#define EXPERIMENTMODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include <QDir>
#include "experiment.h"

class ExperimentModel : public QAbstractListModel
{
public:
	ExperimentModel(QObject *parent = 0, QDir dir = QDir());
	~ExperimentModel();

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
