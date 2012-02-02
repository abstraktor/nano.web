#ifndef IPN_CHOOSETOOLBOXMODELAPP_H
#define IPN_CHOOSETOOLBOXMODELAPP_H

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

class ChooseToolBoxmodelApp : public App
{
	 Q_OBJECT

    public:
		ChooseToolBoxmodelApp(QWidget *parent = 0);

		inline bool isOpaque() {return false;}
		void setElement(QWebElement el);
		QWebElement getElement();

	signals:
		void borderButtonClicked();
		void paddingButtonClicked();
		void marginButtonClicked();
		void anotherButtonClicked();


    protected:
		virtual void mousePressEvent(QMouseEvent *event);
		virtual void mouseMoveEvent(QMouseEvent *event);
		virtual void mouseReleaseEvent(QMouseEvent *event);
		virtual void paintEvent(QPaintEvent *event);

	private:
		void updateView();
		ScalableButtonWidget *m_topLeft1, *m_topRight1, *m_bottomLeft1, *m_bottomRight1;
		QPoint topLeft, topRight, bottomLeft, bottomRight;
		QWebElement currentEl;


		// helpers
		int signum(int number);

};

} // namespace ipn

#endif /* end of include guard: IPN_CHOOSETOOLBOXMODELAPP_H */
