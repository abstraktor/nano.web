#ifndef IPN_BACKGROUNDWIDGET_H
#define IPN_BACKGROUNDWIDGET_H

#include <QWidget>

namespace ipn
{

	class BackgroundWidget : public QWidget
	{
		Q_OBJECT

		public:
			enum {BG_TRANSPARENT, BG_GRAY, BG_WHITE};

			BackgroundWidget(QWidget *parent = 0);

			int color();
			void setColor(int color);

		public slots:

		protected:
			void paintEvent(QPaintEvent *event);

		private:
			int m_color;
	};

}

#endif // IPN_BUTTONWIDGET_H
