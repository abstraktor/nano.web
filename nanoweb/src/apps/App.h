#ifndef IPN_APP_H
#define IPN_APP_H

#include "widgets/OverlayWidget.h"
#include <QWidget>

namespace ipn
{

	// App is an abstract class which represents an app for the iPod nano. You have to derive
	// from this class if you want to create new apps.
	class App : public QWidget
	{
		Q_OBJECT

		public:
			App(QWidget *parent = 0);

			// This boolean constant function indicates if an app is opaque (true) or not (false).
			// Opaque apps will be painted above other apps and will not push other apps away when started.
			// Every app should decide if it is opaque or not, otherwise the default (true) is assumed.
			virtual inline bool isOpaque() {return true;}

			// Part of gesture recognition, you won't normally need this function unless
			// you want to add custom gestures.
			void handleGesture(GestureType type, qreal param = 0);

		signals:
			// Gesture signals. Connect to these signals if you want to react to gesture events:

			// Signal emitted when the users have two fingers on the screen and rotates them.
			// The parameter 'delta' is the angle difference, which can be positive or negative.
			void pinchRotationAngleChanged(qreal delta);

			// Signal emitted when the users have two fingers on the screen and the distance
			// between the two touch points becomes smaller or greater. The exact changement is
			// provided by the parameter 'delta', which can be positive or negative.
			void pinchScaleFactorChanged(qreal delta);

			// Signal emitted when the users have two fingers on the screen and the distance
			// between the two touch points becomes greater (pinch in) or smaller (pinch out).
			// If one of these signals is emitted, pinchScaleFactorChanged() is also emitted.
			void pinchInTriggered();
			void pinchOutTriggered();

			// Signal emitted when the users swipe a finger over the screen. The starting point
			// and the final point make up a line, whose angle is provided by the parameter 'angle'.
			// 0.0 <= angle < 360.0
			void swipeTriggered(qreal angle);

			// Signals emitted when the users swipe a finger over the screen to a specific
			// direction. If one of these signals is emitted, swipeTriggered() is also emitted.
			void swipeLeftTriggered();
			void swipeUpTriggered();
			void swipeRightTriggered();
			void swipeDownTriggered();
	};

} // namespace ipn

#endif /* end of include guard: IPN_APP_H */
