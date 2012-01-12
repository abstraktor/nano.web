#include "BorderEditApp.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPolygon>
#include <QVector>
#include <QTimer>
#include <QtDebug>
#include <QRect>
#include <QtCore/qmath.h>
#include "widgets/BackgroundWidget.h"
#include "widgets/TitleBarWidget.h"
#include "widgets/TextWidget.h"
#include "widgets/ScalableButtonWidget.h"
#include "widgets/PageIndicatorWidget.h"
#include "helpers.h"
#include <QtCore/qmath.h>
#include "webhelpers.h"

#define ANIMATION_TIME 500.0
#define FRAMES 25.0

#define NOAXIS 0
#define XAXIS 1
#define YAXIS 2

namespace ipn
{

	BorderEditApp::BorderEditApp(QWidget *pParent) : App(pParent)
	{
		backgroundString = "";

		leftPressed = topPressed = bottomPressed = rightPressed = false;

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
		m_pageIndicator->move(120 - m_pageIndicator->width() / 2, 175);


		animationStart = QPoint();
		animationDestination = QPoint();
		tickCount = 0;


		topLeft = QPoint(36, 36);
		topRight = QPoint(138, 36);
		bottomLeft = QPoint(36, 128);
		bottomRight = QPoint(138, 128);

		updateView();

		connect(this, SIGNAL(swipeRightTriggered()), this, SLOT(swipeRight()));
		connect(this, SIGNAL(swipeLeftTriggered()), this, SLOT(swipeLeft()));
		connect(this, SIGNAL(backButtonClickTriggered()), this, SLOT(backButtonClick()));

	}

	void BorderEditApp::setElement(QWebElement el) {
		currentEl = el;
		updateView();
	}

	QWebElement BorderEditApp::getElement() {
		return currentEl;
	}

	void BorderEditApp::updateView() {
		update();
	}

	void BorderEditApp::backButtonClick()
	{
		qDebug() << "Backbutton clicked! ";
	}

	void BorderEditApp::swipeRight()
	{
		animationStart = translation;
		if (canLeft()) {
			animationDestination = QPoint(136, 0);
			m_pageIndicator->setActiveSegment(m_pageIndicator->getActiveSegment() + 1);
		}
		else {
			setAnimationParametersToZero();
		}
		animationTimer->start();
	}
	void BorderEditApp::swipeLeft()
	{
		animationStart = translation;
		if (canRight()) {
			animationDestination = QPoint(-136, 0);
			m_pageIndicator->setActiveSegment(m_pageIndicator->getActiveSegment() - 1);

		}
		else {
			setAnimationParametersToZero();
		}
		animationTimer->start();
	}

	void BorderEditApp::timerTick()
	{
		tickCount++;
		QPoint vector = animationDestination - animationStart;
		translation = animationStart + ((float) tickCount / FRAMES) * vector;
		updateView();
		if (tickCount == (int) FRAMES) {
			stopAnimation();
		}
	}

	void BorderEditApp::stopAnimation() {
		animationTimer->stop();
		diff = translation = animationDestination;
		tickCount = 0;
		updateView();

	}

	void BorderEditApp::mousePressEvent(QMouseEvent *event)
	{
		stopAnimation();
		QRect top = QRect(52, 0, 136, 52);
		if (top.contains(event->pos())) {
			backgroundString = ":img/boxmodel-app/bm_topbutton_pressed.png";
			topPressed = true;
		}
		QRect right = QRect(188, 52, 52, 136);
		if (right.contains(event->pos())) {
			backgroundString = ":img/boxmodel-app/bm_rightbutton_pressed.png";
			rightPressed = true;
		}
		QRect bottom = QRect(52, 188, 136, 52);
		if (bottom.contains(event->pos())) {
			backgroundString = ":img/boxmodel-app/bm_bottombutton_pressed.png";
			bottomPressed = true;
		}
		QRect left = QRect(0, 52, 52, 136);
		if (left.contains(event->pos())) {
			backgroundString = ":img/boxmodel-app/bm_leftbutton_pressed.png";
			leftPressed = true;
		}
		updateView();
	}

	void BorderEditApp::mouseMoveEvent(QMouseEvent *event)
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
				backgroundString = "";
				axis = XAXIS;
			}

				diff.setY(0);
			if (doSwiping) {
				translation = diff;
			}
		}
		updateView();
	}

	void BorderEditApp::mouseReleaseEvent(QMouseEvent *event) {
		if (doSwiping) {
			// for all pages
			animationDestination = QPoint();
			for (int i = 0; i < 3; i++) {
				if (distance(i * QPoint(-136, 0), diff) < distance(animationDestination, diff))
					animationDestination = i * QPoint(-136, 0);
			}
			m_pageIndicator->setActiveSegment(animationDestination.x() / -136);
			animationStart = diff;
			animationTimer->start();
		}
		mousePressed = false;
		doSwiping = false;
		moves = 0;
		axis = NOAXIS;
		backgroundString = "";


		QString clickedCssProperty = "";
		if (m_pageIndicator->getActiveSegment() == 0)
			clickedCssProperty = "width";
		else if (m_pageIndicator->getActiveSegment() == 1)
			clickedCssProperty = "color";
		else if (m_pageIndicator->getActiveSegment() == 2)
			clickedCssProperty = "style";
		QRect top = QRect(52, 0, 136, 52);
		if (topPressed && top.contains(event->pos()))
			emit borderEdit("border-top-" + clickedCssProperty);
		QRect right = QRect(188, 52, 52, 136);
		if (rightPressed && right.contains(event->pos()))
			emit borderEdit("border-right-" + clickedCssProperty);
		QRect bottom = QRect(52, 188, 136, 52);
		if (bottomPressed && bottom.contains(event->pos()))
			emit borderEdit("border-bottom-" + clickedCssProperty);
		QRect left = QRect(0, 52, 52, 136);
		if (leftPressed && left.contains(event->pos()))
			emit borderEdit("border-left-" + clickedCssProperty);
		updateView();

		leftPressed = topPressed = bottomPressed = rightPressed = false;
	}

	void BorderEditApp::paintEvent(QPaintEvent*)
	{

		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);
		painter.setBrush(QBrush(QColor(60, 60, 60), Qt::SolidPattern));
		painter.drawRect(0, 0, 240, 240);

		painter.setFont(QFont("Ubuntu", 15 * ipn::helpers::fontSizeFactor, QFont::Bold	));
		painter.drawText(0, 0, 240, 30, Qt::AlignCenter, "el: " + ipn::webhelpers::elementIdentifierString(currentEl));

		QPixmap pixmap = QPixmap(":img/boxmodel-app/bm_released.png");
		if (backgroundString != "")
			pixmap = QPixmap(backgroundString);
		painter.drawPixmap(0, 0, 240, 240, pixmap);


		painter.translate(translation);
		painter.setPen(QPen(Qt::white, 5.0));
		painter.drawText(52, 52, 136, 136, Qt::AlignCenter, "border\nwidth");
		painter.drawText(188, 52, 136, 136, Qt::AlignCenter, "border\ncolor");
		painter.drawText(324, 52, 136, 136, Qt::AlignCenter, "border\nstyle");
		//painter.drawText(278, 110, "border");
		//painter.drawText(283, 135, "color");
		//painter.drawText(466, 110, "border");
		//painter.drawText(466, 135, "style");
		painter.translate(-translation);

		QString cssproperty;
		if (m_pageIndicator->getActiveSegment() == 0) {
			cssproperty = "width";
			painter.setPen(QPen(Qt::black, 5.0));
			painter.drawText(0, 0, 240, 52, Qt::AlignCenter, currentEl.styleProperty("border-top-" + cssproperty, QWebElement::ComputedStyle));
			painter.rotate(90);
			painter.translate(0, -240);
			painter.drawText(0, 0, 240, 52, Qt::AlignCenter, currentEl.styleProperty("border-right-" + cssproperty, QWebElement::ComputedStyle));

			painter.translate(0, 240);
			painter.rotate(90);
			painter.translate(-240, -240);
			painter.translate(240, 240);
			painter.rotate(90);
			painter.translate(-240, 0);
			painter.drawText(0, 0, 240, 52, Qt::AlignCenter, currentEl.styleProperty("border-left-" + cssproperty, QWebElement::ComputedStyle));
			painter.translate(240, 0);
			painter.rotate(90);
			painter.drawText(0, 188, 240, 52, Qt::AlignCenter, currentEl.styleProperty("border-bottom-" + cssproperty, QWebElement::ComputedStyle));
		}
		else if (m_pageIndicator->getActiveSegment() == 1) {
			cssproperty = "color";

			QColor top, right, bottom, left;
			top = ipn::webhelpers::stringToColor(currentEl.styleProperty("border-top-color", QWebElement::ComputedStyle));
			left = ipn::webhelpers::stringToColor(currentEl.styleProperty("border-left-color", QWebElement::ComputedStyle));
			right = ipn::webhelpers::stringToColor(currentEl.styleProperty("border-right-color", QWebElement::ComputedStyle));
			bottom = ipn::webhelpers::stringToColor(currentEl.styleProperty("border-bottom-color", QWebElement::ComputedStyle));
			painter.setPen(QPen(Qt::black, 2.0));
			painter.setBrush(QBrush(top, Qt::SolidPattern));
			painter.drawRoundedRect(70, 10, 100, 32, 9.0, 9.0);
			painter.rotate(90);
			painter.translate(0, -240);
			painter.setBrush(QBrush(right, Qt::SolidPattern));
			painter.drawRoundedRect(70, 10, 100, 32, 9.0, 9.0);

			painter.translate(0, 240);
			painter.rotate(90);
			painter.translate(-240, -240);
			painter.setBrush(QBrush(bottom, Qt::SolidPattern));
			painter.drawRoundedRect(70, 10, 100, 32, 9.0, 9.0);
			painter.translate(240, 240);
			painter.rotate(90);
			painter.translate(-240, 0);
			painter.setBrush(QBrush(left, Qt::SolidPattern));
			painter.drawRoundedRect(70, 10, 100, 32, 9.0, 9.0);
			painter.translate(240, 0);
			painter.rotate(90);
			//painter.setBrush(QBrush(bottom, Qt::SolidPattern));
			//painter.drawText(0, 188, 240, 52, Qt::AlignCenter, currentEl.styleProperty("border-bottom-" + cssproperty, QWebElement::ComputedStyle));
		}
		else if (m_pageIndicator->getActiveSegment() == 2) {
			cssproperty = "style";
			painter.setPen(QPen(Qt::black, 5.0));
			painter.drawText(0, 0, 240, 52, Qt::AlignCenter, currentEl.styleProperty("border-top-" + cssproperty, QWebElement::ComputedStyle));
			painter.rotate(90);
			painter.translate(0, -240);
			painter.drawText(0, 0, 240, 52, Qt::AlignCenter, currentEl.styleProperty("border-right-" + cssproperty, QWebElement::ComputedStyle));

			painter.translate(0, 240);
			painter.rotate(90);
			painter.translate(-240, -240);
			painter.translate(240, 240);
			painter.rotate(90);
			painter.translate(-240, 0);
			painter.drawText(0, 0, 240, 52, Qt::AlignCenter, currentEl.styleProperty("border-left-" + cssproperty, QWebElement::ComputedStyle));
			painter.translate(240, 0);
			painter.rotate(90);
			painter.drawText(0, 188, 240, 52, Qt::AlignCenter, currentEl.styleProperty("border-bottom-" + cssproperty, QWebElement::ComputedStyle));
		}

	}

	bool BorderEditApp::canLeft() {
		return true;
	}
	bool BorderEditApp::canRight() {
		return true;
	}

	void BorderEditApp::setAnimationParametersToZero() {
		animationDestination = QPoint(0, 0);
	}

	int BorderEditApp::signum(int number) {
		if (number > 0)
			return 1;
		else if (number < 0)
			return -1;
		return 0;
	}
	double BorderEditApp::distance(QPoint a, QPoint b) {
		QPoint d = a - b;
		return qSqrt(d.x() * d.x() + d.y() * d.y());
	}

} // namespace ipn
