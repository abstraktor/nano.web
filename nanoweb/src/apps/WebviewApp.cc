#include "apps/WebviewApp.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPolygon>
#include <QVector>
#include <QtWebKit>
#include "widgets/BackgroundWidget.h"
#include "widgets/TitleBarWidget.h"
#include "widgets/TextWidget.h"
#include "widgets/ScalableButtonWidget.h"

namespace ipn
{
	WebviewApp::WebviewApp(QWidget *pParent) : App(pParent)
	{

		m_currentScaleFactor = 1.0;
		m_currentRotationAngle = 0.0;

		m_webView = new QWebView(this);
		m_webView->load(QUrl("http://www.meilenwerk.de/"));
		m_webView->move(00, 00);
		m_webView->resize(240, 240);
		m_webView->show();

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

	void WebviewApp::changePinchRotationAngle(qreal delta)
	{
		m_currentRotationAngle += delta;
		m_rotationAngleText->setText("rotation angle: " + QString::number(m_currentRotationAngle) + "°");

		update();
	}

	void WebviewApp::changePinchScaleFactor(qreal delta)
	{
		m_currentScaleFactor *= delta;
		m_scaleFactorText->setText("scaleFactor: " + QString::number(m_currentScaleFactor) + "x");

		update();
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
		m_swipeAngleText->setText("swipe angle: " + QString::number(angle) + "°");
		update();
	}

	void WebviewApp::mousePressEvent(QMouseEvent *event)
	{
		// Begin a new line:
		QPolygon newPolyLine;
		newPolyLine.push_back(event->pos());
		m_drawing.push_back(newPolyLine);
	}

	void WebviewApp::mouseMoveEvent(QMouseEvent *event)
	{
		if (m_drawing.empty())
			return;

		if (event->buttons() == Qt::LeftButton)
			m_drawing.back().push_back(event->pos());

		update();
	}
} // namespace ipn
