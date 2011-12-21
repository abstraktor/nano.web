#ifndef IPN_TITLEBARBUTTONWIDGET_H
#define IPN_TITLEBARBUTTONWIDGET_H

#include "ButtonWidget.h"

namespace ipn
{
	class TextWidget;

	class TitleBarButtonWidget : public ButtonWidget
	{
		Q_OBJECT

		public:
			TitleBarButtonWidget(QWidget *parent = 0);

			enum {BUTTON_RECTANGULAR, BUTTON_LEFT, BUTTON_RIGHT};

			void setText(QString text);
			void setButtonType(int buttonType);

		protected:
			TextWidget *m_text;
			int m_buttonType;
			int m_borderLeft, m_borderRight;
	};

} // namespace ipn

#endif // IPN_CUSTOMBUTTONWIDGET_H
