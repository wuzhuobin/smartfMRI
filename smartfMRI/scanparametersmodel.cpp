#include "scanparametersmodel.h"

ScanParametersModel::ScanParametersModel(QObject *parent)
	: QAbstractListModel(parent) ,length(0)
{
	qDebug() << "ScanParametersModel construction";
}

ScanParametersModel::ScanParametersModel(Experiment& e, bool editFlag, QObject * parent)
	: QAbstractListModel(parent), editFlag(editFlag)
{
	headerList += QString(" TR (ms)");
	headerList += QString(" Number of dummy scans (dynamics)");
	headerList += QString(" Number of cycles (cycles)");
	headerList += QString(" Number of dynamics per task block (dynamics)");
	headerList += QString(" Duration of task trial (ms)");
	headerList += QString(" Number of dynamics per rest block (dynamics)");
	headerList += QString(" Furation of rest trial (ms)");
	headerList += QString(" Scan time");

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
	getValuesFromExperiment(e);
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
	if (role != Qt::EditRole || 
		index.column() != 0 || 
		index.row() >= values.size() || 
		value.toDouble() < 0)
		return false;
	else {
		values[index.row()] = (int)value.toDouble();

	}
	emit dataChanged(index, index);

	return true;
}

int ScanParametersModel::setValuesToExperiment(Experiment& e)
{
	// TR (default: 3000ms)
	if (e.sps4.getAttributes().contains("TR")) {
		e.sps4.getValue(0)[e.sps4.getAttributes().indexOf("TR")] =
			QString::number(values[0]);
	}
	else {
		e.sps4.getAttributes() += "TR";
		e.sps4.getValue(0) += (QString::number(values[0]));
	}
	// number of dummy scans  (default: 2 dynamics)
	if (e.sps4.getAttributes().contains("number of dummy scans")) {
		e.sps4.getValue(0)[e.sps4.getAttributes().indexOf("number of dummy scans")] =
			(QString::number(values[1]));
	}
	else {
		e.sps4.getAttributes() += "number of dummy scans";
		e.sps4.getValue(0) += (QString::number(values[1]));
	}
	if (e.sps1.getAttributes().contains("Duration")) {
		e.sps1.getValue(0)[e.sps1.getAttributes().indexOf("Duration")] =
			(QString::number(values[1] * values[0]));
	}
	else {
		e.sps1.getAttributes() += "Duration";
		e.sps1.getValue(0) += (QString::number(values[1] * values[0]));
	}
	//  number of cycles (default: 5 cycles)
	if (e.sps2.getAttributes().contains("Weight")) {
		e.sps2.getValue(0)[e.sps2.getAttributes().indexOf("Weight")] =
			(QString::number(values[2]));
	}
	else {
		e.sps2.getAttributes() += "Weight";
		e.sps2.getValue(0) += QStringList(QString::number(values[2]));
	}
	// number of dynamics per task block (default: 10 dynamics)
	// duration of task trial(default: 3000 ms)
	// number of dynamics per rest block(default: 10 dynamics)
	// duration of rest trial(default: 3000 ms)
	if (e.sps4.getAttributes().contains("number of dynamics per task block")) {
		e.sps4.getValue(0)[e.sps4.getAttributes().
			indexOf("number of dynamics per task block")] = QString::number(values[3]);
	}
	else {
		e.sps4.getAttributes() += "number of dynamics per task block";
		e.sps4.getValue(0) += QString::number(values[3]);
	}
	if (e.sps4.getAttributes().contains("duration of task trial")) {
		e.sps4.getValue(0)[e.sps4.getAttributes().indexOf("duration of task trial")] =
			QString::number(values[4]);
	}
	else {
		e.sps4.getAttributes() += "duration of task trial";
		e.sps4.getValue(0) += QString::number(values[4]);

	}
	if (e.sps4.getAttributes().contains("number of dynamics per rest block")) {
		e.sps4.getValue(0)[e.sps4.getAttributes().
			indexOf("number of dynamics per rest block")] = QString::number(values[5]);
	}
	else {
		e.sps4.getAttributes() += "number of dynamics per rest block";
		e.sps4.getValue(0) += QString::number(values[5]);
	}
	if (e.sps4.getAttributes().contains("duration of rest trial")) {
		e.sps4.getValue(0)[e.sps4.getAttributes().indexOf("duration of rest trial")] =
			QString::number(values[6]);
	}
	else {
		e.sps4.getAttributes() += "duration of rest trial";
		e.sps4.getValue(0) += QString::number(values[6]);
	}
	if (e.sps3.getAttributes().contains("Procedure") &&
		e.sps3.getAttributes().contains("Weight") &&
		e.sps3.getValues().size() >= 2) {
		for (int i = 0; i < 2; ++i) {
			if (e.sps3.getValue(i)[e.sps3.getAttributes().indexOf("Procedure")] ==
				"TaskBlockProc") {
				e.sps3.getValue(i)[e.sps3.getAttributes().indexOf("Weight")] =
					QString::number(values[3] * values[0] / values[4]);
			}
			else if(e.sps3.getValue(i)[e.sps3.getAttributes().indexOf("Procedure")] ==
				"RestBlockProc") {
				e.sps3.getValue(i)[e.sps3.getAttributes().indexOf("Weight")] =
					QString::number(values[5] * values[0] / values[6]);
			}
		}
	}
	else {
		e.sps3.getAttributes() += "Procedure";
		e.sps3.getValue(0) += "TaskBlockProc";
		e.sps3.getValue(1) += "RestBlockProc";
		e.sps3.getAttributes() += "Weight";
		e.sps3.getValue(0) += QString::number(values[3] * values[0] / values[4]);
		e.sps3.getValue(1) += QString::number(values[5] * values[0] / values[6]);

	}
	return 1;
}

int ScanParametersModel::getValuesFromExperiment(Experiment& e)
{
	// number of dummy scans  (default: 2 dynamics)
	if (e.sps4.getAttributes().contains("number of dummy scans")) {
		values[1] = e.sps4.getValue(0)
			[e.sps4.getAttributes().indexOf("number of dummy scans")].toDouble();
	}
	// TR (default: 3000ms)
	if (e.sps1.getAttributes().contains("Duration")) {
	//if(true){
		values[0] = e.sps1.getValue(0)
			[e.sps1.getAttributes().indexOf("Duration")].toDouble() / values[1];
		values[0] = (int)values[0];
	}
	else if (e.sps4.getAttributes().contains("TR")) {
		values[0] = e.sps4.getValue(0)[e.sps4.getAttributes().indexOf("TR")].toDouble();
	}
	// number of cycles (default: 5 cycles)
	if (e.sps2.getAttributes().contains("Weight")) {
		values[2] = e.sps2.getValue(0)
			[e.sps2.getAttributes().indexOf("Weight")].toDouble();
	}
	// number of dynamics per task block (default: 10 dynamics)
	if (e.sps4.getAttributes().contains("number of dynamics per task block")) {
		values[3] = e.sps4.getValue(0)
			[e.sps4.getAttributes().indexOf("number of dynamics per task block")].toDouble();
	}
	// number of dynamics per rest block(default: 10 dynamics)
	if (e.sps4.getAttributes().contains("number of dynamics per rest block")) {
		values[5] = e.sps4.getValue(0)
			[e.sps4.getAttributes().indexOf("number of dynamics per rest block")].toDouble();
	}
	// duration of task trial(default: 3000 ms)
	// duration of rest trial(default: 3000 ms)
	if (e.sps3.getAttributes().contains("Procedure") &&
		e.sps3.getAttributes().contains("Weight")
		&& e.sps3.getValues().size() >= 2) {
		for (int i = 0; i < 2; ++i) {
			if (e.sps3.getValue(i)[e.sps3.getAttributes().indexOf("Procedure")] ==
				"TaskBlockProc") {
				values[4] = values[3] * values[0] /
					e.sps3.getValue(i)[e.sps3.getAttributes().indexOf("Weight")].toDouble();
				values[4] = (int)values[4];
			}
			else if (e.sps3.getValue(i)[e.sps3.getAttributes().indexOf("Procedure")] ==
				"RestBlockProc") {
				values[6] = values[5] * values[0] /
					e.sps3.getValue(i)[e.sps3.getAttributes().indexOf("Weight")].toDouble();
				values[6] = (int)values[6];
			}
		}
	}
	else {
		if (e.sps4.getAttributes().contains("duration of task trial")) {
			values[4] = e.sps4.getValue(0)
				[e.sps4.getAttributes().indexOf("duration of task trial")].toDouble();
		}
		if (e.sps4.getAttributes().contains("duration of rest trial")) {
			values[6] = e.sps4.getValue(0)
				[e.sps4.getAttributes().indexOf("duration of rest trial")].toDouble();
		}
	}
	values[7] = (values[0] * values[1] + values[3] * values[4] + values[5] * values[6])*values[2];
	int min = int(values[7] / 1000 / 60);
	scanTime = QString::number(min) + "min" + QString::number(values[7] / 1000 - min * 60) + "s";

	return 1;
}
