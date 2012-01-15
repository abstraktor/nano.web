#include "MockUpApp.h"
#include <QDebug>

namespace ipn
{

        MockUpApp::MockUpApp(QWidget *parent) : App(parent)
		{
			m_flickArea = new FlickArea(this);
			m_flickArea->resize(240, 240);
			m_flickArea->move(0, 0);

			m_image = new MockupWidget(m_flickArea);
			m_image->setImage(":/img/our_imgs/mockup.png");
			connect(this, SIGNAL(pinchScaleFactorChanged(qreal)), this, SLOT(changePinchScaleFactor(qreal)));
			zoomFactor = 1.0;

			m_text = new TextWidget(this);
			m_text->otherStyle = true;
			m_text->setText("Vorlage");
			m_text->resize(100, 30);
			m_text->move(140, 210);

			name = "MockUpApp";
        }

		void MockUpApp::changePinchScaleFactor(qreal delta)
		{
			zoomFactor = delta * zoomFactor;
			if (zoomFactor >= 3.0)
			{
				zoomFactor = 3.0;
				return;
			}
			if (zoomFactor < 0.2)
			{
				zoomFactor = 0.2;
				return;
			}
			qDebug() << zoomFactor;
			m_image->setZoomFactor(zoomFactor);
			m_image->update();
		}

} // namespace ipn
