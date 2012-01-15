#ifndef IPN_BORDEREDITAPP_H
#define IPN_BORDEREDITAPP_H

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

class BorderEditApp : public App
{
	 Q_OBJECT

    public:
		BorderEditApp(QWidget *parent = 0);

		inline bool isOpaque() {return false;}
		void setElement(QWebElement el);
		QWebElement getElement();

	public slots:
		void timerTick();
		void swipeLeft();
                void swipeRight();


	signals:
		void borderEdit(QString property);

    protected:
		virtual void mousePressEvent(QMouseEvent *event);
		virtual void mouseMoveEvent(QMouseEvent *event);
		virtual void mouseReleaseEvent(QMouseEvent *event);
		virtual void paintEvent(QPaintEvent *event);

	private:
		bool canLeft();
		bool canRight();
		void stopAnimation();
		bool leftPressed, topPressed, rightPressed, bottomPressed, centerPressed;
		void updateView();
		PageIndicatorWidget *m_pageIndicator;
		QPoint topLeft, topRight, bottomLeft, bottomRight;
		QWebElement currentEl;

		QString backgroundString;

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

#endif /* end of include guard: IPN_BORDEREDITAPP_H */
