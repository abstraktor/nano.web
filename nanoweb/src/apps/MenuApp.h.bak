#ifndef IPN_MENUAPP_H
#define IPN_MENUAPP_H

#include "App.h"

namespace ipn
{

	class BackgroundWidget;
	class TitleBarWidget;
	class ScalableButtonWidget;

	class MenuApp : public App
	{
		Q_OBJECT

		public:
            MenuApp(QWidget *parent = 0);

			enum ButtonPosition {TopLeft, TopRight, BottomLeft, BottomRight};

			ScalableButtonWidget *button(ButtonPosition position);
			void addButton(ButtonPosition position, QString title, QString iconImage);

			inline bool isOpaque() {return true;}
			TitleBarWidget *titleBar();

		signals:
			void backButtonClicked();
            void topLeftButtonClicked();
            void topRightButtonClicked();
            void bottomLeftButtonClicked();
            void bottomRightButtonClicked();

		protected:
			BackgroundWidget *m_back;

			TitleBarWidget *m_titleBar;
			ScalableButtonWidget *m_buttons[4];
	};

} // namespace ipn

#endif /* end of include guard: IPN_MENUAPP_H */
