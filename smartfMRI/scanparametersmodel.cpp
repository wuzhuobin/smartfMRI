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
	headerList += QString("number of dummy scans (dynamics)");
	headerList += QString("number of cycles (cycles)");
	headerList += QString("number of dynamics per task block (dynamics)");
	headerList += QString("duration of task trial (ms)");
	headerList += QString("number of dynamics per rest block (dynamics)");
	headerList += QString("duration of rest trial (dynamics)");
	headerList += QString("Scan time");

	while (values.size() < headerList.size()) {
		values += 0.0;
	}
	values[0] = 3000;
	values[1] = 2;
	values[2] = 5;
	values[3] = 10;
	values[4] = 3000;
	values[5] = 10;
	values[6] = 3000;
	setValuesFromExperiment(e);
	this->length = headerList.size();
	qDebug() << "ScanParametersModel construction";

}

ScanParametersModel::~ScanParametersModel()
{
	qDebug() << "ScanParametersModel destruction";

}

int ScanParametersModel::rowCount(const QModelIndex & parent) const
{
	if(editFlag)
		return this->length-1;
	else
	return this->length;
}

QVariant ScanParametersModel::data(const QModelIndex & index, int role) const
{
	if (index.row() < 0 || index.row() >= length)
		return QVariant();
	else {
		switch (role)
		{
		case Qt::DisplayRole:
			if (index.row() == 7)
				return scanTime;
			return values[index.row()];
			break;
		case Qt::ToolTipRole:
			return QVariant();
			break;
		default:
			return QVariant();
			break;
		}
	}
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
	if (role != Qt::EditRole || index.column() != 0 || index.row() >= values.size())
		return false;
	else
		values[index.row()] = value.toDouble();
	emit dataChanged(index, index);

	return true;
}

int ScanParametersModel::setValuesToExperiment(Experiment& e)
{
	// TR (default: 3000ms)
	if (e.sps4.getAttributes().contains("TR")) {
		e.sps4.getValues()[e.sps4.getAttributes().indexOf("TR")] =
			QStringList(QString::number(values[0]));
	}
	else {
		e.sps4.getAttributes() += "TR";
		e.sps4.getValues() += QStringList(QString::number(values[0]));
	}
	// number of dummy scans  (default: 2 dynamics)
	if (e.sps1.getAttributes().contains("Duration")) {
		e.sps1.getValues()[e.sps4.getAttributes().indexOf("Duration")] = 
			QStringList(QString::number(values[1]/values[0]));
	}
	else {
		e.sps4.getAttributes() += "Duration";
		e.sps4.getValues() += QStringList(QString::number(values[1] / values[0]));
	}
	//  number of cycles (default: 5 cycles)
	if (e.sps2.getAttributes().contains("Weight")) {
		e.sps2.getValues()[e.sps2.getAttributes().indexOf("Weight")] =
			QStringList(QString::number(values[2]));
	}
	else {
		e.sps2.getAttributes() += "Weight";
		e.sps2.getValues() += QStringList(QString::number(values[2]));
	}
	// number of dynamics per task block (default: 10 dynamics)
	if (e.sps1.getAttributes().contains("number of dynamics per task block")) {
		e.sps1.getValues()[e.sps1.getAttributes().indexOf("number of dynamics per task block")] = QString::number(values[1]);
	}
	if (e.sps1.getAttributes().contains("Weight")) {
		e.sps1.getValues()[e.sps1.getAttributes().indexOf("Weight")] = QString::number(values[4]);
	}
	if (e.sps2.getAttributes().contains("StimDuration")) {
		e.sps2.getValues()[e.sps2.getAttributes().indexOf("StimDuration")] = QString::number(values[5]);
	}
	if (e.sps2.getAttributes().contains("FixationDuration")) {
		 e.sps2.getValues()[e.sps2.getAttributes().indexOf("FixationDuration")] = QString::number(values[6]);
	}
	if (e.sps2.getAttributes().contains("Weight")) {
		e.sps2.getValues()[e.sps2.getAttributes().indexOf("Weight")] = QString::number(
			(values[5] + values[6])==0?0:(values[2])/ (values[5] + values[6]));
	}
	return 1;
}

int ScanParametersModel::setValuesFromExperiment(Experiment& e)
{
	if (e.sps3.getAttributes().contains("TR")) {
	//if(true){
		QString value = e.sps3.getValues()[e.sps3.getAttributes().indexOf("TR")];
		values[0] = value.toDouble();
	}
	if (e.sps3.getAttributes().contains("DummySamples")) {
		QString value = e.sps3.getValues()[e.sps3.getAttributes().indexOf("DummySamples")];
		values[3] = value.toDouble();
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
		values[2] = value.toDouble()* (values[5] + values[6]);
	}
	values[7] = (values[3] * values[0] + (values[2] + values[1])*values[4]);
	int min = int(values[7] / 1000 / 60);
	scanTime = QString::number(min) + "min" + QString::number(values[7] / 1000 - min * 60) + "s";

	return 1;
}
