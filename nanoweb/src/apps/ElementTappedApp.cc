#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPolygon>
#include <QVector>
#include "widgets/BackgroundWidget.h"
#include "widgets/TitleBarWidget.h"
#include "widgets/TextWidget.h"
#include "widgets/ScalableButtonWidget.h"
#include "ElementTappedApp.h"

namespace ipn
{

    ElementTappedApp::ElementTappedApp(QWidget *pParent) : App(pParent)
	{
        m_elementBackground = new BackgroundWidget(this);
        m_elementBackground->setColor(BackgroundWidget::BG_GRAY);
        m_elementBackground->move(0, 0);
        m_elementBackground->resize(240, 120);

        m_buttonBackground = new BackgroundWidget(this);
        m_buttonBackground->setColor(BackgroundWidget::BG_GRAY);
        m_buttonBackground->move(0, 120);
        m_buttonBackground->resize(240, 120);

        m_elementText = new TextWidget(this);
		m_elementText->setColor(Qt::white);
		m_elementText->setFontStyle(1);
        m_elementText->move(0, 0);
		m_elementText->resize(240, 60);
		m_elementText->setText("a.HorNavLinkBig");

        m_elementContentText = new TextWidget(this);
		m_elementContentText->setColor(Qt::white);
		m_elementContentText->move(0, 30);
        m_elementContentText->resize(240, 60);
		m_elementContentText->setText("\"Zürichsee\"");

		m_explainText = new TextWidget(this);
		m_explainText->setColor(Qt::white);
		m_explainText->move(0, 90);
		m_explainText->resize(240, 60);
		m_explainText->setFontSize(12);
		m_explainText->setText("Link clicked!\nDecide, how to go on.");


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


		// Connect gestures:
		connect(this, SIGNAL(swipeTriggered(qreal)), this, SLOT(swipe(qreal)));
		connect(this, SIGNAL(swipeRightTriggered()), this, SLOT(swipeRight()));
		connect(this, SIGNAL(swipeUpTriggered()), this, SLOT(swipeUp()));
		connect(this, SIGNAL(swipeDownTriggered()), this, SLOT(swipeDown()));
        connect(this, SIGNAL(swipeLeftTriggered()), this, SLOT(swipeLeft()));
		connect(this, SIGNAL(pinchInTriggered()), this, SLOT(pinchIn()));
		connect(this, SIGNAL(pinchOutTriggered()), this, SLOT(pinchOut()));
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

    void ElementTappedApp::swipe(qreal angle)
    {
    }

} // namespace ipn
