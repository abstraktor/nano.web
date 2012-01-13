#include "MultiTapApp.h"
#include "widgets/BackgroundWidget.h"
#include "widgets/ImageWidget.h"
#include "widgets/TextWidget.h"
#include "widgets/ScalableButtonWidget.h"
#include <QTimer>
#include <QtDebug>

namespace ipn
{

	/*QString characters[12] =
	{
		".,?!'\"1-()@/:_",
		"abc2äàáãâåæç",
		"def3èéëêð",
		"ghi4ìíîï",
		"jkl5£",
		"mno6öòóôõøñ",
		"pqrs7$",
		"tuv8üùúû",
		"wxyz9ýþ",
		0,
		" 0",
		0
	};*/
	QString characters[12] =
	{
		"1",
		"2",
		"3",
		"4",
		"5",
		"6",
		"7",
		"8",
		"9",
		0,
		"0",
		0
	};

	MultiTapApp::MultiTapApp(QWidget *parent) : App(parent)
	{
		m_back = new BackgroundWidget(this);
		m_back->setColor(BackgroundWidget::BG_GRAY);
		m_back->move(0, 0);

		m_textBoxLeft = new ImageWidget(this);
		m_textBoxLeft->setImage(":/img/textbox/background_left.png");
		m_textBoxLeft->move(8, 8);
		m_textBoxLeft->resize(32, 40);

		m_textBoxMiddle = new ImageWidget(this);
		m_textBoxMiddle->setImage(":/img/textbox/background_middle.png");
		m_textBoxMiddle->move(40, 8);
		m_textBoxMiddle->resize(160, 40);

		m_textBoxRight = new ImageWidget(this);
		m_textBoxRight->setImage(":/img/textbox/background_right.png");
		m_textBoxRight->move(200, 8);
		m_textBoxRight->resize(32, 40);

		m_text = new TextWidget(this);
		m_text->setColor(Qt::black);
		m_text->setAlignment(Qt::AlignLeft);
		m_text->resize(172, 32);
		m_text->move(20, 16);

		m_unitButton = new ScalableButtonWidget(this);
		m_unitButton->move(162, 8);
		m_unitButton->resize(70, 40);
		m_unitButton->setImage(":/img/buttons/default");
		m_unitButton->setIconImage(":/img/icons/multitap/key_12a");
		connect(m_unitButton, SIGNAL(clicked()), this, SLOT(unitChange()));

		for (int i = 0; i < 12; i++)
		{
			m_keys[i] = new ScalableButtonWidget(this);
			m_keys[i]->setImage(":/img/buttons/default");
			m_keys[i]->resize(70, 40);
			m_keys[i]->setIconImage(QString(":/img/icons/multitap/key_")
				+ QString::number(i) + QString(".png"));

			int row = i / 3;
			int column = i % 3;
			m_keys[i]->move(8 + 77 * column, 56 + 46 * row);

			connect(m_keys[i], SIGNAL(clicked()), this, SLOT(multiTapKeyPressed()));
		}

		m_cursorBlinkTimer = new QTimer(this);
		m_cursorBlinkTimer->setInterval(500);
		m_cursorBlinkTimer->setSingleShot(false);
		connect(m_cursorBlinkTimer, SIGNAL(timeout()), this, SLOT(blink()));
		m_cursorBlinkTimer->start();

		m_multiTapTimer = new QTimer(this);
		m_multiTapTimer->setInterval(1000);
		m_multiTapTimer->setSingleShot(true);
		connect(m_multiTapTimer, SIGNAL(timeout()), this, SLOT(catchCurrentChar()));

		m_currentChar = QChar();
		m_currentText = QString();
		m_lastKey = -1;
		m_cursorBlink = false;
	}

	QString MultiTapApp::text()
	{
		return m_currentText;
	}

	void MultiTapApp::multiTapKeyPressed()
	{
		for (int i = 11; i >= 0; i--)
			if (m_keys[i] == sender())
			{
				handleKey(i);
				break;
			}
	}

	void MultiTapApp::handleKey(int key)
	{
		if (key == 9)
		{
			// delete currently pressed key
			if (m_currentChar.isNull() && !m_currentText.isEmpty())
				m_currentText.chop(1);
			else
				m_currentChar = QChar();

			m_cursorBlink = false;
			m_cursorBlinkTimer->start();
		}
		else if (key == 11)
		{
			// accept button pressed
			emit accepted();
		}
		else
		{
			// Character key pressed

			m_currentText.append(characters[key].at(0));

			m_multiTapTimer->start();
			m_cursorBlinkTimer->stop();
			m_cursorBlink = false;
		}

		m_lastKey = key;

		refreshText();
	}

	void MultiTapApp::blink()
	{
		m_cursorBlink = !m_cursorBlink;

		refreshText();
	}

	void MultiTapApp::catchCurrentChar()
	{
		m_currentText.append(m_currentChar);
		m_currentChar = QChar();
		m_lastKey = -1;

		blink();
		m_cursorBlinkTimer->start();
	}

	void MultiTapApp::refreshText()
	{
		QString text = m_currentText;

		if (m_currentChar != QChar())
			text += m_currentChar;

		if (m_cursorBlink)
			text += "|";

		m_text->setText(text);
	}

	void MultiTapApp::unitChange() {
		qDebug() << "TODO: change unit";
	}

} // namespace ipn
