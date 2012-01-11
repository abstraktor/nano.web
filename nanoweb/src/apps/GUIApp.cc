#include "GUIApp.h"
#include "widgets/BackgroundWidget.h"
#include "widgets/SwitchButtonWidget.h"
#include "widgets/TitleBarWidget.h"
#include "widgets/SliderWidget.h"
#include "widgets/TextWidget.h"
#include "widgets/FlickArea.h"
#include "widgets/PageIndicatorWidget.h"

namespace ipn
{

	GUIApp::GUIApp(QWidget *parent) : App(parent)
	{
		m_back = new BackgroundWidget(this);
		m_back->setColor(BackgroundWidget::BG_GRAY);
		m_back->move(0, 0);

		m_titleBar = new TitleBarWidget(this);
		m_titleBar->setTitle("Simple GUI");
		m_titleBar->move(0, 0);
		m_titleBar->addButton(TitleBarWidget::BUTTON_BACK);

		m_switchButton = new SwitchButtonWidget(this);
		m_switchButton->move(48, 56);
		m_switchButton->setTitle("a switch button");

		m_slider = new SliderWidget(this);
		m_slider->setWidth(160);
		m_slider->move(16, 128);
		m_slider->setTitle("a slider");

		m_flickArea = new FlickArea(this);
		m_flickArea->move(0, 176);
		m_flickArea->resize(240, 64);

		m_scrollText = new TextWidget(m_flickArea);
		m_scrollText->setText("Scroll me! Lorem ipsum dolor sit amet adscipsing consectetur ...");
		m_scrollText->move(128, 0);
		m_scrollText->resize(768, 64);
		m_scrollText->setColor(Qt::white);
		m_scrollText->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

		m_pageIndicator = new PageIndicatorWidget(this);
		m_pageIndicator->setNumberOfSegments(6);
		m_pageIndicator->move(120 - m_pageIndicator->width() / 2, 224);

		connect(m_flickArea, SIGNAL(moved()), this, SLOT(updatePageIndicator()));
	}

	TitleBarWidget *GUIApp::titleBar()
	{
		return m_titleBar;
	}

	void GUIApp::updatePageIndicator()
	{
		m_pageIndicator->setPosition(m_flickArea->relativeScrollPosition().x());
	}

} // namespace ipn
