#include <QWidget>
#include <QMouseEvent>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsWebView>
#include <QWebSettings>
#include "nanoweb/NanoWebView.h"

namespace ipn
{
	NanoWebView::NanoWebView(QGraphicsItem *parent) : QGraphicsWebView(parent)
	{
	}
}

