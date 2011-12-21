#include "IPodFrameWidget.h"
#include "widgets/ImageWidget.h"
#include "widgets/ButtonWidget.h"
#include "helpers.h"
#include <QGridLayout>
#include <QMoveEvent>
#include <QSize>
#include <QTimer>
#include <math.h>

namespace ipn
{

	IPodFrameWidget::IPodFrameWidget(QWidget *parent) : QWidget(parent),
		m_currentlyDragging(false),
		m_dragging(false)
	{
		m_paddingTop = 57;

		QGridLayout *layout = new QGridLayout(this);

		QString frameParts[3][3] = {{"tl.png", "t.png", "tr.png"},
			{"l.png", "", "r.png"},
			{"bl.png", "b.png", "br.png"}};

		for (int i = FRAME_TOP; i <= FRAME_BOTTOM; i++)
			for (int j = FRAME_LEFT; j <= FRAME_RIGHT; j++)
				// Draw all parts of the frame and leave the middle empty
				if (!(i == FRAME_CENTER && j == FRAME_CENTER))
				{
					m_frameImages[i][j] = new ImageWidget(this);
					m_frameImages[i][j]->setImage(":/img/frame/" + frameParts[i][j]);

					// Make sure the screen's resolution is always 240×240 pixels
					if (i == FRAME_CENTER)
						m_frameImages[i][j]->resize(m_frameImages[i][j]->width(), 240);

					if (j == FRAME_CENTER)
						m_frameImages[i][j]->resize(240, m_frameImages[i][j]->height());

					layout->addWidget(m_frameImages[i][j], i, j);
				}

		m_appWidget = new QWidget(this);

		layout->addWidget(m_appWidget, FRAME_CENTER, FRAME_CENTER);
		layout->setSpacing(0);
		layout->setContentsMargins(0, m_paddingTop, 0, 0);

		m_hardwareButton = new ButtonWidget(this);
		m_hardwareButton->setInactiveImages(":/img/frame/hardware_button.png",
			":/img/frame/hardware_button_down.png");
		m_hardwareButton->move(240, 0);
		m_hardwareButton->setMouseTracking(true);
		connect(m_hardwareButton, SIGNAL(clicked()), this, SLOT(popApp()));

		setFixedSize(frameSize());
		resize(frameSize());

		m_animationOffset = 0;
		m_animationType = ANIMATION_NONE;

		m_animationTimer = new QTimer(this);
		m_animationTimer->setInterval(30);
		m_animationTimer->setSingleShot(false);
		connect(m_animationTimer, SIGNAL(timeout()), this, SLOT(drawAnimation()));

		setMouseTracking(true);
		setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	}

	QSize IPodFrameWidget::frameSize()
	{
		int width = m_frameImages[FRAME_TOP][FRAME_LEFT]->width()
			+ 240 + m_frameImages[FRAME_TOP][FRAME_RIGHT]->width();

		int height = m_frameImages[FRAME_TOP][FRAME_LEFT]->height()
			+ 240 + m_frameImages[FRAME_BOTTOM][FRAME_LEFT]->height()
			+ m_paddingTop;

		return QSize(width, height);
	}

	QRect IPodFrameWidget::contentRect()
	{
		int x = m_frameImages[FRAME_TOP][FRAME_LEFT]->width();
		int y = m_frameImages[FRAME_TOP][FRAME_LEFT]->height() + m_paddingTop;

		return QRect(x, y, 240, 240);
	}

	int IPodFrameWidget::paddingTop()
	{
		return m_paddingTop;
	}

	void IPodFrameWidget::mouseMoveEvent(QMouseEvent *event)
	{
		if (m_prevMousePosition.isNull())
			m_prevMousePosition = event->globalPos();

		if (m_dragging)
			move(pos() + event->globalPos() - m_prevMousePosition);

		m_prevMousePosition = event->globalPos();
		event->ignore();
	}

	void IPodFrameWidget::mousePressEvent(QMouseEvent *event)
	{
		if (!contentRect().contains(event->pos()))
			m_dragging = true;

		m_prevMousePosition = event->globalPos();
	}

	void IPodFrameWidget::mouseReleaseEvent(QMouseEvent*)
	{
		m_dragging = false;
	}

	void IPodFrameWidget::moveEvent(QMoveEvent *event)
	{
		// Emit event for use without and with the position difference as parameter
		emit frameMoved();
		emit frameMoved(event->pos() - event->oldPos());
	}

	App *IPodFrameWidget::topApp()
	{
		return m_appStack.isEmpty() ? NULL : m_appStack.back();
	}

	App *IPodFrameWidget::preTopApp()
	{
		return m_appStack.size() < 2 ? NULL : m_appStack.at(m_appStack.size() - 2);
	}

	void IPodFrameWidget::instantPushApp(App *app)
	{
		// Make sure the app's parent is our app wrapper widget
		app->setParent(m_appWidget);
		app->resize(240, 240);
		app->move(0, 0);

		// Push the app on the stack an redraw everything
		m_appStack.append(app);
		refresh();
	}

	void IPodFrameWidget::pushApp(App *app)
	{
		instantPushApp(app);

		if (topApp())
			topApp()->move(240, 0);

		if (preTopApp())
		{
			preTopApp()->move(0, 0);
			preTopApp()->show();
		}

		m_animationOffset = 240;
		m_animationType = ANIMATION_LEFT;
		m_animationTimer->start();
	}

	void IPodFrameWidget::instantPopApp()
	{
		if (m_appStack.isEmpty())
			return;

		// Remove the app from the stack, but keep a pointer on it
		App *lastApp = m_appStack.back();
		m_appStack.pop_back();

		// Redraw everything
		refresh();

		// After refreshing, hide the app to prevent flickering
		lastApp->hide();
	}

	void IPodFrameWidget::popApp()
	{
		if (m_appStack.isEmpty())
			return;

		if (m_animationType != ANIMATION_NONE)
			return;

		m_popAppCount = 1;
		m_opaquePopAppCount = 1;

		popMultipleApps();
	}

	void IPodFrameWidget::instantSwitchBackTo(App *app)
	{
		// Delete the last app from the stack until we find the specified app
		while (!m_appStack.isEmpty())
		{
			if (m_appStack.last() == app)
				break;

			m_appStack.last()->hide();
			m_appStack.pop_back();
		}

		// Redraw everything
		refresh();
	}

	void IPodFrameWidget::switchBackTo(App *app)
	{
		if (m_animationType != ANIMATION_NONE)
			return;

		m_opaquePopAppCount = -1;

		for (int i = m_appStack.size() - 1; i >= 0; i--)
		{
			m_opaquePopAppCount += m_appStack.at(i)->isOpaque();

			if (app == m_appStack.at(i))
			{
				m_popAppCount = m_appStack.size() - i - 1;
				popMultipleApps();

				return;
			}
		}
	}

	void IPodFrameWidget::instantReplaceAllAppsBy(App *app)
	{
		// Hide all apps on the stack
		for (QVector<App*>::iterator a = m_appStack.begin(); a != m_appStack.end(); a++)
			(*a)->hide();

		// Make the specified app the only app on the stack
		m_appStack.clear();
		instantPushApp(app);

		// Redraw everything
		refresh();
	}

	void IPodFrameWidget::refresh()
	{
		// Iterate backwards to the last opaque app:
		QVector<App*>::iterator w = m_appStack.end() - 1;
		(*w)->show();

		while (w != m_appStack.begin() && !(*w)->isOpaque())
		{
			w--;
			(*w)->show();
		}

		// All other apps below are not visible and don't have to be drawn:
		while (w != m_appStack.begin())
		{
			w--;
			(*w)->hide();
		}
	}

	void IPodFrameWidget::drawAnimation()
	{
		if (m_animationType == ANIMATION_LEFT)
			m_animationOffset *= 0.6;
		else if (m_animationType == ANIMATION_RIGHT)
			m_animationOffset *= 1.0 - 0.4 * pow(0.5, (float)m_opaquePopAppCount - 1.0);

		if (m_animationOffset > -1.0 && m_animationOffset < 1.0)
		{
			// Animation finished
			m_animationOffset = 0;
			m_animationTimer->stop();

			if (m_animationType == ANIMATION_RIGHT)
				// Remove apps
				for (int i = 0; i < m_popAppCount; i++)
				{
					m_appStack.back()->hide();
					m_appStack.pop_back();
				}

			if (m_animationType == ANIMATION_LEFT && topApp() && preTopApp()
				&& topApp()->isOpaque())
			{
				preTopApp()->hide();
				preTopApp()->move(0, 0);
			}

			if (topApp())
				topApp()->move(0, 0);

			m_animationType = ANIMATION_NONE;

			return;
		}

		// Proceed animation:
		if (m_animationType == ANIMATION_LEFT)
		{
			if (topApp())
				topApp()->move(m_animationOffset, 0);

			if (preTopApp() && topApp()->isOpaque())
				preTopApp()->move(m_animationOffset - 240.0, 0);
		}

		if (m_animationType == ANIMATION_RIGHT)
		{
			int pos = m_opaquePopAppCount;

			for (int i = m_appStack.size() - 1; i >= m_appStack.size() - 1 - m_popAppCount; i--)
			{
				if (i < m_appStack.size() - 1)
				{
					pos--;

					if (!m_appStack.at(i+1)->isOpaque())
					{
						if (i == m_appStack.size() - 1 - m_popAppCount)
						{
							m_appStack.at(i)->move(0, 0);

							continue;
						}
						else
							pos++;
					}
				}

				m_appStack.at(i)->move(m_animationOffset + 240.0 * (float)pos, 0);
			}
		}
	}

	void IPodFrameWidget::popMultipleApps()
	{
		if (m_appStack.size() < 2)
			return;

		for (int i = 0; i < m_popAppCount; i++)
			m_appStack.at(m_appStack.size() - 2 - i)->show();

		m_animationOffset = -240.0 * (float)m_opaquePopAppCount;
		m_animationType = ANIMATION_RIGHT;
		m_animationTimer->start();
	}

} // namespace ipn
