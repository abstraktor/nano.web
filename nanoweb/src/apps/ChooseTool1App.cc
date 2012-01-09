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
#include "widgets/PageIndicatorWidget.h"
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


		m_pageIndicator = new PageIndicatorWidget(this);
		m_pageIndicator->setNumberOfSegments(3);
		m_pageIndicator->setActiveSegment(0);
		m_pageIndicator->move(120 - m_pageIndicator->width() / 2, 224);


		animationStart = QPoint();
		animationDestination = QPoint();
		tickCount = 0;

		m_topLeft1 = new ScalableButtonWidget(this);
		m_topLeft1->resize(64, 64);
		m_topLeft1->setImage(":/img/buttons/default");
		m_topLeft1->setIconImage(":/img/our_icons/edit");
		m_topLeft1->setTitle("box model");
		m_topRight1 = new ScalableButtonWidget(this);
		m_topRight1->resize(64, 64);
		m_topRight1->setImage(":/img/buttons/default");
		m_topRight1->setIconImage(":/img/our_icons/edit");
		m_topRight1->setTitle("text");
		m_bottomLeft1 = new ScalableButtonWidget(this);
		m_bottomLeft1->resize(64, 64);
		m_bottomLeft1->setImage(":/img/buttons/default");
		m_bottomLeft1->setIconImage(":/img/our_icons/edit");
		m_bottomLeft1->setTitle("color");
		m_bottomRight1 = new ScalableButtonWidget(this);
		m_bottomRight1->resize(64, 64);
		m_bottomRight1->setImage(":/img/buttons/default");
		m_bottomRight1->setIconImage(":/img/our_icons/edit");
		m_bottomRight1->setTitle("position");

		m_topLeft2 = new ScalableButtonWidget(this);
		m_topLeft2->resize(64, 64);
		m_topLeft2->setImage(":/img/buttons/default");
		m_topLeft2->setIconImage(":/img/our_icons/edit");
		m_topLeft2->setTitle("list");
		m_topRight2 = new ScalableButtonWidget(this);
		m_topRight2->resize(64, 64);
		m_topRight2->setImage(":/img/buttons/default");
		m_topRight2->setIconImage(":/img/our_icons/edit");
		m_topRight2->setTitle("add child");
		m_bottomLeft2 = new ScalableButtonWidget(this);
		m_bottomLeft2->resize(64, 64);
		m_bottomLeft2->setImage(":/img/buttons/default");
		m_bottomLeft2->setIconImage(":/img/our_icons/edit");
		m_bottomLeft2->setTitle("attributes");
		m_bottomRight2 = new ScalableButtonWidget(this);
		m_bottomRight2->resize(64, 64);
		m_bottomRight2->setImage(":/img/buttons/default");
		m_bottomRight2->setIconImage(":/img/our_icons/edit");
		m_bottomRight2->setTitle("delete");

		topLeft = QPoint(36, 36);
		topRight = QPoint(138, 36);
		bottomLeft = QPoint(36, 128);
		bottomRight = QPoint(138, 128);

		updateView();

		connect(this, SIGNAL(swipeRightTriggered()), this, SLOT(swipeRight()));
		connect(this, SIGNAL(swipeLeftTriggered()), this, SLOT(swipeLeft()));
		connect(this, SIGNAL(backButtonClickTriggered()), this, SLOT(backButtonClick()));
	}

	void ChooseTool1App::setElement(QWebElement el) {
		currentEl = el;
		updateView();
	}

	void ChooseTool1App::updateView() {
		update();
		QPoint standardTranslation = QPoint(240, 0);
		QPoint tl1 = topLeft + translation - m_pageIndicator->getActiveSegment() * standardTranslation;
		m_topLeft1->move(tl1.x(), tl1.y());
		QPoint tr1 = topRight + translation - m_pageIndicator->getActiveSegment() * standardTranslation;
		m_topRight1->move(tr1.x(), tr1.y());
		QPoint bl1 = bottomLeft + translation - m_pageIndicator->getActiveSegment() * standardTranslation;
		m_bottomLeft1->move(bl1.x(), bl1.y());
		QPoint br1 = bottomRight + translation - m_pageIndicator->getActiveSegment() * standardTranslation;
		m_bottomRight1->move(br1.x(), br1.y());

		QPoint tl2 = topLeft + translation + standardTranslation - m_pageIndicator->getActiveSegment() * standardTranslation;
		m_topLeft2->move(tl2.x(), tl2.y());
		QPoint tr2 = topRight + translation + standardTranslation - m_pageIndicator->getActiveSegment() * standardTranslation;
		m_topRight2->move(tr2.x(), tr2.y());
		QPoint bl2 = bottomLeft + translation + standardTranslation - m_pageIndicator->getActiveSegment() * standardTranslation;
		m_bottomLeft2->move(bl2.x(), bl2.y());
		QPoint br2 = bottomRight + translation + standardTranslation - m_pageIndicator->getActiveSegment() * standardTranslation;
		m_bottomRight2->move(br2.x(), br2.y());
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
			m_pageIndicator->setActiveSegment(m_pageIndicator->getActiveSegment() + 1);
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
			m_pageIndicator->setActiveSegment(m_pageIndicator->getActiveSegment() - 1);

		}
		else {
			setAnimationParametersToZero();
		}
		animationTimer->start();
	}

	void ChooseTool1App::timerTick()
	{
		tickCount++;
		//qDebug() << "dest :" << animationDestination;
		//qDebug() << "start:" << animationStart;
		//QPoint vector = animationDestination - animationStart;
		translation = animationStart - ((float) tickCount / FRAMES) * animationStart;
		//translation = (animationStart + QPoint(240, 0)) - ((float) tickCount / FRAMES) * (animationStart + QPoint(240, 0));;
		updateView();
		if (tickCount == (int) FRAMES) {
			animationTimer->stop();
			translation = animationDestination;
			tickCount = 0;
			updateView();
			diff = translation = QPoint();
			updateView();
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
				//if (abs(diff.x()) > abs(diff.y()))
					axis = XAXIS;
			}

			//}
			//if (axis == XAXIS)
				diff.setY(0);
			if (doSwiping) {
				translation = diff;
			}
		}
		updateView();
	}

	void ChooseTool1App::mouseReleaseEvent(QMouseEvent *event) {
		if (doSwiping) {
			if (axis == XAXIS) {
				// animate x-axis
				if (abs(diff.x()) < 100) {
					animationDestination = m_pageIndicator->getActiveSegment() * QPoint(240, 0);
					animationStart = diff;
				}
				else {
					if (signum(diff.x()) == +1) {
						if (canLeft()) {
							m_pageIndicator->setActiveSegment(m_pageIndicator->getActiveSegment() - 1);
							animationDestination = m_pageIndicator->getActiveSegment() * QPoint(240, 0);
							animationStart = diff - QPoint(240, 0);
						}
						else {
							setAnimationParametersToZero();
						}
					}
					else if (signum (diff.x()) == -1) {
						if (canRight()) {
							m_pageIndicator->setActiveSegment(m_pageIndicator->getActiveSegment() + 1);
							animationDestination = m_pageIndicator->getActiveSegment() * QPoint(240, 0);
							animationStart = diff + QPoint(240, 0);
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
			//animationStart = diff;
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

		painter.setPen(QPen(Qt::white, 5.0));
		painter.setFont(QFont("Ubuntu", 15 * ipn::helpers::fontSizeFactor, QFont::Bold	));
		painter.drawText(0, 0, 240, 30, Qt::AlignCenter, "el: " + ipn::webhelpers::elementIdentifierString(currentEl));

	}

	bool ChooseTool1App::canLeft() {
		return true;
	}
	bool ChooseTool1App::canRight() {
		return true;
	}

	void ChooseTool1App::setAnimationParametersToZero() {
		animationDestination = QPoint(0, 0);
	}

	int ChooseTool1App::signum(int number) {
		if (number > 0)
			return 1;
		else if (number < 0)
			return -1;
		return 0;
	}

} // namespace ipn
