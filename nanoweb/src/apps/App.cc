#include "App.h"

namespace ipn
{

	App::App(QWidget *parent) : QWidget(parent)
	{
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
		}
	}

} // namespace ipn
