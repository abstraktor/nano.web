#include "MockUpApp.h"
#include <QDebug>

namespace ipn
{

    MockUpApp::MockUpApp(QWidget *parent) : App(parent)
    {
        connect(this, SIGNAL(setContentScrollPosition(QPoint)), parent, SLOT(setContentScrollPosition(QPoint)));
        connect(this, SIGNAL(getContentScrollPosition()), parent, SLOT(getContentScrollPosition()));
        connect(this, SIGNAL(setContentZoomFactor(double)), parent, SLOT(setContentZoomFactor(double)));
        connect(this, SIGNAL(getContentZoomFactor()), parent, SLOT(getContentZoomFactor()));

        m_flickArea = new FlickArea(this);
        m_flickArea->resize(240, 240);
        m_flickArea->move(0,0);

        m_image = new MockupWidget(m_flickArea);
        m_image->setImage(":/img/our_imgs/mockup.png");
        connect(this, SIGNAL(pinchScaleFactorChanged(qreal)), this, SLOT(changePinchScaleFactor(qreal)));
        zoomFactor = 1.0;
        connect(m_image, SIGNAL(moved(QPoint)), this, SLOT(sendContentScrollPosition(QPoint)));

        m_text = new TextWidget(this);
        m_text->otherStyle = true;
        m_text->setText("Vorlage");
        m_text->resize(100, 30);
        m_text->move(140, 210);

        name = "MockUpApp";
    }

    void MockUpApp::updateView() {
        raise();
        m_image->setZoomFactor(emit getContentZoomFactor());
        m_image->move(emit getContentScrollPosition());
        m_flickArea->update();
        m_image->update();
        update();
    }

	void MockUpApp::sendUpdatedInfo(QPoint pos) {
		emit setContentScrollPosition(pos);
		emit setContentZoomFactor(zoomFactor);
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
		sendUpdatedInfo(m_image->pos());
		m_image->update();
    }

} // namespace ipn
