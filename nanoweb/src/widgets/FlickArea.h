#ifndef IPN_FLICKAREA_H
#define IPN_FLICKAREA_H

#include "ClickableWidget.h"

namespace ipn
{
	class FlickArea : public ClickableWidget
	{
		Q_OBJECT

		public:
			FlickArea(QWidget *parent = 0);

			virtual void resize(int width, int height);

			QPointF relativeScrollPosition();

		public slots:
			void forwardMouseEvent(QMouseEvent *event, bool simulateMouseRelease = false);

		signals:
			void moved();

		protected:
			void mousePressEvent(QMouseEvent *event);
			void mouseMoveEvent(QMouseEvent *event);
			void mouseReleaseEvent(QMouseEvent *event);
			void paintEvent(QPaintEvent *event);

		private:
			ClickableWidget *m_overlay;

			QTimer *m_animationTimer;
			QPoint m_lastMousePos;
			QPoint m_mouseDownPos;
			QPoint m_scrollOffset;
			bool m_mouseMovedSinceMousePress;
			QWidget *m_currentChild;

			float calculateFlickDistance(float realDistance);
			void flick(QPoint offset);

		private slots:
			void proceedAnimation();
	};

} // namespace ipn

#endif // IPN_FLICKAREA_H
