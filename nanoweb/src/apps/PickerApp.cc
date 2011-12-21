#include "PickerApp.h"
#include "widgets/BackgroundWidget.h"
#include "widgets/TitleBarWidget.h"
#include "widgets/PickerWidget.h"
#include "widgets/FlickArea.h"

namespace ipn
{

	PickerApp::PickerApp(QWidget *pParent) : App(pParent)
	{
		m_back = new BackgroundWidget(this);
		m_back->setColor(BackgroundWidget::BG_GRAY);
		m_back->move(0, 0);

		m_titleBar = new TitleBarWidget(this);
		m_titleBar->setTitle("connection");
		m_titleBar->move(0, 0);
		m_titleBar->addButton(TitleBarWidget::BUTTON_CLOSE);

		m_flickArea = new FlickArea(this);
		m_flickArea->resize(240, 192);
		m_flickArea->move(0, 48);

		m_picker = new PickerWidget(m_flickArea);
		m_picker->addEntry("Local Area Network");
		m_picker->addEntry("Wireless LAN");
		m_picker->addEntry("Bluetooth");
		m_picker->addEntry("Infrared");
		m_picker->addEntry("USB");
		m_picker->addEntry("Firewire");
		m_picker->addEntry("None");
		m_picker->setActiveEntry(2);
		m_picker->move(0, 0);
	}

	TitleBarWidget *PickerApp::titleBar()
	{
		return m_titleBar;
	}

} // namespace ipn
