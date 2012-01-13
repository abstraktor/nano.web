#ifndef IPN_NANOQWEBVIEWAPP_H
#define IPN_NANOQWEBVIEWAPP_H

#include "widgets/OverlayWidget.h"
#include <QWidget>
#include <QtWebKit>
#include <QWebView>
#include <QMouseEvent>
#include <QWebElement>

namespace ipn
{
	class NanoQWebview : public QWebView
	{
		Q_OBJECT

		public:
			NanoQWebview(QWidget *parent = 0);
		protected:
			virtual void mousePressEvent(QMouseEvent *);
			virtual void mouseMoveEvent(QMouseEvent *);
			virtual void mouseReleaseEvent(QMouseEvent *);
		signals:
			void elementTapped(QWebElement el);

		private:


	};

} // namespace ipn

#endif /* end of include guard: IPN_NANOQWEBVIEWAPP_H */
