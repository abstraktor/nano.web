#include "MapApp.h"
#include "widgets/TitleBarWidget.h"
#include "widgets/FlickArea.h"
#include "widgets/ImageWidget.h"

namespace ipn
{

	MapApp::MapApp(QWidget *parent) : App(parent)
	{
		m_titleBar = new TitleBarWidget(this);
		m_titleBar->setTitle("MapApp");
		m_titleBar->move(0, 0);
		m_titleBar->addButton(TitleBarWidget::BUTTON_BACK);

		m_flickArea = new FlickArea(this);
		m_flickArea->resize(240, 192);
		m_flickArea->move(0, 48);

		m_image = new ImageWidget(m_flickArea);
		m_image->setImage(":/img/backgrounds/map.png");
	}

	TitleBarWidget *MapApp::titleBar()
	{
		return m_titleBar;
	}

} // namespace ipn
