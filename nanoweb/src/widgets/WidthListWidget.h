#ifndef IPN_WIDTHLISTWIDGET_H
#define IPN_WIDTHLISTWIDGET_H

#include <QWidget>

namespace ipn
{

	class TextWidget;
	class ImageWidget;

	class WidthListWidget : public QWidget
	{
		Q_OBJECT

		public:
			WidthListWidget(QWidget *parent = 0);

			void addEntry(QString text);

			int activeEntry();
			QString activeEntryText();
			void setActiveEntry(int activeEntry);

		signals:
			void entryChanged();

		protected:
			virtual void paintEvent(QPaintEvent *event);
			virtual void mousePressEvent(QMouseEvent *event);
			virtual void mouseReleaseEvent(QMouseEvent *event);

		private:
			QVector<QString> m_entries;
			int m_activeEntry;
			int m_highlightedEntry;
	};

} // namespace ipn

#endif // IPN_WIDTHLISTWIDGET_H
