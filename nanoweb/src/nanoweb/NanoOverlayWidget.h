#ifndef NANOOVERLAYWIDGET_H
#define NANOOVERLAYWIDGET_H

#include "widgets/OverlayWidget.h"

#include <QWidget>

namespace ipn
{

    class NanoOverlayWidget : public OverlayWidget
    {
        Q_OBJECT
    public:
        explicit NanoOverlayWidget(QWidget *parent = 0);

    signals:

    public slots:

    };

} // end namespace ipn
#endif // NANOOVERLAYWIDGET_H
