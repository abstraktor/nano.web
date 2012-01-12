#ifndef IPN_TEXTWIDGET_H
#define IPN_TEXTWIDGET_H

#include <QWidget>

namespace ipn
{

	class TextWidget : public QWidget
	{
		Q_OBJECT

		public:
			TextWidget(QWidget *parent = 0);

			enum {STYLE_REGULAR, STYLE_BOLD};

			int textHeight();

			QString text();
			void setText(QString text);

			int fontSize();
			void setFontSize(int fontSize);

			float lineHeight();
			void setLineHeight(float lineHeight);

			int fontStyle();
			void setFontStyle(int fontStyle);

			QColor color();
			void setColor(QColor color);

			Qt::Alignment alignment();
			void setAlignment(Qt::Alignment alignment);

		signals:

		public slots:

		protected:
			void paintEvent(QPaintEvent *event);

			int lineHeightInPixels();
			int numberOfLines();

		private:
			QStringList m_textLines;
			int m_fontSize;
			float m_lineHeight;
			int m_fontStyle;
			QColor m_color;
			Qt::Alignment m_alignment;
	};

} // namespace ipn

#endif // IPN_TEXTWIDGET_H
