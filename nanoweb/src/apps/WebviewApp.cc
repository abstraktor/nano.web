#include "apps/WebviewApp.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPolygon>
#include <QVector>
#include <QtWebKit>
#include <QtDebug>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsWebView>
#include <QWebSettings>
#include "widgets/BackgroundWidget.h"
#include "widgets/TitleBarWidget.h"
#include "widgets/TextWidget.h"
#include "widgets/ScalableButtonWidget.h"
#include "nanoweb/NanoWebView.h"

namespace ipn
{
	WebviewApp::WebviewApp(QWidget *pParent) : App(pParent)
	{

		m_currentScaleFactor = 1.0;
		m_currentRotationAngle = 0.0;

		/*
		 * Important Websites, read and understand before editing this code:
		 *    - http://codeposts.blogspot.com/2010/06/qtwebkit-goes-mobile.html
		 *    - http://trac.webkit.org/wiki/QtWebKitTiling (slightly different)
		 *    - http://doc.qt.nokia.com/4.7-snapshot/qgraphicswebview.html#QGraphicsWebView
		 */

		// qt web settings: enable tiling and flatten frames
		QWebSettings::globalSettings()->setAttribute(QWebSettings::TiledBackingStoreEnabled, true);
		QWebSettings::globalSettings()->setAttribute(QWebSettings::FrameFlatteningEnabled, true);

		m_scene = new QGraphicsScene();

		m_webView = new NanoWebView();
		m_webView->resize(240, 240);
		m_webView->load(QUrl("http://www.meilenwerk.de/"));
		m_webView->setResizesToContents(true);
		m_webView->setZoomFactor(1.0);

		m_scene->addItem(m_webView);

		m_graphicsView = new QGraphicsView(m_scene, this);
		m_graphicsView->setFrameShape(QFrame::NoFrame);
		m_graphicsView->move(0, 0);
		m_graphicsView->resize(240, 240);
		m_graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		m_graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

		m_graphicsView->show();

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
} // namespace ipn
