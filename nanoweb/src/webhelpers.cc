#include "webhelpers.h"
#include <QDebug>
#include <QtGlobal>

#define CONTENTLENGTH 15

namespace ipn
{
	namespace webhelpers
	{
	QString elementIdentifierString(QWebElement el)
	{
		QString s;
		if (el.attribute("id") != "")
			s =  el.tagName().toUpper() + "#" + el.attribute("id");
		else if (el.attribute("class") != "")
			s =  el.tagName().toUpper() + "." + el.attribute("class");
		else
			s = el.tagName().toUpper();

		if (s.length() > CONTENTLENGTH)
			s = s.left(CONTENTLENGTH) + "...";
		return s;
	}

	QString elementContentString(QWebElement el)
	{
		QString s = el.toPlainText().trimmed().replace("\n", " ");
		if (s.length() == 0)
			return "[no content]";
		if (s.length() > CONTENTLENGTH) {
			s = s.left(CONTENTLENGTH) + "...";
		}
		return "\"" + s + "\"";
	}

	QColor stringToColor(QString colorString) {
		if (colorString == "")
			return QColor(0, 0, 0);
		if (!colorString.contains("rgb")) {
			qDebug() << "Error: not implemented color, contact Stefan: " << colorString;
			return Qt::black;
		}
		int r, g, b;
		QString newS;

		for (int i = 0; i < colorString.length(); i++) {
			if (colorString.at(i).isDigit())
				newS += colorString.at(i);
			if (colorString.at(i) == ',')
				newS += "#";

		}
		QStringList split = newS.split("#");
		r = split.at(0).toInt();
		g = split.at(1).toInt();
		b = split.at(2).toInt();
		return  QColor(r, g, b);
	}


	bool hasPreviousSibling(QWebElement el) {
		return nodeExists(el.previousSibling());
	}

	bool hasNextSibling(QWebElement el) {
		return nodeExists(el.nextSibling());
	}

	bool hasFirstChild(QWebElement el) {
		return nodeExists(el.firstChild());
	}

	bool hasParent(QWebElement el) {
		return nodeExists(el.parent());
	}

	bool nodeExists(QWebElement el) {
		return el.tagName() != "";
	}

	} // namespace webhelpers
} // namespace ipn
