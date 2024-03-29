#ifndef IPN_MULTITAPAPP_H
#define IPN_MULTITAPAPP_H

#include "App.h"

namespace ipn
{

	class BackgroundWidget;
	class ImageWidget;
	class TextWidget;
	class ScalableButtonWidget;

	class MultiTapApp : public App
	{
		Q_OBJECT

		public:
			MultiTapApp(QWidget *parent = 0);

			inline bool isOpaque() {return true;}

			QString text();

		signals:
			void accepted(QString value);

		protected slots:
			void multiTapKeyPressed();
			void blink();
			void refreshText();
			void unitChange();

		protected:
			void handleKey(int key);

		private:
			BackgroundWidget *m_back;

			ImageWidget *m_textBoxLeft, *m_textBoxMiddle, *m_textBoxRight;
			TextWidget *m_text;
			ScalableButtonWidget *m_unitButton, *m_keys[12];

			QString m_currentText;
			QString unit;
			QTimer *m_cursorBlinkTimer;
			bool m_cursorBlink;
	};

} // namespace ipn

#endif /* end of include guard: IPN_MULTITAPAPP_H */
