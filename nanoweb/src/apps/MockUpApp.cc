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
        zoomFactor = 1.0;
        connect(this, SIGNAL(pinchScaleFactorChanged(qreal)), this, SLOT(changePinchScaleFactor(qreal)));
		connect(m_image, SIGNAL(moved(QPoint)), this, SLOT(sendUpdatedInfo()));

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

	void MockUpApp::sendUpdatedInfo() {
		emit setContentScrollPosition(m_image->pos());
		emit setContentZoomFactor(zoomFactor);
    }

    void MockUpApp::changePinchScaleFactor(qreal delta)
    {
        zoomFactor = delta * zoomFactor;
        if (zoomFactor >= 3.0)
        {
			zoomFactor = 3.0;
        }
		if (zoomFactor < 0.3)
        {
			zoomFactor = 0.3;
		}
		QPoint p = m_image->pos() - QPoint(120, 120);
		p = p * delta;
		p = p + QPoint(120, 120);
		p = setPositionCorrectly(p);
		m_image->move(p);
        m_image->setZoomFactor(zoomFactor);
		sendUpdatedInfo();
        m_image->update();
    }


	QPoint MockUpApp::setPositionCorrectly(QPoint p) {
		if (abs(p.x()) > (930 * zoomFactor - 240))
			p.setX(-(930 * zoomFactor - 240));
		if (abs(p.y()) > (525 * zoomFactor - 240))
			p.setY(-(525 * zoomFactor - 240));
		if (p.x() >= 0)
			p.setX(0);
		if (p.y() >= 0)
			p.setY(0);
		return p;
	}

} // namespace ipn
