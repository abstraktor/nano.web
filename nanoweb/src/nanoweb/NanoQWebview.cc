#include "NanoQWebview.h"
#include <QWebView>
#include <QDebug>
#include <QWebElement>

namespace ipn
{
        NanoQWebview::NanoQWebview(QWidget *parent) : QWebView(parent)
	{
                event_by_area = false;
	}


        void NanoQWebview::mousePressEvent(QMouseEvent *event) {
            if(event->button != Qt::MidButton) {
                event->ignore();
                return;
            }
        }

        void NanoQWebview::mouseMoveEvent(QMouseEvent *event) {
            if(event->button != Qt::MidButton) {
                event->ignore();
                return;
            }
        }

        void NanoQWebview::mouseReleaseEvent(QMouseEvent *event) {
            if(event->button != Qt::MidButton) {
                event->ignore();
                return;
            }

            if(event->pos() != QPoint(-1,-1)){
                emit mouseClick(event);
            }
        }

} // namespace ipn
