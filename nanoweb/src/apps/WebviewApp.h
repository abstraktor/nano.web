#ifndef IPN_WEBVIEWAPP_H
#define IPN_WEBVIEWAPP_H

#include "App.h"
#include <QtWebKit>
#include <QWebView>
#include "widgets/FlickArea.h"
#include "nanoweb/NanoQWebview.h"

namespace ipn
{
class BackgroundWidget;
class TitleBarWidget;
class TextWidget;
class ScalableButtonWidget;
class NanoQWebView;
class TextWidget;

class WebviewApp : public App
{
    Q_OBJECT

public:
    WebviewApp(QWidget *parent = 0, bool displayWidget = false);
    NanoQWebview *m_webView;

    inline bool isOpaque() {return false;}
    QPoint getScrollPosition();
    void updateView();

public slots:
    void changePinchScaleFactor(qreal delta);
    void pinchIn();
    void pinchOut();
    void swipeLeft();
    void swipeUp();
    void swipeRight();
    void swipeDown();
    void swipe(qreal angle);
    void sendUpdatedInfo();
    void elementTappedHandler(QMouseEvent *event);

signals:
    void quitButtonClicked();
    void elementTapped(QWebElement el);
    void zoomTriggered();
    void setScrollPosition(QPoint newP);
    QPoint getContentScrollPosition();
    void setContentZoomFactor(double z);
    double getContentZoomFactor();


protected slots:
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    QVector<QPolygon> m_drawing;
    FlickArea *m_flickArea;
    TextWidget *m_text;

    bool iAmBackButtonWebView;
	BackgroundWidget *m_back;

	qreal m_currentScaleFactor;
};

} // namespace ipn

#endif /* end of include guard: IPN_WEBVIEWAPP_H */
