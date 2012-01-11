#include "ClickableWidget.h"
#include <QResizeEvent>

#define NO_POINT QPoint(-1, -1)

namespace ipn
{

	ClickableWidget::ClickableWidget(QWidget *parent) : QWidget(parent)
	{
		m_mouseDown = false;
		m_enabled = true;
		m_mouseDownPosition = NO_POINT;
	}

	void ClickableWidget::mousePressEvent(QMouseEvent *event)
	{
		event->ignore();

		if (m_enabled)
		{
			m_mouseDown = true;
			m_mouseDownPosition = event->pos();

			emit pressed();
		}

		update();
	}

	void ClickableWidget::mouseReleaseEvent(QMouseEvent *event)
	{
		event->ignore();

		// check if mouse was actually pressed on this widget
		// and if the mouse has not been moved to much before releasing
		if (m_mouseDown && m_enabled && QLineF(m_mouseDownPosition, event->pos()).length() <= 10)
			emit clicked();

		m_mouseDown = false;
		m_mouseDownPosition = NO_POINT;

		if (m_enabled)
			emit released();

		update();
	}

	void ClickableWidget::setEnabled(bool enabled)
	{
		m_enabled = enabled;
	}

	bool ClickableWidget::isEnabled()
	{
		return m_enabled;
	}

	bool ClickableWidget::isMouseDown()
	{
		return m_mouseDown;
	}

	bool ClickableWidget::isMouseOver()
	{
		QPoint cursorPosition = mapFromGlobal(QCursor::pos());

		return (rect().contains(cursorPosition));
	}

	QPoint ClickableWidget::distanceSinceMouseDown()
	{
		if (m_mouseDownPosition == NO_POINT)
			return QPoint(0, 0);

		QPoint cursorPosition = mapFromGlobal(QCursor::pos());

		return cursorPosition - m_mouseDownPosition;
	}

	void ClickableWidget::press()
	{
		m_mouseDown = true;
		m_mouseDownPosition = mapFromGlobal(QCursor::pos());

		emit pressed();

		update();
	}

	void ClickableWidget::release()
	{
		m_mouseDown = false;
		m_mouseDownPosition = NO_POINT;

		emit released();

		update();
	}

} // namespace ipn
