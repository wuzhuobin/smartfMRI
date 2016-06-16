#pragma once
#include <QWidget>
#include <QFile>
#include <QDebug>
#include "MacEncoding.h"
#include "iphelper\getmacadd.h"
#include "ui_keyconfirm.h"
/**
 * @class keyConfirm
 * check the licence file is correct or not
 * @author
 * @version
 */
class keyConfirm : public QWidget {
	Q_OBJECT

public:
	/**
	 * Constructor
	 * @param parent the parent
	 *
	 */
	keyConfirm(QWidget * parent = Q_NULLPTR);
	/**
	 * Destructor
	 */
	~keyConfirm();
	/**
	 * check the licence.bat in ./licence.bat
	 * if it exists and is correct, return true
	 * @return true if correct
	 *         false if incorrect
	 */
	bool checkLicence();
private:
	// ui
	Ui::keyConfirm ui;
};
