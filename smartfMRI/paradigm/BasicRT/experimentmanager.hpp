#pragma once
#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QUrl>
#include <QDir>
#include <QDirIterator>
#include "ui_experimentmanager.h"

class ExperimentManager : public QDialog {
	Q_OBJECT

public:
	ExperimentManager(QWidget * parent = Q_NULLPTR);
	~ExperimentManager();
	int setUpdataFlag(bool flag);
	bool getUpdataFlag();
	int setBeforeUrl(QUrl url);
	QUrl getBeforeUrl();
	int setParadigmUrl(QUrl url);
	QUrl getParadigmUrl();
public slots:
	int copyParadigm();


private:
	Ui::ExperimentManager ui;
	bool updataFlag;
	QUrl paradigmUrl;
	QUrl beforeUrl;
};
