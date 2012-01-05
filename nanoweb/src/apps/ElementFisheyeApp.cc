#include "ElementFisheyeApp.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPolygon>
#include <QVector>
#include <QTimer>
#include <QtDebug>
#include <math.h>
#include "widgets/BackgroundWidget.h"
#include "widgets/TitleBarWidget.h"
#include "widgets/TextWidget.h"
#include "widgets/ScalableButtonWidget.h"

namespace ipn
{

	ElementFisheyeApp::ElementFisheyeApp(QWidget *pParent) : App(pParent)
	{

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

		translation = QPoint();
		diff = QPoint();
		mousePressed = false;
		moves = 0;
		animationTimer = new QTimer(this);
		doSwiping = false;
		axis = 0;
	}

	void ElementFisheyeApp::changePinchRotationAngle(qreal delta)
	{
	}

	void ElementFisheyeApp::changePinchScaleFactor(qreal delta)
	{
	}

	void ElementFisheyeApp::pinchIn()
	{
	}

	void ElementFisheyeApp::pinchOut()
	{
	}

	void ElementFisheyeApp::swipeLeft()
	{
	}

	void ElementFisheyeApp::swipeUp()
	{
	}

	void ElementFisheyeApp::swipeRight()
	{
	}

	void ElementFisheyeApp::swipeDown()
	{
	}

	void ElementFisheyeApp::swipe(qreal angle)
	{
	}

	void ElementFisheyeApp::mousePressEvent(QMouseEvent *event)
	{
	}

	void ElementFisheyeApp::mouseMoveEvent(QMouseEvent *event)
	{
		if (!event->buttons() == Qt::LeftButton)
				return;
		if (!mousePressed) {
			mousePressed = true;
			lastPoint = event->pos();
			return;
		}
		else {
			moves++;
			diff = diff + (event->pos() - lastPoint);
		//	qDebug() << diff;
			lastPoint = event->pos();
			if (moves == 15) {
				double length = sqrt(pow(diff.x(), 2) + pow(diff.y(), 2));
				if (length >= 5 && diff.x() != diff.y()) {
					doSwiping = true;
					// detect x or y
					if (abs(diff.x()) > abs(diff.y()))
						axis = 1;
					else
						axis = 2;
					qDebug() << diff;
					qDebug() << axis;
				}

			}
			if (axis == 1)
				diff.setY(0);
			else if (axis == 2)
				diff.setX(0);
			if (doSwiping) {
				translation = diff;
			}
		}
		update();
	}

	void ElementFisheyeApp::mouseReleaseEvent(QMouseEvent *) {
		mousePressed = false;
		doSwiping = false;
		moves = 0;
		axis = 0;
	}

	void ElementFisheyeApp::paintEvent(QPaintEvent*)
	{
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);

		// paint white background
		painter.setBrush(QBrush(QColor(240, 240, 240), Qt::SolidPattern));
		painter.drawRect(0, 0, 240, 240);

		painter.translate(translation);
		// draw select element
		painter.translate(0, 0);
		drawFisheye(&painter);
		// draw parent
		painter.translate(0, -240);
		drawFisheye(&painter);
		// draw left sibling
		painter.translate(-240, 240);
		drawFisheye(&painter);
		// draw right sibling
		painter.translate(480, 0);
		drawFisheye(&painter);
		// draw child
		painter.translate(-240, 240);
		drawFisheye(&painter);

		//for (QVector<QPolygon>::iterator p = m_drawing.begin(); p != m_drawing.end(); p++)
		//	painter.drawPolyline(*p);
	}

	void ElementFisheyeApp::drawFisheye(QPainter *painter, QWebElement *el) {
		painter->setPen(QPen(Qt::black, 5.0));
		painter->drawLine(60, 10, 180, 10);
		painter->drawLine(10, 60, 10, 180);
		painter->drawLine(60, 230, 180, 230);
		painter->drawLine(230, 60, 230, 180);

		painter->setFont(QFont("Ubuntu", 14, QFont::Bold	));
		painter->drawText(rect(), Qt::AlignCenter, "a.VertNavLink");
		painter->setFont(QFont("Ubuntu", 10, QFont::Normal	));
		painter->drawText(0, 200, 240, 20, Qt::AlignCenter, "tap to edit");
	}

} // namespace ipn
