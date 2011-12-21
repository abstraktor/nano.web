#include "TitleBarButtonWidget.h"
#include "TextWidget.h"
#include "helpers.h"
#include <QPainter>

namespace ipn
{

	TitleBarButtonWidget::TitleBarButtonWidget(QWidget *parent) : ButtonWidget(parent)
	{
		m_text = new TextWidget(this);
		m_text->setAlignment(Qt::AlignCenter);
		m_text->setFontSize(12);
		m_text->setFontStyle(TextWidget::STYLE_BOLD);
		m_text->setColor(Qt::white);

		setButtonType(BUTTON_RECTANGULAR);
	}

	void TitleBarButtonWidget::setText(QString text)
	{
		m_text->setText(text);
	}

	void TitleBarButtonWidget::setButtonType(int buttonType)
	{
		m_buttonType = buttonType;

		switch (buttonType)
		{
			case BUTTON_RECTANGULAR:
				setInactiveImages(":/img/buttons/title_bar_button_default.png",
					":/img/buttons/title_bar_button_default_down.png");
				m_borderLeft = 8;
				m_borderRight = 8;
				break;
			case BUTTON_LEFT:
				setInactiveImages(":/img/buttons/title_bar_button_left.png",
					":/img/buttons/title_bar_button_left_down.png");
				m_borderLeft = 14;
				m_borderRight = 8;
				break;
			case BUTTON_RIGHT:
				setInactiveImages(":/img/buttons/title_bar_button_right.png",
					":/img/buttons/title_bar_button_right_down.png");
				m_borderLeft = 8;
				m_borderRight = 14;
				break;
		}

		m_text->move(m_borderLeft, 0);
		m_text->resize(width() - m_borderLeft - m_borderRight, height());
	}

} // namespace ipn
