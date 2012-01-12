#ifndef IPN_ScalableButtonWidget_H
#define IPN_ScalableButtonWidget_H

#include "ButtonWidget.h"

namespace ipn
{

	class TextWidget;
	class ImageWidget;

	class ScalableButtonWidget : public ButtonWidget
	{
		Q_OBJECT

		public:
			ScalableButtonWidget(QWidget *parent = 0);

			virtual void resize(int width, int height);
			virtual void move(int x, int y);

			void setTitle(QString title);

			QString text();
			TextWidget *textAsTextWidget();
			void setText(QString text);

			void setImage(QString fileNamePrefix);
			void setIconImage(QString iconFileName);

			int outerBorder();
			void setOuterBorder(int outerBorder);
			int interiorBorder();
			void setInteriorBorder(int interiorBorder);

		protected:
			virtual void paintEvent(QPaintEvent*);
			virtual void drawButton();

			int m_width, m_height;
			int m_outerBorder, m_interiorBorder;
			TextWidget *m_text;
			ImageWidget *m_iconImage;
	};

} // namespace ipn

#endif // IPN_ScalableButtonWidget_H
