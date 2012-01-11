#ifndef IPN_CLICKABLEWIDGET_H
#define IPN_CLICKABLEWIDGET_H

#include <QWidget>

namespace ipn
{

	class ClickableWidget : public QWidget
	{
		Q_OBJECT

		public:
			ClickableWidget(QWidget *parent = 0);

			void setEnabled(bool enabled);
			bool isEnabled();
			bool isMouseDown();
			bool isMouseOver();
			QPoint distanceSinceMouseDown();

		signals:
			void clicked();
			void pressed();
			void released();

		public slots:
			void press();
			void release();

		protected:
			virtual void mouseReleaseEvent(QMouseEvent *event);
			virtual void mousePressEvent(QMouseEvent *event);

		private:
			bool m_mouseDown;
			QPoint m_mouseDownPosition;
			bool m_enabled;
	};

} // namespace ipn

#endif // IPN_CLICKABLEWIDGET_H
