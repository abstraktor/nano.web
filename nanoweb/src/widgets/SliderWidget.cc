#include "SliderWidget.h"
#include "ButtonWidget.h"
#include "ImageWidget.h"
#include "TextWidget.h"
#include "helpers.h"
#include <QMouseEvent>

namespace ipn
{

	SliderWidget::SliderWidget(QWidget *parent) : ClickableWidget(parent)
	{
		m_position = 0.5;
		m_active = false;
		m_title = new TextWidget(this);
		m_title->setColor(Qt::white);
		m_title->setFontSize(11);
		m_title->setFontStyle(TextWidget::STYLE_BOLD);
		m_title->setAlignment(Qt::AlignHCenter);

		m_barLeftImage = new ImageWidget(this);
		m_barLeftImage->setImage(":/img/slider/bar_left.png");

		m_barActiveImage = new ImageWidget(this);
		m_barActiveImage->setImage(":/img/slider/bar_active.png");

		m_barInactiveImage = new ImageWidget(this);
		m_barInactiveImage->setImage(":/img/slider/bar_inactive.png");

		m_barRightImage = new ImageWidget(this);
		m_barRightImage->setImage(":/img/slider/bar_right.png");

		m_grabber = new ButtonWidget(this);
		m_grabber->setInactiveImages(":/img/slider/grabber.png", ":/img/slider/grabber_down.png");
		m_grabber->setAttribute(Qt::WA_TransparentForMouseEvents);

		setWidth(128);
	}

	void SliderWidget::paintEvent(QPaintEvent*)
	{
		float position = m_position;

		if (isMouseDown())
			position = helpers::maxf(0, helpers::minf(1, m_position + ((float)distanceSinceMouseDown().x() / (float)m_width)));

		int padding = m_grabber->height() / 2;
		int separator = m_width * position;
		int activeWidth = helpers::max(0, helpers::min(m_width, separator - 8));
		int inactiveWidth = helpers::max(0, helpers::min(m_width, m_width - separator - 8));

		m_barLeftImage->move(padding, padding - m_barLeftImage->height() / 2);
		m_barActiveImage->move(padding + 8, padding - m_barActiveImage->height() / 2);
		m_barActiveImage->resize(activeWidth, m_barActiveImage->height());
		m_barInactiveImage->move(padding + separator, padding - m_barInactiveImage->height() / 2);
		m_barInactiveImage->resize(inactiveWidth, m_barInactiveImage->height());
		m_barRightImage->move(padding + m_width - 8, padding - m_barRightImage->height() / 2);

		m_grabber->move(padding + separator - m_grabber->width() / 2, 0);

		m_title->move(0, m_grabber->height() - 4);
	}

	void SliderWidget::mousePressEvent(QMouseEvent *event)
	{
		int padding = m_grabber->height() / 2;
		m_position = helpers::maxf(0, helpers::minf(1, (float)(event->pos().x() - padding) / (float)m_width));

		m_grabber->press();

		ClickableWidget::mousePressEvent(event);
	}

	void SliderWidget::mouseMoveEvent(QMouseEvent *event)
	{
		if (isMouseDown())
			update();

		event->ignore();
	}

	void SliderWidget::mouseReleaseEvent(QMouseEvent *event)
	{
		m_position = helpers::maxf(0, helpers::minf(1, m_position + ((float)distanceSinceMouseDown().x() / (float)m_width)));

		m_grabber->release();

		ClickableWidget::mouseReleaseEvent(event);
	}

	void SliderWidget::setWidth(int width)
	{
		m_width = width;

		if (m_title->text() != QString())
			resize(m_width + m_grabber->width(), m_grabber->height() - 4 + m_title->textHeight());
		else
			resize(m_width + m_grabber->width(), m_grabber->height());
	}

	QString SliderWidget::title()
	{
		return m_title->text();
	}

	TextWidget *SliderWidget::titleAsTextWidget()
	{
		return m_title;
	}

	void SliderWidget::setTitle(QString title)
	{
		m_title->setText(title);
		m_title->resize(width(), m_title->textHeight());

		resize(m_width + m_grabber->width(), m_grabber->height() - 4 + m_title->textHeight());
	}

	bool SliderWidget::isActive()
	{
		return m_active;
	}

	void SliderWidget::setActive(bool isActive)
	{
		bool oldActive = m_active;
		m_active = isActive;

		// if the image changed, refresh the button view
		if (m_active != oldActive)
			update();
	}

	float SliderWidget::position()
	{
		return m_position;
	}

	void SliderWidget::setPosition(float position)
	{
		m_position = position;
	}

} // namespace ipn
