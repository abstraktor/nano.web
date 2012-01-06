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
		//qDebug() << "EVENT: mousePress" << pos;
		//qDebug() << "#" << this->page()->mainFrame()->hitTestContent(pos).element().tagName().length() << "#";
		QWebElement el = this->page()->mainFrame()->hitTestContent(pos).element();
		if (el.tagName() == "")
			el = this->page()->mainFrame()->hitTestContent(pos).linkElement();  // for link element
		qDebug() << "TagName: " << "" << "#" << el.tagName();

		event->setAccepted(true);
		el.setStyleProperty("background-color", "red !important");
		emit elementTapped(el);
	}

} // namespace ipn
