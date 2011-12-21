#include "TextWidget.h"
#include "helpers.h"
#include <QPainter>

namespace ipn
{

	TextWidget::TextWidget(QWidget *parent) : QWidget(parent)
	{
		m_textLines = QStringList(QString());
		m_fontSize = 15;
		m_fontStyle = STYLE_REGULAR;
		m_alignment = Qt::AlignCenter;
		m_color = Qt::black;
		m_lineHeight = 1.0;

		setAttribute(Qt::WA_TransparentForMouseEvents);
	}

	void TextWidget::paintEvent(QPaintEvent*)
	{
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing, true);

		if (m_textLines.size() > 0)
		{
			int weight = 50;

			if (m_fontStyle == STYLE_BOLD)
				weight = 75;

			painter.setFont(QFont("Ubuntu", m_fontSize * ipn::helpers::fontSizeFactor, weight));

			painter.setOpacity(1.0);
			painter.setPen(m_color);

			int yOffset;

			if (m_alignment & Qt::AlignTop)
				yOffset = 0;
			else if (m_alignment & Qt::AlignBottom)
				yOffset = -textHeight() + lineHeightInPixels();
			else
				yOffset = -((m_textLines.size() - 1) * lineHeightInPixels()) / 2;

			for (int i = 0; i < m_textLines.size(); i++)
			{
				painter.drawText(0, yOffset, width(), height(), m_alignment, m_textLines[i]);
				yOffset += lineHeightInPixels();
			}
		}
	}

	int TextWidget::lineHeightInPixels()
	{
		// Convert point size to pixels
		float inPixels = m_fontSize * 1.5;

		return inPixels * m_lineHeight;
	}

	int TextWidget::numberOfLines()
	{
		return m_textLines.size();
	}

	int TextWidget::textHeight()
	{
		return numberOfLines() * lineHeightInPixels();
	}

	QString TextWidget::text()
	{
		QString text = QString();

		for (int i = 0; i < m_textLines.size(); i++)
		{
			if (i != 0)
				text += '\n';

			text += m_textLines[i];
		}

		return text;
	}

	void TextWidget::setText(QString text)
	{
		m_textLines = text.split('\n');

		update();
	}

	int TextWidget::fontSize()
	{
		return m_fontSize;
	}

	void TextWidget::setFontSize(int fontSize)
	{
		m_fontSize = fontSize;
	}

	float TextWidget::lineHeight()
	{
		return m_lineHeight;
	}

	void TextWidget::setLineHeight(float lineHeight)
	{
		m_lineHeight = lineHeight;
	}

	int TextWidget::fontStyle()
	{
		return m_fontStyle;
	}

	void TextWidget::setFontStyle(int fontStyle)
	{
		m_fontStyle = fontStyle;
	}

	QColor TextWidget::color()
	{
		return m_color;
	}

	void TextWidget::setColor(QColor color)
	{
		m_color = color;
	}

	Qt::Alignment TextWidget::alignment()
	{
		return m_alignment;
	}

	void TextWidget::setAlignment(Qt::Alignment alignment)
	{
		m_alignment = alignment;
	}

}
