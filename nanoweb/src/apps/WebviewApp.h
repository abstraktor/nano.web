#ifndef IPN_WEBVIEWAPP_H
#define IPN_WEBVIEWAPP_H

#include "App.h"

namespace ipn
{
	class BackgroundWidget;
	class TitleBarWidget;
	class TextWidget;
	class ScalableButtonWidget;

        class WebviewApp : public App
	{
		Q_OBJECT

		public:
                        WebviewApp(QWidget *parent = 0);

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


                private:
                        QVector<QPolygon> m_drawing;

			BackgroundWidget *m_back;

			TitleBarWidget *m_lastGesture;
			TextWidget *m_scaleFactorText, *m_rotationAngleText, *m_swipeAngleText;
			ScalableButtonWidget *m_quitButton;

                        qreal m_currentScaleFactor, m_currentRotationAngle;
	};

} // namespace ipn

#endif /* end of include guard: IPN_WEBVIEWAPP_H */
