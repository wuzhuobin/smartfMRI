#include "logfiledata.h"

QList<QString> LogFileData::change(QString fileContent)
{
	QList<QString> listAll = fileContent.split("\n");
	
	QList<QString> B = listAll.filter("TrialList.Cycle");
	QList<QString> T = listAll.filter("TrialList.Sample");
	QList<QString> K = listAll.filter("Stim.RESP");
	QList<QString> A = listAll.filter("Stim.ACC");
	QList<QString> RT = listAll.filter("Stim.RT");
	int length = B.size();
	if (T.size() < length)	length = T.size();
	else if (K.size() < length)	length = K.size();
	else if (A.size() < length)	length = A.size();
	else if (RT.size() < length)	length = RT.size();
	else length = B.size();
	QStringList list;
	for (int i = 0; i < length; ++i) {
		QString s;
		s += "B = ";
		s += B[i].split(":")[1].remove("\r") + ", ";
		s += "T = ";
		s += T[i].split(":")[1].remove("\r") + ", ";
		s += "K = ";
		s += K[i].split(":")[1].remove("\r") + ", ";
		s += "A = ";
		s += A[i].split(":")[1].remove("\r") + ", ";
		s += "RT = ";
		s += RT[i].split(":")[1];  
		list << s;
	}


	

	return list;
}
