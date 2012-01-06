#ifndef IPN_ELEMENTTAPPEDAPP_H
#define IPN_ELEMENTTAPPEDAPP_H

#include "App.h"

namespace ipn
{
class BackgroundWidget;
class TitleBarWidget;
class TextWidget;
class ScalableButtonWidget;

class ElementTappedApp : public App
{
        Q_OBJECT

    public:
        ElementTappedApp(QWidget *parent = 0);

        inline bool isOpaque() {return true;}
        void setMessage(QString message);

    public slots:
        void pinchIn();
        void pinchOut();
        void swipeLeft();
        void swipeUp();
        void swipeRight();
        void swipeDown();
        void swipe(qreal angle);


    signals:
        void quitButtonClicked();


    private:

        BackgroundWidget *m_elementBackground;
        BackgroundWidget *m_buttonBackground;

		TextWidget *m_elementText, *m_elementContentText, *m_explainText;
        ScalableButtonWidget *m_browseElementButton, *m_followLinkButton;
};

} // namespace ipn

#endif /* end of include guard: IPN_ELEMENTTAPPEDAPP_H */
