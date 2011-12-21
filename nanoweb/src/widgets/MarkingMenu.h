#ifndef IPN_MARKINGMENU_H
#define IPN_MARKINGMENU_H

#include <QWidget>

namespace ipn
{
	class TextWidget;

	class MarkingMenu : public QWidget
	{
		Q_OBJECT

		public:
			MarkingMenu(QWidget *parent = 0);

			void addEntry(QString text, QColor backgroundColor = Qt::white,
				QColor textColor = Qt::black);

			void deactivateAllEntries();

			int entryId(qreal angle);
			QString entryText(qreal angle);

			void setActiveColor(QColor color);

			virtual void mousePressEvent(QMouseEvent *event);
			virtual void mouseReleaseEvent(QMouseEvent *event);
			virtual void mouseMoveEvent(QMouseEvent *event);

		signals:
			void entryClicked(int entryId);
			void entryClicked(QString entryText);

		protected:
			void paintEvent(QPaintEvent *event);

		private:
			void determineActiveEntry(QPoint cursorPosition);
			void updateTextPositions();

			struct MarkingMenuEntry
			{
				TextWidget *text;
				QColor backgroundColor;
			};

			QVector<MarkingMenuEntry> m_menuEntries;
			int m_activeEntryId;
			QColor m_activeColor;
	};

} // namespace ipn

#endif // IPN_MARKINGMENU_H
