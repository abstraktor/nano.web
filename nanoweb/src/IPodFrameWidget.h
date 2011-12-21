#ifndef IPN_IPODFRAMEWIDGET_H
#define IPN_IPODFRAMEWIDGET_H

#include <QPoint>
#include <QRect>
#include <QWidget>
#include "App.h"

class QMoveEvent;
class QTimer;

enum {ANIMATION_LEFT, ANIMATION_RIGHT, ANIMATION_NONE};

namespace ipn
{

	class ImageWidget;
	class ButtonWidget;

	/** IPodFrameWidget implements a widgets which shows a ipod nano frame based
	 *  on some images in img/.  See the ctor code for details.
	 */
	class IPodFrameWidget : public QWidget
	{
		Q_OBJECT

		public:
			enum HandPosture {UnknownPosture, SingleTouchPosture, PressButtonPosture};
			enum {FRAME_TOP = 0, FRAME_LEFT = 0, FRAME_CENTER = 1, FRAME_BOTTOM = 2, FRAME_RIGHT = 2};

			IPodFrameWidget(QWidget *parent = 0);

			App *topApp();
			App *preTopApp();

			QSize frameSize();
			QRect contentRect();
			int paddingTop();

		signals:
			/** Signal emmited when the frame is moved, use this to emulate
			 *  accelerometer data or for peephole displays.
			 */
			void frameMoved();
			void frameMoved(const QPoint relativeMovement);

		public slots:
			// slots used for manipulating the app stack (animated):
			void pushApp(App *app);
			void popApp();
			void switchBackTo(App *app);

			// instant app stack manipulation functions (not animated):
			void instantPushApp(App *app);
			void instantPopApp();
			void instantSwitchBackTo(App *app);
			void instantReplaceAllAppsBy(App *app);

		private slots:
			void drawAnimation();

		protected:
			void mouseMoveEvent(QMouseEvent *event);
			void mousePressEvent(QMouseEvent *event);
			void mouseReleaseEvent(QMouseEvent *event);
			void moveEvent(QMoveEvent*);

		private:
			void popMultipleApps();
			void refresh();

			ImageWidget *m_frameImages[3][3];
			ButtonWidget *m_hardwareButton;

			int m_paddingTop;

			QPoint m_prevMousePosition;
			bool m_currentlyDragging;
			bool m_dragging;

			QVector<App*> m_appStack;
			QWidget *m_appWidget;

			// members needed for implementing animation:
			QTimer *m_animationTimer;
			float m_animationOffset;
			int m_animationType;
			int m_popAppCount;
			int m_opaquePopAppCount;
		};

} // namespace ipn

#endif /* end of include guard: IPN_IPODFRAMEWIDGET_H */
