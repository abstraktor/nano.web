#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPolygon>
#include <QVector>
#include <QDebug>
#include "widgets/BackgroundWidget.h"
#include "widgets/TitleBarWidget.h"
#include "widgets/TextWidget.h"
#include "widgets/ScalableButtonWidget.h"
#include "helpers.h"
#include "webhelpers.h"
#include "ElementTappedApp.h"

namespace ipn
{

ElementTappedApp::ElementTappedApp(QWidget *parent) : App(parent)
{
	connect(this, SIGNAL(elementTapped(QWebElement)), parent, SLOT(switchToElementFisheye(QWebElement)));
	connect(this, SIGNAL(leftButtonClicked()), parent, SLOT(switchToElementFisheye()));
	connect(this, SIGNAL(editButtonClicked()), parent, SLOT(switchToChooseTool1App()));

	buttonColor = QColor(180, 180, 180);
	isElementTapped = false;

	m_explainText = new TextWidget(this);
	m_explainText->setColor(Qt::white);
	m_explainText->move(0, 0);
	m_explainText->resize(240, 30);
	m_explainText->setFontSize(12);
	m_explainText->setText("Your selection:");
	m_explainText->setText("");


	m_editElementButton = new ScalableButtonWidget(this);
	m_editElementButton->move(150, 150);
	m_editElementButton->resize(60, 60);
	m_editElementButton->setImage(":/img/buttons/default");
	m_editElementButton->setIconImage(":/img/our_icons/edit");
	m_editElementButton->setTitle("edit");
	connect(m_editElementButton, SIGNAL(clicked()), this, SIGNAL(editButtonClicked()));

	m_refineButton = new ScalableButtonWidget(this);
	m_refineButton->move(30, 150);
	m_refineButton->resize(60, 60);
	m_refineButton->setImage(":/img/buttons/default");
	m_refineButton->setIconImage(":/img/our_icons/refine");
	m_refineButton->setTitle("");
	connect(m_refineButton, SIGNAL(clicked()), this, SIGNAL(leftButtonClicked()));


	// Connect gestures:
	connect(this, SIGNAL(swipeRightTriggered()), this, SLOT(swipeRight()));
	connect(this, SIGNAL(swipeUpTriggered()), this, SLOT(swipeUp()));
	connect(this, SIGNAL(swipeDownTriggered()), this, SLOT(swipeDown()));
	connect(this, SIGNAL(swipeLeftTriggered()), this, SLOT(swipeLeft()));
	connect(this, SIGNAL(pinchInTriggered()), this, SLOT(pinchIn()));
	connect(this, SIGNAL(pinchOutTriggered()), this, SLOT(pinchOut()));
}

void ElementTappedApp::mousePressEvent(QMouseEvent *event)
{
	/*
		if (event->pos().y() <= 120) {
			buttonColor = QColor(100, 100, 100);
			update();
		}
		*/
}

void ElementTappedApp::mouseReleaseEvent(QMouseEvent *event)
{
	update();
	/*
		if (event->pos().y() <= 120) {
			buttonColor = QColor(180, 180, 180);
			update();
			emit elementTapped(currentEl);
		}
		*/
}

void ElementTappedApp::elementTappedInFisheye(QWebElement el) {
	currentEl = el;
	updateView();
}

void ElementTappedApp::updateView() {
	//m_refineButton->setEnabled(currentEl.tagName() == "A");
	update();

}

QWebElement ElementTappedApp::getElement() {
	return currentEl;
}

void ElementTappedApp::setElement(QWebElement el) {
	currentEl = el;
	updateView();
}

void ElementTappedApp::pinchIn()
{
}

void ElementTappedApp::pinchOut()
{
}

void ElementTappedApp::swipeLeft()
{
}

void ElementTappedApp::swipeUp()
{
}

void ElementTappedApp::swipeRight()
{
}

void ElementTappedApp::swipeDown()
{
}


void ElementTappedApp::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	painter.setBrush(QBrush(QColor(64, 64, 64), Qt::SolidPattern));
	painter.drawRect(0, 0, 240, 240);

	painter.setBrush(QBrush(buttonColor, Qt::SolidPattern));
	//painter.drawRoundedRect(40, 50, 160, 70, 10.0, 10.0);

	if (!isElementTapped)
		painter.setBrush(QBrush(QColor(255, 255, 255), Qt::SolidPattern));
	else
		painter.setBrush(QBrush(QColor(200, 200, 200), Qt::SolidPattern));
	painter.setPen(Qt::NoPen);
	//painter.drawRoundedRect(15, 40, 210, 90, 15.0, 15.0);
	painter.setPen(Qt::SolidLine);


	QPixmap pix;
	pix = QPixmap(":img/our_imgs/elementTapped_background.png");
	painter.drawPixmap(0, 28, 240, 110, pix);

	painter.setPen(QPen(Qt::white, 5.0));
	painter.setFont(QFont("Ubuntu", 15 * ipn::helpers::fontSizeFactor, QFont::Bold));

	painter.drawText(20, 30, 240, 30, Qt::AlignLeft, ipn::webhelpers::elementShortIdentifierString(currentEl));
	QString elementType = ipn::webhelpers::elementTypeString(currentEl);
	painter.drawText(20, 60, 240, 30, Qt::AlignLeft, elementType);

	if (currentEl.tagName().toUpper() == "IMG") {
		QPixmap pixmap;
		if (currentEl.attribute("src").contains("MW_Logo"))
			pixmap = QPixmap(":img/our_imgs/meilenwerk.png");
		if (currentEl.attribute("src").contains("zuerichsee"))
			pixmap = QPixmap(":img/our_imgs/zurichsee.png");
		painter.drawPixmap(20, 95, 200, 35, pixmap);
	}
	else {
		painter.drawText(20, 87, 240, 30, Qt::AlignLeft, ipn::webhelpers::elementContentString(currentEl));
	}

	painter.setFont(QFont("Ubuntu", 11 * ipn::helpers::fontSizeFactor, QFont::Bold));
	painter.drawText(5, 209, 120, 30, Qt::AlignCenter, "refine selection");
	painter.setBrush(QBrush(QColor(64, 64, 64), Qt::SolidPattern));
	painter.setPen(QPen(QColor(30, 30, 30), 0));
	painter.drawRect(0, 0, 240, 28);
	painter.setPen(QPen(Qt::white, 0));
	painter.drawText(0, 0, 240, 28, Qt::AlignCenter, "YOUR SELECTION");
}


} // namespace ipn
