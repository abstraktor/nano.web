#include "PageIndicatorWidget.h"
#include <QPainter>

namespace ipn
{

	PageIndicatorWidget::PageIndicatorWidget(QWidget *parent) : QWidget(parent)
	{
		m_numberOfSegments = 5;
		m_activeSegment = 0;

		m_activePixmap = new QPixmap(":/img/page_indicator/page_indicator_active.png");
		m_inactivePixmap = new QPixmap(":/img/page_indicator/page_indicator_inactive.png");
	}

	PageIndicatorWidget::~PageIndicatorWidget()
	{
		if (m_activePixmap)
			delete m_activePixmap;

		if (m_inactivePixmap)
			delete m_inactivePixmap;
	}

	void PageIndicatorWidget::paintEvent(QPaintEvent *)
	{
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing, true);

		for (int i = 0; i < m_numberOfSegments; i++)
		{
			if (m_activeSegment == i)
				painter.drawPixmap(16 * i, 0, *m_activePixmap);
			else
				painter.drawPixmap(16 * i, 0, *m_inactivePixmap);
		}
	}

	void PageIndicatorWidget::setNumberOfSegments(int numberOfSegments)
	{
		m_numberOfSegments = numberOfSegments;

		resize(16 * m_numberOfSegments - 8, 8);
		update();
	}

	void PageIndicatorWidget::setPosition(float position)
	{
		m_activeSegment = (int)(position * m_numberOfSegments);

		update();
	}

	void PageIndicatorWidget::setActiveSegment(int activeSegment)
	{
		m_activeSegment = activeSegment;

		update();
	}

} // namespace ipn
