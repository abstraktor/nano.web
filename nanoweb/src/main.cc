#include "MainWindow.h"

#include <QtGui/QApplication>
#include <QFontDatabase>
#include <QTime>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	// Initialize random number generator:
	qsrand(QTime(0, 0, 0, 0).msecsTo(QTime::currentTime()));

	// Add your own fonts here if you need more:
	QFontDatabase::addApplicationFont(":/fonts/Ubuntu-R.ttf");
	QFontDatabase::addApplicationFont(":/fonts/Ubuntu-B.ttf");

	ipn::MainWindow mainWindow;

        QFont font = qApp->font();
        font.setPixelSize(2);
        qApp->setFont(font);

	mainWindow.setOrientation(ipn::MainWindow::ScreenOrientationAuto);
	mainWindow.showExpanded();

	return app.exec();
}
