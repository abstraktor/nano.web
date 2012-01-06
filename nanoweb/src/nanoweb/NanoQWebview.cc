#include "NanoQWebview.h"
#include <QWebView>
#include <QDebug>
#include <QWebElement>

namespace ipn
{
	NanoQWebview::NanoQWebview(QWidget *parent) : QWebView(parent)
	{
	}

	void NanoQWebview::mousePressEvent(QMouseEvent *event) {
		QPoint pos = event->pos();
		qDebug() << "EVENT: mousePress" << pos;
		QWebElement el = this->page()->mainFrame()->hitTestContent(pos).element();
		//QWebElement el = this->page()->mainFrame()->hitTestContent(pos).linkElement();  // for link element
		qDebug() << "TagName: " << el.tagName();

		event->setAccepted(true);
		emit elementTapped();
	}

} // namespace ipn
