#include "ClockApp.h"
#include "widgets/BackgroundWidget.h"
#include "widgets/TextWidget.h"
#include "widgets/ScalableButtonWidget.h"
#include <QDateTime>
#include <QTimerEvent>

namespace ipn
{

	ClockApp::ClockApp(QWidget *parent) : App(parent)
	{
		m_back = new BackgroundWidget(this);
		m_back->setColor(BackgroundWidget::BG_TRANSPARENT);
		m_back->move(0, 0);

		m_timeText = new TextWidget(this);
		m_timeText->move(0, 0);
		m_timeText->resize(240, 240);
		m_timeText->setAlignment(Qt::AlignCenter);
		m_timeText->setFontSize(40);
		m_timeText->setColor(Qt::white);

		m_okButton = new ScalableButtonWidget(this);
		m_okButton->move(160, 180);
		m_okButton->resize(64, 48);
		m_okButton->setImage(":/img/buttons/default");
		m_okButton->setText("OK");

		startTimer(500);
	}

	void ClockApp::timerEvent(QTimerEvent*)
	{
		m_timeText->setText(QDateTime::currentDateTime().toString("hh:mm:ss"));
	}

	void ClockApp::mouseReleaseEvent(QMouseEvent*)
	{
		emit okButtonClicked();
	}

} // namespace ipn
