#ifndef SCANPARAMETERS_H
#define SCANPARAMETERS_H

#include <QObject>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QFile>

/**
 * @class ScanParameters
 * read Scan Parameters of *.txt files
 * read & write methods are used to read and write the *.txt files content
 * attributes and values are null, if read is not invoked
 * @author
 * @version
 */
class ScanParameters : public QObject
{
public:
	// status of reading or writing *.txt files
	enum status
	{
		CannotOpenTheFile,
		FileIncorrect,
		Successful,
		ParametersIncorrect
	};
	/**
	 * constructor
	 * 
	 * @param fileName file name of *.txt file
	 * @param parent parent QObject
	 */
	ScanParameters(QString fileName = QString(), QObject *parent = 0);
	/**
	 * read the *.txt file content to attributes and values 
	 * they are null if read is not invoked
	 * @return  status of reading *.txt files
	 */
	status read();
	/**
	 * write the *.text file with attributes and values
	 * read should be invoked first
	 * @return status of writing *.txt files
	 */
	status write();
	/**
	 * destructor
	 */
	~ScanParameters();
	/**
	 * get the reference of attributes
	 * can change it directly, then use write method for writing it to *.txt files
	 * @return referenc of attibutes
	 */
	QStringList& getAttributes();
	/**
	 * get the reference of values
	 * can chage it directly, then use write mothod for writing it to *.txt files
	 * @return referenc of values
	 */
	QList<QStringList>& getValues();

private:
	//the file name of *.txt file
	QString parametersFileName;
	// the first row of the *.txt file, every attribute should be seperated by '\t'
	QStringList attributes;
	// the remain rows of the *.txt file, every value should be seperated by '\t'
	// very row should be seperated by '\n'
	QList<QStringList> values;
};

#endif // SCANPARAMETERS_H
