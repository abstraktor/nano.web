#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QApplication>
#include <QGraphicsWebView>
#include <QGraphicsSceneMouseEvent>
#include <QWebElement>
#include <QWebFrame>
#include "nanoweb/NanoWebView.h"

namespace ipn
{
    NanoWebView::NanoWebView(QGraphicsItem *parent) : QGraphicsWebView(parent)
        {

	}

    void NanoWebView::mousePressEvent(QGraphicsSceneMouseEvent *event) {
		QPoint pos = QPoint(event->scenePos().x(), event->scenePos().y());
		QWebElement el = this->page()->mainFrame()->hitTestContent(pos).element();
		//QWebElement el = this->page()->mainFrame()->hitTestContent(pos).linkElement();  // for link element

        event->setAccepted(true);
        //emit elementTapped();
    }

}

