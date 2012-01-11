#ifndef IPN_PEEPHOLEAPP_H
#define IPN_PEEPHOLEAPP_H

#include "App.h"

class QLabel;

namespace ipn
{

	class TextWidget;

	// PeepholeApp demonstrates how to do peepholes.
	class PeepholeApp : public App
	{
		Q_OBJECT

		public:
			PeepholeApp(QWidget *parent = 0);

		public slots:
			void moveContents(const QPoint relativeMovement);

		private:
			TextWidget *m_text;
	};

} // namespace ipn

#endif /* end of include guard: IPN_PEEPHOLEAPP_H */
