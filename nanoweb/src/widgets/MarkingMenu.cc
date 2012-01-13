#include "MarkingMenu.h"
#include "widgets/TextWidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <math.h>

namespace ipn
{

	MarkingMenu::MarkingMenu(QWidget *parent) : QWidget(parent)
	{
		// Set the default size:
		resize(240, 240);

		// By default, no entry is active:
		m_activeEntryId = -1;

		// Set the default active background color:
		m_activeColor = QColor(0, 224, 0);
	}

	void MarkingMenu::paintEvent(QPaintEvent*)
	{
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing, true);

		// Make all entries visible:
		int entryCount = m_menuEntries.size();

		// If there are no entries, do not draw anything:
		if (entryCount <= 0)
			return;

		for (int i = 0; i < entryCount; i++)
		{
			// Draw the pie sector without border and with the given background color:
			painter.setPen(Qt::transparent);

			if (m_activeEntryId == i)
				painter.setBrush(QBrush(m_activeColor));
			else
				painter.setBrush(QBrush(m_menuEntries.at(i).backgroundColor));

			painter.drawPie(rect(), ((180 + i * 360) / entryCount) * 16, (360 / entryCount) * 16);
		}
	}

	void MarkingMenu::addEntry(QString text, QColor backgroundColor, QColor textColor)
	{
		MarkingMenuEntry newEntry;

		// Create a new TextWidget for the new entry and define its look
		newEntry.text = new TextWidget(this);
		newEntry.text->setText(text);
		newEntry.text->setFontSize(15);
		newEntry.text->setAlignment(Qt::AlignCenter);
		newEntry.text->setColor(textColor);

		newEntry.backgroundColor = backgroundColor;

		m_menuEntries.append(newEntry);

		// Due to the new entry, all texts have to be repositioned
		updateTextPositions();
	}

	void MarkingMenu::updateTextPositions()
	{
		int entryCount = m_menuEntries.size();
		const float pi = 3.1415;

		for (int i = 0; i < entryCount; i++)
		{
			// Calculate the center point of the text rectangle:
			int centerX = width() / 2
				+ width() / 3.5 * cos((float)(i+1) * pi * 2 / entryCount);
			int centerY = height() / 2
				- height() / 3.5 * sin((float)(i+1) * pi * 2 / entryCount);
			QPoint center(centerX, centerY);

			// Calculate the position of the text and update it:
			QPoint textRectSize = QPoint(width() / 2, height() / 2);
			QPoint textPos(center - textRectSize / 2);

			m_menuEntries[i].text->resize(textRectSize.x(), textRectSize.y());
			m_menuEntries[i].text->move(textPos);
		}

		update();
	}

	void MarkingMenu::setActiveColor(QColor color)
	{
		m_activeColor = color;
	}

	int MarkingMenu::entryId(qreal angle)
	{
		angle -= 180 / m_menuEntries.size();

		while (angle >= 360.0)
			angle -= 360.0;

		while (angle < 0)
			angle += 360.0;

		return angle * m_menuEntries.size() / 360;
	}

	QString MarkingMenu::entryText(qreal angle)
	{
		return m_menuEntries.at(entryId(angle)).text->text();
	}

	void MarkingMenu::determineActiveEntry(QPoint cursorPosition)
	{
		qreal angle = QLineF(QPoint(width() / 2, height() / 2), cursorPosition).angle();
		m_activeEntryId = entryId(angle);

		update();
	}

	void MarkingMenu::mousePressEvent(QMouseEvent *event)
	{
		determineActiveEntry(event->pos());

		event->ignore();
	}

	void MarkingMenu::mouseReleaseEvent(QMouseEvent *event)
	{
		qreal angle = QLineF(QPoint(width() / 2, height() / 2), event->pos()).angle();

		emit entryClicked(entryId(angle));
		emit entryClicked(entryText(angle));

		m_activeEntryId = -1;

		event->ignore();
	}

	void MarkingMenu::mouseMoveEvent(QMouseEvent *event)
	{
		determineActiveEntry(event->pos());

		event->accept();
	}

	void MarkingMenu::deactivateAllEntries()
	{
		m_activeEntryId = -1;

		update();
	}
}
