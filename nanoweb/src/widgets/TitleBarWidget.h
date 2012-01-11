#ifndef IPN_TITLEBARWIDGET_H
#define IPN_TITLEBARWIDGET_H

#include "ClickableWidget.h"

namespace ipn
{

	class TitleBarButtonWidget;
	class TextWidget;
	class ImageWidget;

	class TitleBarWidget : public ClickableWidget
	{
		Q_OBJECT

		public:
			enum {BUTTON_BACK, BUTTON_CANCEL, BUTTON_CLOSE, BUTTON_DONE, BUTTON_EDIT, BUTTON_QUIT, BUTTON_REDO, BUTTON_SAVE, BUTTON_UNDO};

			TitleBarWidget(QWidget *parent = 0);

			void setTitle(QString title);

			void setLeftButton(QString text, int buttonType);
			void setRightButton(QString text, int buttonType);

			void addButton(int buttonType);

		signals:
			void leftButtonClicked();
			void rightButtonClicked();

		protected:
			void paintEvent(QPaintEvent *event);

			TextWidget *m_title;
			ImageWidget *m_titlebarImage;

			TitleBarButtonWidget *m_leftButton, *m_rightButton;
	};

} // namespace ipn

#endif // IPN_TITLEBARWIDGET_H
