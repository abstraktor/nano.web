#ifndef IPN_MUSICAPP_H
#define IPN_MUSICAPP_H

#include "App.h"

namespace ipn
{

	class BackgroundWidget;
	class FlickArea;

	class MusicApp : public App
	{
		Q_OBJECT

		public:
			MusicApp(QWidget *parent = 0);

			inline bool isOpaque() {return false;}

		private:
			BackgroundWidget *m_back;
			FlickArea *m_flickArea;
	};

} // namespace ipn

#endif /* end of include guard: IPN_MUSICAPP_H */
