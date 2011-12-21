#include "ButtonWidget.h"
#include "TextWidget.h"
#include "ImageWidget.h"
#include "helpers.h"
#include <QPainter>

namespace ipn
{

	ButtonWidget::ButtonWidget(QWidget *parent) : ClickableWidget(parent)
	{
		m_active = false;

		m_title = new TextWidget(this);
		m_title->setColor(Qt::white);
		m_title->setFontSize(11);
		m_title->setFontStyle(TextWidget::STYLE_BOLD);
		m_title->setAlignment(Qt::AlignHCenter);

		m_image = new ImageWidget(this);
		m_image->move(0, 0);

		m_activeImage = NULL;
		m_activeDownImage = NULL;
		m_inactiveImage = NULL;
		m_inactiveDownImage = NULL;
		m_disabledImage = NULL;
	}

	ButtonWidget::~ButtonWidget()
	{
		if (m_activeImage)
			delete m_activeImage;

		if (m_activeDownImage)
			delete m_activeDownImage;

		if (m_inactiveImage)
			delete m_inactiveImage;

		if (m_inactiveDownImage)
			delete m_inactiveDownImage;

		if (m_disabledImage)
			delete m_disabledImage;
	}

	void ButtonWidget::paintEvent(QPaintEvent*)
	{
		// every button needs a default image
		if (m_inactiveImage == NULL)
			return;

		m_image->setImage(currentImage());
	}

	QPixmap *ButtonWidget::currentImage()
	{
		// button is not enabled → show 'disabled' image if it exists
		if (!isEnabled() && m_disabledImage)
			return m_disabledImage;

		// button is down and active → show 'active/down' image if it exists
		else if (isMouseDown() && m_active && m_activeDownImage)
			return m_activeDownImage;

		// button is not down and active → show 'active' image if it exists
		else if (m_active && m_activeImage)
			return m_activeImage;

		// button is down and not active → show 'inactive/down' image if it exists
		else if (isMouseDown() && !m_active && m_inactiveDownImage)
			return m_inactiveDownImage;

		// in all other cases show the default 'inactive' image
		else
			return m_inactiveImage;
	}

	QString ButtonWidget::title()
	{
		return m_title->text();
	}

	TextWidget *ButtonWidget::titleAsTextWidget()
	{
		return m_title;
	}

	void ButtonWidget::setTitle(QString title)
	{
		m_title->setText(title);
		m_title->resize(m_title->width(), m_title->textHeight());

		if (m_inactiveImage)
			resize(m_inactiveImage->width(), m_inactiveImage->height() + 4 + m_title->textHeight());
	}

	bool ButtonWidget::isActive()
	{
		return m_active;
	}

	void ButtonWidget::setActive(bool isActive)
	{
		bool oldActive = m_active;
		m_active = isActive;

		// if the image changed, refresh the button view
		if (m_active != oldActive)
			update();
	}

	void ButtonWidget::setInactiveImages(QString inactiveFileName, QString inactiveDownFileName)
	{
		if (m_inactiveImage)
			delete m_inactiveImage;

		if (m_inactiveDownImage)
			delete m_inactiveDownImage;

		if (inactiveFileName != QString())
			m_inactiveImage = new QPixmap(inactiveFileName);

		if (inactiveDownFileName != QString())
			m_inactiveDownImage = new QPixmap(inactiveDownFileName);

		if (m_title->text() != QString())
			resize(m_inactiveImage->width(), m_inactiveImage->height() + 4 + m_title->textHeight());
		else
			resize(m_inactiveImage->width(), m_inactiveImage->height());

		if (m_inactiveImage)
			m_title->move(0, m_inactiveImage->height() + 4);

		m_title->resize(width(), m_title->height());

		update();
	}

	void ButtonWidget::setActiveImages(QString activeFileName, QString activeDownFileName)
	{
		if (m_activeImage)
			delete m_activeImage;

		if (m_activeDownImage)
			delete m_activeDownImage;

		if (activeFileName != QString())
			m_activeImage = new QPixmap(activeFileName);

		if (activeDownFileName != QString())
			m_activeDownImage = new QPixmap(activeDownFileName);

		update();
	}

	void ButtonWidget::setDisabledImage(QString disabledFileName)
	{
		if (m_disabledImage)
			delete m_disabledImage;

		if (disabledFileName != QString())
			m_disabledImage = new QPixmap(disabledFileName);

		update();
	}

} // namespace ipn
