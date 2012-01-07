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
		/*
        m_elementBackground = new BackgroundWidget(this);
        m_elementBackground->setColor(BackgroundWidget::BG_GRAY);
        m_elementBackground->move(0, 0);
        m_elementBackground->resize(240, 120);


        m_buttonBackground = new BackgroundWidget(this);
        m_buttonBackground->setColor(BackgroundWidget::BG_GRAY);
        m_buttonBackground->move(0, 120);
		m_buttonBackground->resize(240, 120);*/

		/*m_elementText = new TextWidget(this);
		m_elementText->setColor(Qt::white);
		m_elementText->setFontStyle(1);
        m_elementText->move(0, 0);
		m_elementText->resize(240, 60);
		m_elementText->setText("---element identifier---");

        m_elementContentText = new TextWidget(this);
		m_elementContentText->setColor(Qt::white);
		m_elementContentText->move(0, 30);
        m_elementContentText->resize(240, 60);
		//m_elementContentText->setText("---content---");*/

		buttonColor = QColor(180, 180, 180);

		m_explainText = new TextWidget(this);
		m_explainText->setColor(Qt::white);
		m_explainText->move(0, 0);
		m_explainText->resize(240, 30);
		m_explainText->setFontSize(12);
		m_explainText->setText("You selected:");


        m_browseElementButton = new ScalableButtonWidget(this);
		m_browseElementButton->move(30, 150);
		m_browseElementButton->resize(60, 60);
		m_browseElementButton->setImage(":/img/buttons/default");
		m_browseElementButton->setIconImage(":/img/our_icons/edit");
		m_browseElementButton->setTitle("edit");
        connect(m_browseElementButton, SIGNAL(clicked()), this, SIGNAL(quitButtonClicked()));

        m_followLinkButton = new ScalableButtonWidget(this);
		m_followLinkButton->move(150, 150);
		m_followLinkButton->resize(60, 60);
		m_followLinkButton->setImage(":/img/buttons/default");
		m_followLinkButton->setIconImage(":/img/our_icons/followlink");
		m_followLinkButton->setTitle("follow link");
		connect(m_followLinkButton, SIGNAL(clicked()), this, SIGNAL(quitButtonClicked()));
		connect(m_browseElementButton, SIGNAL(clicked()), this, SIGNAL(editButtonClicked()));


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
		if (event->pos().y() <= 120) {
			buttonColor = QColor(100, 100, 100);
			update();
		}
	}

	void ElementTappedApp::mouseReleaseEvent(QMouseEvent *event)
	{
		if (event->pos().y() <= 120) {
			buttonColor = QColor(180, 180, 180);
			update();
			emit elementTapped(currentEl);
		}
	}

	void ElementTappedApp::setElement(QWebElement el) {
		currentEl = el;
		update();
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
		painter.drawRoundedRect(40, 50, 160, 70, 10.0, 10.0);

		painter.setPen(QPen(Qt::white, 5.0));
		painter.setFont(QFont("Ubuntu", 15 * ipn::helpers::fontSizeFactor, QFont::Bold));

		painter.drawText(0, 60, 240, 20, Qt::AlignCenter, ipn::webhelpers::elementIdentifierString(currentEl));
		painter.drawText(0, 90, 240, 20, Qt::AlignCenter, ipn::webhelpers::elementContentString(currentEl));
	}


} // namespace ipn
