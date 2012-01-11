#include "WidthListWidget.h"
#include "TextWidget.h"
#include "ImageWidget.h"
#include "helpers.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

#define NO_ENTRY -1

namespace ipn
{

	WidthListWidget::WidthListWidget(QWidget *parent) : QWidget(parent)
	{
		m_entries = QVector<QString>();
		m_highlightedEntry = NO_ENTRY;
		m_activeEntry = NO_ENTRY;

	}

	void WidthListWidget::addEntry(QString text)
	{
		int numberOfEntries = m_entries.size();

		/*TextWidget *newEntry = new TextWidget(this);
		newEntry->setColor(Qt::black);
		newEntry->setText(text);
		newEntry->setAlignment(Qt::AlignLeft);
		newEntry->resize(184, newEntry->textHeight());
		newEntry->move(16, 12 + 48 * numberOfEntries);*/
		m_entries.append(text);

		resize(240, (numberOfEntries + 1) * 48);

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
			painter.drawRect(0, i * 48, 240, 48);
			painter.setPen(QPen(Qt::black, 1.0f));
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
				painter.drawLine(40, i * 48 + 24, 200, i * 48 + 24);
			}
			painter.drawText(0, i * 48, 240, 48, Qt::AlignCenter, m_entries.at(i));
			if (i == 0) continue;
			painter.setPen(QPen(Qt::white, 1.0f));
			painter.drawLine(QPoint(0, i * 48 - 1), QPoint(width(), i * 48 - 1));
		}

		QPixmap pixmap = QPixmap(":img/our_imgs/arrow_down.png");
		painter.drawPixmap(0, 192, 240, 8, pixmap);
	}

	void WidthListWidget::mousePressEvent(QMouseEvent *event)
	{
		if (event->pos().y() < 0 || event->pos().y() > m_entries.size() * 48)
		{
			m_highlightedEntry = -1;
			return;
		}

		m_highlightedEntry = event->pos().y() / 48;

		update();
	}

	void WidthListWidget::mouseReleaseEvent(QMouseEvent *event)
	{
		QRect highlightedEntryRect = QRect(0, m_highlightedEntry * 48,
			240, (m_highlightedEntry + 1) * 48);

		if (highlightedEntryRect.contains(event->pos()))
		{
			m_activeEntry = m_highlightedEntry;
			emit entryChanged();
		}

		m_highlightedEntry = -1;

		update();
	}

	int WidthListWidget::activeEntry()
	{
		return m_activeEntry;
	}

	QString WidthListWidget::activeEntryText()
	{
		if (m_activeEntry == NO_ENTRY || m_activeEntry >= m_entries.size())
			return QString();

		return m_entries[m_activeEntry];
	}

	void WidthListWidget::setActiveEntry(int activeEntry)
	{
		m_activeEntry = activeEntry;

		update();
	}

}
