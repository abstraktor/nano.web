#ifndef IPN_CLOCKAPP_H
#define IPN_CLOCKAPP_H

#include "App.h"

class QTimerEvent;

namespace ipn
{

	class BackgroundWidget;
	class TextWidget;
	class ScalableButtonWidget;

	class ClockApp : public App
	{
		Q_OBJECT

		public:
			ClockApp(QWidget * parent = 0);

			inline bool isOpaque() {return false;}

		signals:
			void okButtonClicked();

		protected:
			virtual void timerEvent(QTimerEvent *event);
			virtual void mouseReleaseEvent(QMouseEvent *event);

		private:
			BackgroundWidget *m_back;

			TextWidget *m_timeText;
			ScalableButtonWidget *m_okButton;
	};


} // namespace ipn

#endif /* end of include guard: IPN_CLOCKAPP_H */
