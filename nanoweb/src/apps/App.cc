#include "App.h"
#include <QtDebug>

namespace ipn
{

	App::App(QWidget *parent) : QWidget()
	{
		// Create a timer invoking the menu if the users hold a finger on the screen
		// for a specific amount of time in milliseconds:
		m_buttonHoldTimer = new QTimer(this);
		m_buttonHoldTimer->setInterval(500);
		m_buttonHoldTimer->setSingleShot(true);

		// Invoke the marking menu on button clicks and on timer expiration:
		connect(m_buttonHoldTimer, SIGNAL(timeout()), this, SLOT(triggerButtonHold()));

		connect(this, SIGNAL(backButtonClickTriggered()), this, SLOT(backButtonClick()));
		connect(this, SIGNAL(rightButtonClickTriggered()), this, SLOT(rightButtonClick()));
		connect(this, SIGNAL(leftButtonClickTriggered()), this, SLOT(leftButtonClick()));

		connect(this, SIGNAL(backButtonHoldTriggered()), this, SLOT(backButtonHold()));
		connect(this, SIGNAL(rightButtonHoldTriggered()), this, SLOT(rightButtonHold()));
		connect(this, SIGNAL(leftButtonHoldTriggered()), this, SLOT(leftButtonHold()));

		// let's connect the local signals to our parent's slots
		connect(this, SIGNAL(performPopApp()), parent, SLOT(popApp()));
		connect(this, SIGNAL(switchToMockUp()), parent, SLOT(switchToMockUp()));
		connect(this, SIGNAL(switchToWebPage()), parent, SLOT(switchToWebPage()));
		connect(this, SIGNAL(switchToWebPageIfNecessary()), parent, SLOT(switchToWebPageIfNecessary()));
	}

	void App::popApp()
	{
		emit performPopApp();
	}

	void App::triggerButtonHold()
	{
		if(m_holdingButton == Left)
			emit leftButtonHoldTriggered();
		else if(m_holdingButton == Right)
			emit rightButtonHoldTriggered();
		else if(m_holdingButton == Back)
			emit backButtonHoldTriggered();
		//else if(m_holdingButton == "Screen")
		//    emit holdTriggered();

		m_holdingButton = AllReleased;
	}

	void App::handleGesture(GestureType type, qreal param)
	{
		switch (type)
		{
		case PinchIn:
			emit pinchInTriggered();
			break;
		case PinchOut:
			emit pinchOutTriggered();
			break;
		case PinchRotation:
			emit pinchRotationAngleChanged(param);
			break;
		case PinchScale:
			emit pinchScaleFactorChanged(param);
			break;
		case Swipe:
			emit swipeTriggered(param);
			break;
		case SwipeLeft:
			emit swipeLeftTriggered();
			break;
		case SwipeUp:
			emit swipeUpTriggered();
			break;
		case SwipeRight:
			emit swipeRightTriggered();
			break;
		case SwipeDown:
			emit swipeDownTriggered();
			break;

		case LeftButtonPress:
			m_buttonHoldTimer->start();
			m_holdingButton = Left;
			emit leftButtonPressTriggered();
			break;
		case LeftButtonRelease:
			if(m_buttonHoldTimer->isActive()) {
				emit leftButtonReleaseTriggered();
				emit leftButtonClickTriggered();
			}
			m_buttonHoldTimer->stop();
			break;

		case RightButtonPress:
			m_buttonHoldTimer->start();
			m_holdingButton = Right;
			emit rightButtonPressTriggered();
			break;
		case RightButtonRelease:
			if(m_buttonHoldTimer->isActive()) {
				emit rightButtonReleaseTriggered();
				emit rightButtonClickTriggered();
			}
			m_buttonHoldTimer->stop();
			break;

		case BackButtonPress:
			m_buttonHoldTimer->start();
			m_holdingButton = Back;
			emit backButtonPressTriggered();
			break;
		case BackButtonRelease:
			if(m_buttonHoldTimer->isActive()) {
				emit backButtonReleaseTriggered();
				emit backButtonClickTriggered();
			}
			m_buttonHoldTimer->stop();
			break;
		}
	}
	void App::backButtonClick()
	{
		emit popApp();
		qDebug() << "Backbutton clicked! (popping app as default action)";
	}

	void App::rightButtonClick()
	{
		emit switchToMockUp();
		qDebug() << "Rightbutton clicked! ";
	}

	void App::leftButtonClick()
	{
		emit switchToWebPage();
		qDebug() << "Leftbutton clicked! ";
	}

	void App::leftButtonHold()
	{
		qDebug() << "Leftbutton hold! ";
	}

	void App::rightButtonHold()
	{
		qDebug() << "Rightbutton hold! ";
	}

	void App::backButtonHold()
	{
		qDebug() << "BAckbutton hold";
		emit switchToWebPageIfNecessary();
	}

} // namespace ipn
