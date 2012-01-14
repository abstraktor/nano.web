#ifndef IPN_MOCKUPWIDGET_H
#define IPN_MOCKUPWIDGET_H

#include <QWidget>

namespace ipn
{

	class MockupWidget : public QWidget
	{
		Q_OBJECT

		public:
			MockupWidget(QWidget *parent = 0);
			virtual ~MockupWidget();

			virtual void resize(int width, int height);

			bool isMouseOver();

			void setOpacity(float opacity);
			float opacity();
			void setImage(QString imageFileName);
			void setImage(QPixmap *image);
			void setZoomFactor(double zoomFactor);
			double getZoomFactor();
			QPixmap *image();

		protected:
			void paintEvent(QPaintEvent*);

		private:
			float m_opacity;
			bool m_wasImageCreatedInternally;
			QPixmap *m_image, *scaled_pointer;
			QPixmap scaled;
			double zoomFactor;
	};
}

#endif // IPN_MOCKUPWIDGET_H
