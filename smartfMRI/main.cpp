#include "smartfmri.h"
#include "keyconfirm.hpp"
#include "EncryptionAuthentication.h"

#include <QStyleFactory>
#include <QtWidgets/QApplication>


/**
 * My Main Page {#mainpage}
 * ============
 * this is Smart fMRI's main page
 * 
 *
 *
 */

int main(int argc, char *argv[])
{
	QApplication q(argc, argv);

	qApp->setStyle(QStyleFactory::create("Fusion"));
	QPalette darkPalette;
	darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
	darkPalette.setColor(QPalette::WindowText, Qt::white);
	darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
	darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
	darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
	darkPalette.setColor(QPalette::ToolTipText, Qt::white);
	darkPalette.setColor(QPalette::Text, Qt::white);
	darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
	darkPalette.setColor(QPalette::ButtonText, Qt::white);
	darkPalette.setColor(QPalette::BrightText, Qt::red);
	darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

	darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
	darkPalette.setColor(QPalette::HighlightedText, Qt::black);

	qApp->setPalette(darkPalette);

	qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");

	SmartfMRI w;
	//keyConfirm k;
	//// checkLicece, if the licence is correct, the main window will show up
	//if (k.checkLicence()) {
	//	w.show();
	//}
	//else {
	//	k.show();
	//}
	//return qApp->exec();

	EncryptionAuthentication ea(0, QString(), QString(),
		QDateTime(QDate(2017, 12, 31), QTime(24, 0, 0)), "68686868");
	ea.enableExpiredDateTimeHint(false);
	if (ea.authenticationExecAndKeyType(
		EncryptionAuthentication::HAVING_KEY |
		EncryptionAuthentication::USER_PASSWORD |
		EncryptionAuthentication::EXPIRED_DATE_TIME) != EncryptionAuthentication::NORMAL) {
		return EXIT_FAILURE;
	}
	else {
		 w.show(); 
		return qApp->exec();
	}

}
