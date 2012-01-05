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
        void setMessage(QString message);

	public slots:
		void timerTick();


    signals:
        void quitButtonClicked();


    protected:
		virtual void mousePressEvent(QMouseEvent *event);
		virtual void mouseMoveEvent(QMouseEvent *event);
		virtual void mouseReleaseEvent(QMouseEvent *event);
		virtual void paintEvent(QPaintEvent *event);


	private:
		void drawFisheye(QPainter *painter, QWebElement *el = 0);
		int signum(int number);
		QVector<QPolygon> m_drawing;
		qreal translatex, translatey;

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

};

} // namespace ipn

#endif /* end of include guard: IPN_ELEMENTFISHEYEAPP_H */
