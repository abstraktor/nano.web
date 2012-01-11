#include "PaintApp.h"
#include <QBrush>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPolygon>
#include <QVector>

namespace ipn
{

	PaintApp::PaintApp(QWidget *parent) : App(parent)
	{
	}

	void PaintApp::mousePressEvent(QMouseEvent *event)
	{
		// Begin a new line:
		QPolygon newPolyLine;
		newPolyLine.push_back(event->pos());
		m_drawing.push_back(newPolyLine);
	}

	void PaintApp::mouseMoveEvent(QMouseEvent *event)
	{
		if (m_drawing.empty())
			return;

		if (event->buttons() == Qt::LeftButton)
			m_drawing.back().push_back(event->pos());

		update();
	}

	void PaintApp::paintEvent(QPaintEvent*)
	{
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);

		painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
		painter.drawRect(0, 0, 240, 240);

		painter.setPen(QPen(Qt::red, 5.0));

		for (QVector<QPolygon>::iterator p = m_drawing.begin(); p != m_drawing.end(); p++)
			painter.drawPolyline(*p);
	}

} // namespace ipn
