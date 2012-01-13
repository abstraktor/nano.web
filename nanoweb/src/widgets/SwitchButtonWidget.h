#ifndef IPN_SWITCHBUTTONWIDGET_H
#define IPN_SWITCHBUTTONWIDGET_H

#include "ButtonWidget.h"

namespace ipn
{

	class SwitchButtonWidget : public ButtonWidget
	{
		Q_OBJECT

		public:
			SwitchButtonWidget(QWidget *parent = 0);

			bool isOn();

		public slots:
			void switchOn();
			void switchOff();
			void toggle();
	};

} // namespace ipn

#endif // IPN_SWITCHBUTTONWIDGET_H
