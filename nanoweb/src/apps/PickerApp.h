#ifndef IPN_PICKERAPP_H
#define IPN_PICKERAPP_H

#include "App.h"

namespace ipn
{

	class BackgroundWidget;
	class TitleBarWidget;
	class PickerWidget;
	class FlickArea;

	class PickerApp : public App
	{
		Q_OBJECT

		public:
			PickerApp(QWidget *parent = 0);

			inline bool isOpaque() {return true;}

			TitleBarWidget *titleBar();

		private:
			BackgroundWidget *m_back;
			TitleBarWidget *m_titleBar;
			FlickArea *m_flickArea;
			PickerWidget *m_picker;
	};

} // namespace ipn

#endif /* end of include guard: IPN_PICKERAPP_H */
