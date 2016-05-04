#ifndef QCOPYDIRRECURSIVELY_H
#define QCOPYDIRRECURSIVELY_H

#include <QObject>
#include <QDir>
#include <QFileInfo>
#include <QDebug>

class QCopyDirRecursively : public QObject
{
public:
	QCopyDirRecursively(QObject *parent);
	~QCopyDirRecursively();
	static bool copy(QString oldPath, QString newPath);

private:

};

#endif // QCOPYDIRRECURSIVELY_H
