#include "ScalableButtonWidget.h"
#include "TextWidget.h"
#include "ImageWidget.h"
#include "helpers.h"
#include <QPainter>
#include <QFile>

namespace ipn
{

	ScalableButtonWidget::ScalableButtonWidget(QWidget *parent) : ButtonWidget(parent)
	{
		m_outerBorder = 8;
		m_interiorBorder = 8;

		m_text = new TextWidget(this);
		m_text->setFontSize(15);
		m_text->setFontStyle(TextWidget::STYLE_BOLD);
		m_text->setAlignment(Qt::AlignBottom);

		m_iconImage = new ImageWidget(this);
	}

	void ScalableButtonWidget::resize(int width, int height)
	{
		m_width = width;
		m_height = height;

		// add a descender of 4 pixels so that letters like 'g' are displayed entirely
		int descender = 4;

		if (titleAsTextWidget()->text() != QString())
			ButtonWidget::resize(m_width + 2 * m_outerBorder,
				m_height + 2 * m_outerBorder + 4 + m_text->textHeight() + descender);
		else
			ButtonWidget::resize(m_width + 2 * m_outerBorder,
				m_height + 2 * m_outerBorder);

		titleAsTextWidget()->move(0, m_outerBorder + m_height + descender);
		titleAsTextWidget()->resize(this->width(), titleAsTextWidget()->textHeight() + descender);

		m_text->move(m_outerBorder, m_outerBorder);
		m_text->resize(width, height);
	}

	void ScalableButtonWidget::move(int x, int y)
	{
		QWidget::move(x - m_outerBorder, y - m_outerBorder);
	}

	void ScalableButtonWidget::setTitle(QString title)
	{
		ButtonWidget::setTitle(title);

		titleAsTextWidget()->move(0, m_outerBorder + m_height + 4);
		resize(m_width, m_height);
	}

	QString ScalableButtonWidget::text()
	{
		return m_text->text();
	}

	TextWidget *ScalableButtonWidget::textAsTextWidget()
	{
		return m_text;
	}

	void ScalableButtonWidget::setText(QString text)
	{
		m_text->setText(text);

		update();
	}

	void ScalableButtonWidget::setImage(QString fileNamePrefix)
	{
		QFile inactiveFile(fileNamePrefix + ".png");
		QFile inactiveDownFile(fileNamePrefix + "_down.png");
		QFile activeFile(fileNamePrefix + "_active.png");
		QFile activeDownFile(fileNamePrefix + "_active_down.png");
		QFile disabledFile(fileNamePrefix + "_disabled.png");

		if (inactiveFile.exists() && inactiveDownFile.exists())
			setInactiveImages(fileNamePrefix + ".png", fileNamePrefix + "_down.png");
		else if (inactiveFile.exists())
			setInactiveImages(fileNamePrefix + ".png");

		if (activeFile.exists() && activeDownFile.exists())
			setActiveImages(fileNamePrefix + "_active.png", fileNamePrefix + "_active_down.png");
		else if (activeFile.exists())
			setActiveImages(fileNamePrefix + "_active.png");

		if (disabledFile.exists())
			setDisabledImage(fileNamePrefix + "_disabled.png");

		m_text->move(m_outerBorder, m_outerBorder);
		m_text->resize(m_width, m_height);
		m_text->setAlignment(Qt::AlignCenter);

		resize(m_width,	m_height);
	}

	void ScalableButtonWidget::setIconImage(QString iconFileName)
	{
		m_iconImage->setImage(iconFileName);

		update();
	}

	int ScalableButtonWidget::outerBorder()
	{
		return m_outerBorder;
	}

	void ScalableButtonWidget::setOuterBorder(int outerBorder)
	{
		m_outerBorder = outerBorder;
	}

	int ScalableButtonWidget::interiorBorder()
	{
		return m_interiorBorder;
	}

	void ScalableButtonWidget::setInteriorBorder(int interiorBorder)
	{
		m_interiorBorder = interiorBorder;
	}

	void ScalableButtonWidget::paintEvent(QPaintEvent*)
	{
		// every button needs a default image
		if (m_inactiveImage == NULL)
			return;

		if (isEnabled())
			titleAsTextWidget()->setColor(Qt::white);
		else
			titleAsTextWidget()->setColor(Qt::gray);

		drawButton();

		if (!isEnabled())
			m_iconImage->setOpacity(0.75);
		else
			m_iconImage->setOpacity(1.0);

		m_iconImage->move(m_outerBorder + (m_width - m_iconImage->width()) / 2,
			m_outerBorder + (m_height - m_iconImage->height()) / 2);
	}

	void ScalableButtonWidget::drawButton()
	{
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing, true);

		// get the current button image and draw it
		QPixmap *buttonImage = currentImage();

		int sourceSize = buttonImage->width();

		int sourceSplit[4] = {0,
			m_outerBorder + m_interiorBorder,
			sourceSize - m_outerBorder - m_interiorBorder,
			sourceSize};

		int fillSplit[4][2] = {{0, 0},
			{m_outerBorder + m_interiorBorder, m_outerBorder + m_interiorBorder},
			{m_outerBorder + m_width - m_interiorBorder, m_outerBorder + m_height - m_interiorBorder},
			{m_width + 2 * m_outerBorder, m_height + 2 * m_outerBorder}};

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				QRect sourceRect = QRect(sourceSplit[i],
					sourceSplit[j],
					sourceSplit[i + 1] - sourceSplit[i],
					sourceSplit[j + 1] - sourceSplit[j]);

				QRect fillRect = QRect(fillSplit[i][0],
					fillSplit[j][1],
					fillSplit[i + 1][0] - fillSplit[i][0],
					fillSplit[j + 1][1] - fillSplit[j][1]);

				painter.drawPixmap(fillRect, *buttonImage, sourceRect);
			}
	}

} // namespace ipn
