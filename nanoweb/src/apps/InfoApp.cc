#include "InfoApp.h"
#include "widgets/BackgroundWidget.h"
#include "widgets/TextWidget.h"
#include "widgets/ScalableButtonWidget.h"

namespace ipn
{

	InfoApp::InfoApp(QWidget *parent) : App(parent)
	{
		m_back = new BackgroundWidget(this);
		m_back->setColor(BackgroundWidget::BG_TRANSPARENT);
		m_back->move(0, 0);

		m_note = new TextWidget(this);
		m_note->move(0, 0);
		m_note->resize(240, 240);
		m_note->setAlignment(Qt::AlignCenter);
		m_note->setFontSize(15);
		m_note->setLineHeight(1.25);
		m_note->setColor(Qt::white);

		m_okButton = new ScalableButtonWidget(this);
		m_okButton->move(160, 180);
		m_okButton->resize(64, 48);
		m_okButton->setImage(":/img/buttons/default");
		m_okButton->setText("OK");
		connect(m_okButton, SIGNAL(clicked()), this, SIGNAL(okButtonClicked()));
	}

	void InfoApp::setMessage(QString message)
	{
		m_note->setText(message);

		update();
	}

} // namespace ipn
