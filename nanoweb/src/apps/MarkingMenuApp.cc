#include "MarkingMenuApp.h"
#include "widgets/BackgroundWidget.h"
#include "widgets/TextWidget.h"
#include "widgets/ScalableButtonWidget.h"
#include "widgets/MarkingMenu.h"
#include "helpers.h"
#include <QTimer>

namespace ipn
{

	MarkingMenuApp::MarkingMenuApp(QWidget *parent) : App(parent)
	{
		m_back = new BackgroundWidget(this);
		m_back->setColor(BackgroundWidget::BG_TRANSPARENT);
		m_back->move(0, 0);

		m_message = new TextWidget(this);
		m_message->setColor(Qt::white);
		m_message->resize(240, 180);
		m_message->setText("Hold your finger\non the screen or\npush the button to\ninvoke the menu.");

		m_quitButton = new ScalableButtonWidget(this);
		m_quitButton->move(148, 184);
		m_quitButton->resize(80, 48);
		m_quitButton->setImage(":/img/buttons/default");
		m_quitButton->setText("exit");
		connect(m_quitButton, SIGNAL(clicked()), this, SIGNAL(quitButtonClicked()));

		m_menuButton = new ScalableButtonWidget(this);
		m_menuButton->move(2, 184);
		m_menuButton->resize(136, 48);
		m_menuButton->setImage(":/img/buttons/default");
		m_menuButton->setText("invoke menu");

		// Create a marking menu with four entries:
		m_markingMenu = new MarkingMenu(this);
		m_markingMenu->hide();
		m_markingMenu->addEntry("first", Qt::white, Qt::black);
		m_markingMenu->addEntry("second", Qt::gray, Qt::white);
		m_markingMenu->addEntry("third", Qt::white, Qt::black);
		m_markingMenu->addEntry("fourth", Qt::gray, Qt::white);

		// Create a timer invoking the menu if the users hold a finger on the screen
		// for a specific amount of time in milliseconds:
		m_menuInvokeTimer = new QTimer(this);
		m_menuInvokeTimer->setInterval(500);
		m_menuInvokeTimer->setSingleShot(true);

		// Grab swipe gesture:
		connect(this, SIGNAL(swipeTriggered(qreal)), this, SLOT(handleSwipeGesture(qreal)));

		// Invoke the marking menu on button clicks and on timer expiration:
		connect(m_menuButton, SIGNAL(clicked()), m_markingMenu, SLOT(show()));
		connect(m_menuInvokeTimer, SIGNAL(timeout()), m_markingMenu, SLOT(show()));
		connect(m_menuInvokeTimer, SIGNAL(timeout()), m_markingMenu, SLOT(setFocus()));

		// Determine what happens if the user selects a menu entry:
		connect(m_markingMenu, SIGNAL(entryClicked(QString)), this, SLOT(handleMenuClick(QString)));
	}

	void MarkingMenuApp::handleSwipeGesture(qreal angle)
	{
		m_markingMenu->hide();
		m_message->setText(m_markingMenu->entryText(angle));

		update();
	}

	void MarkingMenuApp::handleMenuClick(QString entryText)
	{
		m_markingMenu->hide();
		m_message->setText(entryText);

		update();
	}

	void MarkingMenuApp::mousePressEvent(QMouseEvent *event)
	{
		m_menuInvokeTimer->start();

		App::mousePressEvent(event);
		m_markingMenu->mousePressEvent(event);
	}

	void MarkingMenuApp::mouseReleaseEvent(QMouseEvent *event)
	{
		m_markingMenu->deactivateAllEntries();

		if (!m_menuInvokeTimer->isActive())
			m_markingMenu->mouseReleaseEvent(event);

		m_menuInvokeTimer->stop();

		App::mouseReleaseEvent(event);
	}

	void MarkingMenuApp::mouseMoveEvent(QMouseEvent *event)
	{
		m_markingMenu->mouseMoveEvent(event);
	}

} // namespace ipn
