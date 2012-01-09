#ifndef IPN_CHOOSETOOL1APP_H
#define IPN_CHOOSETOOL1APP_H

#include "App.h"
#include <QWebElement>
#include <QTimer>

namespace ipn
{
class BackgroundWidget;
class TitleBarWidget;
class TextWidget;
class ScalableButtonWidget;

class ChooseTool1App : public App
{
	 Q_OBJECT

    public:
		ChooseTool1App(QWidget *parent = 0);

		inline bool isOpaque() {return false;}
		void setElement(QWebElement el);

	public slots:
		void timerTick();
		void swipeLeft();
		void swipeRight();
		void backButtonClick();


    signals:
		void tapped();


    protected:
		virtual void mousePressEvent(QMouseEvent *event);
		virtual void mouseMoveEvent(QMouseEvent *event);
		virtual void mouseReleaseEvent(QMouseEvent *event);
		virtual void paintEvent(QPaintEvent *event);

	private:
		bool canLeft();
		bool canRight();
		QWebElement currentEl, nextEl;

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

};

} // namespace ipn

#endif /* end of include guard: IPN_CHOOSETOOL1APP_H */
