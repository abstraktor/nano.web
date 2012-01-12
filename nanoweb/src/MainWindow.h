// checksum 0x9a77 version 0x30001
/*
  This file was generated by the Mobile Qt Application wizard of Qt Creator.
  MainWindow is a convenience class containing mobile device specific code
  such as screen orientation handling.
  It is recommended not to modify this file, since newer versions of Qt Creator
  may offer an updated version of it.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "widgets/OverlayWidget.h"

#include <QtGui/QMainWindow>
#include <QWebElement>

class QMouseEvent;
class QResizeEvent;

namespace ipn
{

class IPodFrameWidget;

class App;
class MenuApp;
class InfoApp;
class ClockApp;
class PaintApp;
class MusicApp;
class GUIApp;
class MapApp;
class GestureApp;
class MarkingMenuApp;
class MultiTapApp;
class PickerApp;
class PeepholeApp;
class WebviewApp;
class ElementTappedApp;
class ElementFisheyeApp;
class ChooseTool1App;
class ChooseToolBoxmodelApp;
class BorderEditApp;
class BorderStyleApp;
class BorderWidthApp;
class MockUpApp;

class OverlayWidget;
class TitleBarWidget;
class ScalableButtonWidget;
class ImageWidget;

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        enum ScreenOrientation
        {
            ScreenOrientationLockPortrait,
            ScreenOrientationLockLandscape,
            ScreenOrientationAuto
        };

        explicit MainWindow(QWidget *parent = 0);

        virtual void resizeEvent(QResizeEvent *event);
		virtual void moveEvent(QMoveEvent *event);

        void setOrientation(ScreenOrientation orientation);
        void showExpanded();

    signals:

    protected:
        virtual void mouseMoveEvent(QMouseEvent *event);

    public slots:
        void popApp();

    private slots:
        void moveOverlay();

        // For emulating touch noise:
        void handleMousePress(QMouseEvent *event);
        void handleMouseRelease(QMouseEvent *event);
        void handleMouseMove(QMouseEvent *event);
        void handleMouseHover(QMouseEvent *event);
        void forwardMouseEvent(QMouseEvent *event);

        // Handle gestures triggered by m_overlayWidget:
        void handleGesture(GestureType type, qreal param);

        // Slots for connecting apps:
		void switchToWebPage();
                void switchToMockUp();
		void switchToElementTapped();
		void switchToElementTapped(QWebElement el);
		void switchToElementFisheye();
		void switchToElementFisheye(QWebElement el);
		void switchToInfo();
		void switchToChooseTool1App();
		void switchToChooseToolBoxmodelApp();
		void switchToBorderApp();
		void switchToSpecificBorderApp(QString cssproperty);
		void elementTappedLeftButtonClicked();
		void elementTappedInFisheye();

        void switchToApp(App *app);

    private:
        void moveHandOverlay(QPoint pos);

        IPodFrameWidget *m_frameWidget;

        // Apps
        MenuApp *m_menuApp, *m_displayMenuApp, *m_interactiveMenuApp, *m_inputMenuApp, *m_choiceMenuApp;
        WebviewApp *m_webviewApp;
        ElementTappedApp *m_elementTappedApp;
		ElementFisheyeApp *m_elementFisheyeApp;
		InfoApp *m_infoApp;
		ChooseTool1App *m_chooseTool1App;
		ChooseToolBoxmodelApp *m_chooseToolBoxmodelApp;
		BorderEditApp *m_borderEditApp;
		BorderStyleApp *m_borderStyleApp;
		BorderWidthApp *m_borderWidthApp;
        MockUpApp *m_mockUpApp;

        // For emulating touch noise:
        OverlayWidget *m_overlayWidget;
        QPoint m_currentOffset;
        QWidget *m_currentChild;
        static const int m_noiseRadius = 20;

        // Finger:
        ImageWidget *m_fingerImage;
        static const QPoint kSingleTouchOffset;
        bool m_isMouseDown;
};

} // namespace ipn

#endif // MAINWINDOW_H
