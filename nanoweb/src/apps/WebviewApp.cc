
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPolygon>
#include <QVector>
#include <QtWebKit>
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
WebviewApp::WebviewApp(QWidget *parent) : App(parent)
{

	connect(this, SIGNAL(elementTapped(QWebElement)), parent, SLOT(switchToElementTapped(QWebElement)));

	mousePressed = false;
	doSwiping = false;
	doZooming = false;

	translation = QPoint();
	diff = QPoint();
	lastPoint = QPoint();

	/*
	m_flickArea = new FlickArea(this);
	m_flickArea->move(0, 0);
	m_flickArea->resize(240, 240);
	*/



	// qt web settings: enable tiling and flatten frames
	QWebSettings::globalSettings()->setAttribute(QWebSettings::TiledBackingStoreEnabled, true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::FrameFlatteningEnabled, true);

	m_webView = new NanoQWebview(this);
	m_webView->resize(10000, 10000);
	m_webView->move(0, 0);
	m_webView->load(QUrl("qrc:///meilenwerk/meilenwerk.html"));
	//m_webView->load(QUrl("qrc:///meilenwerk/testpage.html"));
	m_webView->show();
	m_webView->setZoomFactor(1.0);

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


	connect(m_webView, SIGNAL(elementTapped(QWebElement)), this, SLOT(elementTappedHandler(QWebElement)));
}

void WebviewApp::elementTappedHandler(QWebElement el) {
	if (!doSwiping && !doZooming) {
		emit elementTapped(el);
	}
}

void WebviewApp::mousePressEvent(QMouseEvent *event) {
	doZooming = false;
}

void WebviewApp::mouseMoveEvent(QMouseEvent *event)
{
	if (!event->buttons() == Qt::LeftButton)
		return;
	if (!mousePressed) {
		mousePressed = true;
		lastPoint = event->pos();
		return;
	}
	else {
		diff = diff + (event->pos() - lastPoint);
		lastPoint = event->pos();
		double length = qSqrt(diff.x() * diff.x() + diff.y() * diff.y());
		if (length >= 2) {
			doSwiping = true;
		}
		if (doSwiping) {
			setDiffCorrectly();
			translation = diff;
		}
	}
	updateView();
}

void WebviewApp::setDiffCorrectly() {
	if (abs(diff.x()) > (930 * m_webView->zoomFactor() - 240))
		diff.setX(-(930 * m_webView->zoomFactor() - 240));
	if (abs(diff.y()) > (525 * m_webView->zoomFactor() - 240))
		diff.setY(-(525 * m_webView->zoomFactor() - 240));
	if (diff.x() > 0)
		diff.setX(0);
	if (diff.y() > 0)
		diff.setY(0);
}

void WebviewApp::mouseReleaseEvent(QMouseEvent *event) {
	mousePressed = false;
	doSwiping = false;
}

void WebviewApp::changePinchRotationAngle(qreal delta)
{
}


void WebviewApp::updateView() {
	update();
	m_webView->move(translation.x(), translation.y());
	m_webView->update();
}

void WebviewApp::changePinchScaleFactor(qreal delta)
{
	doZooming = true;
	m_webView->setZoomFactor(m_webView->zoomFactor() * delta);
	if (m_webView->zoomFactor() >= 3.0)
	{
		m_webView->setZoomFactor(3.0);
		return;
	}
	if (m_webView->zoomFactor() < 0.2)
	{
		m_webView->setZoomFactor(0.2);
		return;
	}
	if (delta > 1.0) {
		diff = diff - QPoint(120, 120);
		diff = diff * delta;
		diff = diff + QPoint(120, 120);
	}
	else {
		diff = diff * delta;
	}
	setDiffCorrectly();
	translation = diff;
	updateView();
	emit zoomTriggered();
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
}


} // namespace ipn
