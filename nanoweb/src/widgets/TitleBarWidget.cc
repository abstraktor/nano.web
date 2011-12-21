#include "TitleBarWidget.h"
#include "TitleBarButtonWidget.h"
#include "TextWidget.h"
#include "ImageWidget.h"
#include "helpers.h"
#include <QPainter>

namespace ipn
{

	TitleBarWidget::TitleBarWidget(QWidget *parent)	: ClickableWidget(parent)
	{
		resize(240, 48);

		m_titlebarImage = new ImageWidget(this);
		m_titlebarImage->setImage(":/img/backgrounds/title_bar.png");
		m_titlebarImage->move(0, 0);

		m_title = new TextWidget(this);
		m_title->setColor(Qt::black);
		m_title->setFontSize(14);
		m_title->setFontStyle(TextWidget::STYLE_BOLD);
		m_title->setLineHeight(0.8);

		m_leftButton = NULL;
		m_rightButton = NULL;
	}

	void TitleBarWidget::paintEvent(QPaintEvent *)
	{
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing, true);

		int position = 0;
		int textWidth = width();

		if (m_leftButton)
		{
			position += 74;
			textWidth -= 74;
		}

		if (m_rightButton)
			textWidth -= 74;

		m_title->move(position, 0);
		m_title->resize(textWidth, 48);
	}

	void TitleBarWidget::setTitle(QString title)
	{
		m_title->setText(title);

		update();
	}

	void TitleBarWidget::setLeftButton(QString text, int buttonType)
	{
		if (m_leftButton != NULL)
			delete m_leftButton;

		m_leftButton = new TitleBarButtonWidget(this);
		m_leftButton->setButtonType(buttonType);
		m_leftButton->setText(text);
		m_leftButton->move(0, 0);

		connect(m_leftButton, SIGNAL(clicked()), this, SIGNAL(leftButtonClicked()));
	}

	void TitleBarWidget::setRightButton(QString text, int buttonType)
	{
		if (m_rightButton != NULL)
			delete m_rightButton;

		m_rightButton = new TitleBarButtonWidget(this);
		m_rightButton->setButtonType(buttonType);
		m_rightButton->setText(text);
		m_rightButton->move(240 - m_rightButton->width(), 0);

		connect(m_rightButton, SIGNAL(clicked()), this, SIGNAL(rightButtonClicked()));
	}

	void TitleBarWidget::addButton(int buttonType)
	{
		switch (buttonType)
		{
			case BUTTON_BACK:
				setLeftButton("back", TitleBarButtonWidget::BUTTON_LEFT);
				break;
			case BUTTON_CANCEL:
				setRightButton("cancel", TitleBarButtonWidget::BUTTON_RECTANGULAR);
				break;
			case BUTTON_CLOSE:
				setRightButton("close", TitleBarButtonWidget::BUTTON_RECTANGULAR);
				break;
			case BUTTON_DONE:
				setRightButton("done", TitleBarButtonWidget::BUTTON_RECTANGULAR);
				break;
			case BUTTON_EDIT:
				setRightButton("edit", TitleBarButtonWidget::BUTTON_RECTANGULAR);
				break;
			case BUTTON_QUIT:
				setRightButton("quit", TitleBarButtonWidget::BUTTON_RECTANGULAR);
				break;
			case BUTTON_REDO:
				setRightButton("redo", TitleBarButtonWidget::BUTTON_RECTANGULAR);
				break;
			case BUTTON_SAVE:
				setRightButton("save", TitleBarButtonWidget::BUTTON_RECTANGULAR);
				break;
			case BUTTON_UNDO:
				setRightButton("undo", TitleBarButtonWidget::BUTTON_RECTANGULAR);
				break;
		}
	}

} // namespace ipn
