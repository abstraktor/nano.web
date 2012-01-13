#include "BorderWidthApp.h"
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
#include "widgets/FlickArea.h"
#include "widgets/WidthListWidget.h"
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

        BorderWidthApp::BorderWidthApp(QWidget *parent) : App(parent)
	{
                connect(this, SIGNAL(valueChosen()), parent, SLOT(popApp()));

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


		m_picker = new WidthListWidget(this);
		m_picker->addEntry("thin");
		m_picker->addEntry("medium");
		m_picker->addEntry("thick");
		m_picker->addEntry("number");
		m_picker->move(0, 40);


		updateView();

		connect(this, SIGNAL(swipeRightTriggered()), this, SLOT(swipeRight()));
		connect(this, SIGNAL(swipeLeftTriggered()), this, SLOT(swipeLeft()));
		connect(this, SIGNAL(backButtonClickTriggered()), this, SLOT(backButtonClick()));
		connect(m_picker, SIGNAL(entryClicked(QString)), this, SLOT(entryClicked(QString)));

	}

	void BorderWidthApp::entryClicked(QString value) {
		if (value == "number") {
			emit requestNumber();
			return;
		}
		currentEl.setStyleProperty(cssproperty, value);
		emit valueChosen();
	}

	void BorderWidthApp::numberClicked(QString value) {
		qDebug() << "pppp" << value;
		currentEl.setStyleProperty(cssproperty, value);
		emit valueChosen();
	}

	void BorderWidthApp::setElement(QWebElement el) {
		currentEl = el;
		updateView();
	}

	QWebElement BorderWidthApp::getElement() {
		return currentEl;
	}

	void BorderWidthApp::updateView() {
		update();
	}

	void BorderWidthApp::backButtonClick()
	{
		qDebug() << "Backbutton clicked! ";
	}

	void BorderWidthApp::swipeRight()
	{
		animationStart = translation;
		if (canLeft()) {
			animationDestination = QPoint(188, 0);
		}
		else {
			setAnimationParametersToZero();
		}
		animationTimer->start();
	}
	void BorderWidthApp::swipeLeft()
	{
		animationStart = translation;
		if (canRight()) {
			animationDestination = QPoint(-188, 0);

		}
		else {
			setAnimationParametersToZero();
		}
		animationTimer->start();
	}

	void BorderWidthApp::timerTick()
	{
		tickCount++;
		QPoint vector = animationDestination - animationStart;
		translation = animationStart + ((float) tickCount / FRAMES) * vector;
		updateView();
		if (tickCount == (int) FRAMES) {
			animationTimer->stop();
			diff = translation = animationDestination;
			tickCount = 0;
			updateView();
		}
	}

	void BorderWidthApp::mousePressEvent(QMouseEvent *event)
	{
	}

	void BorderWidthApp::mouseMoveEvent(QMouseEvent *event)
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
				axis = XAXIS;
			}

				diff.setY(0);
			if (doSwiping) {
				translation = diff;
			}
		}
		updateView();
	}

	void BorderWidthApp::mouseReleaseEvent(QMouseEvent *event) {
		if (doSwiping) {
			// for all pages
			animationDestination = QPoint();
			for (int i = 0; i < 3; i++) {
				if (distance(i * QPoint(-188, 0), diff) < distance(animationDestination, diff))
					animationDestination = i * QPoint(-188, 0);
			}
			animationStart = diff;
			animationTimer->start();
		}
		mousePressed = false;
		doSwiping = false;
		moves = 0;
		axis = NOAXIS;
		updateView();
	}

	void BorderWidthApp::paintEvent(QPaintEvent*)
	{
		m_picker->selected = currentEl.styleProperty(cssproperty, QWebElement::CascadedStyle);

		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);
		painter.setBrush(QBrush(QColor(60, 60, 60), Qt::SolidPattern));
		painter.drawRect(0, 0, 240, 240);

		painter.setBrush(QBrush(QColor(64, 64, 64), Qt::SolidPattern));
		painter.drawRect(0, 0, 240, 40);

		painter.setPen(QPen(Qt::white, 5.0));
		painter.setFont(QFont("Ubuntu", 15 * ipn::helpers::fontSizeFactor, QFont::Bold));
		painter.drawText(0, 0, 240, 40, Qt::AlignCenter, cssproperty);
	}

	bool BorderWidthApp::canLeft() {
		return true;
	}
	bool BorderWidthApp::canRight() {
		return true;
	}

	void BorderWidthApp::setAnimationParametersToZero() {
		animationDestination = QPoint(0, 0);
	}

	int BorderWidthApp::signum(int number) {
		if (number > 0)
			return 1;
		else if (number < 0)
			return -1;
		return 0;
	}
	double BorderWidthApp::distance(QPoint a, QPoint b) {
		QPoint d = a - b;
		return qSqrt(d.x() * d.x() + d.y() * d.y());
	}

} // namespace ipn
