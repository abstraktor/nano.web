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
		if (el.attribute("id") != "")
			return el.tagName() + "#" + el.attribute("id");
		if (el.attribute("class") != "")
			return el.tagName() + "." + el.attribute("class");

		return el.tagName();
	}

	QString elementContentString(QWebElement el)
	{
		QString s = el.toPlainText().trimmed();
		if (s.length() == 0)
			return "[no content]";
		if (s.length() > CONTENTLENGTH) {
			s = s.left(CONTENTLENGTH) + "...";
		}
		return "\"" + s + "\"";
	}

	} // namespace webhelpers
} // namespace ipn
