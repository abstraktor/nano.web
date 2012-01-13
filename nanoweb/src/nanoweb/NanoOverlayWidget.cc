#include "NanoOverlayWidget.h"
#include "OverlayWidget.h"

namespace ipn
{

    NanoOverlayWidget::NanoOverlayWidget(QWidget *parent) : OverlayWidget(parent)
    {
        connect(this, SIGNAL(mousePressed(QMouseEvent*)), parent, SLOT(handleMousePress(QMouseEvent*)));
        connect(this, SIGNAL(mouseReleased(QMouseEvent*)), parent, SLOT(handleMouseRelease(QMouseEvent*)));
        connect(this, SIGNAL(mouseMoved(QMouseEvent*)), parent, SLOT(handleMouseMove(QMouseEvent*)));
        connect(this, SIGNAL(mouseHovered(QMouseEvent*)), parent, SLOT(handleMouseHover(QMouseEvent*)));
        connect(this, SIGNAL(gestureTriggered(GestureType,qreal)), parent, SLOT(handleGesture(GestureType,qreal)));
    }

}
