#ifndef EXPERIMENTMODEL_H
#define EXPERIMENTMODEL_H

#include <QAbstractListModel>
#include "experiment.h"
#include "qdebug.h"

class ExperimentModel : public QAbstractListModel
{
public:
	ExperimentModel(QObject *parent = 0);
	~ExperimentModel();

	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	bool insertRow(int row, Experiment& e,const QModelIndex& parent = QModelIndex());

private:
	QMap<QString, Experiment*> qExpMap;

};

#endif // EXPERIMENTMODEL_H
