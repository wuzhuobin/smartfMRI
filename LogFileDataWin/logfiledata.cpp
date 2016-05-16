#include "logfiledata.h"

QList<QString> LogFileData::change(QString fileContent)
{
	QList<QString> listAll = fileContent.split("\n");
	
	QList<QString> B = listAll.filter("TrialList.Cycle");
	QList<QString> T = listAll.filter("TrialList.Sample");
	QList<QString> K = listAll.filter("Stim.RESP");
	QList<QString> A = listAll.filter("Stim.ACC");
	QList<QString> RT = listAll.filter("Stim.RT");
	QList<QString> Date = listAll.filter("SessionDate");
	QList<QString> Time = listAll.filter("SessionTime");
	QList<QString> OnsetTime = listAll.filter("Stim.OnsetTime");


	int length = B.size();
	if (T.size() < length)	length = T.size();
	else if (K.size() < length)	length = K.size();
	else if (A.size() < length)	length = A.size();
	else if (RT.size() < length)	length = RT.size();
	else if (OnsetTime.size() < length) length = OnsetTime.size();
	else length = B.size();

	QStringList list;

	for (int i = 0; i < length; ++i) {
		QString s;
		if (i == 0) {
			list << ("Date = " + Date[0].split(":")[1].remove("\r"));
			list << ("Time = " + Time[0].split(":")[1].remove("\r"));
		}
		s += QDateTime::fromString(Time[0].split(": ")[1].remove("\r"),
			"hh:mm:ss").addMSecs(OnsetTime[i].split(": ")[1].remove("\r").toInt())
			.toString("hh:mm:ss.zzz: ");
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
