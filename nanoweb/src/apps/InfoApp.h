#ifndef IPN_INFOAPP_H
#define IPN_INFOAPP_H

#include "App.h"

namespace ipn
{
	class BackgroundWidget;
	class TextWidget;
	class ScalableButtonWidget;

	class InfoApp : public App
	{
		Q_OBJECT

		public:
			InfoApp(QWidget *parent = 0);

			inline bool isOpaque() {return false;}

			void setMessage(QString message);

		signals:
			void okButtonClicked();

		private:
			BackgroundWidget *m_back;

			TextWidget *m_note;
			ScalableButtonWidget *m_okButton;
	};

} // namespace ipn

#endif /* end of include guard: IPN_INFOAPP_H */
