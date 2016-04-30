#ifndef SCANPARAMETERSLISTMODEL_H
#define SCANPARAMETERSLISTMODEL_H

#include <QAbstractListModel>
#include <QDebug>

class ScanParametersModel : public QAbstractListModel
{
public:
	ScanParametersModel(QObject *parent);
	~ScanParametersModel();
	int rowCount(const QModelIndex &parent) const;
	QVariant data(const QModelIndex &index, int role) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

private:
	QStringList headerList;
	QList<QVariant> qvl;

};

#endif // SCANPARAMETERSLISTMODEL_H