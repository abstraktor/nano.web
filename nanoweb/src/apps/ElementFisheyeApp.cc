#include "ElementFisheyeApp.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPolygon>
#include <QVector>
#include <QTimer>
#include <QtDebug>
#include <QtCore/qmath.h>
#include "widgets/BackgroundWidget.h"
#include "widgets/TitleBarWidget.h"
#include "widgets/TextWidget.h"
#include "widgets/ScalableButtonWidget.h"
#include "helpers.h"

#define ANIMATION_TIME 500.0
#define FRAMES 25.0

#define NOAXIS 0
#define XAXIS 1
#define YAXIS 2

namespace ipn
{

	ElementFisheyeApp::ElementFisheyeApp(QWidget *pParent) : App(pParent)
	{
		translation = QPoint();
		diff = QPoint();
		mousePressed = false;
		moves = 0;
		animationTimer = new QTimer(this);
		animationTimer->setInterval(ANIMATION_TIME / FRAMES);
		connect(animationTimer, SIGNAL(timeout()), this, SLOT(timerTick()));
		doSwiping = false;
		axis = NOAXIS;



		animationStart = QPoint();
		animationDestination = QPoint();
		tickCount = 0;


		connect(this, SIGNAL(swipeRightTriggered()), this, SLOT(swipeRight()));
		connect(this, SIGNAL(swipeUpTriggered()), this, SLOT(swipeUp()));
		connect(this, SIGNAL(swipeDownTriggered()), this, SLOT(swipeDown()));
		connect(this, SIGNAL(swipeLeftTriggered()), this, SLOT(swipeLeft()));
	}

	void ElementFisheyeApp::swipeRight()
	{
		qDebug() << "swipe right";
	}
	void ElementFisheyeApp::swipeUp()
	{
		qDebug() << "swipe up";
	}
	void ElementFisheyeApp::swipeDown()
	{
		qDebug() << "swipe down";
	}
	void ElementFisheyeApp::swipeLeft()
	{
		qDebug() << "swipe left";
	}

	void ElementFisheyeApp::timerTick()
	{
		tickCount++;
		QPoint vector = animationDestination - animationStart;
		translation = animationStart + ((float) tickCount / FRAMES) * vector;
		update();
		if (tickCount == (int) FRAMES) {
			animationTimer->stop();
			translation = animationDestination;
			tickCount = 0;
			update();
			diff = translation = QPoint();
		}
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
			lastPoint = event->pos();
			if (moves == 10) {
				double length = qSqrt(diff.x() * diff.x() + diff.y() * diff.y());
				if (length >= 5 && diff.x() != diff.y()) {
					doSwiping = true;
					// detect x or y
					if (abs(diff.x()) > abs(diff.y()))
						axis = XAXIS;
					else
						axis = YAXIS;
				}

			}
			if (axis == XAXIS)
				diff.setY(0);
			else if (axis == YAXIS)
				diff.setX(0);
			if (doSwiping) {
				translation = diff;
			}
		}
		update();
	}

	void ElementFisheyeApp::mouseReleaseEvent(QMouseEvent *) {
		if (doSwiping) {
			if (axis == XAXIS) {
				// animate x-axis
				if (abs(diff.x()) < 100)
					animationDestination = QPoint(0, 0);
				else
					animationDestination = QPoint(240 * signum(diff.x()), 0);
			}
			else if (axis == YAXIS) {
				// animate y-axis
				if (abs(diff.y()) < 100)
					animationDestination = QPoint(0, 0);
				else
					animationDestination = QPoint(0, 240 * signum(diff.y()));
			}
			animationStart = diff;
			animationTimer->start();
		}
		mousePressed = false;
		doSwiping = false;
		moves = 0;
		axis = NOAXIS;
	}

	void ElementFisheyeApp::paintEvent(QPaintEvent*)
	{
		QWebElement *el = 0;
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);

		painter.translate(translation);
		// draw select element
		painter.translate(0, 0);
		drawFisheye(&painter, el, Qt::white);
		// draw parent
		painter.translate(0, -240);
		drawFisheye(&painter, el, Qt::gray);
		// draw left sibling
		painter.translate(-240, 240);
		drawFisheye(&painter, el, Qt::gray);
		// draw right sibling
		painter.translate(480, 0);
		drawFisheye(&painter, el, Qt::gray);
		// draw child
		painter.translate(-240, 240);
		drawFisheye(&painter, el, Qt::gray);

		//for (QVector<QPolygon>::iterator p = m_drawing.begin(); p != m_drawing.end(); p++)
		//	painter.drawPolyline(*p);
	}

	void ElementFisheyeApp::drawFisheye(QPainter *painter, QWebElement *el, QColor bgcolor) {
		painter->setBrush(QBrush(bgcolor, Qt::SolidPattern));
		painter->drawRect(0, 0, 240, 240);

		painter->setPen(QPen(Qt::black, 5.0));
		painter->drawLine(60, 10, 180, 10);
		painter->drawLine(10, 60, 10, 180);
		painter->drawLine(60, 230, 180, 230);
		painter->drawLine(230, 60, 230, 180);

		painter->setFont(QFont("Ubuntu", 15 * ipn::helpers::fontSizeFactor, QFont::Bold	));
		painter->drawText(rect(), Qt::AlignCenter, "a.VertNavLink");
		painter->setFont(QFont("Ubuntu", 10, QFont::Normal	));
		painter->drawText(0, 200, 240, 20, Qt::AlignCenter, "tap to edit");
	}

	int ElementFisheyeApp::signum(int number) {
		if (number > 0)
				return 1;
		else if (number < 0)
				return -1;
		return 0;
	}

} // namespace ipn
