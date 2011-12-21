#ifndef IPN_BUTTONWIDGET_H
#define IPN_BUTTONWIDGET_H

#include "ClickableWidget.h"

namespace ipn
{

	class TextWidget;
	class ImageWidget;

	class ButtonWidget : public ClickableWidget
	{
		Q_OBJECT

		public:
			ButtonWidget(QWidget *parent = 0);
			virtual ~ButtonWidget();

			QString title();
			TextWidget *titleAsTextWidget();
			virtual void setTitle(QString title);

			bool isActive();
			void setActive(bool isActive);

			void setInactiveImages(QString inactiveFileName, QString inactiveDownFileName = QString());
			void setActiveImages(QString activeFileName, QString activeDownFileName = QString());
			void setDisabledImage(QString disabledFileName);

		protected:
			virtual void paintEvent(QPaintEvent *event);
			QPixmap *currentImage();

			QPixmap *m_inactiveImage, *m_inactiveDownImage, *m_activeImage, *m_activeDownImage, *m_disabledImage;

		private:
			ImageWidget *m_image;
			TextWidget *m_title;

			bool m_active;
	};

} // namespace ipn

#endif // IPN_BUTTONWIDGET_H
