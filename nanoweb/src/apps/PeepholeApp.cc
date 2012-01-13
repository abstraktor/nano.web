#include "PeepholeApp.h"
#include "widgets/TextWidget.h"

namespace ipn
{

	PeepholeApp::PeepholeApp(QWidget *parent) : App(parent)
	{
		m_text = new TextWidget(this);
		m_text->setText("Peep Hole!\nPeep Hole!\nPeep Hole!");
		m_text->move(0, 0);
		m_text->resize(2 * 240, 2 * 240);
		m_text->setAlignment(Qt::AlignTop | Qt::AlignLeft);
		m_text->setFontSize(60);
		m_text->setFontStyle(TextWidget::STYLE_BOLD);
	}

	void PeepholeApp::moveContents(const QPoint relativeMovement)
	{
		m_text->move(m_text->pos() - relativeMovement);

		update();
	}

} // namespace ipn
