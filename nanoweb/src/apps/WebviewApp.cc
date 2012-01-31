
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
WebviewApp::WebviewApp(QWidget *parent, bool displayWidget) : App(parent)
{
	connect(this, SIGNAL(elementTapped(QWebElement)), parent, SLOT(switchToElementTapped(QWebElement)));

	m_flickArea = new FlickArea(this);
	//m_flickArea->move(0, 0);
	m_flickArea->resize(240, 240);

	// qt web settings: enable tiling and flatten frames
	QWebSettings::globalSettings()->setAttribute(QWebSettings::TiledBackingStoreEnabled, true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::FrameFlatteningEnabled, true);

	m_webView = new NanoQWebview(m_flickArea);
	m_webView->resize(930, 525);
   // m_webView->move(0, 0);
	m_webView->load(QUrl("qrc:///meilenwerk/meilenwerk.html"));
	//m_webView->load(QUrl("qrc:///meilenwerk/testpage.html"));
	m_webView->show();
	m_webView->setZoomFactor(1.0);


	name = "WebViewApp";
	if (displayWidget) {
		m_text = new TextWidget(this);
		m_text->otherStyle = true;
		m_text->setText("Webseite");
		m_text->resize(100, 30);
		m_text->move(140, 210);
		//name = "WebViewApp2";
	}

	iAmBackButtonWebView = displayWidget;


	// Connect gestures:
	connect(this, SIGNAL(swipeTriggered(qreal)), this, SLOT(swipe(qreal)));
	connect(this, SIGNAL(swipeRightTriggered()), this, SLOT(swipeRight()));
	connect(this, SIGNAL(swipeUpTriggered()), this, SLOT(swipeUp()));
	connect(this, SIGNAL(swipeDownTriggered()), this, SLOT(swipeDown()));
	connect(this, SIGNAL(swipeLeftTriggered()), this, SLOT(swipeLeft()));
	connect(this, SIGNAL(pinchScaleFactorChanged(qreal)), this, SLOT(changePinchScaleFactor(qreal)));
	connect(this, SIGNAL(pinchInTriggered()), this, SLOT(pinchIn()));
	connect(this, SIGNAL(pinchOutTriggered()), this, SLOT(pinchOut()));
	//connect(m_webView,SIGNAL(mouseClickEvent(QMouseEvent *)),this,SLOT(mousePressEvent(QMouseEvent *)));

	connect(this, SIGNAL(setScrollPosition(QPoint)), parent, SLOT(setContentScrollPosition(QPoint)));
	connect(this, SIGNAL(getContentScrollPosition()), parent, SLOT(getContentScrollPosition()));
	connect(this, SIGNAL(setContentZoomFactor(double)), parent, SLOT(setContentZoomFactor(double)));
	connect(this, SIGNAL(getContentZoomFactor()), parent, SLOT(getContentZoomFactor()));
	connect(m_webView, SIGNAL(moved(QPoint)), this, SLOT(sendUpdatedInfo()));

	connect(m_webView, SIGNAL(mouseClick(QMouseEvent*)), this, SLOT(elementTappedHandler(QMouseEvent*)));
	updateView();
}

QPoint WebviewApp::getScrollPosition() {
	return m_webView->pos();
}


void WebviewApp::elementTappedHandler(QMouseEvent* event) {
	QPoint pos = event->pos();
	QWebElement el = m_webView->page()->mainFrame()->hitTestContent(pos).element();
	if (el.tagName() == "")
		el = m_webView->page()->mainFrame()->hitTestContent(pos).linkElement();  // for link element

	if (el.tagName() == "") {
		return;
	}

	//el.setStyleProperty("background-color", "red !important"); // PROOF OF CONCEPT
	emit elementTapped(el);
}

void WebviewApp::mouseReleaseEvent(QMouseEvent *event) {

}

void WebviewApp::updateView() {
	raise();
	m_webView->setZoomFactor(emit getContentZoomFactor());
	m_webView->move(emit getContentScrollPosition());
	m_webView->resize(930 * m_webView->zoomFactor() >= 240 ? 930 * m_webView->zoomFactor() : 240, 525 * m_webView->zoomFactor() >= 240 ? 525 * m_webView->zoomFactor() : 240);
	m_webView->update();
	update();
}

void WebviewApp::changePinchScaleFactor(qreal delta)
{
	m_webView->setZoomFactor(m_webView->zoomFactor() * delta);
	if (m_webView->zoomFactor() >= 3.0)
	{
		m_webView->setZoomFactor(3.0);
	}
	if (m_webView->zoomFactor() < 0.2)
	{
		m_webView->setZoomFactor(0.2);
	}

	QPoint p = m_webView->pos() - QPoint(120, 120);
	p = p * delta;
	p = p + QPoint(120, 120);
	p = setPositionCorrectly(p);
	m_webView->move(p);
	sendUpdatedInfo();
	updateView();
	emit zoomTriggered();
}

QPoint WebviewApp::setPositionCorrectly(QPoint p) {
	if (abs(p.x()) > (930 * m_webView->zoomFactor() - 240))
		p.setX(-(930 * m_webView->zoomFactor() - 240));
	if (abs(p.y()) > (525 * m_webView->zoomFactor() - 240))
		p.setY(-(525 * m_webView->zoomFactor() - 240));
	if (p.x() >= 0)
		p.setX(0);
	if (p.y() >= 0)
		p.setY(0);
	return p;
}

void WebviewApp::sendUpdatedInfo() {
	emit setContentZoomFactor(m_webView->zoomFactor());
	emit setScrollPosition(m_webView->pos());
	updateView();
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
