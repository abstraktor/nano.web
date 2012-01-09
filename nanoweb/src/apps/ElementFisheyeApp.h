#ifndef IPN_ELEMENTFISHEYEAPP_H
#define IPN_ELEMENTFISHEYEAPP_H

#include "App.h"
#include <QWebElement>
#include <QTimer>

namespace ipn
{
class BackgroundWidget;
class TitleBarWidget;
class TextWidget;
class ScalableButtonWidget;

class ElementFisheyeApp : public App
{
        Q_OBJECT

    public:
		ElementFisheyeApp(QWidget *parent = 0);

		inline bool isOpaque() {return false;}
		void setElement(QWebElement el);

	public slots:
		void timerTick();
		void swipeLeft();
		void swipeUp();
		void swipeRight();
		void swipeDown();
		void backButtonClick();


    signals:
		void elementTapped(QWebElement el);


    protected:
		virtual void mousePressEvent(QMouseEvent *event);
		virtual void mouseMoveEvent(QMouseEvent *event);
		virtual void mouseReleaseEvent(QMouseEvent *event);
		virtual void paintEvent(QPaintEvent *event);

	private:
		void drawFisheye(QPainter *painter, QWebElement el, QColor bgcolor = Qt::white);
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

#endif /* end of include guard: IPN_ELEMENTFISHEYEAPP_H */
