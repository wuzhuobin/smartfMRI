#include "experimentmodel.h"

ExperimentModel::ExperimentModel(QObject *parent, QDir dir)
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
			this->insertRow(this->rowCount(), *new Experiment(fil[0].absoluteFilePath(), this));
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
		//return qExpMap.keys()[index.row()];
		break;
	case Qt::ToolTipRole:
		return path;
		//return QString(qExpMap.values()[index.row()]->getUrl().path());
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
	//QDesktopServices::openUrl(e.getUrl());

	QMapIterator<QString, Experiment*> i(qExpMap);
	while (i.hasNext()) {
		i.next();
		qDebug() << i.key() << i.value()->getDir().absolutePath();
		//qDebug() << i.key() << i.value();
	}
	endInsertRows();

	return  true;
}




