
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPolygon>
#include <QVector>
#include <QtWebKit>
#include <QtDebug>
#include <QApplication>
#include <QWebSettings>
#include "apps/WebviewApp.h"
#include "widgets/BackgroundWidget.h"
#include "widgets/TitleBarWidget.h"
#include "widgets/TextWidget.h"
#include "widgets/ScalableButtonWidget.h"
#include "widgets/FlickArea.h"
#include "nanoweb/NanoQWebview.h"

namespace ipn
{
	WebviewApp::WebviewApp(QWidget *pParent) : App(pParent)
	{
		/*
		m_flickArea = new FlickArea(this);
		m_flickArea->move(0, 0);
		m_flickArea->resize(240, 240);
		*/


		/*
			 * Important Websites, read and understand before editing this code:
			 *    - http://codeposts.blogspot.com/2010/06/qtwebkit-goes-mobile.html
			 *    - http://trac.webkit.org/wiki/QtWebKitTiling (slightly different)
			 *    - http://doc.qt.nokia.com/4.7-snapshot/qgraphicswebview.html#QGraphicsWebView
			 */

		// qt web settings: enable tiling and flatten frames
		QWebSettings::globalSettings()->setAttribute(QWebSettings::TiledBackingStoreEnabled, true);
		QWebSettings::globalSettings()->setAttribute(QWebSettings::FrameFlatteningEnabled, true);

		m_webView = new NanoQWebview(this);
		m_webView->resize(1000, 1000);
		m_webView->move(0, 0);
		//m_webView->load(QUrl("http://www.meilenwerk.de/Meilenwerk_Zuerichsee_index.php"));
		m_webView->load(QUrl("qrc:///meilenwerk/meilenwerk.html"));
		m_webView->load(QUrl("qrc:///meilenwerk/testpage.html"));
		m_webView->show();
		//m_webView->setZoomFactor(1.0);

		//m_webView->page()->setPreferredContentsSize(QSize(240, 240));

		// Connect gestures:
		connect(this, SIGNAL(swipeTriggered(qreal)), this, SLOT(swipe(qreal)));
		connect(this, SIGNAL(swipeRightTriggered()), this, SLOT(swipeRight()));
		connect(this, SIGNAL(swipeUpTriggered()), this, SLOT(swipeUp()));
		connect(this, SIGNAL(swipeDownTriggered()), this, SLOT(swipeDown()));
		connect(this, SIGNAL(swipeLeftTriggered()), this, SLOT(swipeLeft()));
		connect(this, SIGNAL(pinchRotationAngleChanged(qreal)), this, SLOT(changePinchRotationAngle(qreal)));
		connect(this, SIGNAL(pinchScaleFactorChanged(qreal)), this, SLOT(changePinchScaleFactor(qreal)));
		connect(this, SIGNAL(pinchInTriggered()), this, SLOT(pinchIn()));
		connect(this, SIGNAL(pinchOutTriggered()), this, SLOT(pinchOut()));
		connect(this, SIGNAL(backButtonClickTriggered()), this, SLOT(backButtonClick()));
		connect(this, SIGNAL(rightButtonClickTriggered()), this, SLOT(rightButtonClick()));
		connect(this, SIGNAL(leftButtonClickTriggered()), this, SLOT(leftButtonClick()));
		connect(m_webView, SIGNAL(elementTapped(QWebElement)), this, SIGNAL(elementTapped(QWebElement)));
	}

	void WebviewApp::mousePressEvent(QMouseEvent *event) {
		qDebug() << "Element clicked";
	}

	void WebviewApp::changePinchRotationAngle(qreal delta)
	{
	}

	void WebviewApp::changePinchScaleFactor(qreal delta)
	{
	}

	void WebviewApp::pinchIn()
	{
	}

	void WebviewApp::pinchOut()
	{
	}

	void WebviewApp::swipeLeft()
	{
	}

	void WebviewApp::swipeUp()
	{
	}

	void WebviewApp::swipeRight()
	{
	}

	void WebviewApp::swipeDown()
	{
	}

	void WebviewApp::swipe(qreal angle)
	{
		qDebug() << "EVENT: Swipe " << angle;
	}

	void WebviewApp::mouseMoveEvent(QMouseEvent *event)
	{
	}

	void WebviewApp::backButtonClick()
	{
		qDebug() << "Backbutton clicked! ";
	}

	void WebviewApp::rightButtonClick()
	{
		qDebug() << "Rightbutton clicked! ";
	}

	void WebviewApp::leftButtonClick()
	{
		qDebug() << "Leftbutton clicked! ";
	}
} // namespace ipn
