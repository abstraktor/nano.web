#ifndef IPN_BORDERWIDTHAPP_H
#define IPN_BORDERWIDTHAPP_H

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

class BorderWidthApp : public App
{
	 Q_OBJECT

    public:
		BorderWidthApp(QWidget *parent = 0);

		inline bool isOpaque() {return false;}
		void setElement(QWebElement el);
		QWebElement getElement();

	public slots:
		void timerTick();
		void swipeLeft();
		void swipeRight();
		void backButtonClick();


	signals:
		void borderWidthEdit(QString property);
		void borderStyleEdit(QString property);
		void borderColorEdit(QString property);


    protected:
		virtual void mousePressEvent(QMouseEvent *event);
		virtual void mouseMoveEvent(QMouseEvent *event);
		virtual void mouseReleaseEvent(QMouseEvent *event);
		virtual void paintEvent(QPaintEvent *event);

	private:
		bool canLeft();
		bool canRight();
		void updateView();
		QWebElement currentEl;
		QString cssproperty;

		/*
		 * Start animation stuff
		 */
		QPoint translation;
		QPoint lastPoint;
		QPoint diff;

		QPoint animationStart;
		QPoint animationDestination;
		int tickCount;

		bool mousePressed;
		bool doSwiping;
		QTimer *animationTimer;
		int moves;

		int axis;
		/*
		 * End animation stuff
		 */
		// helpers
		int signum(int number);
		void setAnimationParametersToZero();
		double distance(QPoint a, QPoint b);

};

} // namespace ipn

#endif /* end of include guard: IPN_BORDERWIDTHAPP_H */
