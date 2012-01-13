#ifndef IPN_MAPAPP_H
#define IPN_MAPAPP_H

#include "App.h"

namespace ipn
{
	class TitleBarWidget;
	class FlickArea;
	class ImageWidget;

	class MapApp : public App
	{
		Q_OBJECT

		public:
			MapApp(QWidget *parent = 0);

			inline bool isOpaque() {return true;}

			TitleBarWidget *titleBar();

		private:
			TitleBarWidget *m_titleBar;
			FlickArea *m_flickArea;
			ImageWidget *m_image;
	};

} // namespace ipn

#endif /* end of include guard: IPN_MAPAPP_H */
