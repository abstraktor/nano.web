#include "SwitchButtonWidget.h"

namespace ipn
{

	SwitchButtonWidget::SwitchButtonWidget(QWidget *parent) : ButtonWidget(parent)
	{
		setInactiveImages(":/img/buttons/switchbutton_off.png",
			":/img/buttons/switchbutton_off_down.png");

		setActiveImages(":/img/buttons/switchbutton_on.png",
			":/img/buttons/switchbutton_on_down.png");

		setDisabledImage(":/img/buttons/switchbutton_disabled.png");

		connect(this, SIGNAL(clicked()), this, SLOT(toggle()));
	}

	bool SwitchButtonWidget::isOn()
	{
		return isActive();
	}

	void SwitchButtonWidget::switchOn()
	{
		setActive(true);
	}

	void SwitchButtonWidget::switchOff()
	{
		setActive(false);
	}

	void SwitchButtonWidget::toggle()
	{
		setActive(!isActive());
	}

}
