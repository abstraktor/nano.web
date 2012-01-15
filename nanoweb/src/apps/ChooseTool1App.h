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
class PageIndicatorWidget;

class ChooseTool1App : public App
{
	 Q_OBJECT

    public:
		ChooseTool1App(QWidget *parent = 0);

		inline bool isOpaque() {return false;}
		void setElement(QWebElement el);
		QWebElement getElement();

	public slots:
		void timerTick();
		void swipeLeft();
                void swipeRight();
		void anotherButtonClickedSlot();
		void boxmodelButtonClickedSlot();


    signals:
		void boxmodelButtonClicked();
		void anotherButtonClicked();


    protected:
		virtual void mousePressEvent(QMouseEvent *event);
		virtual void mouseMoveEvent(QMouseEvent *event);
		virtual void mouseReleaseEvent(QMouseEvent *event);
		virtual void paintEvent(QPaintEvent *event);

	private:
		bool canLeft();
		bool canRight();
		void updateView();
		void stopAnimation();
		PageIndicatorWidget *m_pageIndicator;
		ScalableButtonWidget *m_topLeft1, *m_topRight1, *m_bottomLeft1, *m_bottomRight1;
		ScalableButtonWidget *m_topLeft2, *m_topRight2, *m_bottomLeft2, *m_bottomRight2;
		ScalableButtonWidget *m_topLeft3, *m_topRight3, *m_bottomLeft3, *m_bottomRight3;
		QPoint topLeft, topRight, bottomLeft, bottomRight;
		QWebElement currentEl;

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

#endif /* end of include guard: IPN_CHOOSETOOL1APP_H */
