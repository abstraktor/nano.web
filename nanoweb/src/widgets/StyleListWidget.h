#ifndef IPN_STYLELISTWIDGET_H
#define IPN_STYLELISTWIDGET_H

#include <QWidget>

namespace ipn
{

	class TextWidget;
	class ImageWidget;

	class StyleListWidget : public QWidget
	{
		Q_OBJECT

		public:
			StyleListWidget(QWidget *parent = 0);

			void addEntry(QString text);

			QString selected;


		signals:
			void entryClicked(QString value);

		protected:
			virtual void paintEvent(QPaintEvent *event);
			virtual void mousePressEvent(QMouseEvent *event);
			virtual void mouseReleaseEvent(QMouseEvent *event);
			virtual void mouseMoveEvent(QMouseEvent *event);

		private:
			QVector<QString> m_entries;

			bool doSwiping, mousePressed, doZooming, buttonPressed;
			QPoint translation, diff, lastPoint;
			int m_activeEntry;
	};

} // namespace ipn

#endif // IPN_STYLELISTWIDGET_H
