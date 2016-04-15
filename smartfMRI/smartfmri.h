#ifndef SMARTFMRI_H
#define SMARTFMRI_H

#include <QtWidgets/QMainWindow>
#include "ui_smartfmri.h"

class smartfMRI : public QMainWindow
{
	Q_OBJECT

public:
	smartfMRI(QWidget *parent = 0);
	~smartfMRI();

private:
	Ui::smartfMRIClass ui;
};

#endif // SMARTFMRI_H
