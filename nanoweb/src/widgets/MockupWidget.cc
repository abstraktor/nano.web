#include "MockupWidget.h"
#include "helpers.h"
#include <QPainter>
#include <QDebug>

namespace ipn
{
	MockupWidget::MockupWidget(QWidget *parent) : QWidget(parent)
	{
		setAttribute(Qt::WA_TransparentForMouseEvents);

		m_opacity = 1.0;
		m_image = NULL;

		zoomFactor = 1.0;
	}

	double MockupWidget::getZoomFactor() {
		return zoomFactor;
	}

	void MockupWidget::setZoomFactor(double zoomFactor) {
		this->zoomFactor = zoomFactor;

		scaled = m_image->scaledToWidth(zoomFactor * m_image->width());
		scaled_pointer = &scaled;

		this->setImage(scaled_pointer);
	}

	MockupWidget::~MockupWidget()
	{
		if (m_wasImageCreatedInternally && m_image)
			delete m_image;
	}

	void MockupWidget::resize(int width, int height)
	{
		QWidget::resize(width, height);

		setFixedSize(width, height);
	}

	bool MockupWidget::isMouseOver()
	{
		QPoint cursorPosition = mapFromGlobal(QCursor::pos());

		return (rect().contains(cursorPosition));
	}

	void MockupWidget::setOpacity(float opacity)
	{
		m_opacity = opacity;
	}

	float MockupWidget::opacity()
	{
		return m_opacity;
	}

	void MockupWidget::setImage(QString imageFileName)
	{
		if (m_wasImageCreatedInternally && m_image)
			delete m_image;

		m_image = new QPixmap(imageFileName);
		m_wasImageCreatedInternally = true;

		resize(m_image->width(), m_image->height());
		update();
	}

	void MockupWidget::setImage(QPixmap *image)
	{
		resize(scaled_pointer->width(), scaled_pointer->height());
		setFixedSize(width(), height());
		update();
	}

	QPixmap *MockupWidget::image()
	{
		return m_image;
	}

	void MockupWidget::paintEvent(QPaintEvent*)
	{
		if (!m_image)
			return;

		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing, true);
		painter.setOpacity(m_opacity);

		painter.drawPixmap(0, 0, width(), height(), *m_image);
	}

} // namespace ipn
