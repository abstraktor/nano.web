#ifndef IPN_ELEMENTTAPPEDAPP_H
#define IPN_ELEMENTTAPPEDAPP_H

#include "App.h"
#include <QWebElement>

namespace ipn
{
class BackgroundWidget;
class TitleBarWidget;
class TextWidget;
class ScalableButtonWidget;

class ElementTappedApp : public App
{
	Q_OBJECT

public:
	ElementTappedApp(QWidget *parent = 0);

	inline bool isOpaque() {return true;}
	QWebElement getElement();
	void setElement(QWebElement el);
	void updateView();

public slots:
	void pinchIn();
	void pinchOut();
	void swipeLeft();
	void swipeUp();
	void swipeRight();
	void swipeDown();
	void elementTappedInFisheye(QWebElement el);

protected:
	virtual void paintEvent(QPaintEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

signals:
	void leftButtonClicked();
	void elementTapped(QWebElement el);
	void editButtonClicked();


private:
	bool isElementTapped;
	bool showText;
	QColor buttonColor;
	TextWidget *m_explainText;
	ScalableButtonWidget *m_editElementButton, *m_refineButton;
	QWebElement currentEl;

};

} // namespace ipn

#endif /* end of include guard: IPN_ELEMENTTAPPEDAPP_H */
