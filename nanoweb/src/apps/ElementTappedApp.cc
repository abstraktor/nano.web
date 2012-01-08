#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPolygon>
#include <QVector>
#include "widgets/BackgroundWidget.h"
#include "widgets/TitleBarWidget.h"
#include "widgets/TextWidget.h"
#include "widgets/ScalableButtonWidget.h"
#include "helpers.h"
#include "webhelpers.h"
#include "ElementTappedApp.h"

namespace ipn
{

    ElementTappedApp::ElementTappedApp(QWidget *pParent) : App(pParent)
	{
		buttonColor = QColor(180, 180, 180);

		m_explainText = new TextWidget(this);
		m_explainText->setColor(Qt::white);
		m_explainText->move(0, 0);
		m_explainText->resize(240, 30);
		m_explainText->setFontSize(12);
		m_explainText->setText("You selected:");


		m_editElementButton = new ScalableButtonWidget(this);
		m_editElementButton->move(150, 150);
		m_editElementButton->resize(60, 60);
		m_editElementButton->setImage(":/img/buttons/default");
		m_editElementButton->setIconImage(":/img/our_icons/edit");
		m_editElementButton->setTitle("edit");
		connect(m_editElementButton, SIGNAL(clicked()), this, SIGNAL(editButtonClicked()));

        m_followLinkButton = new ScalableButtonWidget(this);
		m_followLinkButton->move(30, 150);
		m_followLinkButton->resize(60, 60);
		m_followLinkButton->setImage(":/img/buttons/default");
		m_followLinkButton->setIconImage(":/img/our_icons/followlink");
		m_followLinkButton->setTitle("follow link");
		connect(m_followLinkButton, SIGNAL(clicked()), this, SIGNAL(leftButtonClicked()));


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
		if (event->pos().y() >= 50 && event->pos().y() <= 140)
			emit elementTapped(currentEl);
		/*
		if (event->pos().y() <= 120) {
			buttonColor = QColor(100, 100, 100);
			update();
		}
		*/
	}

	void ElementTappedApp::mouseReleaseEvent(QMouseEvent *event)
	{
		/*
		if (event->pos().y() <= 120) {
			buttonColor = QColor(180, 180, 180);
			update();
			emit elementTapped(currentEl);
		}
		*/
	}

	void ElementTappedApp::updateView() {
		if (currentEl.tagName() == "A")
		{
			m_followLinkButton->setTitle("follow link");
			m_followLinkButton->setIconImage(":/img/our_icons/followlink");
		}
		else {
			m_followLinkButton->setTitle("back");
			m_followLinkButton->setIconImage(":/img/our_icons/back");

		}
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
		QPixmap pixmap(":img/our_imgs/elementTapped_background.png");
		painter.drawPixmap(0, 40, 240, 90, pixmap);

		painter.setPen(QPen(Qt::white, 5.0));
		painter.setFont(QFont("Ubuntu", 15 * ipn::helpers::fontSizeFactor, QFont::Bold));

		painter.drawText(0, 60, 240, 20, Qt::AlignCenter, ipn::webhelpers::elementIdentifierString(currentEl));
		painter.drawText(0, 90, 240, 20, Qt::AlignCenter, ipn::webhelpers::elementContentString(currentEl));
	}


} // namespace ipn
