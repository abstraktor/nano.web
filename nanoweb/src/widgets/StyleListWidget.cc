#include "StyleListWidget.h"
#include "TextWidget.h"
#include "ImageWidget.h"
#include "helpers.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QtCore/qmath.h>

#define NO_ENTRY -1

namespace ipn
{

	StyleListWidget::StyleListWidget(QWidget *parent) : QWidget(parent)
	{
		mousePressed = false;
		doSwiping = false;
		doZooming = false;

		translation = QPoint();
		diff = QPoint();
		lastPoint = QPoint();

		m_entries = QVector<QString>();
		selected = "";

	}

	void StyleListWidget::addEntry(QString text)
	{
		int numberOfEntries = m_entries.size();
		m_entries.append(text);

		resize(240, (numberOfEntries + 1) * 48);

		update();
	}

	void StyleListWidget::paintEvent(QPaintEvent*)
	{
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing, true);
		painter.setFont(QFont("Ubuntu", 15 * ipn::helpers::fontSizeFactor, QFont::Bold));

		painter.translate(translation);

		for (int i = 0; i < m_entries.size(); i++) {
			painter.setPen(Qt::NoPen);
			QRect rect = QRect(0, i * 48, 240, 48);

			painter.setBrush(QBrush(QColor(225, 225, 225), Qt::SolidPattern));
			if(m_entries.at(i) == selected)
				painter.setBrush(QBrush(QColor(204, 204, 204), Qt::SolidPattern));
			if (buttonPressed && rect.contains(lastPoint - translation))
				painter.setBrush(QBrush(QColor(135, 135, 135), Qt::SolidPattern));

			painter.drawRect(rect);
			painter.setPen(QPen(Qt::black, 1.0f));
			painter.setRenderHint(QPainter::Antialiasing, false);
			if (m_entries.at(i) == "solid") {
				painter.drawLine(40, i * 48 + 24, 200, i * 48 + 24);
			}
			else if (m_entries.at(i) == "double") {
				painter.drawLine(40, i * 48 + 22, 200, i * 48 + 22);
				painter.drawLine(40, i * 48 + 26, 200, i * 48 + 26);
			}
			else if (m_entries.at(i) == "dotted") {
				QPen p = painter.pen();
				p.setStyle(Qt::DotLine);
				painter.setPen(p);
				painter.drawLine(40, i * 48 + 24, 200, i * 48 + 24);
			}
			else if (m_entries.at(i) == "dashed") {
				QPen p = painter.pen();
				p.setStyle(Qt::DashLine);
				painter.setPen(p);
				painter.drawLine(40, i * 48 + 24, 200, i * 48 + 24);
			}
			else if (m_entries.at(i) == "none") {
				painter.drawText(0, i * 48, 240, 48, Qt::AlignCenter, "none");
			}
			painter.setRenderHint(QPainter::Antialiasing, true);
			if (i == 0) continue;
			painter.setPen(QPen(Qt::white, 1.0f));
			painter.drawLine(QPoint(0, i * 48 - 1), QPoint(width(), i * 48 - 1));
		}

		painter.translate(-translation);
		if (translation.y() != 0) {
			QPixmap pixmap = QPixmap(":img/our_imgs/arrow_up.png");
			painter.drawPixmap(0, 0, 240, 8, pixmap);
		}

		if (translation.y() != -40) {
			QPixmap pixmap = QPixmap(":img/our_imgs/arrow_down.png");
			painter.drawPixmap(0, 192, 240, 8, pixmap);
		}
	}

	void StyleListWidget::mousePressEvent(QMouseEvent *event)
	{
		lastPoint = event->pos();
		buttonPressed = true;
		update();
	}

	void StyleListWidget::mouseMoveEvent(QMouseEvent *event)
	{
		if (!event->buttons() == Qt::LeftButton)
			return;
		if (!mousePressed) {
			mousePressed = true;
			lastPoint = event->pos();
			return;
		}
		else {
			diff = diff + (event->pos() - lastPoint);
			lastPoint = event->pos();
			double length = qSqrt(diff.x() * diff.x() + diff.y() * diff.y());
			if (length >= 2) {
				doSwiping = true;
				buttonPressed = false;
			}
			if (doSwiping) {
				diff.setX(0);
				if (diff.y() > 0)
					diff.setY(0);
				if (abs(diff.y()) > 40)
					diff.setY(-40);
				translation = diff;
			}
		}
		update();
	}

	void StyleListWidget::mouseReleaseEvent(QMouseEvent *event)
	{
		if (buttonPressed) {
			int index = ((event->pos() - translation).y() / 48);
			emit entryClicked(m_entries.at(index));
		}
		mousePressed = false;
		doSwiping = false;
		buttonPressed = false;
		update();
	}

}
