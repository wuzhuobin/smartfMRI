#include "scanparametersmodel.h"

ScanParametersModel::ScanParametersModel(QObject *parent)
	: QAbstractListModel(parent)
{
	headerList += QString("TR (ms)");
	headerList += QString("Control Period (ms)");
	headerList += QString("Task Period (ms)");
	headerList += QString("Dummy Samples (sampels)");
	headerList += QString("Cycles (cycles)");
	headerList += QString("Task Trail Period (ms)");
	headerList += QString("Control Trail Period (ms)");
	headerList += QString("Scan time (s)");

	qvl << 3000.0 << 30000.0 << 30000.0 << 2 << 4 << 4000.0 << 8000.0 << "Scan Time";
	
	qDebug() << "ScanParametersModel construction";
}

ScanParametersModel::~ScanParametersModel()
{
	qDebug() << "ScanParametersModel destruction";

}

int ScanParametersModel::rowCount(const QModelIndex & parent) const
{
	return 8;
}

QVariant ScanParametersModel::data(const QModelIndex & index, int role) const
{
	if (index.row() < 0 || index.row() >= 8)
		return QVariant();
	switch (role)
	{
	case Qt::DisplayRole:
		return qvl[index.row()];
		break;
	case Qt::ToolTipRole:
		return QVariant();
		break;
	default:
		return QVariant();
		break;
	}
	return QVariant();
}

QVariant ScanParametersModel::headerData(int section, Qt::Orientation orientation, int role) const
{

	if (role != Qt::DisplayRole && orientation != Qt::Horizontal) {
		return QVariant();
	}
	else
		return headerList[section];
		
}

Qt::ItemFlags ScanParametersModel::flags(const QModelIndex & index) const
{
	if (!index.isValid())
		return Qt::ItemIsEnabled;
	if (index.row() == 7)
		return Qt::ItemIsEnabled;

	return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

bool ScanParametersModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (role != Qt::EditRole || index.column() != 0 || index.row() >= qvl.size())
		return false;
	if (index.row() == 3 || index.row() == 4)
		qvl[index.row()] = value.toInt();
	else
		qvl[index.row()] = value.toDouble();
	emit dataChanged(index, index);

	return true;
}
