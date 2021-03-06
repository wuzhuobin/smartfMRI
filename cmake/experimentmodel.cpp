#include "experimentmodel.h"

ExperimentModel::ExperimentModel(QDir dir,QObject *parent)
	: QAbstractListModel(parent), dir(dir)
{
	qDebug() << dir;
	QFileInfoList folders = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

	for (int i = 0; i < folders.size(); ++i) {
		qDebug() << folders[i].absoluteFilePath();
		QFileInfoList fil(QDir(folders[i].absoluteFilePath()).entryInfoList(
			QStringList("*.ebs2")));
		if (fil.size() > 0) {
			qDebug() << fil[0].absoluteFilePath();
			this->insertRow(this->rowCount(), *new Experiment(QFileInfo(fil[0].absoluteFilePath()), this));
		}
	}

	qDebug() << "ExperimentModel construction";
}

ExperimentModel::~ExperimentModel()
{
	qDebug() << "ExperimentModel disconstruction";
}

int ExperimentModel::rowCount(const QModelIndex &parnet) const 
{

	return qExpMap.size();
}


QVariant ExperimentModel::data(const QModelIndex &index, int role) const 
{
	if (qExpMap.isEmpty())
		return QVariant();
	if (index.row() < 0 || index.row() >= qExpMap.size())
		return QVariant();
	QString key = qExpMap.keys()[index.row()];
	QString path = qExpMap[key]->getDir().absolutePath();
	switch (role)
	{
	case Qt::DisplayRole:
		return key;
		break;
	case Qt::ToolTipRole:
		return path;
		break;
	default:
		return QVariant();
		break;
	}
	return QVariant();
}

bool ExperimentModel::insertRow(int row, Experiment& e, const QModelIndex & parent)
{
	beginInsertRows(parent, row, row);
	if(row > qExpMap.size() || row < 0)
		return false;
	qExpMap[e.getName()] = &e;
	endInsertRows();

	return  true;
}

bool ExperimentModel::insertRows(int row, int count, const QModelIndex & parent)
{

	beginInsertRows(parent, row, row + count);

	endInsertRows();
	return true;
}

Experiment* ExperimentModel::getExperiment(const QString key) const
{
	return qExpMap[key];
}




