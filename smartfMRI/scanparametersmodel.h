#ifndef SCANPARAMETERSLISTMODEL_H
#define SCANPARAMETERSLISTMODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include "experiment.h"

class ScanParametersModel : public QAbstractListModel
{
public:
	ScanParametersModel(QObject *parent);
	ScanParametersModel(Experiment& e, bool editFlag, QObject *parent);
	~ScanParametersModel();
	int rowCount(const QModelIndex &parent) const;
	QVariant data(const QModelIndex &index, int role) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	int setValuesToExperiment(Experiment& e);
	int setValuesFromExperiment(Experiment& e);

private:
	bool editFlag;
	int length;
	QList<QString> headerList;
	QList<double> values;
	QString scanTime;

};

#endif // SCANPARAMETERSLISTMODEL_H
