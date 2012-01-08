#include "ChooseTool1App.h"
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
#include "webhelpers.h"

#define ANIMATION_TIME 500.0
#define FRAMES 25.0

#define NOAXIS 0
#define XAXIS 1
#define YAXIS 2

namespace ipn
{

	ChooseTool1App::ChooseTool1App(QWidget *pParent) : App(pParent)
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
		connect(this, SIGNAL(swipeLeftTriggered()), this, SLOT(swipeLeft()));
		connect(this, SIGNAL(backButtonClickTriggered()), this, SLOT(backButtonClick()));
	}

	void ChooseTool1App::setElement(QWebElement el) {
		currentEl = el;
		update();
	}

	void ChooseTool1App::backButtonClick()
	{
		qDebug() << "Backbutton clicked! ";
	}

	void ChooseTool1App::swipeRight()
	{
		animationStart = translation;
		if (canLeft()) {
			animationDestination = QPoint(240, 0);
			nextEl = currentEl.previousSibling();
		}
		else {
			setAnimationParametersToZero();
		}
		animationTimer->start();
	}
	void ChooseTool1App::swipeLeft()
	{
		animationStart = translation;
		if (canRight()) {
			animationDestination = QPoint(-240, 0);
			nextEl = currentEl.nextSibling();

		}
		else {
			setAnimationParametersToZero();
		}
		animationTimer->start();
	}

	void ChooseTool1App::timerTick()
	{
		tickCount++;
		QPoint vector = animationDestination - animationStart;
		translation = animationStart + ((float) tickCount / FRAMES) * vector;
		update();
		if (tickCount == (int) FRAMES) {
			animationTimer->stop();
			currentEl = nextEl;
			translation = animationDestination;
			tickCount = 0;
			update();
			diff = translation = QPoint();
		}
	}

	void ChooseTool1App::mousePressEvent(QMouseEvent *event)
	{
	}

	void ChooseTool1App::mouseMoveEvent(QMouseEvent *event)
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
			//if (moves == 1) {
			double length = qSqrt(diff.x() * diff.x() + diff.y() * diff.y());
			if (length >= 5 && diff.x() != diff.y()) {
				doSwiping = true;
				// detect x or y
				if (abs(diff.x()) > abs(diff.y()))
					axis = XAXIS;
				else
					axis = YAXIS;
			}

			//}
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

	void ChooseTool1App::mouseReleaseEvent(QMouseEvent *event) {
		if (doSwiping) {
			if (axis == XAXIS) {
				// animate x-axis
				if (abs(diff.x()) < 100) {
					animationDestination = QPoint(0, 0);
					nextEl = currentEl;
				}
				else {
					if (signum(diff.x()) == +1) {
						if (canLeft()) {
							animationDestination = QPoint(240, 0);
							nextEl = currentEl.previousSibling();
						}
						else {
							setAnimationParametersToZero();
						}
					}
					else if (signum (diff.x()) == -1) {
						if (canRight()) {
							animationDestination = QPoint(-240, 0);
							nextEl = currentEl.nextSibling();
						}
						else {
							setAnimationParametersToZero();
						}
					}
					else {
						qDebug() << "Error: should not happen";
					}
				}
			}
			animationStart = diff;
			animationTimer->start();
		}
		else {
			QRect r = QRect(60, 60, 120, 120);
			if (r.contains(event->pos()) && r.contains(event->pos() - diff) && diff.x() <= 5 && diff.y() <= 5)
				emit tapped();
		}
		mousePressed = false;
		doSwiping = false;
		moves = 0;
		axis = NOAXIS;
	}

	void ChooseTool1App::paintEvent(QPaintEvent*)
	{

		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);
		painter.setBrush(QBrush(QColor(60, 60, 60), Qt::SolidPattern));
		painter.drawRect(0, 0, 240, 240);
		painter.translate(translation);
		painter.drawText(0, 200, 240, 20, Qt::AlignCenter, "tap to go back");

	}

	bool ChooseTool1App::canLeft() {
		return true;
	}
	bool ChooseTool1App::canRight() {
		return true;
	}

	void ChooseTool1App::setAnimationParametersToZero() {
		animationDestination = QPoint(0, 0);
		nextEl = currentEl;
	}

	int ChooseTool1App::signum(int number) {
		if (number > 0)
			return 1;
		else if (number < 0)
			return -1;
		return 0;
	}

} // namespace ipn
