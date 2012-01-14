#ifndef IPN_EXPLANATIONAPP_H
#define IPN_EXPLANATIONAPP_H

#include "App.h"

namespace ipn
{
	class BackgroundWidget;
	class TextWidget;
	class ScalableButtonWidget;

	class ExplanationApp : public App
	{
		Q_OBJECT

	public:
		ExplanationApp(QWidget *parent = 0);

		inline bool isOpaque() {return false;}

	signals:
		void okButtonClicked();
	protected:
		virtual void paintEvent(QPaintEvent *event);

	private:
		ScalableButtonWidget *m_okButton;
	};

	} // namespace ipn

#endif /* end of include guard: IPN_EXPLANATIONAPP_H */
