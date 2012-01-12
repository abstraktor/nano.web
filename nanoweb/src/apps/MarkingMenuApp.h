#ifndef IPN_MARKINGMENUAPP_H
#define IPN_MARKINGMENUAPP_H

#include "App.h"

namespace ipn
{
	class BackgroundWidget;
	class TextWidget;
	class ScalableButtonWidget;
	class MarkingMenu;

	class MarkingMenuApp : public App
	{
		Q_OBJECT

		public:
			MarkingMenuApp(QWidget *parent = 0);

		inline bool isOpaque() {return false;}

		signals:
			void quitButtonClicked();

		protected:
			virtual void mousePressEvent(QMouseEvent *event);
			virtual void mouseReleaseEvent(QMouseEvent *event);
			virtual void mouseMoveEvent(QMouseEvent *event);

		private slots:
			void handleSwipeGesture(qreal angle);
			void handleMenuClick(QString entryText);

		private:
			BackgroundWidget *m_back;

			TextWidget *m_message;
			ScalableButtonWidget *m_quitButton, *m_menuButton;
			MarkingMenu *m_markingMenu;

			QTimer *m_menuInvokeTimer;
	};

} // namespace ipn

#endif /* end of include guard: IPN_MARKINGMENUAPP_H */
