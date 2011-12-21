#ifndef IPN_PAGEINDICATORWIDGET_H
#define IPN_PAGEINDICATORWIDGET_H

#include <QWidget>

namespace ipn
{

	class PageIndicatorWidget : public QWidget
	{
		Q_OBJECT

		public:
			PageIndicatorWidget(QWidget *parent);
			~PageIndicatorWidget();

			void setNumberOfSegments(int numberOfSegments);
			void setPosition(float position);
			void setActiveSegment(int activeSegment);

		protected:
			virtual void paintEvent(QPaintEvent *event);

		private:
			int m_numberOfSegments;
			int m_activeSegment;

			QPixmap *m_activePixmap, *m_inactivePixmap;
	};

} // namespace ipn

#endif // IPN_PAGEINDICATORWIDGET_H
