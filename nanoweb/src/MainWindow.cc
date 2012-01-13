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
#include "apps/ElementFisheyeApp.h"
#include "apps/ChooseTool1App.h"
#include "apps/ChooseToolBoxmodelApp.h"
#include "apps/BorderEditApp.h"
#include "apps/BorderWidthApp.h"
#include "apps/BorderStyleApp.h"
#include "widgets/TitleBarWidget.h"
#include "widgets/ScalableButtonWidget.h"
#include "widgets/ImageWidget.h"
#include "helpers.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QDebug>

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
		m_menuApp->addButton(MenuApp::TopLeft, "website", ":/img/our_icons/website.png");
		m_menuApp->addButton(MenuApp::TopRight, "mockup", ":/img/our_icons/mockup.png");
		m_menuApp->addButton(MenuApp::BottomLeft, "--", ":/img/icons/default.png");
		m_menuApp->addButton(MenuApp::BottomRight, "--", ":/img/icons/default.png");
		m_menuApp->titleBar()->setTitle("NANOWEB");

		m_webviewApp = new WebviewApp();
		m_elementTappedApp = new ElementTappedApp();
		m_elementFisheyeApp = new ElementFisheyeApp();
		m_infoApp = new InfoApp();
		m_chooseTool1App = new ChooseTool1App();
		m_chooseToolBoxmodelApp = new ChooseToolBoxmodelApp();
		m_borderEditApp = new BorderEditApp();
		m_borderWidthApp = new BorderWidthApp();
		m_borderStyleApp = new BorderStyleApp();
		m_multiTapApp = new MultiTapApp();


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

		connect(m_webviewApp, SIGNAL(elementTapped(QWebElement)), this, SLOT(switchToElementTapped(QWebElement)));
		connect(m_elementTappedApp, SIGNAL(elementTapped(QWebElement)), this, SLOT(switchToElementFisheye(QWebElement)));
		connect(m_elementTappedApp, SIGNAL(leftButtonClicked()), this, SLOT(elementTappedLeftButtonClicked()));
		connect(m_elementTappedApp, SIGNAL(editButtonClicked()), this, SLOT(switchToChooseTool1App()));
		connect(m_elementFisheyeApp, SIGNAL(elementTapped(QWebElement)), m_frameWidget, SLOT(instantPopApp()));
		connect(m_elementFisheyeApp, SIGNAL(elementTapped(QWebElement)), m_elementTappedApp, SLOT(elementTappedInFisheye(QWebElement)));
		connect(m_elementFisheyeApp, SIGNAL(backButtonClickTriggered()), this, SLOT(elementTappedInFisheye()));
		connect(m_chooseTool1App, SIGNAL(boxmodelButtonClicked()), this, SLOT(switchToChooseToolBoxmodelApp()));
		connect(m_chooseTool1App, SIGNAL(anotherButtonClicked()), this, SLOT(switchToInfo()));
		connect(m_chooseToolBoxmodelApp, SIGNAL(borderButtonClicked()), this, SLOT(switchToBorderApp()));
		connect(m_borderEditApp, SIGNAL(borderEdit(QString)), this, SLOT(switchToSpecificBorderApp(QString)));
		connect(m_borderStyleApp, SIGNAL(valueChosen()), m_frameWidget, SLOT(popApp()));
		connect(m_borderWidthApp, SIGNAL(valueChosen()), m_frameWidget, SLOT(popApp()));
		connect(m_borderWidthApp, SIGNAL(requestNumber()), this, SLOT(switchToMultiTapApp()));
		connect(m_multiTapApp, SIGNAL(accepted(QString)), m_borderWidthApp, SLOT(numberClicked(QString)));
		connect(m_multiTapApp, SIGNAL(accepted(QString)), m_frameWidget, SLOT(popApp()));


		// Forward event notifications from the frame widget:
		connect(m_frameWidget, SIGNAL(frameMoved()), this, SLOT(moveOverlay()));



		connect(m_menuApp, SIGNAL(topLeftButtonClicked()), this, SLOT(switchToWebPage()));
		connect(m_menuApp, SIGNAL(topRightButtonClicked()), this, SLOT(switchToInfo()));
		connect(m_menuApp, SIGNAL(bottomLeftButtonClicked()), this, SLOT(switchToInfo()));
		connect(m_menuApp, SIGNAL(bottomRightButtonClicked()), this, SLOT(switchToInfo()));


		// quit button
		connect(m_menuApp->titleBar(), SIGNAL(rightButtonClicked()), this, SLOT(close()));
		//connect(m_webviewApp, SIGNAL(quitButtonClicked()), m_frameWidget, SLOT(popApp()));
		connect(m_infoApp, SIGNAL(okButtonClicked()), m_frameWidget, SLOT(popApp()));


		// Initialize finger:
		m_fingerImage = new ImageWidget(this);
		m_fingerImage->setImage(":/img/fingers/index_finger.png");

	#ifdef Q_OS_SYMBIAN
		// Do not display the finger on nokia phones:
		m_fingerImage->hide();
	#endif

		setMouseTracking(true);
	}


	void MainWindow::elementTappedInFisheye() {
		m_elementTappedApp->elementTappedInFisheye(m_elementFisheyeApp->getElement());
	}

	void MainWindow::resizeEvent(QResizeEvent *event)
	{
		int centerX = event->size().width() / 2 - m_frameWidget->width() / 2;
		int centerY = event->size().height() / 2 - (m_frameWidget->height() + m_frameWidget->paddingTop()) / 2;

		m_frameWidget->move(centerX, centerY);
		m_overlayWidget->move(m_frameWidget->pos() + m_frameWidget->contentRect().topLeft());
	}

	// For each app, we need a slot which pushes it on the app stack:
	void MainWindow::switchToWebPage()				{m_frameWidget->pushApp(m_webviewApp);}
	void MainWindow::switchToElementTapped()		{m_frameWidget->pushApp(m_elementTappedApp);}
	void MainWindow::switchToElementFisheye()		{m_frameWidget->pushApp(m_elementFisheyeApp);}
	void MainWindow::switchToInfo()					{m_frameWidget->pushApp(m_infoApp);}
	void MainWindow::switchToChooseTool1App() {
		m_chooseTool1App->setElement(m_elementTappedApp->getElement());
		m_frameWidget->pushApp(m_chooseTool1App);
	}
	void MainWindow::switchToChooseToolBoxmodelApp() {
		m_chooseToolBoxmodelApp->setElement(m_chooseTool1App->getElement());
		m_frameWidget->pushApp(m_chooseToolBoxmodelApp);
	}
	void MainWindow::switchToElementTapped(QWebElement el) {
		//m_elementTappedApp->setElement(el);  m_frameWidget->pushApp(m_elementTappedApp);
		m_borderEditApp->setElement(el);
		m_frameWidget->pushApp(m_borderEditApp);
	}
	void MainWindow::switchToElementFisheye(QWebElement el) {m_elementFisheyeApp->setElement(el);  m_frameWidget->instantPushApp(m_elementFisheyeApp);}
	void MainWindow::elementTappedLeftButtonClicked() {
		switchToInfo();
	}
	void MainWindow::switchToBorderApp() {
		m_borderEditApp->setElement(m_chooseToolBoxmodelApp->getElement());
		m_frameWidget->pushApp(m_borderEditApp);
	}
	void MainWindow::switchToSpecificBorderApp(QString property) {
		if (property.contains("width")) {
			m_borderWidthApp->cssproperty = property;
			m_borderWidthApp->setElement(m_borderEditApp->getElement());
			m_frameWidget->pushApp(m_borderWidthApp);
		}
		else if (property.contains("color")) {
			switchToInfo();
		}
		else if (property.contains("style")) {
			m_borderStyleApp->cssproperty = property;
			m_borderStyleApp->setElement(m_borderEditApp->getElement());
			m_frameWidget->pushApp(m_borderStyleApp);
		}
	}
	void MainWindow::switchToMultiTapApp() {
		m_frameWidget->pushApp(m_multiTapApp);
	}



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

	void MainWindow::moveEvent(QMoveEvent *event) {
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
