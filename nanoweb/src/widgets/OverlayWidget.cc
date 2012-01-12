#include "OverlayWidget.h"
#include <QMouseEvent>
#include <QGestureEvent>
#include <QSwipeGesture>
#include <QPinchGesture>
#include <QWheelEvent>

namespace ipn
{

	OverlayWidget::OverlayWidget(QWidget *parent) : QWidget(parent)
	{
		setMouseTracking(true);

		grabGesture(Qt::PinchGesture);

		m_multiTouchStarted = false;
		m_isMouseDown = false;
	}

	void OverlayWidget::mousePressEvent(QMouseEvent *event)
	{
		m_isMouseDown = true;
		m_mouseDownPos = event->pos();
		m_mouseDownTimer.start();

		emit mousePressed(event);
	}

	void OverlayWidget::mouseReleaseEvent(QMouseEvent *event)
	{
		// Check if the user has performed a swipe gesture:
		QLineF swipeLine(m_mouseDownPos, event->pos());

		// A swipe gesture is only triggered after moving the mouse or finger
		// by at least 120 pixels in 350 milliseconds (change these values if you like)
		if (swipeLine.length() >= 120 && timeElapsedSinceLastMousePress() <= 350
			&& !m_multiTouchStarted)
		{
			emit gestureTriggered(Swipe, swipeLine.angle());

			if (swipeLine.angle() < 45 || swipeLine.angle() > 315)
				emit gestureTriggered(SwipeRight);

			if (swipeLine.angle() < 135 && swipeLine.angle() > 45)
				emit gestureTriggered(SwipeUp);

			if (swipeLine.angle() < 225 && swipeLine.angle() > 135)
				emit gestureTriggered(SwipeLeft);

			if (swipeLine.angle() < 315 && swipeLine.angle() > 225)
				emit gestureTriggered(SwipeDown);
		}

		m_multiTouchStarted = false;
		m_isMouseDown = false;

		emit mouseReleased(event);
	}

	void OverlayWidget::mouseMoveEvent(QMouseEvent *event)
	{
		emit mouseHovered(event);

		if (m_isMouseDown)
			emit mouseMoved(event);
	}

	void OverlayWidget::wheelEvent(QWheelEvent *event)
	{
		if (event->buttons() & Qt::MidButton)
			// Emulate multi-touch rotation
			emit gestureTriggered(PinchRotation, event->delta() / 40.0);
		else
		{
			// Emulate multi-touch scaling
			qreal scaleFactor = (event->delta() > 0)
				? (event->delta() * 1.1 / 120.0)
				: (-event->delta() * 0.9 / 120.0);

			emit gestureTriggered(PinchScale, scaleFactor);

			if (event->delta() > 0)
				emit gestureTriggered(PinchIn);
			else if (event->delta() < 0)
				emit gestureTriggered(PinchOut);
		}
	}

	bool OverlayWidget::event(QEvent *event)
	{
		if (event->type() == QEvent::Gesture)
			return gestureEvent(static_cast<QGestureEvent*>(event));

		return QWidget::event(event);
	}

	bool OverlayWidget::gestureEvent(QGestureEvent *event)
	{
		if (QGesture *pinch = event->gesture(Qt::PinchGesture))
			pinchTriggered(static_cast<QPinchGesture *>(pinch));

		return true;
	}

	void OverlayWidget::pinchTriggered(QPinchGesture *gesture)
	{
		QPinchGesture::ChangeFlags changeFlags = gesture->changeFlags();

		if (gesture->state() == Qt::GestureFinished)
			m_multiTouchStarted = true;

		if (changeFlags & QPinchGesture::RotationAngleChanged)
		{
			qreal value = gesture->property("rotationAngle").toReal();
			qreal lastValue = gesture->property("lastRotationAngle").toReal();

			emit gestureTriggered(PinchRotation, value - lastValue);
		}

		if (changeFlags & QPinchGesture::ScaleFactorChanged)
		{
			qreal value = gesture->property("scaleFactor").toReal();

			emit gestureTriggered(PinchScale, value);
		}

		if (gesture->state() == Qt::GestureFinished)
		{
			qreal value = gesture->property("scaleFactor").toReal();
			qreal lastValue = gesture->property("lastScaleFactor").toReal();

			if (value < lastValue)
				emit gestureTriggered(PinchIn);
			else if (value > lastValue)
				emit gestureTriggered(PinchOut);
		}
	}

	qint64 OverlayWidget::timeElapsedSinceLastMousePress()
	{
		return m_mouseDownTimer.elapsed();
	}

} // namespace ipn
