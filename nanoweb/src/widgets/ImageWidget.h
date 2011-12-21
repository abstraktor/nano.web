#ifndef IPN_IMAGEWIDGET_H
#define IPN_IMAGEWIDGET_H

#include <QWidget>

namespace ipn
{

	class ImageWidget : public QWidget
	{
		Q_OBJECT

		public:
			ImageWidget(QWidget *parent = 0);
			virtual ~ImageWidget();

			virtual void resize(int width, int height);

			bool isMouseOver();

			void setOpacity(float opacity);
			float opacity();
			void setImage(QString imageFileName);
			void setImage(QPixmap *image);
			QPixmap *image();

		protected:
			void paintEvent(QPaintEvent*);

		private:
			float m_opacity;
			bool m_wasImageCreatedInternally;
			QPixmap *m_image;
	};

}

#endif // IPN_CLICKABLEWIDGET_H
