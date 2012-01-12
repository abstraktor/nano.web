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
		event->setAccepted(false);
	}

	void NanoQWebview::mouseMoveEvent(QMouseEvent *event) {
		event->setAccepted(false);
	}

	void NanoQWebview::mouseReleaseEvent(QMouseEvent *event) {
		QPoint pos = event->pos();
		QWebElement el = this->page()->mainFrame()->hitTestContent(pos).element();
		if (el.tagName() == "")
			el = this->page()->mainFrame()->hitTestContent(pos).linkElement();  // for link element

		event->setAccepted(false);
		//el.setStyleProperty("background-color", "red !important"); // PROOF OF CONCEPT
		emit elementTapped(el);
		event->setAccepted(false);
	}
} // namespace ipn
