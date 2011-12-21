#ifndef IPN_SliderWidget_H
#define IPN_SliderWidget_H

#include "ClickableWidget.h"

namespace ipn
{

	class ImageWidget;
	class ButtonWidget;
	class TextWidget;

	class SliderWidget : public ClickableWidget
	{
		Q_OBJECT

		public:
			SliderWidget(QWidget *parent = 0);

			void setWidth(int width);
			QString title();
			TextWidget *titleAsTextWidget();
			void setTitle(QString title);
			bool isActive();
			void setActive(bool isActive);
			float position();
			void setPosition(float position);

		protected:
			virtual void paintEvent(QPaintEvent *event);
			virtual void mousePressEvent(QMouseEvent *event);
			virtual void mouseMoveEvent(QMouseEvent *event);
			virtual void mouseReleaseEvent(QMouseEvent *event);

		private:
			ImageWidget *m_barLeftImage, *m_barActiveImage, *m_barInactiveImage, *m_barRightImage;
			ButtonWidget *m_grabber;
			TextWidget *m_title;

			int m_width;
			float m_position;
			bool m_active;
	};

} // namespace ipn

#endif // IPN_SliderWidget_H
