#ifndef MOCKUPAPP_H
#define MOCKUPAPP_H

#include "App.h"
#include "widgets/FlickArea.h"
#include "widgets/ImageWidget.h"

namespace ipn
{

        class FlickArea;
        class MockUpApp : public App
        {
                Q_OBJECT

                public:
                        MockUpApp(QWidget * parent = 0);

                signals:

                protected:

                private:
                        FlickArea *m_flickArea;
                        ImageWidget *m_image;
        };


}
#endif // MOCKUPAPP_H
