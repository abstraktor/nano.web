#ifndef IPN_NANOQWEBVIEWAPP_H
#define IPN_NANOQWEBVIEWAPP_H

#include "widgets/OverlayWidget.h"
#include <QWidget>
#include <QtWebKit>
#include <QWebView>
#include <QMouseEvent>

namespace ipn
{
	class NanoQWebview : public QWebView
	{
		Q_OBJECT

		public:
			NanoQWebview(QWidget *parent = 0);
		protected:
			virtual void mousePressEvent(QMouseEvent *);
		signals:
			virtual void elementTapped();

	};

} // namespace ipn

#endif /* end of include guard: IPN_NANOQWEBVIEWAPP_H */
