#include "MainWindow.h"

#include <QtGui/QApplication>
#include <QFontDatabase>
#include <QTime>


#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsWebView>
#include <QWebSettings>

int main(int argc, char *argv[])
{
	/*	QApplication app(argc, argv);
  const int width = 640;
  const int height = 480;

  QGraphicsScene scene;

  QGraphicsView view(&scene);
  view.setFrameShape(QFrame::NoFrame);
  view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  QGraphicsWebView webview;
  webview.resize(width, height);
  webview.load(QUrl("http://www.wouwlabs.com/blogs/jeez"));

  scene.addItem(&webview);
  view.resize(width, height);
  view.show();

  return app.exec();*/

	QApplication app(argc, argv);

	// Initialize random number generator:
	qsrand(QTime(0, 0, 0, 0).msecsTo(QTime::currentTime()));

	// Add your own fonts here if you need more:
	QFontDatabase::addApplicationFont(":/fonts/Ubuntu-R.ttf");
	QFontDatabase::addApplicationFont(":/fonts/Ubuntu-B.ttf");

	ipn::MainWindow mainWindow;

	mainWindow.setOrientation(ipn::MainWindow::ScreenOrientationAuto);
	mainWindow.showExpanded();

	return app.exec();

}
