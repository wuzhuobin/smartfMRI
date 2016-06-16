#include "keyconfirm.hpp"

keyConfirm::keyConfirm(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);

	this->connect(this->ui.exitPushButton, SIGNAL(clicked()), this, SLOT(close()));
	char mac[18];
	getMacAdd(mac);

	this->ui.macLineEdit->setText(mac);
}

keyConfirm::~keyConfirm() {
	
}

bool keyConfirm::checkLicence()
{
	QFile licence("license.dat");
	if(!licence.exists())	return false;
	if (!licence.open(QIODevice::ReadOnly | QIODevice::Text)) return false;
	QString key = licence.readLine();
	key.remove("\n");
	qDebug() << ui.macLineEdit->text();
	qDebug() << key;
	MacEncoding mac( ui.macLineEdit->text().toStdString());
	if (key == QString::fromStdString(mac.encodeString())) return true;
	return false;
}
