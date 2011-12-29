#ifndef IPN_WEBVIEWAPP_H
#define IPN_WEBVIEWAPP_H

#include "App.h"
#include <QtWebKit>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsWebView>

namespace ipn
{
	class BackgroundWidget;
	class TitleBarWidget;
	class TextWidget;
	class ScalableButtonWidget;
	class NanoWebView;

	class WebviewApp : public App
	{
		Q_OBJECT

	public:
		WebviewApp(QWidget *parent = 0);

		inline bool isOpaque() {return false;}

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


	private:
		QVector<QPolygon> m_drawing;
		QGraphicsView *m_graphicsView;
		QGraphicsScene *m_scene;
		NanoWebView *m_webView;

		BackgroundWidget *m_back;


		qreal m_currentScaleFactor, m_currentRotationAngle;
	};

} // namespace ipn

#endif /* end of include guard: IPN_WEBVIEWAPP_H */
