#ifndef IPN_GUIAPP_H
#define IPN_GUIAPP_H

#include "App.h"

namespace ipn
{

	class BackgroundWidget;
	class TitleBarWidget;
	class SwitchButtonWidget;
	class SliderWidget;
	class TextWidget;
	class PageIndicatorWidget;
	class FlickArea;

	class GUIApp : public App
	{
		Q_OBJECT

		public:
			GUIApp(QWidget *parent = 0);

			inline bool isOpaque() {return true;}

			TitleBarWidget *titleBar();

		protected slots:
			void updatePageIndicator();

		private:
			BackgroundWidget *m_back;
			TitleBarWidget *m_titleBar;
			SwitchButtonWidget *m_switchButton;
			SliderWidget *m_slider;

			TextWidget *m_scrollText;
			FlickArea *m_flickArea;
			PageIndicatorWidget *m_pageIndicator;
	};

} // namespace ipn

#endif /* end of include guard: IPN_GUIAPP_H */
