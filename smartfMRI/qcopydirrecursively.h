#ifndef QCOPYDIRRECURSIVELY_H
#define QCOPYDIRRECURSIVELY_H

#include <QObject>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
/**
 * an utility class for copying files recursively
 * @author
 * @version
 */
class QCopyDirRecursively : public QObject
{
public:
	QCopyDirRecursively(QObject *parent);
	~QCopyDirRecursively();
	/**
	 * an static method to copy all the files in oldPath to newPath
	 * @param oldPath the directory where files need to be copied
	 * @param newPath the directory which files need to be copied to 
	 * @return true succeed
	 *         false fail
	 */
	static bool copy(QString oldPath, QString newPath);

private:

};

#endif // QCOPYDIRRECURSIVELY_H
