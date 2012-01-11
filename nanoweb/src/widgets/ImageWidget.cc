#include "ImageWidget.h"
#include "helpers.h"
#include <QPainter>

namespace ipn
{

	ImageWidget::ImageWidget(QWidget *parent) : QWidget(parent)
	{
		setAttribute(Qt::WA_TransparentForMouseEvents);

		m_opacity = 1.0;
		m_image = NULL;
	}

	ImageWidget::~ImageWidget()
	{
		if (m_wasImageCreatedInternally && m_image)
			delete m_image;
	}

	void ImageWidget::resize(int width, int height)
	{
		QWidget::resize(width, height);

		setFixedSize(width, height);
	}

	bool ImageWidget::isMouseOver()
	{
		QPoint cursorPosition = mapFromGlobal(QCursor::pos());

		return (rect().contains(cursorPosition));
	}

	void ImageWidget::setOpacity(float opacity)
	{
		m_opacity = opacity;
	}

	float ImageWidget::opacity()
	{
		return m_opacity;
	}

	void ImageWidget::setImage(QString imageFileName)
	{
		if (m_wasImageCreatedInternally && m_image)
			delete m_image;

		m_image = new QPixmap(imageFileName);
		m_wasImageCreatedInternally = true;

		resize(m_image->width(), m_image->height());
		update();
	}

	void ImageWidget::setImage(QPixmap *image)
	{
		if (m_image == image)
			return;

		if (m_wasImageCreatedInternally && m_image)
			delete m_image;

		m_image = image;
		m_wasImageCreatedInternally = false;

		resize(m_image->width(), m_image->height());
		setFixedSize(width(), height());
		update();
	}

	QPixmap *ImageWidget::image()
	{
		return m_image;
	}

	void ImageWidget::paintEvent(QPaintEvent*)
	{
		if (!m_image)
			return;

		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing, true);
		painter.setOpacity(m_opacity);

		painter.drawPixmap(0, 0, width(), height(), *m_image);
	}

} // namespace ipn
