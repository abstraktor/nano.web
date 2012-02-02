#include "PaddingEditApp.h"
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


namespace ipn
{

PaddingEditApp::PaddingEditApp(QWidget *parent) : App(parent)
{
	connect(this, SIGNAL(borderEdit(QString)), parent, SLOT(switchToSpecificBorderApp(QString)));

	backgroundString = "";

	leftPressed = topPressed = bottomPressed = rightPressed = centerPressed = false;

	topLeft = QPoint(36, 36);
	topRight = QPoint(138, 36);
	bottomLeft = QPoint(36, 128);
	bottomRight = QPoint(138, 128);

	updateView();

	connect(this, SIGNAL(swipeRightTriggered()), this, SLOT(swipeRight()));
	connect(this, SIGNAL(swipeLeftTriggered()), this, SLOT(swipeLeft()));

}

void PaddingEditApp::setElement(QWebElement el) {
	currentEl = el;
	updateView();
}

QWebElement PaddingEditApp::getElement() {
	return currentEl;
}

void PaddingEditApp::updateView() {
	update();
}

void PaddingEditApp::swipeRight()
{
}
void PaddingEditApp::swipeLeft()
{
}


void PaddingEditApp::mousePressEvent(QMouseEvent *event)
{
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
	QRect center = QRect(52, 52, 136, 136);
	if (center.contains(event->pos()))
		centerPressed = true;
	updateView();
}

void PaddingEditApp::mouseReleaseEvent(QMouseEvent *event) {

	backgroundString = "";

	QRect top = QRect(52, 0, 136, 52);
	if (topPressed && top.contains(event->pos()))
		emit borderEdit("padding-top");
	QRect right = QRect(188, 52, 52, 136);
	if (rightPressed && right.contains(event->pos()))
		emit borderEdit("padding-right");
	QRect bottom = QRect(52, 188, 136, 52);
	if (bottomPressed && bottom.contains(event->pos()))
		emit borderEdit("padding-bottom");
	QRect left = QRect(0, 52, 52, 136);
	if (leftPressed && left.contains(event->pos()))
		emit borderEdit("padding-left");
	QRect center = QRect(52, 52, 136, 136);
	if (centerPressed && center.contains(event->pos()))
		emit borderEdit("padding");

	updateView();

	leftPressed = topPressed = bottomPressed = rightPressed = false;
}

void PaddingEditApp::paintEvent(QPaintEvent*)
{

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setBrush(QBrush(QColor(60, 60, 60), Qt::SolidPattern));
	painter.drawRect(0, 0, 240, 240);

	painter.setFont(QFont("Ubuntu", 15 * ipn::helpers::fontSizeFactor, QFont::Bold	));
	painter.drawText(0, 0, 240, 30, Qt::AlignCenter, "el: " + ipn::webhelpers::elementIdentifierString(currentEl));

	QPixmap pixmap = QPixmap(":img/boxmodel-app/bm_released.png");
	if (backgroundString != "")
		pixmap = QPixmap(backgroundString);
	painter.drawPixmap(0, 0, 240, 240, pixmap);

	painter.setPen(QPen(Qt::white, 5.0));
	painter.drawText(52, 52, 136, 136, Qt::AlignCenter, "padding");

	painter.setPen(QPen(Qt::black, 5.0));
	painter.drawText(0, 0, 240, 52, Qt::AlignCenter, currentEl.styleProperty("padding-top", QWebElement::ComputedStyle));
	painter.rotate(90);
	painter.translate(0, -240);
	painter.drawText(0, 0, 240, 52, Qt::AlignCenter, currentEl.styleProperty("padding-right", QWebElement::CascadedStyle));

	painter.translate(0, 240);
	painter.rotate(90);
	painter.translate(-240, -240);
	painter.translate(240, 240);
	painter.rotate(90);
	painter.translate(-240, 0);
	painter.drawText(0, 0, 240, 52, Qt::AlignCenter, currentEl.styleProperty("padding-left", QWebElement::CascadedStyle));
	painter.translate(240, 0);
	painter.rotate(90);
	painter.drawText(0, 188, 240, 52, Qt::AlignCenter, currentEl.styleProperty("padding-bottom", QWebElement::CascadedStyle));

}

bool PaddingEditApp::canLeft() {
	return true;
}
bool PaddingEditApp::canRight() {
	return true;
}


int PaddingEditApp::signum(int number) {
	if (number > 0)
		return 1;
	else if (number < 0)
		return -1;
	return 0;
}
} // namespace ipn
