#ifndef IPN_PAINTAPP_H
#define IPN_PAINTAPP_H

#include "App.h"

class QMouseEvent;
class QPolygon;

namespace ipn
{

	// PaintApp demonstrates how to paint custom graphics whithin a widget.
	class PaintApp : public App
	{
		Q_OBJECT

		public:
			PaintApp(QWidget *parent = 0);

			inline bool isOpaque() {return true;}

		protected:
			virtual void mousePressEvent(QMouseEvent *event);
			virtual void mouseMoveEvent(QMouseEvent *event);
			virtual void paintEvent(QPaintEvent *event);

		private:
			QVector<QPolygon> m_drawing;
	};

} // namespace ipn

#endif /* end of include guard: IPN_PAINTAPP_H */
