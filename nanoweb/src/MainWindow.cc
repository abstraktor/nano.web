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
		m_menuApp->addButton(MenuApp::TopLeft, "display", ":/img/icons/icon.png");
		m_menuApp->addButton(MenuApp::TopRight, "input", ":/img/icons/icon.png");
		m_menuApp->addButton(MenuApp::BottomLeft, "choice", ":/img/icons/icon.png");
		m_menuApp->addButton(MenuApp::BottomRight, "interactive", ":/img/icons/icon.png");
		m_menuApp->titleBar()->setTitle("choose\na category");

		m_displayMenuApp = new MenuApp();
		m_displayMenuApp->titleBar()->addButton(TitleBarWidget::BUTTON_BACK);
		m_displayMenuApp->addButton(MenuApp::TopLeft, "Infos", ":/img/icons/icon.png");
		m_displayMenuApp->addButton(MenuApp::TopRight, "Clock", ":/img/icons/icon.png");
		m_displayMenuApp->addButton(MenuApp::BottomLeft, "Music", ":/img/icons/icon.png");
		m_displayMenuApp->titleBar()->setTitle("display apps");

		m_interactiveMenuApp = new MenuApp();
		m_interactiveMenuApp->titleBar()->addButton(TitleBarWidget::BUTTON_BACK);
		m_interactiveMenuApp->addButton(MenuApp::TopLeft, "Paint", ":/img/icons/icon.png");
		m_interactiveMenuApp->addButton(MenuApp::TopRight, "Map", ":/img/icons/icon.png");
		m_interactiveMenuApp->addButton(MenuApp::BottomLeft, "Peephole", ":/img/icons/icon.png");
		m_interactiveMenuApp->titleBar()->setTitle("interactive apps");

		m_inputMenuApp = new MenuApp();
		m_inputMenuApp->titleBar()->addButton(TitleBarWidget::BUTTON_BACK);
		m_inputMenuApp->addButton(MenuApp::TopLeft, "disabled", ":/img/icons/icon.png");
		m_inputMenuApp->button(MenuApp::TopLeft)->setEnabled(false);
		m_inputMenuApp->addButton(MenuApp::TopRight, "Gestures", ":/img/icons/icon.png");
		m_inputMenuApp->addButton(MenuApp::BottomLeft, "MultiTap", ":/img/icons/icon.png");
		m_inputMenuApp->titleBar()->setTitle("input apps");

		m_choiceMenuApp = new MenuApp();
		m_choiceMenuApp->titleBar()->addButton(TitleBarWidget::BUTTON_BACK);
		m_choiceMenuApp->addButton(MenuApp::TopLeft, "Simple GUI", ":/img/icons/icon.png");
		m_choiceMenuApp->addButton(MenuApp::TopRight, "Marking M.", ":/img/icons/icon.png");
		m_choiceMenuApp->addButton(MenuApp::BottomLeft, "Picker", ":/img/icons/icon.png");
		m_choiceMenuApp->titleBar()->setTitle("choice apps");

		m_infoApp = new InfoApp();
		m_infoApp->setMessage("This is an\nInfoApp which\ncan display some text.");
		m_clockApp = new ClockApp();
		m_paintApp = new PaintApp();
		m_musicApp = new MusicApp();
		m_guiApp = new GUIApp();
		m_mapApp = new MapApp();
		m_peepholeApp = new PeepholeApp();
		connect(m_frameWidget, SIGNAL(frameMoved(const QPoint)), m_peepholeApp, SLOT(moveContents(const QPoint)));
		m_gestureApp = new GestureApp();
		m_markingMenuApp = new MarkingMenuApp();
		m_multiTapApp = new MultiTapApp();
		m_pickerApp = new PickerApp();

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

		// Wire up menus <-> menus:
		connect(m_menuApp, SIGNAL(topLeftButtonClicked()), this, SLOT(switchToDisplayMenuApp()));
		connect(m_menuApp, SIGNAL(topRightButtonClicked()), this, SLOT(switchToInputMenuApp()));
		connect(m_menuApp, SIGNAL(bottomLeftButtonClicked()), this, SLOT(switchToChoiceMenuApp()));
		connect(m_menuApp, SIGNAL(bottomRightButtonClicked()), this, SLOT(switchToInteractiveMenuApp()));
		connect(m_menuApp->titleBar(), SIGNAL(rightButtonClicked()), this, SLOT(close()));
		connect(m_displayMenuApp->titleBar(), SIGNAL(leftButtonClicked()), m_frameWidget, SLOT(popApp()));
		connect(m_inputMenuApp->titleBar(), SIGNAL(leftButtonClicked()), m_frameWidget, SLOT(popApp()));
		connect(m_choiceMenuApp->titleBar(), SIGNAL(leftButtonClicked()), m_frameWidget, SLOT(popApp()));
		connect(m_interactiveMenuApp->titleBar(), SIGNAL(leftButtonClicked()), m_frameWidget, SLOT(popApp()));
		connect(m_displayMenuApp, SIGNAL(swipeRightTriggered()), m_frameWidget, SLOT(popApp()));
		connect(m_inputMenuApp, SIGNAL(swipeRightTriggered()), m_frameWidget, SLOT(popApp()));
		connect(m_choiceMenuApp, SIGNAL(swipeRightTriggered()), m_frameWidget, SLOT(popApp()));
		connect(m_interactiveMenuApp, SIGNAL(swipeRightTriggered()), m_frameWidget, SLOT(popApp()));

		// Wire up menus -> apps:
		connect(m_displayMenuApp, SIGNAL(topLeftButtonClicked()), this, SLOT(switchToInfoApp()));
		connect(m_displayMenuApp, SIGNAL(topRightButtonClicked()), this, SLOT(switchToClockApp()));
		connect(m_displayMenuApp, SIGNAL(bottomLeftButtonClicked()), this, SLOT(switchToMusicApp()));
		connect(m_inputMenuApp, SIGNAL(topRightButtonClicked()), this, SLOT(switchToGestureApp()));
		connect(m_inputMenuApp, SIGNAL(bottomLeftButtonClicked()), this, SLOT(switchToMultiTapApp()));
		connect(m_interactiveMenuApp, SIGNAL(topLeftButtonClicked()), this, SLOT(switchToPaintApp()));
		connect(m_interactiveMenuApp, SIGNAL(topRightButtonClicked()), this, SLOT(switchToMapApp()));
		connect(m_interactiveMenuApp, SIGNAL(bottomLeftButtonClicked()), this, SLOT(switchToPeepholeApp()));
		connect(m_choiceMenuApp, SIGNAL(topLeftButtonClicked()), this, SLOT(switchToGUIApp()));
		connect(m_choiceMenuApp, SIGNAL(topRightButtonClicked()), this, SLOT(switchToMarkingMenuApp()));
		connect(m_choiceMenuApp, SIGNAL(bottomLeftButtonClicked()), this, SLOT(switchToPickerApp()));

		// Wire up menus <- apps:
		connect(m_infoApp, SIGNAL(okButtonClicked()), m_frameWidget, SLOT(popApp()));
		connect(m_infoApp, SIGNAL(swipeRightTriggered()), m_frameWidget, SLOT(popApp()));
		connect(m_clockApp, SIGNAL(okButtonClicked()), m_frameWidget, SLOT(popApp()));
		connect(m_guiApp->titleBar(), SIGNAL(leftButtonClicked()), m_frameWidget, SLOT(popApp()));
		connect(m_markingMenuApp, SIGNAL(quitButtonClicked()), m_frameWidget, SLOT(popApp()));
		connect(m_mapApp->titleBar(), SIGNAL(leftButtonClicked()), m_frameWidget, SLOT(popApp()));
		connect(m_peepholeApp, SIGNAL(swipeRightTriggered()), m_frameWidget, SLOT(popApp()));
		connect(m_gestureApp, SIGNAL(quitButtonClicked()), m_frameWidget, SLOT(popApp()));
		connect(m_paintApp, SIGNAL(swipeRightTriggered()), m_frameWidget, SLOT(popApp()));
		connect(m_musicApp, SIGNAL(swipeRightTriggered()), m_frameWidget, SLOT(popApp()));
		connect(m_pickerApp->titleBar(), SIGNAL(rightButtonClicked()), m_frameWidget, SLOT(popApp()));
		connect(m_multiTapApp, SIGNAL(accepted()), m_frameWidget, SLOT(popApp()));

		// Forward event notifications from the frame widget:
		connect(m_frameWidget, SIGNAL(frameMoved()), this, SLOT(moveOverlay()));

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
	void MainWindow::switchToDisplayMenuApp()		{m_frameWidget->pushApp(m_displayMenuApp);}
	void MainWindow::switchToInteractiveMenuApp()	{m_frameWidget->pushApp(m_interactiveMenuApp);}
	void MainWindow::switchToInputMenuApp()			{m_frameWidget->pushApp(m_inputMenuApp);}
	void MainWindow::switchToChoiceMenuApp()		{m_frameWidget->pushApp(m_choiceMenuApp);}
	void MainWindow::switchToInfoApp()				{m_frameWidget->pushApp(m_infoApp);}
	void MainWindow::switchToClockApp()				{m_frameWidget->pushApp(m_clockApp);}
	void MainWindow::switchToPaintApp()				{m_frameWidget->pushApp(m_paintApp);}
	void MainWindow::switchToMusicApp()				{m_frameWidget->pushApp(m_musicApp);}
	void MainWindow::switchToGUIApp()				{m_frameWidget->pushApp(m_guiApp);}
	void MainWindow::switchToMapApp()				{m_frameWidget->pushApp(m_mapApp);}
	void MainWindow::switchToPeepholeApp()			{m_frameWidget->pushApp(m_peepholeApp);}
	void MainWindow::switchToGestureApp()			{m_frameWidget->pushApp(m_gestureApp);}
	void MainWindow::switchToMarkingMenuApp()		{m_frameWidget->pushApp(m_markingMenuApp);}
	void MainWindow::switchToMultiTapApp()			{m_frameWidget->pushApp(m_multiTapApp);}
	void MainWindow::switchToPickerApp()			{m_frameWidget->pushApp(m_pickerApp);}

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
