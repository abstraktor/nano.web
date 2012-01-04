#ifndef IPN_ELEMENTFISHEYEAPP_H
#define IPN_ELEMENTFISHEYEAPP_H

#include "App.h"
#include <QWebElement>

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
        void changePinchRotationAngle(qreal delta);
        void changePinchScaleFactor(qreal delta);
        void pinchIn();
        void pinchOut();
        void swipeLeft();
        void swipeUp();
        void swipeRight();
        void swipeDown();
        void swipe(qreal angle);


    signals:
        void quitButtonClicked();


    protected:
		virtual void mousePressEvent(QMouseEvent *event);
		virtual void mouseMoveEvent(QMouseEvent *event);
		virtual void mouseReleaseEvent(QMouseEvent *event);
        virtual void paintEvent(QPaintEvent *event);


    private:
		void drawFisheye(QPainter *painter, QWebElement *el = 0);
		QVector<QPolygon> m_drawing;
		qreal translatex, translatey;
		QPoint translation;
		QPoint lastPoint;
		bool mousePressed;

};

} // namespace ipn

#endif /* end of include guard: IPN_ELEMENTFISHEYEAPP_H */
