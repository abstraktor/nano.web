#ifndef MOCKUPAPP_H
#define MOCKUPAPP_H

#include "App.h"
#include "ImageWidget.h"
#include "FlickArea.h"
namespace ipn {
class MockupApp : public App
{
    Q_OBJECT
    public:
    explicit MockupApp(QWidget *parent = 0);

    signals:

    public slots:

    private:
        ImageWidget *m_image;
        FlickArea *m_flickArea;
};
} // end namespace ipn
#endif // MOCKUPAPP_H
