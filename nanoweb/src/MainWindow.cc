#include "MainWindow.h"
#include "IPodFrameWidget.h"
#include "apps/MenuApp.h"
#include "apps/InfoApp.h"
#include "apps/ClockApp.h"
#include "apps/PaintApp.h"
#include "apps/MusicApp.h"
#include "apps/GUIApp.h"
#include "apps/MapApp.h"
#include "apps/GestureApp.h"
#include "apps/MarkingMenuApp.h"
#include "apps/MultiTapApp.h"
#include "apps/PickerApp.h"
#include "apps/PeepholeApp.h"
#include "apps/WebviewApp.h"
#include "apps/ElementTappedApp.h"
#include "widgets/TitleBarWidget.h"
#include "widgets/ScalableButtonWidget.h"
#include "widgets/ImageWidget.h"
#include "helpers.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QResizeEvent>

namespace ipn
{
	const QPoint MainWindow::kSingleTouchOffset = QPoint(48, 43);

	MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
	{
		m_frameWidget = new ipn::IPodFrameWidget(new QWidget);
		setCentralWidget(m_frameWidget);


		// Create apps:
		m_menuApp = new MenuApp();
		m_menuApp->titleBar()->addButton(TitleBarWidget::BUTTON_QUIT);
		m_menuApp->addButton(MenuApp::TopLeft, "meilenwerk", ":/img/icons/icon.png");
                m_menuApp->addButton(MenuApp::TopRight, "element", ":/img/icons/icon.png");
		m_menuApp->addButton(MenuApp::BottomLeft, "--", ":/img/icons/icon.png");
		m_menuApp->addButton(MenuApp::BottomRight, "--", ":/img/icons/icon.png");
		m_menuApp->titleBar()->setTitle("NANOWEB");

		m_webviewApp = new WebviewApp();
                m_elementTappedApp = new ElementTappedApp();
		//m_infoApp->setMessage("You are now seeing a webpage.");


		// Set MenuApp as first app:
		m_frameWidget->instantReplaceAllAppsBy(m_menuApp);

		// Set up OverlayWidget:
		m_overlayWidget = new OverlayWidget(this);
		m_overlayWidget->resize(240, 240);
		m_overlayWidget->move(m_frameWidget->pos() + m_frameWidget->contentRect().topLeft());
		m_currentChild = NULL;

		connect(m_overlayWidget, SIGNAL(mousePressed(QMouseEvent*)), this, SLOT(handleMousePress(QMouseEvent*)));
		connect(m_overlayWidget, SIGNAL(mouseReleased(QMouseEvent*)), this, SLOT(handleMouseRelease(QMouseEvent*)));
		connect(m_overlayWidget, SIGNAL(mouseMoved(QMouseEvent*)), this, SLOT(handleMouseMove(QMouseEvent*)));
		connect(m_overlayWidget, SIGNAL(mouseHovered(QMouseEvent*)), this, SLOT(handleMouseHover(QMouseEvent*)));
		connect(m_overlayWidget, SIGNAL(gestureTriggered(GestureType,qreal)), this, SLOT(handleGesture(GestureType,qreal)));
                connect(m_frameWidget, SIGNAL(gestureTriggered(GestureType,qreal)), this, SLOT(handleGesture(GestureType,qreal)));

		// Forward event notifications from the frame widget:
		connect(m_frameWidget, SIGNAL(frameMoved()), this, SLOT(moveOverlay()));



                // display webpage on topleftbutton-click
                connect(m_menuApp, SIGNAL(topLeftButtonClicked()), this, SLOT(switchToWebPage()));
                connect(m_menuApp, SIGNAL(topRightButtonClicked()), this, SLOT(switchToElementTapped()));
		// go back from webpage to main menu
		//connect(m_webviewApp, SIGNAL(okButtonClicked()), m_frameWidget, SLOT(popApp()));
		// quit button
		connect(m_menuApp->titleBar(), SIGNAL(rightButtonClicked()), this, SLOT(close()));
		connect(m_webviewApp, SIGNAL(quitButtonClicked()), m_frameWidget, SLOT(popApp()));


		// Initialize finger:
		m_fingerImage = new ImageWidget(this);
		m_fingerImage->setImage(":/img/fingers/index_finger.png");

	#ifdef Q_OS_SYMBIAN
		// Do not display the finger on nokia phones:
		m_fingerImage->hide();
	#endif

		setMouseTracking(true);
	}

	void MainWindow::resizeEvent(QResizeEvent *event)
	{
		int centerX = event->size().width() / 2 - m_frameWidget->width() / 2;
		int centerY = event->size().height() / 2 - (m_frameWidget->height() + m_frameWidget->paddingTop()) / 2;

		m_frameWidget->move(centerX, centerY);
		m_overlayWidget->move(m_frameWidget->pos() + m_frameWidget->contentRect().topLeft());
	}

    // For each app, we need a slot which pushes it on the app stack:
    void MainWindow::switchToWebPage()              {m_frameWidget->pushApp(m_webviewApp);}
    void MainWindow::switchToElementTapped()        {m_frameWidget->pushApp(m_elementTappedApp);}

	void MainWindow::handleMousePress(QMouseEvent *event)
	{
	#ifndef Q_OS_SYMBIAN
		// Generate noise if compiled for the desktop:
		m_currentOffset.setX(helpers::limitedRand(m_noiseRadius * 2) - m_noiseRadius);
		m_currentOffset.setY(helpers::limitedRand(m_noiseRadius * 2) - m_noiseRadius);

		// Make sure the offset does not move the cursor outside the screen:
		QPoint targetPoint = event->pos() + m_currentOffset;

		if (targetPoint.x() < 0)
			m_currentOffset.rx() -= targetPoint.x();

		if (targetPoint.y() < 0)
			m_currentOffset.ry() -= targetPoint.y();

		if (targetPoint.x() >= 240)
			m_currentOffset.rx() -= targetPoint.x() - 239;

		if (targetPoint.y() >= 240)
			m_currentOffset.ry() -= targetPoint.y() - 239;
	#endif // Q_OS_SYMBIAN

		// Determine the target widget which receives the event:
		QPoint childPosition = m_frameWidget->mapFromGlobal(QCursor::pos() + m_currentOffset);
		m_currentChild = m_frameWidget->childAt(childPosition);
		m_isMouseDown = true;

		forwardMouseEvent(event);
	}

	void MainWindow::handleMouseRelease(QMouseEvent *event)
	{
		m_isMouseDown = false;

		forwardMouseEvent(event);
	}

	void MainWindow::handleMouseMove(QMouseEvent *event)
	{
		QRect screen = QRect(0, 0, 240, 240);

		// Drop the mouse event if it is outside the screen:
		if (!screen.contains(event->pos() + m_currentOffset))
		{
			event->accept();
			return;
		}

		forwardMouseEvent(event);
	}

	void MainWindow::handleMouseHover(QMouseEvent *event)
	{
		moveHandOverlay(event->pos() + m_frameWidget->pos() + m_frameWidget->contentRect().topLeft());
	}

	void MainWindow::forwardMouseEvent(QMouseEvent *event)
	{
		if (!m_currentChild)
			return;

		QMouseEvent childEvent(event->type(),
							   m_currentChild->mapFromGlobal(QCursor::pos() + m_currentOffset),
							   event->button(),
							   event->buttons(),
							   event->modifiers());

		QApplication::sendEvent(m_currentChild, &childEvent);
	}

	void MainWindow::moveOverlay()
	{
		m_overlayWidget->move(m_frameWidget->pos() + m_frameWidget->contentRect().topLeft());
	}

	void MainWindow::handleGesture(GestureType type, qreal param)
	{
		if (m_frameWidget->topApp())
			m_frameWidget->topApp()->handleGesture(type, param);
	}

	void MainWindow::switchToApp(App *app)
	{
		m_frameWidget->pushApp(app);
	}

	void MainWindow::mouseMoveEvent(QMouseEvent *event)
	{
		if (m_isMouseDown)
			moveHandOverlay(event->pos() - m_currentOffset);
		else
			moveHandOverlay(event->pos());

		event->ignore();
	}

	void MainWindow::moveHandOverlay(QPoint pos)
	{
	#ifndef Q_OS_SYMBIAN
		const int kBorderWidth = 40;
		// A different width for the top because of the window title bar
		const int kTopBorderWidth = 20;

		const QRect cursorInvisibleRect(kBorderWidth,
										kTopBorderWidth,
										width() - (kBorderWidth * 2),
										height() - (kBorderWidth + kTopBorderWidth));

		if (cursorInvisibleRect.contains(pos))
			setCursor(QCursor(Qt::BlankCursor));
		else
			setCursor(QCursor(Qt::ArrowCursor));

		m_fingerImage->move(pos - kSingleTouchOffset);
	#endif // Q_OS_SYMBIAN
	}

	void MainWindow::setOrientation(ScreenOrientation orientation)
	{
	#if defined(Q_OS_SYMBIAN)
		// If the version of Qt on the device is < 4.7.2, that attribute won't work
		if (orientation != ScreenOrientationAuto)
		{
			const QStringList v = QString::fromAscii(qVersion()).split(QLatin1Char('.'));

			if (v.count() == 3 && (v.at(0).toInt() << 16 | v.at(1).toInt() << 8 | v.at(2).toInt()) < 0x040702)
			{
				qWarning("Screen orientation locking only supported with Qt 4.7.2 and above");
				return;
			}
		}
	#endif // Q_OS_SYMBIAN

		Qt::WidgetAttribute attribute;

		switch (orientation)
		{
	#if QT_VERSION < 0x040702
		// Qt < 4.7.2 does not yet have the Qt::WA_*Orientation attributes
		case ScreenOrientationLockPortrait:
			attribute = static_cast<Qt::WidgetAttribute>(128);
			break;
		case ScreenOrientationLockLandscape:
			attribute = static_cast<Qt::WidgetAttribute>(129);
			break;
		default:
		case ScreenOrientationAuto:
			attribute = static_cast<Qt::WidgetAttribute>(130);
			break;
	#else // QT_VERSION < 0x040702
		case ScreenOrientationLockPortrait:
			attribute = Qt::WA_LockPortraitOrientation;
			break;
		case ScreenOrientationLockLandscape:
			attribute = Qt::WA_LockLandscapeOrientation;
			break;
		default:
		case ScreenOrientationAuto:
			attribute = Qt::WA_AutoOrientation;
			break;
	#endif // QT_VERSION < 0x040702
		};

		setAttribute(attribute, true);
	}

	void MainWindow::showExpanded()
	{
	#ifdef Q_OS_SYMBIAN
		showFullScreen();
	#elif defined(Q_WS_MAEMO_5) || defined(Q_WS_MAEMO_6)
		showMaximized();
	#else
		show();
	#endif
	}

} // namespace ipn
