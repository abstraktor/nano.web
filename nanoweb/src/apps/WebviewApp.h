#ifndef IPN_WEBVIEWAPP_H
#define IPN_WEBVIEWAPP_H

#include "App.h"
#include <QtWebKit>
#include <QWebView>
#include "widgets/FlickArea.h"
#include "nanoweb/NanoQWebView.h"

namespace ipn
{
	class BackgroundWidget;
	class TitleBarWidget;
	class TextWidget;
	class ScalableButtonWidget;
	class NanoQWebView;

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
		void backButtonClick();
		void rightButtonClick();
		void leftButtonClick();

	signals:
		void quitButtonClicked();
		void elementTapped(QWebElement el);
		void zoomTriggered();


	protected:
		virtual void mousePressEvent(QMouseEvent *event);
		virtual void mouseMoveEvent(QMouseEvent *event);


	private:
		QVector<QPolygon> m_drawing;
		NanoQWebview *m_webView;
		FlickArea *m_flickArea;

		BackgroundWidget *m_back;


		qreal m_currentScaleFactor, m_currentRotationAngle;
	};

} // namespace ipn

#endif /* end of include guard: IPN_WEBVIEWAPP_H */
