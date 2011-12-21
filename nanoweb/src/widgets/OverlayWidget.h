#ifndef IPN_OVERLAYWIDGET_H
#define IPN_OVERLAYWIDGET_H

#include <QWidget>
#include <QElapsedTimer>

class QGestureEvent;
class QPinchGesture;
class QWheelEvent;

namespace ipn
{

	enum GestureType
	{
		PinchRotation,
		PinchScale,
		PinchIn,
		PinchOut,
		SwipeLeft,
		SwipeUp,
		SwipeRight,
		SwipeDown,
		Swipe
	};

	class OverlayWidget : public QWidget
	{
		Q_OBJECT

		public:
			OverlayWidget(QWidget *parent = 0);

		signals:
			// signal mouse events:
			void mousePressed(QMouseEvent *event);
			void mouseReleased(QMouseEvent *event);
			void mouseMoved(QMouseEvent *event);
			void mouseHovered(QMouseEvent *event);

			// signal gestures:
			void gestureTriggered(GestureType type, qreal param = 0);

		protected:
			virtual void mouseReleaseEvent(QMouseEvent *event);
			virtual void mousePressEvent(QMouseEvent *event);
			virtual void mouseMoveEvent(QMouseEvent *event);
			virtual void wheelEvent(QWheelEvent *event);
			virtual bool event(QEvent *event);
			virtual bool gestureEvent(QGestureEvent *event);

		private:
			bool m_isMouseDown;
			bool m_multiTouchStarted;
			QPoint m_mouseDownPos;
			QElapsedTimer m_mouseDownTimer;

			void pinchTriggered(QPinchGesture *gesture);
			qint64 timeElapsedSinceLastMousePress();

	};

} // namespace ipn

#endif // IPN_OVERLAYWIDGET_H
