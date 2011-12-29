#ifndef IPN_NANOWEBVIEW_H
#define IPN_NANOWEBVIEW_H

#include <QWidget>
#include <QMouseEvent>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsWebView>
#include <QWebSettings>

namespace ipn
{
	class NanoWebView : public QGraphicsWebView
	{
		public:
			NanoWebView(QGraphicsItem *parent = 0);
		protected:
			virtual void mousePressEvent(QGraphicsSceneMouseEvent *);

	};

}

#endif /* end of include guard: IPN_NANOWEBVIEW_H */
