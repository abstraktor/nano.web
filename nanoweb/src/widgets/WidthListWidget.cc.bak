#include "WidthListWidget.h"
#include "TextWidget.h"
#include "ImageWidget.h"
#include "helpers.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

#define NO_ENTRY -1
#define ENTRYHEIGHT 40

namespace ipn
{

	WidthListWidget::WidthListWidget(QWidget *parent) : QWidget(parent)
	{
		m_entries = QVector<QString>();
		m_highlightedEntry = NO_ENTRY;
		m_activeEntry = NO_ENTRY;
		resize(240, 200);

		selected = "";
		buttonPressed = false;

	}

	void WidthListWidget::addEntry(QString text)
	{
		m_entries.append(text);
		update();
	}

	void WidthListWidget::paintEvent(QPaintEvent*)
	{
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing, true);
		painter.setFont(QFont("Ubuntu", 15 * ipn::helpers::fontSizeFactor, QFont::Bold));


		painter.setBrush(QBrush(QColor(225, 225, 225), Qt::SolidPattern));
		for (int i = 0; i < m_entries.size(); i++) {
			painter.setPen(Qt::NoPen);

			QRect rect = QRect(0, i * ENTRYHEIGHT, 240, ENTRYHEIGHT);
			if (i == 3)
				rect = QRect(0, 3 * ENTRYHEIGHT, 240, 200 - 3 * ENTRYHEIGHT);

			painter.setBrush(QBrush(QColor(225, 225, 225), Qt::SolidPattern));

			if(m_entries.at(i) == selected || (i == 3 && selected != "thin" && selected != "medium" && selected != "thick"))
				painter.setBrush(QBrush(QColor(204, 204, 204), Qt::SolidPattern));
			if (buttonPressed && rect.contains(lastPoint))
				painter.setBrush(QBrush(QColor(135, 135, 135), Qt::SolidPattern));

			painter.drawRect(rect);

			painter.setPen(QPen(Qt::black, 1.0f));
			painter.drawText(0, i * ENTRYHEIGHT, 240, ENTRYHEIGHT, Qt::AlignCenter, m_entries.at(i));

			if (i == 3) {
				QPixmap pixmap = QPixmap(":/img/our_imgs/input.png");
				painter.drawPixmap(90, i * ENTRYHEIGHT + 10, 60, 60, pixmap);
				if (i == 3 && selected != "thin" && selected != "medium" && selected != "thick")
					painter.drawText(0, 3 * ENTRYHEIGHT, 90, 200 - 3 * ENTRYHEIGHT, Qt::AlignCenter, selected);
			}

			if (i == 0) continue;
			painter.setPen(QPen(Qt::white, 1.0f));
			painter.drawLine(QPoint(0, i * ENTRYHEIGHT - 1), QPoint(width(), i * ENTRYHEIGHT - 1));
		}


	}

	void WidthListWidget::mousePressEvent(QMouseEvent *event)
	{
		buttonPressed = true;
		lastPoint = event->pos();
		update();
	}

	void WidthListWidget::mouseReleaseEvent(QMouseEvent *event)
	{
		if (buttonPressed) {
			QString value;
			for (int i = 0; i < m_entries.size(); i++) {
				QRect rect = QRect(0, i * ENTRYHEIGHT, 240, ENTRYHEIGHT);
				if (i == 3)
					rect = QRect(0, 3 * ENTRYHEIGHT, 240, 200 - 3 * ENTRYHEIGHT);

				if (rect.contains(lastPoint))
					value = m_entries.at(i);
			}

			if (value == "") value = selected;
			qDebug() << value;
			emit entryClicked(value);
		}

		buttonPressed = false;

		update();
	}

}
