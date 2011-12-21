#include "BackgroundWidget.h"
#include <QPainter>

namespace ipn
{

	BackgroundWidget::BackgroundWidget(QWidget *parent) : QWidget(parent)
	{
		m_color = BG_GRAY;

		resize(240, 240);
	}

	int BackgroundWidget::color()
	{
		return m_color;
	}

	void BackgroundWidget::setColor(int color)
	{
		m_color = color;
	}

	void BackgroundWidget::paintEvent(QPaintEvent*)
	{
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing, true);
		painter.setPen(Qt::NoPen);

		QColor backgroundColor;

		if (m_color == BG_TRANSPARENT)
			backgroundColor = QColor(0, 0, 0, 192);
		else if (m_color == BG_GRAY)
			backgroundColor = QColor(64, 64, 64, 255);
		else if (m_color == BG_WHITE)
			backgroundColor = QColor(255, 255, 255, 255);

		painter.setBrush(QBrush(backgroundColor, Qt::SolidPattern));
		painter.drawRect(0, 0, 240, 240);
		painter.end();
	}

} // namespace ipn
