#include "qcopydirrecursively.h"



QCopyDirRecursively::QCopyDirRecursively(QObject *parent)
	: QObject(parent)
{

}

QCopyDirRecursively::~QCopyDirRecursively()
{

}

bool QCopyDirRecursively::copy(QString oldPath, QString newPath)
{
	bool result = false;
	QList<QFileInfo> qfi = QDir(oldPath).entryInfoList();
	for (int i = 0; i < qfi.size(); ++i) {
		if (qfi[i].fileName() == "." || qfi[i].fileName() == "..") {
			continue;
		}
		else if (qfi[i].isDir()) {
			QDir(newPath).mkdir(qfi[i].fileName());
			result = copy(qfi[i].absoluteFilePath(), newPath + "/" + qfi[i].fileName());
		}
		else {
			result = QFile::copy(qfi[i].absoluteFilePath(), newPath + "/" + qfi[i].fileName());
		}
	}

	return result;
}
