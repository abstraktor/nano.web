#ifndef IPN_PICKERWIDGET_H
#define IPN_PICKERWIDGET_H

#include <QWidget>

namespace ipn
{

	class TextWidget;
	class ImageWidget;

	class PickerWidget : public QWidget
	{
		Q_OBJECT

		public:
			PickerWidget(QWidget *parent = 0);

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
			QVector<TextWidget*> m_entries;
			ImageWidget *m_entryDownImage, *m_checkmarkImage;
			int m_activeEntry;
			int m_highlightedEntry;
	};

} // namespace ipn

#endif // IPN_PICKERWIDGET_H
