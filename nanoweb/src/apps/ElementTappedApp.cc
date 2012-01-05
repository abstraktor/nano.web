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
        m_elementText->setColor(Qt::black);
        m_elementText->move(0, 0);
        m_elementText->resize(240, 60);
        m_elementText->setText("a.HorNavLinkBig");

        m_elementContentText = new TextWidget(this);
        m_elementContentText->setColor(Qt::black);
        m_elementContentText->move(0, 60);
        m_elementContentText->resize(240, 60);
        m_elementContentText->setText("\"Zürichsee\"");

        m_browseElementButton = new ScalableButtonWidget(this);
		m_browseElementButton->move(28, 148);
		m_browseElementButton->resize(64, 64);
        m_browseElementButton->setImage(":/img/buttons/default");
        m_browseElementButton->setText("browse\nelement");
        connect(m_browseElementButton, SIGNAL(clicked()), this, SIGNAL(quitButtonClicked()));

        m_followLinkButton = new ScalableButtonWidget(this);
		m_followLinkButton->move(148, 148);
		m_followLinkButton->resize(64, 64);
        m_followLinkButton->setImage(":/img/buttons/default");
        m_followLinkButton->setText("follow\nlink");
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
