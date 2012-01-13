#include "ChooseToolBoxmodelApp.h"
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
#include <QtCore/qmath.h>
#include "webhelpers.h"

#define ANIMATION_TIME 500.0
#define FRAMES 25.0

#define NOAXIS 0
#define XAXIS 1
#define YAXIS 2

namespace ipn
{

        ChooseToolBoxmodelApp::ChooseToolBoxmodelApp(QWidget *parent) : App(parent)
	{
                connect(this, SIGNAL(borderButtonClicked()), parent, SLOT(switchToBorderApp()));

		m_topLeft1 = new ScalableButtonWidget(this);
		m_topLeft1->resize(64, 64);
		m_topLeft1->setImage(":/img/buttons/default");
		m_topLeft1->setIconImage(":/img/our_icons/edit");
		m_topLeft1->setTitle("border");
		m_topRight1 = new ScalableButtonWidget(this);
		m_topRight1->resize(64, 64);
		m_topRight1->setImage(":/img/buttons/default");
		m_topRight1->setIconImage(":/img/our_icons/edit");
		m_topRight1->setTitle("margin");
		m_bottomLeft1 = new ScalableButtonWidget(this);
		m_bottomLeft1->resize(64, 64);
		m_bottomLeft1->setImage(":/img/buttons/default");
		m_bottomLeft1->setIconImage(":/img/our_icons/edit");
		m_bottomLeft1->setTitle("padding");
		m_bottomRight1 = new ScalableButtonWidget(this);
		m_bottomRight1->resize(64, 64);
		m_bottomRight1->setImage(":/img/buttons/default");
		m_bottomRight1->setIconImage(":/img/our_icons/edit");
		m_bottomRight1->setTitle("dimension");

		topLeft = QPoint(36, 36);
		topRight = QPoint(138, 36);
		bottomLeft = QPoint(36, 128);
		bottomRight = QPoint(138, 128);

		updateView();

		connect(this, SIGNAL(backButtonClickTriggered()), this, SLOT(backButtonClick()));
		connect(m_topLeft1, SIGNAL(clicked()), this, SIGNAL(borderButtonClicked()));
	}

	void ChooseToolBoxmodelApp::setElement(QWebElement el) {
		currentEl = el;
		updateView();
	}

	QWebElement ChooseToolBoxmodelApp::getElement() {
		return currentEl;
	}

	void ChooseToolBoxmodelApp::updateView() {
		update();
		QPoint tl1 = topLeft;
		m_topLeft1->move(tl1.x(), tl1.y());
		QPoint tr1 = topRight;
		m_topRight1->move(tr1.x(), tr1.y());
		QPoint bl1 = bottomLeft;
		m_bottomLeft1->move(bl1.x(), bl1.y());
		QPoint br1 = bottomRight;
		m_bottomRight1->move(br1.x(), br1.y());
	}

	void ChooseToolBoxmodelApp::backButtonClick()
	{
		qDebug() << "Backbutton clicked! ";
	}

	void ChooseToolBoxmodelApp::mousePressEvent(QMouseEvent *event)
	{
	}

	void ChooseToolBoxmodelApp::mouseMoveEvent(QMouseEvent *event)
	{
	}

	void ChooseToolBoxmodelApp::mouseReleaseEvent(QMouseEvent *event) {
	}

	void ChooseToolBoxmodelApp::paintEvent(QPaintEvent*)
	{

		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);
		painter.setBrush(QBrush(QColor(60, 60, 60), Qt::SolidPattern));
		painter.drawRect(0, 0, 240, 240);

		painter.setPen(QPen(Qt::white, 5.0));
		painter.setFont(QFont("Ubuntu", 15 * ipn::helpers::fontSizeFactor, QFont::Bold	));
		painter.drawText(0, 0, 240, 30, Qt::AlignCenter, "el: " + ipn::webhelpers::elementIdentifierString(currentEl));

	}

	int ChooseToolBoxmodelApp::signum(int number) {
		if (number > 0)
			return 1;
		else if (number < 0)
			return -1;
		return 0;
	}

} // namespace ipn
