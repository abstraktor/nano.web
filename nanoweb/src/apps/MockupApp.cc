#include "MockupApp.h"
#include "widgets/ImageWidget.h"
#include "widgets/FlickArea.h"

namespace ipn {
    MockupApp::MockupApp(QWidget *parent) : App(parent)
    {
        m_flickArea = new FlickArea(this);
        m_flickArea->resize(240, 240);

        m_image = new ImageWidget(m_flickArea);
        m_image->resize(240,240);
        m_image->setImage(":/img/mockup-app/storysample_start.png");

    }
}

