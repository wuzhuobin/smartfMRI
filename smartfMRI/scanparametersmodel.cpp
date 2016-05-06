#include "scanparametersmodel.h"

ScanParametersModel::ScanParametersModel(QObject *parent)
	: QAbstractListModel(parent) ,length(0)
{
	qDebug() << "ScanParametersModel construction";
}

ScanParametersModel::ScanParametersModel(Experiment& e, bool editFlag, QObject * parent)
	: QAbstractListModel(parent), editFlag(editFlag)
{
	headerList += QString("TR (ms)");
	headerList += QString("Control Period (ms)");
	headerList += QString("Task Period (ms)");
	headerList += QString("Dummy Samples (sampels)");
	headerList += QString("Cycles (cycles)");
	headerList += QString("Task Trail Period (ms)");
	headerList += QString("Control Trail Period (ms)");
	headerList += QString("Scan time (s)");

	while (values.size() < headerList.size()) {
		values += 0.0;
	}
	
	if (e.sps1.getAttributes().contains("ControlDuration")) {
		QString value = e.sps1.getValues()[e.sps1.getAttributes().indexOf("ControlDuration")];
		values[1] = value.toDouble();
	}
	if (e.sps1.getAttributes().contains("Weight")) {
		QString value = e.sps1.getValues()[e.sps1.getAttributes().indexOf("Weight")];
		values[4] = value.toDouble();
	}
	if (e.sps2.getAttributes().contains("StimDuration")) {
		QString value = e.sps2.getValues()[e.sps2.getAttributes().indexOf("StimDuration")];
		values[5] = value.toDouble();
	}
	if (e.sps2.getAttributes().contains("FixationDuration")) {
		QString value = e.sps2.getValues()[e.sps2.getAttributes().indexOf("FixationDuration")];
		values[6] = value.toDouble();
	}
	if (e.sps2.getAttributes().contains("Weight")) {
		QString value = e.sps2.getValues()[e.sps2.getAttributes().indexOf("Weight")];
		values[2] = value.toDouble()* (values[5]+ values[6]);
	}

	this->length = headerList.size();
	qDebug() << "ScanParametersModel construction";

}

ScanParametersModel::~ScanParametersModel()
{
	qDebug() << "ScanParametersModel destruction";

}

int ScanParametersModel::rowCount(const QModelIndex & parent) const
{
	return this->length;
}

QVariant ScanParametersModel::data(const QModelIndex & index, int role) const
{
	if (index.row() < 0 ||index.row() >=length)
		return QVariant();
	switch (role)
	{
	case Qt::DisplayRole:
		return values[index.row()];
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
	if (section >= length) return QVariant();
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
	else if(editFlag)
		return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
	else 
		return Qt::ItemIsSelectable | Qt::ItemIsEnabled;

}

bool ScanParametersModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	//if (role != Qt::EditRole || index.column() != 0 || index.row() >= values.size())
	//	return false;
	////if (index.row() == 3 || index.row() == 4)
	////	qvl[index.row()] = value.toInt();
	//else
	//	values[index.row()] = value.toString();
	//emit dataChanged(index, index);

	return true;
}

QList<double> ScanParametersModel::getValues()
{
	return this->values;
}
