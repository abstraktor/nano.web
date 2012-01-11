#include "MenuApp.h"
#include "widgets/BackgroundWidget.h"
#include "widgets/TitleBarWidget.h"
#include "widgets/ScalableButtonWidget.h"

namespace ipn
{

	MenuApp::MenuApp(QWidget *parent) : App(parent)
	{
		m_back = new BackgroundWidget(this);
		m_back->setColor(BackgroundWidget::BG_GRAY);
		m_back->move(0, 0);

		m_titleBar = new TitleBarWidget(this);
		m_titleBar->move(0, 0);

		for (int i = 0; i < 4; i++)
		{
			m_buttons[i] = new ScalableButtonWidget(this);
			m_buttons[i]->hide();
		}

		connect(m_buttons[0], SIGNAL(clicked()), this, SIGNAL(topLeftButtonClicked()));
		connect(m_buttons[1], SIGNAL(clicked()), this, SIGNAL(topRightButtonClicked()));
		connect(m_buttons[2], SIGNAL(clicked()), this, SIGNAL(bottomLeftButtonClicked()));
		connect(m_buttons[3], SIGNAL(clicked()), this, SIGNAL(bottomRightButtonClicked()));
	}

	ScalableButtonWidget *MenuApp::button(ButtonPosition position)
	{
		return m_buttons[position];
	}

	void MenuApp::addButton(ButtonPosition position, QString title, QString iconImage)
	{
		m_buttons[position]->show();
		m_buttons[position]->setImage(":/img/buttons/default");
		m_buttons[position]->resize(64, 64);
		m_buttons[position]->setTitle(title);
		m_buttons[position]->setIconImage(iconImage);

		switch (position)
		{
			case TopLeft:
				m_buttons[position]->move(36, 56);
				break;
			case TopRight:
				m_buttons[position]->move(138, 56);
				break;
			case BottomLeft:
				m_buttons[position]->move(36, 148);
				break;
			case BottomRight:
				m_buttons[position]->move(138, 148);
				break;
		}
	}

	TitleBarWidget *MenuApp::titleBar()
	{
		return m_titleBar;
	}

} // namespace ipn
