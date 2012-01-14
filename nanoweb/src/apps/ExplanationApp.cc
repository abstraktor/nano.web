#include "ExplanationApp.h"
#include "widgets/BackgroundWidget.h"
#include "widgets/TextWidget.h"
#include "widgets/ScalableButtonWidget.h"
#include <QPainter>
#include <QDebug>

namespace ipn
{

	ExplanationApp::ExplanationApp(QWidget *parent) : App(parent)
	{

		m_okButton = new ScalableButtonWidget(this);
		m_okButton->move(160, 180);
		m_okButton->resize(64, 48);
		m_okButton->setImage(":/img/buttons/default");
		m_okButton->setText("OK");
		connect(m_okButton, SIGNAL(clicked()), this, SIGNAL(okButtonClicked()));
		setAccessibleName("ExplanationApp");
	}

	void ExplanationApp::paintEvent(QPaintEvent*)
	{
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);

		QPixmap pixmap = QPixmap(":img/our_imgs/explanation.png");
		painter.drawPixmap(0, 0, 240, 240, pixmap);
	}

} // namespace ipn
