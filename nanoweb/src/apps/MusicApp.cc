#include "MusicApp.h"
#include "widgets/FlickArea.h"
#include "widgets/TextWidget.h"
#include "widgets/BackgroundWidget.h"

namespace ipn
{

	MusicApp::MusicApp(QWidget *parent) : App(parent)
	{
		m_back = new BackgroundWidget(this);
		m_back->setColor(BackgroundWidget::BG_GRAY);
		m_back->move(0, 0);

		QVector<QString> songNames;
		songNames.append("Orchestral Intro");
		songNames.append("Welcome To The World of The Plastic Beach");
		songNames.append("White Flag");
		songNames.append("Rhinestone Eyes");
		songNames.append("Stylo");
		songNames.append("Superfast Jellyfish");
		songNames.append("Empire Ants");
		songNames.append("Glitter Freeze");
		songNames.append("Some Kind of Nature");
		songNames.append("On Melancholy Hill");
		songNames.append("Broken");
		songNames.append("Sweepstakes");
		songNames.append("Plastic Beach");
		songNames.append("To Binge");
		songNames.append("Cloud of Unknowing");
		songNames.append("Pirate Jet");

		m_flickArea = new FlickArea(this);
		m_flickArea->resize(240, 240);
		m_flickArea->move(0, 0);

		for (int i = 0; i < songNames.count(); i++)
		{
			TextWidget *t = new TextWidget(m_flickArea);
			t->setColor(Qt::white);
			t->resize(240, 40);
			t->move(0, 40 * i);
			t->setText(songNames.at(i));
		}

	}

} // namespace ipn
