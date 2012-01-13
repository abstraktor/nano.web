#include "FlickArea.h"
#include "helpers.h"
#include <QApplication>
#include <QMouseEvent>
#include <QTimer>
#include <math.h>

namespace ipn
{

	FlickArea::FlickArea(QWidget *parent) : ClickableWidget(parent)
	{
		m_scrollOffset = QPoint(0, 0);

		// Create the animation timer:
		m_animationTimer = new QTimer(this);
		m_animationTimer->setSingleShot(false);
		connect(m_animationTimer, SIGNAL(timeout()), this, SLOT(proceedAnimation()));
		m_animationTimer->start(30);

		// Create an overlay to make sure the children do not catch any events we want to filter
		m_overlay = new ClickableWidget(this);
		m_overlay->move(0, 0);
		m_overlay->resize(width(), height());

		m_currentChild = NULL;
	}

	void FlickArea::resize(int width, int height)
	{
		ClickableWidget::resize(width, height);

		m_overlay->resize(width, height);
	}

	QPointF FlickArea::relativeScrollPosition()
	{
		float relativeX = -(float)childrenRect().x() / (childrenRect().width() - width());
		relativeX = helpers::maxf(0, helpers::minf(1, relativeX));

		float relativeY = -(float)childrenRect().y() / (childrenRect().height() - height());
		relativeY = helpers::maxf(0, helpers::minf(1, relativeY));

		return QPointF(relativeX, relativeY);
	}

	void FlickArea::forwardMouseEvent(QMouseEvent *event, bool simulateMouseRelease)
	{
		// make sure the child exists and that it is not the overlay, else this FlickArea would
		// handle and emit it infinitely
		if (!m_currentChild || m_currentChild == m_overlay)
			return;

		QPoint pos = event->pos() - m_currentChild->pos();
		QEvent::Type type = event->type();

		// simulate mouse release outside the widget by clicking at (-1, -1) which is always outside
		if (simulateMouseRelease)
		{
			pos = QPoint(-1, -1);
			type = QEvent::MouseButtonRelease;
		}

		QMouseEvent childEvent(type, pos, event->button(), event->buttons(), event->modifiers());

		QApplication::sendEvent(m_currentChild, &childEvent);
	}

	void FlickArea::mousePressEvent(QMouseEvent *event)
	{
		m_mouseMovedSinceMousePress = false;

		// to determine the currently clicked child, it is necessary to hide the overlay, else
		// childAt would return us the overlay
		m_overlay->hide();
		m_currentChild = childAt(event->pos());
		forwardMouseEvent(event);
		m_overlay->show();

		m_lastMousePos = event->pos();
		m_scrollOffset = QPoint(0, 0);
	}

	void FlickArea::mouseMoveEvent(QMouseEvent *event)
	{
		m_mouseMovedSinceMousePress = true;

		// since the mouse was moved, simulate a mouse release event on the child
		forwardMouseEvent(event, true);

		QPoint moveDifference = event->pos() - m_lastMousePos;
		m_lastMousePos = event->pos();
		flick(moveDifference);
	}

	void FlickArea::mouseReleaseEvent(QMouseEvent *event)
	{
		// if the area was not flicked, forward the event normally,
		// else simulate releasing the mouse outside the widget to prevent it from being clicked
		if (!m_mouseMovedSinceMousePress)
			forwardMouseEvent(event);
		else
			forwardMouseEvent(event, true);

		m_currentChild = NULL;
	}

	void FlickArea::paintEvent(QPaintEvent*)
	{
		// Make sure the overlay is on top of all other children before drawing the FlickArea
		m_overlay->raise();
	}

	void FlickArea::proceedAnimation()
	{
		// Move each child widget by m_scrollOffset
		foreach (QObject *childObject, children())
		{
			// Don't move our event-catching overlay
			if (childObject == m_overlay)
				continue;

			QWidget *childWidget = qobject_cast<QWidget*>(childObject);

			if (childWidget)
				childWidget->move(childWidget->pos() + (m_scrollOffset * 0.2));
		}

		// If the widgets were moved by at least one pixel, announce the changement
		if (fabs(m_scrollOffset.x() * 0.2) > 0 || fabs(m_scrollOffset.y() * 0.2) > 0)
			emit moved();

		m_scrollOffset *= (1 - 0.2);
	}

	float FlickArea::calculateFlickDistance(float realDistance)
	{
		int signum = (realDistance < 0.0) ? -1 : 1;
		float acceleratedChangement = signum * pow(realDistance / 8.0, 2) * 8.0;

		return fabs(realDistance) > fabs(acceleratedChangement)
			? realDistance
			: acceleratedChangement;
	}

	void FlickArea::flick(QPoint offset)
	{
		// Add the current offset to the sum of offsets:
		m_scrollOffset += QPoint(calculateFlickDistance(offset.x()),
			calculateFlickDistance(offset.y()));

		// Calculate how much place the children take:
		QRect cRect = childrenRect();

		// Make sure the children will stay inside the borders of this widget:
		if (cRect.right() + m_scrollOffset.x() > helpers::max(cRect.width(), width()))
			m_scrollOffset.setX(helpers::max(cRect.width(), width()) - cRect.right());

		if (cRect.left() + m_scrollOffset.x() < helpers::min(width() - cRect.width(), 0))
			m_scrollOffset.setX(-cRect.left() + helpers::min(width() - cRect.width(), 0));

		if (cRect.bottom() + m_scrollOffset.y() > helpers::max(cRect.height(), height()))
			m_scrollOffset.setY(helpers::max(cRect.height(), height()) - cRect.bottom());

		if (cRect.top() + m_scrollOffset.y() < helpers::min(height() - cRect.height(), 0))
			m_scrollOffset.setY(-cRect.top() + helpers::min(height() - cRect.height(), 0));
	}

} // namespace ipn
