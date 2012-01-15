#ifndef MOCKUPAPP_H
#define MOCKUPAPP_H

#include "App.h"
#include "widgets/FlickArea.h"
#include "widgets/MockupWidget.h"
#include "widgets/TextWidget.h"

namespace ipn
{
	class FlickArea;
	class MockUpApp : public App
	{
		Q_OBJECT

		public:
			MockUpApp(QWidget * parent = 0);

		public slots:
			void changePinchScaleFactor(qreal delta);

		private:
			FlickArea *m_flickArea;
			MockupWidget *m_image;
			TextWidget *m_text;
			double zoomFactor;


	};
}
#endif // MOCKUPAPP_H
