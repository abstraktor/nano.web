#ifndef IPN_MarginEditApp_H
#define IPN_MarginEditApp_H

#include "App.h"
#include <QWebElement>
#include <QTimer>

namespace ipn
{
class BackgroundWidget;
class TitleBarWidget;
class TextWidget;
class ScalableButtonWidget;
class PageIndicatorWidget;

class MarginEditApp : public App
{
	Q_OBJECT

public:
	MarginEditApp(QWidget *parent = 0);

	inline bool isOpaque() {return false;}
	void setElement(QWebElement el);
	QWebElement getElement();

public slots:
	void swipeLeft();
	void swipeRight();


signals:
	void borderEdit(QString property);

protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void paintEvent(QPaintEvent *event);

private:
	bool canLeft();
	bool canRight();
	bool leftPressed, topPressed, rightPressed, bottomPressed, centerPressed;
	void updateView();
	QPoint topLeft, topRight, bottomLeft, bottomRight;
	QWebElement currentEl;

	QString backgroundString;

	// helpers
	int signum(int number);
};

} // namespace ipn

#endif /* end of include guard: IPN_MarginEditApp_H */
