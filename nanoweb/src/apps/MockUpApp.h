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
	FlickArea *m_flickArea;
	void show();
	void updateView();

signals:
	QPoint getContentScrollPosition();
	void setContentScrollPosition(QPoint);
	double getContentZoomFactor();
	void setContentZoomFactor(double);

public slots:
	void changePinchScaleFactor(qreal delta);
	void sendUpdatedInfo();

private:
	MockupWidget *m_image;
	TextWidget *m_text;
	double zoomFactor;

	QPoint setPositionCorrectly(QPoint p);


};
}
#endif // MOCKUPAPP_H
