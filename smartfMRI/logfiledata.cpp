#include "logfiledata.h"

#include <QRegularExpression>

QList<QString> LogFileData::change(QString fileContent)
{
	QList<QString> listAll = fileContent.split("\n");
	
	QList<QString> B = listAll.filter("TrialList.Cycle:");
	QList<QString> T = listAll.filter("TrialList.Sample:");
	QList<QString> K = listAll.filter(QRegularExpression("Stim.*\\.RESP:"));
	//QList<QString> K = listAll.filter("Stim.RESP:");
	QList<QString> A = listAll.filter(QRegularExpression("Stim.*\\.ACC:"));
	//QList<QString> A = listAll.filter("Stim.ACC:");
	QList<QString> RT = listAll.filter(QRegularExpression("Stim.*\\.RT:"));
	//QList<QString> RT = listAll.filter("Stim.RT:");
	QList<QString> Date = listAll.filter("SessionDate:");
	QList<QString> Time = listAll.filter("SessionTime:");
	QList<QString> OnsetTime = listAll.filter(QRegularExpression("Stim.*\\.OnsetTime:"));
	//QList<QString> OnsetTime = listAll.filter("Stim.OnsetTime:");
	QList<QString> GoodByeTime = listAll.filter("Goodbye.OnsetTime:");


	int length = B.size();
	if (T.size() < length)	length = T.size();
	else if (K.size() < length)	length = K.size();
	else if (A.size() < length)	length = A.size();
	else if (RT.size() < length)	length = RT.size();
	else if (OnsetTime.size() < length) length = OnsetTime.size();
	else length = B.size();
	qDebug() << "T" << T.size();
	qDebug() << "K" << K.size();
	qDebug() << "A" << A.size();
	qDebug() << "RT" << RT.size();
	qDebug() << "OnsetTime" << OnsetTime.size();
	qDebug() << "B" << B.size();
	QStringList list;
	if (length > 0) {
		list << ("Date = " + Date[0].split(": ")[1].remove("\r"));
		list << ("Begin Time = " + Time[0].split(": ")[1].remove("\r"));
	}
	for (int i = 0; i < length; ++i) {
		QString s;

		s += QDateTime::fromString(Time[0].split(": ")[1].remove("\r"),
			"hh:mm:ss").addMSecs(OnsetTime[i].split(": ")[1].remove("\r").toInt())
			.toString("hh:mm:ss.zzz: ");
		s += "B = ";
		s += B[i].split(": ")[1].remove("\r") + ", ";
		s += "T = ";
		s += T[i].split(": ")[1].remove("\r") + ", ";
		s += "K = ";
		s += K[i].split(": ")[1].remove("\r") + ", ";
		s += "A = ";
		s += A[i].split(": ")[1].remove("\r") + ", ";
		s += "RT = ";
		s += RT[i].split(": ")[1];  
		list << s;

	}
	if (GoodByeTime.size() >0 ) {
		list << ("End Time = " + QDateTime::fromString(Time[0].split(": ")[1].remove("\r"),
			"hh:mm:ss").addMSecs(GoodByeTime[0].split(": ")[1].remove("\r").toInt())
			.toString("hh:mm:ss.zzz"));
	}
	

	return list;
}
