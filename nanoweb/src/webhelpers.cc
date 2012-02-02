#include "webhelpers.h"
#include <QDebug>
#include <QtGlobal>

#define CONTENTLENGTH 15

namespace ipn
{
namespace webhelpers
{

QString elementShortIdentifierString(QWebElement el) {
	QString s;
	s = el.tagName().toUpper();

	s = trim(s);
	return s;
}

QString elementIdentifierString(QWebElement el)
{
	QString s;
	if (el.attribute("id") != "")
		s =  el.tagName() + "#" + el.attribute("id");
	else if (el.attribute("class") != "")
		s =  el.tagName() + "." + el.attribute("class");
	else
		s = el.tagName();
	s = trim(s);
	return s;
}

QString elementTypeString(QWebElement el) {
	QString s;
	if (el.attribute("id") != "")
		s =  "#" + el.attribute("id");
	else if (el.attribute("class") != "")
		s =  "." + el.attribute("class");
	else
		s = "";
	s = trim(s);
	return s;
}

QString elementContentString(QWebElement el)
{
	QString s = el.toPlainText().trimmed().replace("\n", " ");
	if (s.length() == 0) {
		if (el.tagName().toLower() == "img") {
			s = el.attribute("src");
			s = trim(s, true);
		}
		if (s == "") {
			s = "[no content]";
		}
		return s;
	}
	s = trim(s);

	return "\"" + s + "\"";
}

QString elementContent2String(QWebElement el) {
	QString s = "";
	if (el.tagName().toLower() == "img") {
		s = "width: " + el.styleProperty("width", QWebElement::ComputedStyle);
		s = trim(s, true);
	}
	else if (el.tagName().toLower() == "a") {
		s = el.attribute("href");
		s = trim(s, true);
	}
	else if (el.tagName().toLower() == "div" || el.tagName().toLower() == "tbody" || el.tagName().toLower() == "table" || el.tagName().toLower() == "tr" || el.tagName().toLower() == "td" || el.tagName().toLower() == "body") {
		s = "width: " + el.styleProperty("width", QWebElement::ComputedStyle);
		s = trim(s, true);
	}
	return s;
}
QString elementContent3String(QWebElement el) {
	QString s = "";
	if (el.tagName().toLower() == "img") {
		s = "height: " + el.styleProperty("height", QWebElement::ComputedStyle);
		s = trim(s, true);
	}
	else if (el.tagName().toLower() == "div" || el.tagName().toLower() == "tbody" || el.tagName().toLower() == "table" || el.tagName().toLower() == "tr" || el.tagName().toLower() == "td" || el.tagName().toLower() == "body") {
		s = "height: " + el.styleProperty("height", QWebElement::ComputedStyle);
		s = trim(s, true);
	}
	return s;
}
QString elementContent4String(QWebElement el) {
	QString s = "";
	return s;
}

QString trim(QString s, bool right) {
	if (s.length() > CONTENTLENGTH) {
		if (right)
			s = "..." + s.right(CONTENTLENGTH);
		else
			s = s.left(CONTENTLENGTH) + "...";
	}
	return s;
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
