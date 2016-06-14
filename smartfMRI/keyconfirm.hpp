#pragma once
#include <QWidget>
#include <QFile>
#include <QDebug>
#include "MacEncoding.h"
//#include "iphelper\getmacadd.h"
#include "ui_keyconfirm.h"

class keyConfirm : public QWidget {
	Q_OBJECT

public:
	keyConfirm(QWidget * parent = Q_NULLPTR);
	~keyConfirm();
	bool checkLicence();
private:
	Ui::keyConfirm ui;
};
